#pragma once
#include <iostream>

class Robot;

using namespace std;

class RobotList
{
private:
	class Node {
	public:
		Robot* value;
		Node* nextNode = NULL;
		Node(Robot* robot);
		~Node();
	};
	Node* head;
	int count;
public:
	RobotList();
	~RobotList();
	Robot* findRobot(string target);
	void addRobot(Robot* robot);
	void deleteRobot(Robot* robot);
	void printList();
	void sortList();
	bool isEmpty();

private:
	static void addNode(Node** head, Node* newNode);

};

