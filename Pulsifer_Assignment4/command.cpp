#include <iostream>
#include "Robot.h"
#include "RobotList.h"

#include "command.h"

void command::run()
{
	//declare all the variables needed
	char command;
	char direction;
	bool running = true;
	bool moving = true;
	int arraySize;
	string robotIdentifier;
	//User enters the # of robots that they will name
	cout << "Please enter a size: " << endl;
	cin >> arraySize;
	//Create an array with the same size as the user entered

	RobotList robotList;
	//For each Robot in the array, the user enters a name. 
	cout << "Please enter " << arraySize << " names." << endl;
	for (int i = 0; i < arraySize; i++) {
		string robotName;
		cin >> robotName;
		robotList.addRobot(new Robot(robotName));
	}

	//While the user has not entered Q
	while (running) {
		//Display main Menu
		cout << "M - Move a Robot" << endl
			<< "D - Print all Robots and their distances" << endl
			<< "U - Update Robot List" << endl
			<< "R - Rename one Robot" << endl
			<< "Q - Quit the program" << endl;
		cin >> command;
		//Change command to upper case before comparing
		switch (toupper(command)) {
		case 'M':
		{
			//Find the Robot that the user wants to move
			cout << "You want to move a Robot! Which Robot would you like to move?" << endl;
			cin >> robotIdentifier;
			//set the index that is returned from findRobot to a variable
			Robot* robotToMove = robotList.findRobot(robotIdentifier);
			//If the robot is not found
			if (robotToMove == NULL) {
				cout << "Sorry! That Robot wasn't found. Please try again." << endl;
				break;
			}
			//If the robot is found
			else {
				//While the user wants to move display the movement options
				cout << "Great! We are moving the Robot " << robotIdentifier << endl;
				//Displaying the current pos for the target robot
				cout << robotToMove->getName() << "'s current position is "
					<< "(" << robotToMove->getCurrentX() << ","
					<< robotToMove->getCurrentY() << ")" << endl;
				//Menu for moving the robot
				cout << "Here are your options to move the Robot: " << endl
					<< "U - Move the Robot up" << endl
					<< "D - Move the Robot down" << endl
					<< "L - Move the Robot left" << endl
					<< "R - Move the Robot right" << endl
					<< "S - Stop the Robot or start Robot" << endl
					<< "Which command would you like to do?" << endl;
				cin >> direction;

				//Move robot with the direction provided by user
				robotToMove->moveRobot(direction);
				break;
			}
		}
		case 'D':
			//for each robot in the array, print the robot name and the distance it has traveled
			//Sort robotList first
			robotList.sortList();
			robotList.printList();
			break;
		case'U':
		{//Update the list option
			char command;
			cout << "You would like to update the Robot List! What would you like to do?" << endl
				<< "A - Add a Robot to the List" << endl
				<< "D - Delete a Robot that is in the list" << endl;
			cin >> command;
			command = toupper(command);
			//If A then add robot
			if (command == 'A') {
				string toAdd;
				cout << "You are adding a new Robot to the list! What would you like to name the new Robot?" << endl;
				cin >> toAdd;
				robotList.addRobot(new Robot(toAdd));
				cout << toAdd << " is now in the list." << endl;
			}
			//else if D then delete Robot
			else if (command == 'D') {
				string toDelete;
				cout << "Which Robot would you like to delete?" << endl;
				cin >> toDelete;
				Robot* robot = robotList.findRobot(toDelete);
				if (robot != NULL)
					robotList.deleteRobot(robot);
				cout << toDelete << " is now deleted." << endl;
			}
			//If neither, that wasn't an option
			else {
				cout << "Sorry, that wasn't an option. Please try again." << endl;

			}
			break;
		}
		case'R':
		{
			string robotToRename;
			string newName;
			//Rename the Robot
			cout << "You are renaming a Robot. Which Robot would you like to rename?" << endl;
			cin >> robotToRename;
			cout << "What is this Robot's new name?" << endl;
			cin >> newName;
			robotList.findRobot(robotToRename)->renameRobot(newName);
			break;
		}
		case 'Q':
			running = false;
			cout << "Thanks for playing, bye!" << endl;
			break;
		default:
			cout << "Sorry, that was an invalid command" << endl;
		}
	}
	//dtor for Robot List
	robotList.~RobotList();
}
