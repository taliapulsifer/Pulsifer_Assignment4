#include "Robot.h"
#include "RobotList.h"
#include <ostream>
#include <algorithm>
#include <cctype>
using namespace std;

void Robot::moveRobot(char direction)
{
	//If this command is the same as the last command, speed increases
	direction = toupper(direction);
	char directions[] = { 'U', 'D', 'L', 'R', 'S' };
	char* directionsEnd = directions + sizeof(directions);
	//See if the direction is in the options
	if (directionsEnd == find(directions, directionsEnd, direction)) {
		cout << "Sorry, that was an invalid direction. Please try again" << endl;
		return;
	}

	if (direction == 'S')
	{
		if (isStopped == false) {
			currentSpeed = 1;
			cout << name << " is now stopped." << endl;

		}
		else
		{
			cout << name << " has started." << endl;
		}
		isStopped = !isStopped;
		lastCommand = direction;
		return;
	}

	if (isStopped == true)
	{
		cout << name << " cannot move while stopped." << endl;
		return;
	}

	if (direction == lastCommand) {
		if (currentSpeed < 4) {
			currentSpeed += 1;
		}
	}
	else {
		currentSpeed = 1;
	}

	switch (toupper(direction)) {
		//Check the command and move accordingly
	case 'U':
		currentY += currentSpeed;
		break;
	case 'D':
		currentY -= currentSpeed;
		break;
	case 'L':
		currentX -= currentSpeed;
		break;
	case 'R':
		currentX += currentSpeed;
		break;
	}

	//Update the distance traveled based on speed
	distanceTraveled += currentSpeed;
	//update lastcommand for the robot unless it was an invalid command!!!
	lastCommand = direction;
	//Print Robot's location (X, Y)
	cout << getName() << "'s current position is: " << "(" << getCurrentX() << "," << getCurrentY() << ")" << endl;
	return;
}

void Robot::renameRobot(string newName)
{
	name = newName;
}
	
