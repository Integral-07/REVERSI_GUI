#pragma once
#include "Scene.h"
class PLAY :
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
    DATA Play;

public:
    PLAY(class GAME* game);
    ~PLAY() override;

    void draw() override;
    void create() override;
    void nextScene() override;
};

