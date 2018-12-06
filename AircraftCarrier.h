#pragma once

#include "BaseShip.h"

class AircraftCarrier : public BaseShip {

public:

	//constructor
	AircraftCarrier(int = 2, int = 2);
	const int getHitpoints(int);				//gets the hitpoints
	void setHitpoints(int, int);		//sets the hitpoints

private:

	//holds the points the ship is at
	int hitpoints[5];

};