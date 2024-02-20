#pragma once

#define GameTitle "REVERSI"
#define GameWidth 1920
#define GameHeight 1080
#define GameColor 32

#define boardSize 10                  //�Ղ̈�ӂ̒���
#define squaresSize ( boardSize + 2 ) //�����Ώۂ̃}�X�ڂ̐�

#define BoardBasePositionX 450//420~1500                           //�����Ղ̍����x���W
#define BoardBasePositionY BoardBasePositionX - 420       //�����Ղ̍����y���W

#define StoneBasePositionX BoardBasePositionX
#define StoneBasePositionY BoardBasePositionY
#define DistanceOfStone ( (GameWidth - 2*BoardBasePositionX) / squaresSize)
#define DistanceOfFrame DistanceOfStone

#define VisibleBoardPositionX (BoardBasePositionX + DistanceOfStone) //�������̔Ղ̍���x���W
#define VisibleBoardPositionY (BoardBasePositionY + DistanceOfStone)
#define VisibleBoardEndX (GameWidth - VisibleBoardPositionX)
#define VisibleBoardEndY (GameHeight - VisibleBoardPositionY)

#define KeyDownSpan 80 //[ms]