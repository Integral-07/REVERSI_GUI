#pragma once
#include "Scene.h"
class RESULT :
    public Scene
{
public:
    RESULT(class Game* game);
    ~RESULT() override;

    void draw() override;
    void nextScene() override;
};

