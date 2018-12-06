#ifndef LAB9HEADER_H
#define LAB9HEADER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h>

#include "BaseShip.h"
#include "AircraftCarrier.h"

using namespace std;

class BaseGame {

	public:

		void NewGame();					//This function starts a new game for the user, this includes the user and the PC choosing where they want to put their ships
		void LoadGame();				//Loads a presaved game
		void Board(int);					//This updates and displays the board for the user
		void UserTurn();				//This is where the user chooses a point to shoot at
		void AITurn();					//This is where the PC chooses a point to shoot at
		void Hit();						//When the AI shoots one of your ships the PC will then shoot until it destroys your ship
		bool CheckforEnd();				//Does a check for the end of the game
		bool CheckforSave();			//Does a check to see if the user wants to save and exit
		void Save();					//Saves the game for later
		void End();						//checks to see if you save, won, or lost


	private:
		char charc[3];					//This is the number the user enters for the column
		char charr[3];					//This is the number the user enters for the row		
		int max;						//This is the max amount of points the PC can pick
		int ship;						//This stores the first point the PC hits one of your ships
		bool finish = false;			//finish is true when it is the end
		bool win = false;				//Is true when you sink all of the AI ships
		bool loss = false;				//Is true when the PC sinks all your ships
		bool save = false;				//Is true when the user wants to save
		bool shiphit = false;			//Is true when the PC hits one of your ships
		int x = 0, y = 0;				//These are random variables to increment your arrays

		string userboard[25][25];		//This displays the user's board for the user to see
		int userboardran[625];			//this holds every available point for the pc to pick
		int userboardv[625];			//This holds whether your point is a ship, water, or previously shot at
		BaseShip ** userShips = new BaseShip*[7];
		
		string AIboard[25][25];			//This displays the AI's board for the user to see
		int AIboardv[625];				//This holds whether the pc's point is a ship, water, or previously shot at
		BaseShip ** AIShips = new BaseShip*[7];
		
};
#endif