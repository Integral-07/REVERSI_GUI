#pragma once
#include"key.h"
#include"setting.h"
#include<array>

class FrameArray {

private:

	class Frame {

	private:

		double leftUpper_x;
		double leftUpper_y;
		double rightLower_x;
		double rightLower_y;

		bool activation = false;
		unsigned int color;



	public:
		Frame() {}

		Frame(double _leftUpper_x, double _leftUpper_y, unsigned int _color)
			:leftUpper_x(_leftUpper_x), leftUpper_y(_leftUpper_y), color(_color) {

			rightLower_x = leftUpper_x + DistanceOfFrame;
			rightLower_y = leftUpper_y + DistanceOfFrame;
		}

		void activate() {

			activation = true;
			changeColor(ActiveColor);
		}
		void deactivate() {
			activation = false;
			changeColor(DeactiveColor);
		}

		void changeColor(unsigned int newColor) {

			color = newColor;

			return;
		}

		void DrawFrame() {

			DrawBox(leftUpper_x, leftUpper_y, rightLower_x, rightLower_y, color, false);
			return;
		}

		bool isHit(int x, int y) const {

			if (leftUpper_x < x && x < rightLower_x && leftUpper_y < y && y < rightLower_y) {

				return true;
			}

			return false;
		}

	};

	int currentActiveRow = 0;
	int currentActiveLine = 0;
	std::array<std::array<Frame, boardSize>, boardSize> Farray;

public:

	FrameArray() {

		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {

				Farray[i][j] = Frame(FrameBasePositionX + j * DistanceOfFrame, FrameBasePositionY + i * DistanceOfFrame, DeactiveColor);
			}
		}
	}

	void resetActivation() {

		currentActiveRow = 0;
		currentActiveLine = 0;

		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {

				Farray[i][j].deactivate();

			}
		}
	}

	void move2upper() {

		if (currentActiveRow - 1 >= 0) {

			Farray[currentActiveRow][currentActiveLine].deactivate();
			Farray[--currentActiveRow][currentActiveLine].activate();
		}
	}
	void move2lower() {

		if (currentActiveRow + 1 <= boardSize-1) {

			Farray[currentActiveRow][currentActiveLine].deactivate();
			Farray[++currentActiveRow][currentActiveLine].activate();
		}
	}
	void move2left() {

		if (currentActiveLine - 1 >= 0) {

			Farray[currentActiveRow][currentActiveLine].deactivate();
			Farray[currentActiveRow][--currentActiveLine].activate();
		}
	}
	void move2right() {

		if (currentActiveLine + 1 <= boardSize-1) {

			Farray[currentActiveRow][currentActiveLine].deactivate();
			Farray[currentActiveRow][++currentActiveLine].activate();
		}
	}
	void DrawFrames() {

		for (int i = 0; i < boardSize;i++) {
			for (int j = 0; j < boardSize; j++) {

				Farray[i][j].DrawFrame();
			}
		}
		return;
	}

	void DrawFrames(int* mouseX, int* mouseY, bool mousePriority) {

		for (int i = 0; i < boardSize;i++) {
			for (int j = 0; j < boardSize; j++) {

					
				if (mousePriority && Farray[i][j].isHit(*mouseX, *mouseY)) {

					Farray[currentActiveRow][currentActiveLine].deactivate();
					Farray[i][j].activate();

					currentActiveRow = i;
					currentActiveLine = j;
				}

				Farray[i][j].DrawFrame();
			}
		}

		return;
	}

	void cannotPlaced() {

		Farray[currentActiveRow][currentActiveLine].changeColor(BannedColor);
	}

	int getActiveRow() const{

		return currentActiveRow + 1;
	}

	int getActiveLine() const{

		return currentActiveLine + 1;
	}

};