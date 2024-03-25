#pragma once
#include "GAME_OBJECT.h"
#include "GAME.h"

class Scene :
    public GAME_OBJECT
{
public:
    Scene(class GAME* game);
    virtual ~Scene();
    virtual void create();
    virtual void init();
    virtual void proc();
    virtual void update();
    virtual void draw();
    virtual void nextScene();
};

