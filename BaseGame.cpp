#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <time.h>

#include "BaseGame.h"

using namespace std;


void BaseGame::NewGame() {
	//variable declarations
	int coinflip;							//Flips a coin to see who goes first
	int answer, answerr, answerc;			//holds the points the user chooses to place the ships
	int randnum, randnum2;					//This holds the computers random number choice which translates to where on the board the computer puts an O
	int value;								//holds the value of row and column added to make the position in the value of the board
	int numships = 0;						//holds the number of ships used
	BaseShip * n;

											//program logic

											//sets the seed
	srand(time(NULL));

	//sets the max equal to 625 which is how many points there are
	max = 625;

	//sets the value of all the points to tilda
	x = 0;
	while (x < 25) {
		y = 0;
		while (y < 25) {
			userboard[x][y] = '~';
			AIboard[x][y] = '~';
			y++;
		}
		x++;
	}

	x = 0;
	//gives the value arrays to a preset value
	while (x < 625) {
		userboardv[x] = 3;
		userboardran[x] = 3;
		AIboardv[x] = 1;
		x++;
	}

	//start the start of the game here

	//This allows the user to choose whether he wants the ships to be from left to right or up and down
	numships = 0;
	while (numships != 7) {
		cout << "Would you like to place your ship" << endl << "1. Left-Right" << endl << "2. Up-Down" << endl;
		cin >> answer;
		//saves the users choices for row and column inside a answerc for column and answerr for row
		if (answer == 1) {
			Board(numships);
			cout << "Please enter the left most point of the ship you want to place." << endl;
			cout << "Columns are down and Rows are across." << endl << endl;
			cout << "Enter the Column of the point you chose." << endl;
			cin >> answerc;
			cout << "Enter the Row of the point you chose" << endl;
			cin >> answerr;

			//This translates the users choice into a value for the int array
			value = answerc + answerr + answerr * 24;

			//saves the ships points inside num ships and updates the string array for the user to see and sets the values to 0. Puts the ship left to right
			if (answerr < 25 && answerc < 21 && userboardv[value] != 0 && userboardv[value + 1] != 0 && userboardv[value + 2] != 0 && userboardv[value + 3] != 0 && userboardv[value + 4] != 0) {
				userboard[answerr][answerc] = "<";
				userboard[answerr][answerc + 1] = "=";
				userboard[answerr][answerc + 2] = "=";
				userboard[answerr][answerc + 3] = "=";
				userboard[answerr][answerc + 4] = ">";

				userboardv[value] = 0;
				userboardv[value + 1] = 0;
				userboardv[value + 2] = 0;
				userboardv[value + 3] = 0;
				userboardv[value + 4] = 0;

				n = new AircraftCarrier(0, value);
				userShips[numships] = n;

				numships++;
				system("cls");
			}
			else {
				system("cls");
				cout << "Please enter a row lower than 21 and a column lower than 25. Also make sure that your ships do not cross each other." << endl;
			}
		}
		//saves the users choices for row and column inside a answerc for column and answerr for row
		else if (answer == 2) {
			Board(numships);
			cout << "Please enter the top most point of the ship you want to place" << endl;
			cout << "Columns are down and Rows are across." << endl << endl;
			cout << "Enter the Column of the point you chose." << endl;
			cin >> answerc;
			cout << "Enter the Row of the point you chose" << endl;
			cin >> answerr;

			//This translates the users choice into a value for the int array
			value = answerc + answerr + answerr * 24;

			//saves the ships points inside num ships and updates the string array for the user to see and sets the values to 0. Puts the ship up and down
			if (answerc < 25 && answerr < 21 && userboardv[value] != 0 && userboardv[value + 25] != 0 && userboardv[value + 50] != 0 && userboardv[value + 75] != 0 && userboardv[value + 100] != 0) {
				userboard[answerr][answerc] = "^";
				userboard[answerr + 1][answerc] = "O";
				userboard[answerr + 2][answerc] = "O";
				userboard[answerr + 3][answerc] = "O";
				userboard[answerr + 4][answerc] = "v";

				userboardv[value] = 0;
				userboardv[value + 25] = 0;
				userboardv[value + 50] = 0;
				userboardv[value + 75] = 0;
				userboardv[value + 100] = 0;

				n = new AircraftCarrier(1, value);
				userShips[numships] = n;

				numships++;
				system("cls");
			}
			else {
				system("cls");
				cout << "Please enter a column lower than 21 and a row lower than 25. Also make sure that your ships do not cross each other." << endl;
			}

		}
		else {
			cout << "Please enter a valid choice." << endl;
		}
	}

	//sets numships to 0 so that the PC can set 7 ships
	randnum2 = 22;
	numships = 0;
	while (numships != 7) {
		//This random number chooses whether the pc places its ships up and down or left and right
		randnum = rand() % 2 + 1;

		//this is one big if statement ;)
		//It basically checks to see if the random point chosen is a valid point to put a ship on
		if (randnum == 1) {
			if (!((randnum2 >= 19 && randnum2 <= 24) || (randnum2 >= 44 && randnum2 <= 49) || (randnum2 >= 69 && randnum2 <= 74) || (randnum2 >= 94 && randnum2 <= 99) || (randnum2 >= 119 && randnum2 <= 124) || (randnum2 >= 144 && randnum2 <= 149) || (randnum2 >= 169 && randnum2 <= 174) || (randnum2 >= 194 && randnum2 <= 199) || (randnum2 >= 219 && randnum2 <= 224) || (randnum2 >= 244 && randnum2 <= 249) || (randnum2 >= 269 && randnum2 <= 274) || (randnum2 >= 294 && randnum2 <= 299) || (randnum2 >= 419 && randnum2 <= 424) || (randnum2 >= 444 && randnum2 <= 449) || (randnum2 >= 469 && randnum2 <= 474) || (randnum2 >= 494 && randnum2 <= 499) || (randnum2 >= 519 && randnum2 <= 524) || (randnum2 >= 544 && randnum2 <= 549) || (randnum2 >= 569 && randnum2 <= 574) || (randnum2 >= 594 && randnum2 <= 599) || randnum2 >= 620)) {
				if (AIboardv[randnum2] != 0 && AIboardv[randnum2 + 1] != 0 && AIboardv[randnum2 + 2] != 0 && AIboardv[randnum2 + 3] != 0 && AIboardv[randnum2 + 4] != 0) {

					//puts the values to 0 which means it is a ship. This is left to right
					AIboardv[randnum2] = 0;
					AIboardv[randnum2 + 1] = 0;
					AIboardv[randnum2 + 2] = 0;
					AIboardv[randnum2 + 3] = 0;
					AIboardv[randnum2 + 4] = 0;

					n = new AircraftCarrier(0, randnum2);
					AIShips[numships] = n;

					numships++;
				}
			}
		}
		else {
			if (!(randnum2 >= 500)) {
				if (AIboardv[randnum2] != 0 && AIboardv[randnum2 + 25] != 0 && AIboardv[randnum2 + 50] != 0 && AIboardv[randnum2 + 75] != 0 && AIboardv[randnum2 + 100] != 0) {
					//puts the values to 0 which means it is a ship. This is up and down
					AIboardv[randnum2] = 0;
					AIboardv[randnum2 + 25] = 0;
					AIboardv[randnum2 + 50] = 0;
					AIboardv[randnum2 + 75] = 0;
					AIboardv[randnum2 + 100] = 0;

					n = new AircraftCarrier(1, randnum2);
					AIShips[numships] = n;

					numships++;
				}
			}
		}
		//chooses a random point for the PC to choose
		randnum2 = rand() % 625 + 1;

	}

	//
	x = 0;
	y = 0;

	//chooses who goes first and loops until the game is over. If it flips one the user goes first then the computer. If it flips 2 the computer goes first. Also checks to see if the game is over or saved
	coinflip = rand() % 2 + 1;
	system("cls");
	while (CheckforEnd() == false && CheckforSave() == false) {
		if (coinflip == 1) {
			Board(7);
			UserTurn();
			if (CheckforEnd() == false && CheckforSave() == false) {
				AITurn();
			}

		}
		else {
			Board(7);
			AITurn();
			if (CheckforEnd() == false && CheckforSave() == false) {
				UserTurn();
			}

		}
	}
}

