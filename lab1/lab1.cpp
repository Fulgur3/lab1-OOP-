#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Node::Node(int year, int month, int day, int hour, int minute, int second) {
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

Tree::Tree(int year, int month, int day, int hour, int minute, int second) {
	root = new Node(year, month, day, hour, minute, second);
	count = 1;
	Tree::setId(root);
}

Tree:: ~Tree() {
	deleteTree(root);
}

Tree::Node* Tree::getRoot() {
	return root;
}

void Tree::outputTree(Node* current, int temp) {
	cout<<"""[" << current->ID << "]:" << current << " : date = " << current->day << "/" << current->month << "/" << current->year << "year" << " " << current->hour << ":" << current->minute << ":" << current->second << "\n";
	temp++;
	for (int i = 0; i < current->leaves.size(); i++) {
		for (int j = 0; j < temp; j++);
		cout << '\t';
		cout << i << ". ";
		outputTree(current->leaves[i], temp);
	}
}



void Tree::defaultOutput() {
	outputTree(root, 0);
}

void Tree::append(int year, int month, int day, int hour, int minute, int second) {
	Node* current = root;
	int tmp;
	if (root->leaves.empty()) {
		Node* newNode = new Node(year,month,day,hour,minute,second);
			count++;
			Tree ::setId(newNode);
			root->leaves.push_back(newNode);
			cout << "Tree was empty, node is added as root";
			return;
	}
	while (true) {
		Tree::outputTree(current);
		if (current->leaves.empty()) {
			Node* newNode = new Node(year, month, day, hour, minute, second);
			count++;
			Tree::setId(newNode);
			current->leaves.push_back(newNode);
			return;
		}
		cout << "Free leaves: ";
		for (int i = 0; i < current->leaves.size(); i++) {
				cout << i << " ";
			}
		cout<<"Choose the leap or enter\"-1\"\n";
		cin >> tmp;
		if (tmp == -1) {
			Node* newNode = new Node(year, month, day, hour, minute, second);
			count++;
			Tree::setId(newNode);
			current->leaves.push_back(newNode);
			return;
		}
		else
			current->leaves[tmp];
	}
}

Tree::Node* Tree::deleteNode() {
	Node* current = root;
	Node* prev = root;
	int tmp = -1, act;
	if (root->leaves.empty()) {
		cout << "No leaves" << endl;
		return nullptr;
	}
	while (true) {
		Tree::outputTree(current);
		if (current->leaves.empty()) {
			std::cout << "That node hasn't got leaves." << std::endl;
			prev->leaves.erase(prev->leaves.begin() + tmp);
			std::cout << "Node " << current << " is deleted" << std::endl;
			return current;
		}

		std::cout << "Free leaves: ";
		for (int i = 0; i < current->leaves.size(); i++)
			std::cout << i << ' ';
		std::cout << "\nChoose the leafe or press \"-1\"\n";
		std::cin >> act;
		if (act == -1) {
			if (tmp == -1) {
				std::cout << "You can't delete root" << std::endl;
				continue;
			}
			prev->leaves.erase(prev->leaves.begin() + tmp);
			std::cout << "Node " << current << " is deleted" << std::endl;
			return current;

		}
		else {
			tmp = act;
			prev = current;
			current = current->leaves[tmp];
		}
	}
}

void Tree::deleteTree(Tree::Node* current) {
	for (auto& leaf : current->leaves)
		deleteTree(leaf);
	std::cout << "Node " << current << " is deleted" << std::endl;
	delete current;
}

void Tree::setId(Tree::Node* current) {
	current->ID = count;
}

void Tree::printNode(Tree::Node* current) {
	std::cout << "[" << current->ID << "]: " << current << " " <<
		current->day << "/" << current->month << "/" << current->year << "year" << " "
		<< current->hour << ":" << current->minute << ":" << current->second;
}

int main()
{

  
}