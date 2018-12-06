// BattleshipDriver.cpp -- This is a fully functioning battleship game
//CSIS 112-03
//ATOI and IsDigit was taught by the professor. I also learned random number from my udemy course over the winter. All the rest was self made by me and only me.

#include "BaseGame.h"
#include "Template.h"

using namespace std;

//ships are 0, water is 1, hit ship is -2, hit water is -1

int main() {
	//In cout statement below substitute your name and lab number
	cout << "Brian Husting -- Lab 8" << endl << endl;
	//I have read and understand the lab submittal policy

	//Variable declarations
	BaseGame Game;			//calls the variables and BaseGame from the header
	string answer;			//holds what choice the user wants
	Compare<int> max;

	//Program logic

	// asks the user what options he would like to choose
	cout << "Would you like a:" << endl << "1. New Game" << endl << "2. Load Game" << endl << "3. Exit" << endl << "4. Template" << endl;
	cin >> answer;
	
	if (answer == "1") {
		//calls the NewGame function
		system("cls");
		Game.NewGame();
	}
	else if (answer == "2") {
		//calls the LoadGame function
		system("cls");
		Game.LoadGame();
		main();
	}
	else if (answer == "4") {
		//tries to compare two integers, if one of the things to compared is not an integer, throw an exception
		try {
			cout << max.compare(5, 0) << " is bigger" << endl;
			system("pause");
			system("cls");
		}
		catch (...) {
			cout << "Please enter a valid number" << endl;
		}
	}
	else if (answer == "3"){
		//quits the game
		system("cls");
	}
	else {
		//loops to the top of the function if the user does not choose a valid choice
		system("cls");
		cout << "Please choose option 1, 2, or 3." << endl;
		main();
	}

	//Closing program statements
	return 0;
}
