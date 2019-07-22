/*
 * ParkingStructure.cpp
 */
// Abdullah Siddique CS 2336.001
#include "ParkingStructure.h"
#include "Level.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ParkingStructure::ParkingStructure() {
	for (int i = 0; i < this->NUM_OF_LEVELS; i++) {
		const Level level; //creates a vector of objects
		this->levels.push_back(level);
	}
}
ParkingStructure::~ParkingStructure() {}
ParkingStructure::ParkingStructure(int numofLevels, int spots_per_lvl, int spots_per_row, double percentL, double percentM) {
		this->NUM_OF_LEVELS = numofLevels;
		this->SPOTS_PER_LEVEL = spots_per_lvl;
		this->SPOTS_PER_ROW = spots_per_row;
		for (int i = 0; i < this->NUM_OF_LEVELS; i++) {
			Level level; // will also create a vector of objects
			this->levels.push_back(level);
		}
		for (unsigned int i = 0; i < levels.size(); i++) { // will set each of the parameters of each object to the users choice
			this->levels[i].setLevelParameters(spots_per_lvl, spots_per_row, spots_per_lvl*percentL, spots_per_lvl*percentM);
		}
}

void ParkingStructure::addVehicle(char choice) {
		int x = static_cast<int>(this->levels.size());
		for (int i = 0; i < x; i++) {
			if (this->levels[i].roomLeft(choice)) { //check to see if there is room left before adding
				this->levels[i].add(choice);//if so add it
				break;
			}
			}
}
void ParkingStructure::removeVehicle (char choice) {
		int x = static_cast<int>(this->levels.size());
		for (int i = 0; i < x; i++) {
			if (this->levels[i].doesExist(choice)) { // similar case to the add method
				this->levels[i].remove(choice);// remove
				break;
			}
		}
}
bool ParkingStructure::isFull(char choice) {
		return this->levels[this->NUM_OF_LEVELS-1].isFull(choice); // returns the bool value if the last object in the vector is full
}
bool ParkingStructure::isAvailable(char choice) {
	for (unsigned int i = 0; i < this->levels.size(); i++) {
		if (this->levels[i].doesExist(choice)) { // will check to see if we can remove a vehicle from the overall parking structure
			return true;
		}
	}

	return false;
}
int ParkingStructure::size() { // returns the size of the parking structure
		return this->levels.size();
}

void ParkingStructure::print() {
		for (unsigned int i = 0; i < this->levels.size(); i++) {
			cout << "Level" << i << ":  ";
			this->levels[i].print(); // calls the print method of each object in the vector
			cout << endl;
		}
}