void BaseGame::LoadGame() {
	//variable declarations
	ifstream InputF;			//This is the save file
	bool invalidSave = false;
	int inc = 0;				//random increment variable
	int value{ 0 };
	BaseShip *n;

	//program logic

	//opens the save file and tells the user it is loading
	InputF.open("save.dat");
	cout << "Loading";

	//this recalls the numbers from the save file and stores it in the variables
	if (InputF) {

		while (InputF) {
			if (inc <= 624) {
				InputF >> userboardv[inc];
			}
			else if (inc >= 625 && inc <= 1249) {
				if (inc == 625) {
					cout << ".";
					x = 0;
				}
				InputF >> AIboardv[x];
				x++;
			}
			else if (inc >= 1250 && inc <= 1874) {
				if (inc == 1250) {
					cout << ".";
					x = 0;
				}
				InputF >> userboardran[x];
				x++;
			}
			else if (inc >= 1875 && inc <= 1909) {
				if (inc == 1875) {
					cout << ".";
					x = 0;
					y = 0;
				}

				if (x == 0) {
					n = new AircraftCarrier();
					AIShips[y] = n;
				}

				InputF >> value;
				AIShips[y]->setHitpoints(x, value);

				x++;
				if (x == 5) {
					x = 0;
					y++;
				}
			}
			else if (inc >= 1910 && inc <= 1944) {
				if (inc == 1910) {
					cout << ".";
					x = 0;
					y = 0;
				}

				if (x == 0) {
					n = new AircraftCarrier();
					userShips[y] = n;
				}

				InputF >> value;
				userShips[y]->setHitpoints(x, value);

				x++;
				if (x == 5) {
					x = 0;
					y++;
				}
			}
			else if (inc == 1945) {
				cout << ".";
				InputF >> max;
			}
			inc += 1;
		}
	}
	else {
		//tells the user the file is not found
		cout << "\nFile Read Error. Returning to the main menu." << endl;
		system("pause");
		system("cls");
		invalidSave = true;
	}

	InputF.close();
	//loops until the end of the game or when it is saved. User always goes first
	if (invalidSave == false) {
		while (CheckforEnd() == false && CheckforSave() == false) {
			Board(7);
			UserTurn();
			if (CheckforEnd() == false && CheckforSave() == false) {
				AITurn();
			}
		}
	}
}

