#include "RobotList.h"
#include "Robot.h"

//ctor
RobotList::RobotList()
{
	head = NULL;
	count = 0;
}

//dtor
RobotList::~RobotList()
{
	while (head != NULL)
	{
		Node* oldhead = head;
		head = head->nextNode;
		delete oldhead;
	}
}

Robot* RobotList::findRobot(string target)
{
	Node* trav = head;
	while (trav != NULL)
	{
		if (trav->value->getName() == target)
		{
			return trav->value;
		}
		trav = trav->nextNode;
	}
	cout << "Sorry, that robot wasn't found" << endl;
	return NULL;
}



void RobotList::printList()
{
	Node* trav = head;
	while (trav != NULL)
	{
		cout << trav->value->getName() << " - "<< trav->value->getDistance() << endl;
		trav = trav->nextNode;
	}
}

//Sort the list of Robots
void RobotList::sortList()
{
	if (head == NULL || head->nextNode == NULL)
	{
		return;
	}

	Node* newList = head;
	head = head->nextNode;
	newList->nextNode = NULL;

	Node* current = head;
	while (current != NULL)
	{
		Node* temp = current;
		current = current->nextNode;
		temp->nextNode = nullptr;

		addNode(&newList, temp);
	}

	head = newList;
}

//Add Robot in sorted order
void RobotList::addRobot(Robot* robot)
{
	Node* newNode = new Node(robot);
	addNode(&head, newNode);
	count++;
}


bool RobotList::isEmpty()
{
	return head == NULL;
}

void RobotList::addNode(Node** headPtr, Node* newNode)
{
	Node* head = *headPtr;
	if (head == NULL || head->value->getDistance() <= newNode->value->getDistance())
	{
		newNode->nextNode = head;
		*headPtr = newNode;
		return;
	}

	Node* current = head;
	while (current->nextNode != NULL
		&& current->nextNode->value->getDistance() < newNode->value->getDistance())
	{
		current = current->nextNode;
	}

	newNode->nextNode = current->nextNode;
	current->nextNode = newNode;
}

RobotList::Node::Node(Robot* robot)
	: value(robot)
{
}

//Node dtor
RobotList::Node::~Node()
{
	delete value;
}

//delete a single Robot
void RobotList::deleteRobot(Robot* robot)
{
	Node* current = head;
	Node* previous = NULL;
	while (current != NULL)
	{
		if (current->value == robot)
		{
			if (head == current)
			{
				head = head->nextNode;
			}
			if (previous != NULL)
			{
				previous->nextNode = current->nextNode;
			}
			//Add Node dtor to get rid of Robot
			count--;
			delete current;
			return;
		}
		previous = current;
		current = current->nextNode;
	}
}
