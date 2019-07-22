/*
 * Level.cpp
 */
// Abdullah Siddique CS 2336.001
#include "ParkingStructure.h"
#include "Level.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Level::Level() {
	for (int i = 0; i < this->totalSpots; i++) {
		char x = ' ';
		this->level.push_back(x); // creates the default char vector
	}
	this->createLevelStructure(); //formats itself
}
Level::~Level(){}
void Level::setLevelParameters(int total, int row, int l_spots, int m_spots) {
		this->level.clear(); //clears anything that is in the vector before hand in case
		this->totalSpots = total; //setting parameters
		this->rowSpots = row;
		this->largeSpots = l_spots;
		this->motorSpots = m_spots;
		this->compactSpots = this->totalSpots - (this->largeSpots + this->motorSpots);
		for (int i = 0; i < total; i++) {this->level.push_back(' ');} //intializing the vector
		this->createLevelStructure();//formatting
}
void Level::createLevelStructure() {
		int x = static_cast<int>(this->level.size());
		for (int i = 0; i < x; i++) { //depending on how many large/compace/motor spots there are it will set the char vector to lowercase letters
			if (i < this->largeSpots) {
				this->level[i] = 'l';
			} else if (i < this->largeSpots + this->compactSpots) {
				this->level[i] = 'c';
			} else {
				this->level[i] = 'm';
			}
		}
}
bool Level::roomLeft(char choice) { //will check to see if there is room left in the char vector to store the choice of the user B/C/M
		int j = 0;
		if (choice == 'B') {
			for (int i = 0; i < this->largeSpots; i++) {
				if (this->level[i] == 'l') j++;
				if (j == 5) return true;
			} return false;
		} else if (choice == 'C') {
			for (int i = 0; i < this->compactSpots + this->largeSpots; i++) {
				if (this->level[i] == 'l' || this->level[i] == 'c') j++;
				if (j == 1) return true;
			} return false;
		} else if (choice == 'M') {
			for (int i = 0; i <= this->totalSpots; i++) {
				if (this->level[i] == 'l' || this->level[i] == 'c' || this->level[i] == 'm') {
					j++;
				}
				if (j == 1) return true;
			} return false;
		} return false;
}

bool Level::doesExist(char choice) {
		if (choice == 'B') {
			return find(this->level.begin(), this->level.end(), 'B') != this->level.end(); // will use the algorithm library to determine if the choice exists in the vector
		} else if (choice == 'C') {
			return find(this->level.begin(), this->level.end(), 'C') != this->level.end();
		} else if (choice == 'M') {
			return find(this->level.begin(), this->level.end(), 'M') != this->level.end();
		}
		return false;
}
void Level::add(char choice) {// will check each spot depending on what the user enters to add the given choice
		int j = 0;
		if (choice == 'B') {
			for (int i = 0; i < this->largeSpots; i++) {
				if (this->level[i] == 'l') { //notice each has their own logical precedance
					this->level[i] = 'B'; j++;
				}
				if (j == 5) break;
			}
		} else if (choice == 'C') {
			for (int i = 0; i < this->compactSpots + this->largeSpots; i++) {
				if (this->level[i] == 'l' || this->level[i] == 'c') {
					this->level[i] = 'C'; j++;
				}
				if (j == 1) break;
			}
		} else if (choice == 'M') {
			for (int i = 0; i <= this->totalSpots; i++) {
				if (this->level[i] == 'l' || this->level[i] == 'c' || this->level[i] == 'm') {
					this->level[i] = 'M'; j++;
				}
				if (j == 1) break;
			}
		} else cout << "Invalid Input\n"; //tell user they have invalid input
}

void Level::remove(char choice) { //works like the add method by removing only if possible and according to a precedent structure
		if (choice == 'B') {
			for (int i = 0, j = 0; i < this->largeSpots; i++) {
				if (this->level[i] == 'B') {
					this->level[i] = 'l';
					j++;
				}
				if (j == 5) break;
			}
		} else if (choice == 'C') {
			if (count(this->level.begin(), this->level.begin() + this->largeSpots, 'C')) {
				for (int i = 0, j = 0; i < this->largeSpots; i++) {
					if (this->level[i] == 'C') {
						this->level[i] = 'l';
						j++;
					}
					if (j == 1) break;
				}
			} else {
				for (int i = this->largeSpots, j = 0; i < this->largeSpots + this->compactSpots; i++) {
					if (this->level[i] == 'C') {
						this->level[i] = 'c';
						j++;
					}
					if (j == 1) break;
				}
			}
		} else if (choice == 'M') {
			if (count(this->level.begin(), this->level.begin() + this->largeSpots, 'M')) {
				for (int i = 0, j = 0; i < this->largeSpots; i++) {
					if (this->level[i] == 'M') {
						this->level[i] = 'l';
						j++;
					}
					if (j == 1) break;
				}
			} else if (count(this->level.begin() + this->largeSpots, this->level.end() - this->motorSpots, 'M')) {
				for (int i = this->largeSpots, j = 0; i < this->largeSpots + this->compactSpots; i++) {
					if (this->level[i] == 'M') {
						this->level[i] = 'c';
						j++;
					}
					if (j == 1) break;
				}
			} else {
				for (int i = this->largeSpots + this->compactSpots, j = 0; i < this->totalSpots; i++) {
					if (this->level[i] == 'M') {
						this->level[i] = 'm';
						j++;
					}
					if (j == 1) break;
				}
			}
		}
}

bool Level::isFull(char choice) {
		int l_spaces = count(this->level.begin(), this->level.end(), 'l'); //uses algorithm library to determine if the vector no longer has space of the user choice
		int c_spaces = count(this->level.begin(), this->level.end(), 'c');
		int m_spaces = count(this->level.begin(), this->level.end(), 'm');
		if (choice == 'B') {
			if (l_spaces < 5) return true;
		} else if (choice == 'C') {
			if (c_spaces == 0 && l_spaces == 0) return true;
		} else if (choice == 'M') {
			if (c_spaces == 0 && l_spaces == 0 && m_spaces == 0) return true;
		} else return false;
			return false;
}
void Level::print() { // will print the vector out including the whitespaces that are needed
		for (unsigned int i = 0, j = this->rowSpots; i < this->level.size(); i++) {
			if (j == i) { cout << " "; j += rowSpots; }
			cout << this->level[i];
		}
}






