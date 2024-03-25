#pragma once
#include "Scene.h"

class TITLE :
    public Scene
{
public:
    struct DATA {

        unsigned int textColor;
        float fontSize;
        VECTOR2 pos;
        char text[16]; //4‚Ì”{”‚ª‚æ‚«
    };
private:
    DATA Title;

public:
    TITLE(class GAME* game);
    ~TITLE() override;

    void create() override;
    void draw() override;
    void nextScene() override;
};