void BaseGame::UserTurn() {
	//variable declarations
	int value, column, row;			//This holds the column and row the user enters. value converts the column and row to the adjacent value in the array
	bool repeat = false;			//this tells the computer to repeat if the user enters an invalid row or column

									//program logic

									//asks the user to enter a point. If it is valid set the point to -1 or -2 based upon if it is a ship or water
	do {
		if (repeat == true) {
			cout << "Please choose a valid point that is not taken." << endl;
		}

		value = 0;
		cout << "Columns are down and Rows are across. Type S if you want to save" << endl << endl;
		cout << "Enter the Column of the point you chose." << endl;

		//checks to see if the user enter a character or a digit. If it is an s, call the save function
		cin >> charc;
		if (!isdigit(charc[0])) {
			if (CheckforSave() == true) {
				Save();
			}
			else {
				UserTurn();
			}
			break;
		}
		cout << "Enter the Row of the point you chose." << endl;
		cin >> charr;
		if (!isdigit(charr[0])) {
			if (CheckforSave() == true) {
				Save();
			}
			else {
				UserTurn();
			}
			break;
		}
		//if the user enters a number convert it
		value = 0;
		row = atoi(charr);
		column = atoi(charc);
		if (row <= 25 && column <= 25) {
			value = row + column + (row * 24);

			// checks to see if the user chose a point that is taken or not valid
			if (AIboardv[value] == -1 || AIboardv[value] == -2 || row >= 25 || column >= 25) {
				repeat = true;
			}
			else {
				repeat = false;
			}
		}
	} while (repeat == true);

	//changes the value in the array and checks to see if it has ended
	if (save == false) {
		if (AIboardv[value] == 1) {
			AIboardv[value] = -1;
		}
		else if (AIboardv[value] == 0) {
			AIboardv[value] = -2;
		}
		if (CheckforEnd() == true) {
			End();
		}

	}
}

