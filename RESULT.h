#pragma once
#include "Scene.h"
class RESULT :
    public Scene
{
public:
    struct DATA {

        unsigned int textColor;
        float fontSize;
        VECTOR2 pos;
        char text[16]; //4�̔{�����悫
    };
private:
    DATA Result;

public:
    RESULT(class GAME* game);
    ~RESULT() override;

    void draw() override;
    void create() override;
    void nextScene() override;
};

