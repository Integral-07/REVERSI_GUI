#include "selector.h"

bool Selector::getLimitFlag(limitFlags flag) const {

	switch (flag)
	{
	case leftLimit: return LeftLimitFlag;
	case rightLimit: return RightLimitFlag;
	case upperLimit: return UpperLimitFlag;
	case lowerLimit: return LowerLimitFlag;

		//default: throw FLAG_NO_EXIST_ERROR;
	}
}

int Selector::getRow() const {

	return currentRow;
}

int Selector::getLine() const {
	return currentLine;
}

int Selector::coordinate2rl(int xy) {
	//íºåç¿ïWånÇ©ÇÁçsÅEóÒÇ÷ïœä∑

	return 0;
}

void Selector::setPosition(int x, int y) {

	currentRow = coordinate2rl(x);
	currentLine = coordinate2rl(y);

	return;
}

void Selector::resetPosition() {

	setPosition(0, 0);

	return;
}

void Selector::move2left() {

	if (LeftLimitFlag == false) {

		move(-DistanceOfFrame, 0);
		if (leftUpper_x <= VisibleBoardPositionX) {

			LeftLimitFlag = true;
		}

		currentLine--;
	}

	RightLimitFlag = false; //limitâèú

	return;
}

void Selector::move2right() {

	if (RightLimitFlag == false) {

		move(DistanceOfFrame, 0);
		if (rightLower_x >= VisibleBoardEndX) {

			RightLimitFlag = true;
		}

		currentLine++;
	}

	LeftLimitFlag = false; //limitâèú

	return;
}

void Selector::move2upper() {

	if (UpperLimitFlag == false) {

		move(0, -DistanceOfFrame);
		if (leftUpper_y <= VisibleBoardPositionY) {

			UpperLimitFlag = true;
		}

		currentRow--;
	}

	LowerLimitFlag = false; //limitâèú

	return;
}

void Selector::move2lower() {

	if (LowerLimitFlag == false) {

		move(0, DistanceOfFrame);
		if (rightLower_y >= VisibleBoardEndY) {

			LowerLimitFlag = true;
		}

		currentRow++;
	}

	UpperLimitFlag = false; //limitâèú

	return;
}

void Selector::changeColor(unsigned int newColor) {

	color = newColor;

	return;
}

void Selector::DebugMonitor() {

	DrawFormatString(0, 0, GetColor(0, 0, 0), "current_row:%d", currentRow);
	DrawFormatString(0, 100, GetColor(0, 0, 0), "current_line:%d", currentLine);
	DrawFormatString(0, 200, GetColor(0, 0, 0), "UpperLeft_X:%d", leftUpper_x);
	DrawFormatString(0, 300, GetColor(0, 0, 0), "UpperLeft_Y:%d", leftUpper_y);
	DrawFormatString(0, 400, GetColor(0, 0, 0), "LowerRight_X:%d", rightLower_x);
	DrawFormatString(0, 500, GetColor(0, 0, 0), "LowerRight_Y:%d", rightLower_y);
	DrawFormatString(0, 600, GetColor(0, 0, 0), "LimitFlag_upper:%d", UpperLimitFlag);
	DrawFormatString(0, 700, GetColor(0, 0, 0), "LimitFlag_lower:%d", LowerLimitFlag);
	DrawFormatString(0, 800, GetColor(0, 0, 0), "LimitFlag_left:%d", LeftLimitFlag);
	DrawFormatString(0, 900, GetColor(0, 0, 0), "LimitFlag_right:%d", RightLimitFlag);

	return;
}