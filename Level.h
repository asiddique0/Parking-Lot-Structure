#ifndef LEVEL_H_
#define LEVEL_H_
/*
 * In this header file we are declaring our Level class and declaring its private and public methods
 */
// Abdullah Siddique CS 2336.001
#include <string>
#include <vector>
using namespace std;

class Level { //purpose of this class is store and manipulate characters depending on what the user wants
	private:
		int totalSpots = 30; // initial values that the class will begin with
		int rowSpots = 10;
		int largeSpots = 6;
		int motorSpots = 6;
		int compactSpots = 18;
		vector<char> level; // this will store the characters that will be manipulated
	public:
		Level();
		~Level();
		void setLevelParameters(int, int, int, int); // this will be called when the user decides for a custom case
		void createLevelStructure(); // this will craft a level structure for the character array
		bool roomLeft(char); // will see if there is any room left in the vector char
		bool doesExist(char); // will see if there exists the element we are looking for depending on the choice
		void add(char); //add method
		void remove(char); // remove method
		bool isFull(char); // checks to see if char vector has any space left for addition
		void print(); //vector char print method

};




#endif /* LEVEL_H_ */
