#ifndef PARKINGSTRUCTURE_H_
#define PARKINGSTRUCTURE_H_
/*
 * In this header file we are declaring our Parking Structure class and declaring its private and public methods
 */
// Abdullah Siddique CS 2336.001
#include "Level.h"
#include <string>
#include <vector>
using namespace std;


class ParkingStructure { //purpose of this class is to store level objects and manipulate them all as a single unit
	private:
		int NUM_OF_LEVELS = 5; //keep track of user info or use default parameters
		int SPOTS_PER_LEVEL = 30;
		int SPOTS_PER_ROW = 10;
		vector<Level> levels; // will store objects of levels (composition)
	public:
		ParkingStructure();
		ParkingStructure(int, int, int, double, double); //overloaded constructor for custom cases
		~ParkingStructure();
		void addVehicle(char); //add method
		void removeVehicle (char); //remove method
		bool isFull(char); // will check if levels are full to terminate program
		bool isAvailable(char); // will look to see if there is available space
		int size(); // returns size
		void print(); // calls the print method of the Level class

};

#endif /* PARKINGSTRUCTURE_H_ */
