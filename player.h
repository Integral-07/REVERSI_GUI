#pragma once
#include<string>
#include"setting.h"
#include "stone.h"
#include"font.h"

extern int Fonts[10];


class Players {

	class Player {

	private:

		std::string name = "";
		StoneColor stn = Black;

	public:

		Player() {

		}

		Player(std::string _name, StoneColor _stn) :name(_name), stn(_stn) {

		}

		bool operator==(Player& x) {

			if (this->stn == x.stn) {

				return true;
			}

			return false;
		}

		std::string getName() { return name; }

		StoneColor getStoneColor() { return stn; }
	};
private:

	Player* player;
	Player currentPlayer;

public:

	Players(std::string _name_player1, std::string _name_player2) {

		player = new Player[2];

		player[0] = Player(_name_player1, Black);
		player[1] = Player(_name_player2, White);

		currentPlayer = player[0];
	}

	void changePlayer() {

		if (currentPlayer == player[0]) {

			currentPlayer = player[1];
		}
		else {

			currentPlayer = player[0];
		}

		return;
	}

	void changePlayerScene() {

		int DrawWidth = GetDrawFormatStringWidth("%sのターン", currentPlayer.getName().c_str(), Fonts[0]);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawBox(0, GameHeight/3, GameWidth, GameHeight*2/3, GetColor(0, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		DrawFormatStringToHandle((GameWidth - DrawWidth) / 2 - 170, GameHeight / 2 - 50, GetColor(255, 255, 255), Fonts[0], "%sのターン", currentPlayer.getName().c_str());
		ScreenFlip();
		WaitTimer(1000);
	}

	StoneColor getConfStn() {

		if (currentPlayer.getStoneColor() == Black) {

			return White;
		}

		return Black;
	}

	std::string getCurrentPlayerName() {

		return currentPlayer.getName();
	}

	StoneColor getCurrentPlayerStoneColor() {

		return currentPlayer.getStoneColor();
	}
};