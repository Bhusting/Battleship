#include "AircraftCarrier.h"

using namespace std;

AircraftCarrier::AircraftCarrier(int position, int value) {
	if (position == 0) {
		setHitpoints(0, value);
		setHitpoints(1, value + 1);
		setHitpoints(2, value + 2);
		setHitpoints(3, value + 3);
		setHitpoints(4, value + 4);
	}
	else if (position == 1) {
		setHitpoints(0, value);
		setHitpoints(1, value + 25);
		setHitpoints(2, value + 50);
		setHitpoints(3, value + 75);
		setHitpoints(4, value + 100);
	}
}

const int AircraftCarrier::getHitpoints(int position) { return hitpoints[position]; }

void AircraftCarrier::setHitpoints(int position, int value) {

	hitpoints[position] = value;

}