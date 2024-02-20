#pragma once
#include"key.h"
#include"setting.h"

enum limitFlags {

	leftLimit,
	rightLimit,
	upperLimit,
	lowerLimit,

};

class Selector {

private:
	int currentRow = 0;
	int currentLine = 0;

	int UpperLimitFlag = false;
	int LowerLimitFlag = false;
	int LeftLimitFlag = false;
	int RightLimitFlag = false;

	double leftUpper_x;
	double leftUpper_y;
	double rightLower_x;
	double rightLower_y;

	unsigned int color;

	void move(double diff_x, double diff_y) {

		leftUpper_x += diff_x;
		leftUpper_y += diff_y;
		rightLower_x += diff_x;
		rightLower_y += diff_y;

		return;
	}

	int coordinate2rl(int);

public:

	Selector(double _leftUpper_x, double _leftUpper_y, unsigned int _color)
		:leftUpper_x(_leftUpper_x), leftUpper_y(_leftUpper_y), color(_color) {

		rightLower_x = leftUpper_x + DistanceOfFrame;
		rightLower_y = leftUpper_y + DistanceOfFrame;
	}


	void move2left();
	void move2right();
	void move2upper();
	void move2lower();

	void changeColor(unsigned int newColor);

	void DrawFrame() {

		DrawBox(leftUpper_x, leftUpper_y, rightLower_x, rightLower_y, color, false);
		return;
	}

	bool getLimitFlag(limitFlags) const;
	int getRow() const;
	int getLine() const;

	void setPosition(int, int);
	void resetPosition();

	void DebugMonitor();
};