void BaseGame::AITurn() {
	//program logic

	//checks to see if the PC hit a point
	if (shiphit == false) {
		int randnum;					//This holds the computers random number choice which translates to where on the board the computer puts an O
										//sets a random seed
		srand(time(NULL));
		y = 1;
		//chooses a number between max and 1
		if (max > 0) {
			randnum = rand() % max + 1;
		}

		x = 0;

		//This is the core of the program. I am very proud of this. It counts up in each array unless it sees a value that is not positive and is taken. 
		while (x != 625) {
			if (userboardv[x] >= 0) {
				userboardran[x] = y;
				y += 1;
				x += 1;
			}
			else {
				x += 1;
			}
		}

		x = 0;

		//sets the value of the point to its equivalent value if it is a ship or water and sets shiphit to true so that the pc can destoy the rest of the ship
		while (randnum != userboardran[x]) {
			x++;
		}
		if (userboardv[x] == 0) {
			userboardran[x] = -1;
			userboardv[x] = -2;
			ship = x;
			shiphit = true;
		}
		else if (userboardv[x] >= 1) {
			userboardran[x] = -1;
			userboardv[x] = -1;
		}

		//sets subtracts a point from max and checks for the end
		max -= 1;
		if (CheckforEnd() == true) {
			End();
		}
	}
	else {
		//calls hit if the PC hit a point previously
		Hit();

	}
}

void BaseGame::Hit() {
	//variable declarations
	int inc = 0, inc2 = 0;
	bool exit = false;

	//program logic

	//this increments through the ship to finally sink it
	//every one of the pc's turns will be used to sink it
	while (inc2 != 7 && shiphit == true && exit == false) {
		inc = 0;
		while (inc != 4 && shiphit == true && exit == false) {
			if (userShips[inc2]->getHitpoints(inc) == ship) {

				if (userboardv[userShips[inc2]->getHitpoints(0)] != -2) {
					userboardv[userShips[inc2]->getHitpoints(0)] = -2;
					exit = true;
					break;
				}
				else if (userboardv[userShips[inc2]->getHitpoints(1)] != -2) {
					userboardv[userShips[inc2]->getHitpoints(1)] = -2;
					exit = true;
					break;
				}
				else if (userboardv[userShips[inc2]->getHitpoints(2)] != -2) {
					userboardv[userShips[inc2]->getHitpoints(2)] = -2;
					exit = true;
					break;
				}
				else if (userboardv[userShips[inc2]->getHitpoints(3)] != -2) {
					userboardv[userShips[inc2]->getHitpoints(3)] = -2;
					exit = true;
					break;
				}
				else {
					userboardv[userShips[inc2]->getHitpoints(4)] = -2;
					exit = true;
					userShips[inc2]->setState(true);
					shiphit = false;
					break;
				}
			}
			else {
				inc++;
			}
		}
		inc2++;
	}
}

bool BaseGame::CheckforSave() {
	//program logic

	//checks to see if the user enters an s
	if (charc[0] == 'S' || charc[0] == 's' || charr[0] == 'S' || charr[0] == 's') {
		return true;
	}
	else {
		return false;
	}

}

void BaseGame::Save() {
	//variable declarations
	ofstream saveFile;

	//program logic
	saveFile.open("save.dat");

	save = true;

	//saves all of the arrays' data and max inside the the output file
	x = 0;
	while (x != 625) {
		saveFile << userboardv[x] << " ";
		x++;
	}

	x = 0;
	while (x != 625) {
		saveFile << AIboardv[x] << " ";
		x++;
	}

	x = 0;
	while (x != 625) {
		saveFile << userboardran[x] << " ";
		x++;
	}

	x = 0;
	while (x != 7) {
		y = 0;
		while (y != 5) {
			saveFile << AIShips[x]->getHitpoints(y) << " ";
			y++;
		}
		x++;
	}

	x = 0;
	while (x != 7) {
		y = 0;
		while (y != 5) {
			saveFile << userShips[x]->getHitpoints(y) << " ";
			y++;
		}
		x++;
	}

	saveFile << max << " ";
	save = true;
	saveFile.close();
	End();
}

bool BaseGame::CheckforEnd() {
	//variable declarations
	int w{ 0 }, z{ 0 };

	//program logic
	x = 0;
	y = 0;

	//checks to see if all the ship points for the user or the PC are hit
	while (x != 7) {
		y = 0;
		while (y != 5) {
			if (userboardv[userShips[x]->getHitpoints(y)] == 0) {
				y++;
			}
			else if (userboardv[userShips[x]->getHitpoints(y)] == -2) {
				y++;
				w++;
			}
		}
		x++;
	}

	x = 0;
	y = 0;

	while (x != 7) {
		y = 0;
		while (y != 5) {
			if (AIboardv[AIShips[x]->getHitpoints(y)] == 0) {
				y++;
			}
			else if (AIboardv[AIShips[x]->getHitpoints(y)] == -2) {
				y++;
				z++;
			}
		}
		x++;
	}

	//if the user hits all of the AIships exits to the End function. Also does this if the pc hits all of the users ships. If not it exits
	if (w != 35 && z != 35) {
		return false;
	}
	else {
		if (x == 35) {
			win = true;
			return true;
		}
		else if (y == 35) {
			loss = true;
			return true;
		}
	}
}

