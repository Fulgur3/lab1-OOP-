#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Tree

class Tree {
private:
	class Node {
	public: int ID;
		  int year;
		  int month;
		  int day;
		  int hour;
		  int minute;
		  int second;
		  vector<Node*> leaves;
		  Node(int year, int month, int day, int hour, int minute, int second);
	};
	int count;
	Node* root;
public:
	Tree(int year, int month, int day, int hour, int minute, int second);
	~Tree();
	Node* getRoot();
	void append(int year, int month, int day, int hour, int minute, int second);
	void setId(Node* current);
	void outputTree(Node* current, int temp = 0);
	void defaultOutput();
	Node* deleteNode();
	void printNode(Node* current);
	void deleteTree(Node* current);

};