#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include "Utils.h"
#include "Model.h"
#include "Obj.h"

using namespace std;

class Enemy : public Utils
{
public:
    Enemy();
    void load();
    void draw(GLuint programID);

private:
    Model <Obj> enemy;

};

#endif