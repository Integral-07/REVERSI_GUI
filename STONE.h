#pragma once
#include "ACTOR.h"
class STONE :
    public ACTOR
{
public:

    STONE(class GAME* game);

    void draw() override;
    void proc() override;

private:
};

