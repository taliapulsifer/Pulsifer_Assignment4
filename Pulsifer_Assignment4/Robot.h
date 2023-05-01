#pragma once
#include <string>
class Robot
{
private:
	std::string name;
	int currentX;
	int currentY;
	int distanceTraveled;
	int currentSpeed;
	char lastCommand;
	bool isStopped;
public:
	Robot(std::string name) {
		this->name = name;
		currentX = 0;
		currentY = 0;
		currentSpeed = 0;
		distanceTraveled = 0;
		lastCommand = 'Z';
		isStopped = false;
	}
	std::string getName() {
		return name;
	}
	int getDistance() {
		return distanceTraveled;
	}
	int getCurrentX() {
		return currentX;
	}
	int getCurrentY() {
		return currentY;
	}
	bool isMoving() {
		return !isStopped;
	}
	void moveRobot(char direction);
	void renameRobot(std::string newName);
};

