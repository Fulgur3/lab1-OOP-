#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define COUNT 10

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


//===========================================================================



class BinaryTree {
private:
    class Node {
    public:
        int id;
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
        Node* left;
        Node* right;
        Node(int year, int month, int day, int hour, int minute, int second);
    };
    Node* root;
    int count;
public:
    BinaryTree(int year, int month, int day, int hour, int minute, int second);
    ~BinaryTree();
    Node* getRoot();
    void setId(Node* current);
    void append(int year, int month, int day, int hour, int minute, int second);
    Node* deleteNode();
    void deleteTree();
    void output2dTreeUtil(Node* current, int space);
    void output2dTree(Node* current);
    void outTree();
    void printNode(Node* current);
    void print2DUtil(Node* current, int space);
    bool checkValues(Node* current, int year, int month, int day, int hour, int minute, int second);
    bool checkEqual(Node* current, int year, int month, int day, int hour, int minute, int second);
    bool check2Nodes(Node* current, Node* newNode);
    bool checkEqual(Node* current, Node* newNode);
    Node* getParent(Node* current, Node* tree);

};

//===========================================================================

class BinarySearchTree {
private:
    class Node {
    public:
        int id;
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
        Node* left;
        Node* right;
        Node(int year, int month, int day, int hour, int minute, int second);
    };
    Node* root;
    int count;
public:
    BinarySearchTree(int year, int month, int day, int hour, int minute, int second);
    ~BinarySearchTree();
    void setId(Node* current);
    bool checkValues(Node* current, int year, int month, int day, int hour, int minute, int second);
    bool checkEqual(Node* current, int year, int month, int day, int hour, int minute, int second);
    bool check2Nodes(Node* current, Node* newNode);
    bool checkEqual(Node* current, Node* newNode);
    void append(int year, int month, int day, int hour, int minute, int second);
    void output2dTreeUtil(Node* current, int space);
    void output2dTree(Node* current);
    void print2DUtil(Node* current, int space);
    void outTree();
    void printNode(Node* current);
    Node* deleteNode();
    void deleteTree();
    void deleteNodeByValue(int year, int month, int day, int hour, int minute, int second);
    Node* getParent(Node* tree, Node* current);
};
