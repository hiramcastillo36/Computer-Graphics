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