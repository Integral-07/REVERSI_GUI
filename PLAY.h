#pragma once
#include "Scene.h"
class PLAY :
    public Scene
{
public:
    PLAY(class Game* game);
    ~PLAY() override;

    void draw() override;
    void nextScene() override;
};

