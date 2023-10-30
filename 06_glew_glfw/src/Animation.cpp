//
// Created by Hiram Castillo on 15/09/23.
//

#include "../include/Animation.h"

Animation::Animation() {

}

vector <Vertex> Animation :: line(float dt, Vertex v1, Vertex v2){
    vector <Vertex> v = {};
    for(float t = 0.0; t <= 1+dt; t += dt) {
        v.push_back(v1 + ((v2 - v1) * t));
    }

    return v;
}

vector<Vertex> Animation :: hermite(Vertex P1, Vertex P4, Vertex R1, Vertex R4, float dt){

    Mat<float> MH   {   
                        {2, -2, 1, 1}, 
                        {-3,3,-2,-1}, 
                        {0,0, 1, 0}, 
                        {1, 0, 0, 0} 
                    };

    Mat <float> GH = {};
    
    GH.insert_rows(0, P1.row());
    GH.insert_rows(1, P4.row());
    GH.insert_rows(2, R1.row());
    GH.insert_rows(3, R4.row());
    
    cout << GH << endl;

    Col<float> GHx{1, 5, 3, -1};
    
    vector <Vertex> v = {};
    // ciclo para calcular las x
    for(float t=0.0; t<=1.0+dt; t+=dt){
        Row<float> T{ powf(t,3), powf(t,2), t, 1};
        Mat<float> Qt = T * MH * GH;
        
        Vertex tv(Qt(0,0), Qt(0,1), Qt(0,2));
        v.push_back(tv);
    }

    return v;
}

vector<Vertex> Animation :: bezier(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt){

    Mat<float> MH   {   
                        {2, -2, 1, 1}, 
                        {-3,3,-2,-1}, 
                        {0,0, 1, 0}, 
                        {1, 0, 0, 0} 
                    };

    Mat <float> GH = {};
    
    GH.insert_rows(0, P1.row());
    GH.insert_rows(1, P2.row());
    GH.insert_rows(2, P3.row());
    GH.insert_rows(3, P4.row());
    
    Col<float> GHx{1, 5, 3, -1};
    
    vector <Vertex> v = {};
    // ciclo para calcular las x
    for(float t=0.0; t<=1.0+dt; t+=dt){
        Row<float> T{ powf(t,3), powf(t,2), t, 1};
        Mat<float> Qt = T * MH * GH;
        
        Vertex tv(Qt(0,0), Qt(0,1), Qt(0,2));
        v.push_back(tv);
    }

    return v;
}

Mat<float> Animation :: T (float dx, float dy, float dz){
    Mat<float> T = {
                        {1, 0, 0, dx},
                        {0, 1, 0, dy},
                        {0, 0, 1, dz},
                        {0, 0, 0, 1}
                    };
    return T;
}

Mat<float> Animation :: S (float sx, float sy, float sz){
    Mat<float> S = {
                        {sx, 0, 0, 0},
                        {0, sy, 0, 0},
                        {0, 0, sz, 0},
                        {0, 0, 0, 1}
                    };
    return S;
}

Mat<float> Animation :: Rx (float theta){
    float theta_eucli = theta * (M_PI/180);
    Mat<float> Rx = {
                        {1, 0, 0, 0},
                        {0, cos(theta_eucli), -sin(theta_eucli), 0},
                        {0, sin(theta_eucli), cos(theta_eucli), 0},
                        {0, 0, 0, 1}
                    };
    return Rx;
}

Mat<float> Animation :: Ry (float theta){
    float theta_eucli = theta * (M_PI/180);
    Mat<float> Ry = {
                        {cos(theta_eucli), 0, sin(theta_eucli), 0},
                        {0, 1, 0, 0},
                        {-sin(theta_eucli), 0, cos(theta_eucli), 0},
                        {0, 0, 0, 1}
                    };
    return Ry;
}

Mat<float> Animation :: Rz (float theta){
    float theta_eucli = theta * (M_PI/180);
    Mat<float> Rz = {
                        {cos(theta_eucli), -sin(theta_eucli), 0, 0},
                        {sin(theta_eucli), cos(theta_eucli), 0, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 1}
                    };
    return Rz;
}