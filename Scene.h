#pragma once
#include "GameObject.h"
class Scene :
    public GameObject
{
public:
    Scene(class Game* game);
    virtual ~Scene();
    virtual void create();
    virtual void init();
    virtual void proc();
    virtual void update();
    virtual void draw();
    virtual void nextScene();
};

