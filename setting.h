#pragma once

#define GameTitle "REVERSI"
#define GameWidth 1920
#define GameHeight 1080
#define GameColor 32

#define boardSize 10                  //盤の一辺の長さ
#define squaresSize ( boardSize + 2 ) //処理対象のマス目の数

#define BoardBasePositionX 450//420~1500                           //処理盤の左上のx座標
#define BoardBasePositionY BoardBasePositionX - 420       //処理盤の左上のy座標

#define StoneBasePositionX BoardBasePositionX
#define StoneBasePositionY BoardBasePositionY
#define DistanceOfStone ( (GameWidth - 2*BoardBasePositionX) / squaresSize)
#define DistanceOfFrame DistanceOfStone

#define VisibleBoardPositionX (BoardBasePositionX + DistanceOfStone) //見かけの盤の左上x座標
#define VisibleBoardPositionY (BoardBasePositionY + DistanceOfStone)
#define VisibleBoardEndX (GameWidth - VisibleBoardPositionX)
#define VisibleBoardEndY (GameHeight - VisibleBoardPositionY)

#define KeyDownSpan 80 //[ms]