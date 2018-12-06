#include <iostream>
#include "BaseShip.h"

using namespace std;

BaseShip::BaseShip() {
	//sets sunk to false when a new ship is created
	sunk = false;
}

//gets the state
bool BaseShip::getState() {return sunk;}
void BaseShip::setState(bool state) {sunk = state;}			//sets the state

//virtual returns the hitpoint
const int BaseShip::getHitpoints(int value) { return 0;}
//virtual sets the hitpoint
void BaseShip::setHitpoints(int position, int value){}

//overloads the >> operator
std::istream& operator>>(std::istream& input, BaseShip& ship) {
	int points[5];		//saves the hitpoints
	
		//loops untill all the hitpoints are entered
		for (int x{ 0 }; x < 5; x++) {
			//saves the number inside the array and saves it inside hitpoints
			input >> points[x];
			ship.setHitpoints(x, points[x]);

		}
	//returns the input                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
	return input;
}

BaseShip::~BaseShip() {
	//destructor
}