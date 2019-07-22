/*
 * ParkingStructureDriver.cpp
 */
/*This is the driver part of the program that will handle all the interaction with user through
 * the classes in the backend.*/
// Abdullah Siddique CS 2336.001
#include "ParkingStructure.h"
#include "Level.h"

#include <climits>
#include <unistd.h>
#include <iostream>
using namespace std;

int main() {
		int NUM_OF_LEVELS, SPOTS_PER_LEVEL, SPOTS_PER_ROW;
		double LARGE_PERCENT, MOTOR_PERCENT;
		char choice, initialChoice; //variables needed to process info
		//these strings help make the program look cleaner
		const string message1 = "Park Bus(B), Car(C), or Motorcycle(M)? T to terminate, and R to remove.\n";
		const string message2 = "Parking Failed. Final state:\n";
		const string message3 = "Please enter which vehicle you would like to remove. Bus(B), Car(C), Motorcycle(M)\n";
		const string message4 = "Final State Upon Termination:\n";
		const string message5 = "Please enter the number of levels, spots available per level, spots per row, percent of large spots, percent of motorcycle spots (both decimal) in that order:\n";
		cout << "Would you like to enter the Parking Structure information manually? Yes(Y/y), or No(any other character)\n";
		cin >> initialChoice; // get user choice
		if (initialChoice == 'Y' || initialChoice == 'y') { //custom case
			cout << message5;
			cin >> NUM_OF_LEVELS >> SPOTS_PER_LEVEL >> SPOTS_PER_ROW >> LARGE_PERCENT >> MOTOR_PERCENT;
			if (cin.fail()) { // if the user enters invalid information then ask for it again
				while(cin.fail()) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Please enter only numbers!\n";
					cout << message5;
					cin >> NUM_OF_LEVELS >> SPOTS_PER_LEVEL >> SPOTS_PER_ROW >> LARGE_PERCENT >> MOTOR_PERCENT;
				}
			}
			ParkingStructure ps(NUM_OF_LEVELS, SPOTS_PER_LEVEL, SPOTS_PER_ROW, LARGE_PERCENT, MOTOR_PERCENT); //custom constructor
			ps.print();
			cout << message1;
			while (cin >> choice) { //begin loop for what the user wants to do the the parking structure
				if (choice == 'T' || choice == 't') {
					cout << message4;
					break;
				}
				if (choice == 'R' || choice == 'r') {
					char c;
					cout << message3;
					cin >> c;
					if (ps.isAvailable(c)) {
						ps.removeVehicle(c);
					} else {
						cout << "Vehicle doesn't exist!\n";
					}
					ps.print();
					cout << message1;
					continue;
				}
				if (ps.isFull(choice)){
					cout << message2; break;
				}
				ps.addVehicle(choice);
				ps.print();
				cout << message1;
			}
			ps.print();
		} else {
			ParkingStructure ps; //default constructor
			ps.print();
			cout << message1;
			while (cin >> choice) { //begin loop for what the user wants to do the the parking structure
				if (choice == 'T' || choice == 't') {
					cout << message4;
					break;
				}
				if (choice == 'R' || choice == 'r') {
					char c;
					cout << message3;
					cin >> c;
					if (ps.isAvailable(c)) {
						ps.removeVehicle(c);
					} else {
						cout << "Vehicle doesn't exist!\n";
					}
					ps.print();
					cout << message1;
					continue;
				}
				if (ps.isFull(choice)){
					cout <<message2; break;
				}
				ps.addVehicle(choice);
				ps.print();
				cout << message1;
			}
			ps.print();
			sleep(3); // let the user see the final output before exiting
		}



	return 0;
}


