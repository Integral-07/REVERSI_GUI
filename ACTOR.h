#pragma once
#include "GAME_OBJECT.h"

class ACTOR :
    public GAME_OBJECT
{
public:

    ACTOR(class GAME* game);

    virtual void draw() = 0;
    virtual void proc() = 0;


    // Setter/Getter
    void SetPosition(VECTOR2& pos) { Position = pos; }
    const VECTOR2& GetPosition() const { return Position; }

    void SetScale(float scale) { Scale = scale; }
    float GetScale() const { return Scale; }

    void SetColor(unsigned int color) { Color = color; }

private:

    VECTOR2 Position;
    float Scale;
    unsigned int Color;
};

