#pragma once

#include <iostream>

class BaseShip {

public:

	BaseShip();									//constructor
	~BaseShip();								//destructor
	bool getState();							//returns the state
	void setState(bool);						//sets the state
	virtual const int getHitpoints(int);				//gets the hitpoint (virtual)
	virtual void setHitpoints(int, int);		//sets the hitpoints (virtual)

	//overloads the >> operator
	friend std::istream& operator>>(std::istream&, BaseShip&);

private:

	bool sunk;

};