void BaseGame::End() {
	// program logic
	//tells the user if he won, lost, or saved
	if (win == true) {
		cout << "Congratulations! You won!" << endl;
		system("pause");
	}
	else if (loss == true) {
		cout << "Too Bad! You lost!" << endl;
		system("pause");
	}
	else if (save == true) {
		cout << "Your game has been saved." << endl;
		system("pause");
	}

	delete[] userShips, AIShips;
}

//I would not open this if i were you. xD
void BaseGame::Board(int numShips) {

	//variable declarations
	int incr = 0;

	//program logic
	x = 0;

	system("cls");

	//updates the board based upon its value. W if the pc or user hits the water, H if they hit a ship, and ~ if it is water.
	//Also updates what the ships look like based upon its position and where it is
	while (x < 25) {
		y = 0;

		while (y < 25) {
			if (userboardv[incr] == -1) {
				userboard[x][y] = "W";
			}
			else if (userboardv[incr] == -2) {
				userboard[x][y] = "H";
			}
			else if (userboardv[incr] == 3) {
				userboard[x][y] = "~";
			}
			else if (userboardv[incr] == 0) {
				//
				for (int ship{ 0 }; ship < numShips; ship++) {
					if (incr == userShips[ship]->getHitpoints(0)) {
						if (userShips[ship]->getHitpoints(1) == userShips[ship]->getHitpoints(0) + 1) {
							userboard[x][y] = "<";
						}
						else {
							userboard[x][y] = "^";
						}
					}
					else if (incr == userShips[ship]->getHitpoints(1)) {
						if (userShips[ship]->getHitpoints(1) == userShips[ship]->getHitpoints(0) + 1) {
							userboard[x][y] = "=";
						}
						else {
							userboard[x][y] = "O";
						}
					}
					else if (incr == userShips[ship]->getHitpoints(2)) {
						if (userShips[ship]->getHitpoints(1) == userShips[ship]->getHitpoints(0) + 1) {
							userboard[x][y] = "=";
						}
						else {
							userboard[x][y] = "O";
						}
					}
					else if (incr == userShips[ship]->getHitpoints(3)) {
						if (userShips[ship]->getHitpoints(1) == userShips[ship]->getHitpoints(0) + 1) {
							userboard[x][y] = "=";
						}
						else {
							userboard[x][y] = "O";
						}
					}
					else if (incr == userShips[ship]->getHitpoints(4)) {
						if (userShips[ship]->getHitpoints(1) == userShips[ship]->getHitpoints(0) + 1) {
							userboard[x][y] = ">";
						}
						else {
							userboard[x][y] = "v";
						}
					}
				}
			}


			incr += 1;
			y += 1;
		}
		x += 1;
	}

	x = 0;
	incr = 0;

	while (x < 25) {
		y = 0;

		while (y < 25) {
			if (AIboardv[incr] == -1) {
				AIboard[x][y] = "W";
			}
			else if (AIboardv[incr] == -2) {
				AIboard[x][y] = "H";
			}
			else if (AIboardv[incr] == 1 || AIboardv[incr] == 0) {
				AIboard[x][y] = "~";
			}

			incr += 1;
			y += 1;
		}
		x += 1;
	}

	//This displays the board for the user to see.
	cout << "                                              Your Board:                                                                                                Computers Board                     " << endl;

	x = 0;
	cout << "    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24     ";
	cout << "    0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24" << endl;
	while (x < 25) {
		y = 0;
		cout << " " << x << " ";

		if (x < 10) {
			cout << " ";
		}

		while (y < 25) {
			cout << userboard[x][y];
			cout << " | ";
			y++;

		}

		y = 0;
		cout << "   ";
		cout << " " << x << " ";
		while (y < 25) {

			cout << AIboard[x][y];
			cout << " | ";
			y++;

		}
		cout << endl;
		cout << "    ----------------------------------------------------------------------------------------------------      ";
		cout << "----------------------------------------------------------------------------------------------------" << endl;
		x++;
	}
}