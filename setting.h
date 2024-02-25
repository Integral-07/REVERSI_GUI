#pragma once

#define GameTitle "REVERSI"
#define GameWidth 1920
#define GameHeight 1080
#define GameColor 32

#define boardSize 10                  //�Ղ̈�ӂ̒���
#define squaresSize ( boardSize + 2 ) //�����Ώۂ̃}�X�ڂ̐�

#define BoardBasePositionX 450//420~1500                           //�����Ղ̍����x���W
#define BoardBasePositionY BoardBasePositionX - 420       //�����Ղ̍����y���W

#define initBasePosition squaresSize / 2
#define DistanceOfStone ( (GameWidth - 2*BoardBasePositionX) / squaresSize)
#define DistanceOfFrame DistanceOfStone
#define StoneBasePositionX BoardBasePositionX + DistanceOfStone/2
#define StoneBasePositionY BoardBasePositionY + DistanceOfStone/2
#define Radius (DistanceOfStone / 2 - 7)
#define StoneThick 8

#define VisibleBoardPositionX (BoardBasePositionX + DistanceOfStone) //�������̔Ղ̍���x���W
#define VisibleBoardPositionY (BoardBasePositionY + DistanceOfStone)
#define VisibleBoardEndX (GameWidth - VisibleBoardPositionX)
#define VisibleBoardEndY (GameHeight - VisibleBoardPositionY)

#define KeyDownSpan 80 //[ms]

#define FrameBasePositionX VisibleBoardPositionX
#define FrameBasePositionY VisibleBoardPositionY

#define ActiveColor GetColor(255, 255, 255)
#define DeactiveColor GetColor(0, 0, 0)
#define BannedColor GetColor(255, 0,  0)

