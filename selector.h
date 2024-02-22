#pragma once
#include"key.h"
#include"setting.h"
#include< array >

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

		void move(double diff_x, double diff_y) {

			leftUpper_x += diff_x;
			leftUpper_y += diff_y;
			rightLower_x += diff_x;
			rightLower_y += diff_y;

			return;
		}

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

				Farray[i][j] = Frame(VisibleBoardPositionX + j * DistanceOfFrame, VisibleBoardPositionY + i * DistanceOfFrame, DeactiveColor);
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

		Farray[0][0].activate();
	}

	void move2upper() {

		Farray[currentActiveRow][currentActiveLine].deactivate();
		Farray[currentActiveRow++][currentActiveLine].activate();
	}
	void move2lower() {

		Farray[currentActiveRow][currentActiveLine].deactivate();
		Farray[currentActiveRow--][currentActiveLine].activate();
	}
	void move2left() {

		Farray[currentActiveRow][currentActiveLine].deactivate();
		Farray[currentActiveRow][currentActiveLine--].activate();
	}
	void move2right() {

		Farray[currentActiveRow][currentActiveLine].deactivate();
		Farray[currentActiveRow][currentActiveLine++].activate();
	}

	void DrawFrames(int* mouseX, int* mouseY) {

		for (int i = 0; i < boardSize;i++) {
			for (int j = 0; j < boardSize; j++) {

					Farray[currentActiveRow][currentActiveLine].deactivate();
				if (Farray[i][j].isHit(*mouseX, *mouseY)) {

					Farray[i][j].activate();

					currentActiveRow = i;
					currentActiveLine = j;
				}

				Farray[i][j].DrawFrame();
			}
		}
	}

	int getActiveRow() {

		return currentActiveRow;
	}

	int getActiveLine() {

		return currentActiveLine;
	}
};