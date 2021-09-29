#include "Tree.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
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


/////////////////////////////////////////BinaryTree/////////////////////////////////////////////

BinaryTree::Node::Node(int year, int month, int day, int hour, int minute,int second) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    left = right = nullptr;
}

BinaryTree::~BinaryTree() {
    print2DUtil(root, 0);
    deleteTree();
}

BinaryTree::BinaryTree(int year, int month, int day, int hour, int minute,int second) {
    root = new Node(year,month,day,hour,minute,second);
    count++;
    setId(root);
    std::cout << "Root " << root << " is created." << std::endl;
}

BinaryTree::Node* BinaryTree::getRoot() {
    return root;
}

void BinaryTree::setId(Node *current) {
    current->id = count;
}

void BinaryTree::append(int year, int month, int day, int hour, int minute,int second) {
    Node *current = root;
    int tmp;
    while (true) {
        if ((current->left != nullptr) && (current->right != nullptr)) {
            std::cout << "Choose the Node we need to go" << std::endl;
            std::cout << "[1]Left: " << current->left << "\t" << "[2]Right: " << current->right << std::endl;
            std::cin >> tmp;
            switch (tmp) {
                case 1:
                    current = current->left;
                    break;
                case 2:
                    current = current->right;
                    break;
                default:
                    std::cout << "Not integer expression." << std::endl;
            }
        } else {
            if ((current->left == nullptr) && (current->right != nullptr)) {
                std::cout << "Choose the Node we need to go" << std::endl;
                std::cout << "[1]Left(Creating): " << current->left << "\t" << "[2]Right: " << current->right
                          << std::endl;
                std::cin >> tmp;
                switch (tmp) {
                    case 1:
                        current->left = new Node(year,month,day,hour,minute,second);
                        count++;
                        setId(current->left);
                        return;
                    case 2:
                        current = current->right;
                        break;
                    default:
                        break;
                }

            } else if ((current->left != nullptr) && (current->right == nullptr)) {
                std::cout << "Choose the Node we need to go" << std::endl;
                std::cout << "[1]Left: " << current->left << "\t" << "[2]Right(Creating): " << current->right
                          << std::endl;
                std::cin >> tmp;
                switch (tmp) {
                    case 1:
                        current = current->left;
                        break;
                    case 2:
                        current->right = new Node(year,month,day,hour,minute,second);
                        count++;
                        setId(current->right);
                        return;
                    default:
                        break;
                }
            } else {
                std::cout << "Choose the Node we need to go" << std::endl;
                std::cout << "[1]Left(Creating): " << current->left << "\t" << "[2]Right(Creating): " << current->right
                          << std::endl;
                std::cin >> tmp;
                switch (tmp) {
                    case 1:
                        current->left = new Node(year,month,day,hour,minute,second);
                        count++;
                        setId(current->left);
                        return;
                    case 2:
                        current->right = new Node(year,month,day,hour,minute,second);
                        count++;
                        setId(current->right);
                        return;
                    default:
                        break;
                };
            }
        }
    }
}

BinaryTree::Node* BinaryTree::deleteNode()
{
    Node* previous = root;
    Node* current = root;
    if ((root->left == nullptr) && (root->right == nullptr)){ //Если потомки корня == nullptr, затираем указатель на корень
        std::cout << "Root hasn't got leaves" << std::endl;
        root = nullptr;
        std::cout << "Tree with root "<< current <<" is deleted." << std::endl;
        return nullptr;
    }
    while (true) { // Проход по дереву и затирание указателей
        if (current->left != nullptr) {
            previous = current;
            current = current->left;
        } else if ((current->left == nullptr) && (current->right != nullptr)) {
            previous = current;
            current = current->right;
        } else {
            std::cout << "Node " << current << " is deleted." << std::endl;
            if(previous->left == current)
                previous->left = nullptr;
            else
                previous->right = nullptr;
            current = nullptr;
            return nullptr;
        }
    }
}

void BinaryTree::deleteTree(){
    while(root != nullptr)
        deleteNode();
}

void BinaryTree::output2dTreeUtil(Node* current, int space){
    if (root == nullptr)
        return;
    space += COUNT;
    output2dTreeUtil(root->right, space);
    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout<<root->day << "/" << root->month << "/" << root->year << "year" << " " << root->hour << ":" << root->minute << ":" << root->second <<"\n";
    output2dTreeUtil(root->left, space);
}

void BinaryTree::output2dTree(Node *current){
    output2dTreeUtil(current, 0);
}

void BinaryTree::print2DUtil(Node* current, int space)
{
    if (current == nullptr)
        return;

    space += COUNT;

    print2DUtil(current->right, space);

    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout<<current->day << "/" << current->month << "/" << current->year << "year" << " " << current->hour << ":" << current->minute << ":" << current->second <<"\n";

    print2DUtil(current->left, space);
}

void BinaryTree::outTree() {
    print2DUtil(root,0);
}

void BinaryTree::printNode(BinaryTree::Node *current) {
    std::cout << "[" << current->id << "]: " << current << " " <<
              current->day << "/" << current->month << "/" << current->year << "year" << " "
              << current->hour << ":" << current->minute << ":" << current->second;
}

bool BinaryTree::checkValues(Node *current, int year, int month, int day, int hour, int minute, int second) {
    if(current->year >= year){
        if(current->month >= month){
            if(current->day >= day){
                if(current->hour >= hour) {
                    if (current->minute >= minute) {
                        if (current->second > second) {
                            return true;
                        } else return false;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}

bool BinaryTree::checkEqual(Node *current, int year, int month, int day, int hour, int minute, int second){
    if(current->year == year){
        if(current->month == month){
            if(current->day == day){
                if(current->hour == hour) {
                    if (current->minute == minute) {
                        if (current->second == second) {
                            return true;
                        } else return false;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}

bool BinaryTree::check2Nodes(Node* current, Node* newNode){
    if(current->year <= newNode->year){
        if(current->month <= newNode->month){
            if(current->day <= newNode->day){
                if(current->hour <= newNode->hour) {
                    if (current->minute <= newNode->minute) {
                        if (current->second < newNode->second) {
                            return true;
                        } else return false;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}

bool BinaryTree::checkEqual(Node *current, Node *newNode) {
    if(current->year == newNode->year){
        if(current->month == newNode->month){
            if(current->day == newNode->day){
                if(current->hour == newNode->hour) {
                    if (current->minute == newNode->minute) {
                        if (current->second == newNode->second) {
                            return true;
                        } else return false;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}

BinaryTree::Node* BinaryTree::getParent(Node* tree,Node *current) { // Node* parent = getParent(current);
    if(!checkEqual(current, tree)) {
        if (check2Nodes(current, tree)) { //Если дата current меньше чем tree
            Node *res = getParent(tree->left, current); //Получаем родителя для tree->left, рекурсивный проходи
            if (res)
                return res;
            return tree;
        } else if (!check2Nodes(current, tree)) {
            Node *res = getParent(tree->right, current);
            if (res)
                return res;
            return tree;
        }
    } else return nullptr;
}


 

///////////////////////////////BinarySearchTree//////////////////////////////////////////

BinarySearchTree::Node::Node(int year, int month, int day, int hour, int minute,int second) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    left = right = nullptr;
}

BinarySearchTree::BinarySearchTree(int year, int month, int day, int hour, int minute,int second){
    count = 1;
    root = new Node(year,month,day,hour,minute,second);
    std::cout << "Root " << root << " is created." << std::endl;
}

void BinarySearchTree::setId(Node *current) {
    current->id = count;
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree();
}

void BinarySearchTree::output2dTreeUtil(Node* current, int space){
    if (root == nullptr)
        return;
    space += COUNT;
    output2dTreeUtil(root->right, space);
    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout<<root->day << "/" << root->month << "/" << root->year << "year" << " " << root->hour << ":" << root->minute << ":" << root->second <<"\n";
    output2dTreeUtil(root->left, space);
}

void BinarySearchTree::output2dTree(Node *current){
    output2dTreeUtil(current, 0);
}

void BinarySearchTree::print2DUtil(Node* current, int space)
{
    if (current == nullptr)
        return;

    space += COUNT;

    print2DUtil(current->right, space);

    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout<< current->day << "/" << current->month << "/" << current->year << "year" << " " << current->hour << ":" << current->minute << ":" << current->second <<"\n";

    print2DUtil(current->left, space);
}

void BinarySearchTree::printNode(Node *current) {
    std::cout << "[" << current->id << "]: " << current << " " <<
    current->day << "/" << current->month << "/" << current->year << "year" << " "
    << current->hour << ":" << current->minute << ":" << current->second;
}

bool BinarySearchTree::checkValues(Node *current, int year, int month, int day, int hour, int minute, int second) {
    if(current->year >= year){
        if(current->month >= month){
            if(current->day >= day){
                if(current->hour >= hour) {
                    if (current->minute >= minute) {
                        if (current->second > second) {
                            return true;
                        } else return false;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}

bool BinarySearchTree::checkEqual(Node *current, int year, int month, int day, int hour, int minute, int second){
    if(current->year == year){
        if(current->month == month){
            if(current->day == day){
                if(current->hour == hour) {
                    if (current->minute == minute) {
                        if (current->second == second) {
                            return true;
                        } else return false;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}

bool BinarySearchTree::check2Nodes(Node* current, Node* newNode){
    if(current->year <= newNode->year){
        if(current->month <= newNode->month){
            if(current->day <= newNode->day){
                if(current->hour <= newNode->hour) {
                    if (current->minute <= newNode->minute) {
                        if (current->second < newNode->second) {
                            return true;
                        } else return false;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}

bool BinarySearchTree::checkEqual(Node *current, Node *newNode) {
    if(current->year == newNode->year){
        if(current->month == newNode->month){
            if(current->day == newNode->day){
                if(current->hour == newNode->hour) {
                    if (current->minute == newNode->minute) {
                        if (current->second == newNode->second) {
                            return true;
                        } else return false;
                    } else return false;
                } else return false;
            } else return false;
        } else return false;
    } else return false;
}

void BinarySearchTree::append(int year, int month, int day, int hour, int minute, int second){
    Node* current = root;
    while(true){
        if(checkValues(current,year,month,day,hour,minute,second)) {
            if (current->left != nullptr) {
                current = current->left;
            } else {
                count++;
                current->left = new Node(year,month,day,hour,minute,second);
                setId(current->left);
                return;
            }
        } else {
            if (current->right != nullptr) {
                current = current->right;

            } else {
                count++;
                current->right = new Node(year, month, day, hour, minute, second);
                setId(current->right);
                return;
            }
        }
    }
}



BinarySearchTree::Node* BinarySearchTree::deleteNode() {
    Node* previous = root;
    Node* current = root;
    if ((root->left == nullptr) && (root->right == nullptr)){ //Если потомки корня == nullptr, затираем указатель на корень
        std::cout << "Root hasn't got leaves" << std::endl;
        root = nullptr;
        std::cout << "Tree with root "<< current <<" is deleted." << std::endl;
        return nullptr;
    }
    while (true) { // Проход по дереву и затирание указателей
        if (((current->left != nullptr) && (current->right == nullptr)) ||
            ((current->left != nullptr) && (current->right != nullptr))) {
            previous = current;
            current = current->left;
        } else if ((current->left == nullptr) && (current->right != nullptr)) {
            previous = current;
            current = current->right;
        } else {
            std::cout << "Node " << current << " is deleted." << std::endl;
            if(previous->left == current)
                previous->left = nullptr;
            else
                previous->right = nullptr;
            current = nullptr;
            return nullptr;
        }
    }
}

void BinarySearchTree::deleteTree() {
    while(root != nullptr)
        deleteNode();
}

void BinarySearchTree::outTree() {
    std::cout << "======================================================" << std::endl;
    print2DUtil(root,0);
    std::cout << "======================================================" << std::endl;
}


void BinarySearchTree::deleteNodeByValue(int year, int month, int day, int hour, int minute, int second) {
    Node* current = root;
    Node* parent = getParent(root, current);

    if (current->left == nullptr && current->right == nullptr) { // Если потомки отсутствуют
        if (!checkEqual(current, year, month, day, hour, minute, second))
            return;
        else {
            if (parent->left == current) {
                parent->left = nullptr;
                return;
            }
            else if (parent->right == current) {
                parent->right = nullptr;
                return;
            }
        }
    }
    else if (current->left == nullptr || current->right == nullptr) { // 1 потомок
        if (checkEqual(current, year, month, day, hour, minute, second)) {
            if (current->left == nullptr) {
                if (parent->left == nullptr)
                    parent->left = current->right;
                else
                    parent->right = current->right;
            }
            else {
                if (parent->left == current)
                    parent->left = current->left;
                else
                    parent->right = current->left;
            }
        }
        else {
            if (current->left == nullptr) {
                if (!checkValues(current, year, month, day, hour, minute, second))
                    current = current->right;
                else return;
            }
            else if (current->right == nullptr) {
                if (checkValues(current, year, month, day, hour, minute, second))
                    current = current->left;
                else return;
            }
        }
    }
    else { // 2 потомка
        while (true) {
            parent = getParent(root, current);
            Node* temp = current->left;
            if (parent != nullptr) {
                if ((current->left == nullptr && current->right == nullptr) && !checkEqual(current, year, month, day, hour, minute, second))
                    return;
                else if (checkEqual(current, year, month, day, hour, minute, second)) {
                    if (parent->left == current) {
                        parent->left = temp;
                    }
                    else {
                        parent->right = temp;
                    }
                    while (temp->right)
                        temp = temp->right;
                    temp->right = current->right;
                    current = temp;
                }
                else if (!checkEqual(current, year, month, day, hour, minute, second)) {
                    if (current->left != nullptr && current->right != nullptr) {
                        if (checkValues(current, year, month, day, hour, minute, second))
                            current = current->right;
                        else current = current->left;
                    }
                    else if (current->left != nullptr) {
                        current = current->left;
                    }
                    else {
                        current = current->right;
                    }
                }
            }
            else {
                if (!checkEqual(current, year, month, day, hour, minute, second)) {
                    if (checkValues(current, year, month, day, hour, minute, second) && current->left != nullptr)
                        current = current->left;
                    else if (!checkValues(current, year, month, day, hour, minute, second) && current->right != nullptr)
                        current = current->right;
                }
            }
        }
    }
}

BinarySearchTree::Node* BinarySearchTree::getParent(Node* tree, Node* current) { // Node* parent = getParent(current);
    if (!checkEqual(current, tree)) {
        if (check2Nodes(current, tree)) { //Если дата current меньше чем tree
            Node* res = getParent(tree->left, current); //Получаем родителя для tree->left, рекурсивный проходи
            if (res)
                return res;
            return tree;
        }
        else if (!check2Nodes(current, tree)) {
            Node* res = getParent(tree->right, current);
            if (res)
                return res;
            return tree;
        }
    }
    else return nullptr;
}

BinarySearchTree::Node* BinarySearchTree::searchNode(Node* current,int id)
{
 
  
    
    if (current != nullptr && current->id != id) {
        Node* Left = searchNode(current->left, id);
        Node* Right = searchNode(current->right, id);
        if (Left != nullptr) {
            return Left;
        }
        else if (Right != nullptr) {
            return Right;
        }
        else {
            return nullptr;
        }
    }
    
    return current;
    
}

vector<int> BinarySearchTree::get(int key) {
    Node *current= searchNode(root, key);
    vector<int>res;
    res.push_back(current->year);
    res.push_back(current->month);
    res.push_back(current->day);
    return res;
}

long yeartoDays(int y, int m, int d) {
    int LeapYears = (int)y / 4;
    long a = (y - LeapYears) * 365 + LeapYears * 366;
    if (m >= 2) a += 31;
    if (m >= 3 && (int)y / 4 == y / 4) a += 29;
    else if (m >= 3) a += 28;
    if (m >= 4) a += 31;
    if (m >= 5) a += 30;
    if (m >= 6) a += 31;
    if (m >= 7) a += 30;
    if (m >= 8) a += 31;
    if (m >= 9) a += 31;
    if (m >= 10) a += 30;
    if (m >= 11) a += 31;
    if (m == 12) a += 30;
    a += d;
    return a;
}

string weekday(int y, int m, int d) {
    long a = yeartoDays(y, m, d);
    int b = ((a - 2) % 7);
    switch (b) {
    case 0:
        return "Saturday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    case 7:
        return "Sunday";

    }
}

int weekNumber(int y, int m, int d) {
    map<string, int> map2 = { { "Monday" ,1 }, { "Tuesday" , 2},{"Wednesday",3},{"Thursday",4},{"Friday",5},{"Saturday",6},{"Sunday",7} };
    long a = 0;
    if (m >= 2) a += 31;
    if (m >= 3 && (int)y / 4 == y / 4) a += 29;
    else if (m >= 3) a += 28;
    if (m >= 4) a += 31;
    if (m >= 5) a += 30;
    if (m >= 6) a += 31;
    if (m >= 7) a += 30;
    if (m >= 8) a += 31;
    if (m >= 9) a += 31;
    if (m >= 10) a += 30;
    if (m >= 11) a += 31;
    if (m == 12) a += 30;
    a += d;
    a -= map2[weekday(y, m, d)];
    return a / 7+1;
}

string stats(int y, int key) {
    int max = 0;
    string word;
    map<string, int> map = { { "Monday" ,1 }, { "Tuesday" , 2},{"Wednesday",3},{"Thursday",4},{"Friday",5},{"Saturday",6},{"Sunday",7} };
    int arr[7] = {0,0,0,0,0,0,0};
    for (int i = 1; i < 12; i++) {
       
        arr[map[weekday(y, i, key)] - 1]++;;
    }
    for (int i = 0; i < 6; i++) {
        
        if (arr[i+1] > arr[i])
            max = i+2;
        else
            max = i+1 ;
    }
    switch (max) {
    case 0:
        return "Saturday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    case 7:
        return "Sunday";

    }

   
}

long differenceBetweenYears(int y1, int m1, int d1, int y2, int m2, int d2) {
  
    return abs( yeartoDays(y1, m1, d1)-yeartoDays(y2,m2,d2)+1);
}


int main() {
    
    BinarySearchTree obj(0, 0, 0, 0, 0, 0);
    obj.append(7, 7, 7, 7, 7, 7);
    obj.append(2021, 9, 29, 12, 32, 44);
    obj.append(6, 6, 6, 6, 6, 6);
    obj.append(4, 4, 4, 4, 4, 4);
    obj.append(4, 4, 4, 4, 4, 4);
    obj.append(7, 7, 7, 7, 7, 7);
    obj.append(32, 32, 32, 32, 32, 32);
    obj.append(341, 341, 341, 341, 341, 341);
   obj.outTree();
    obj.append(2020, 10, 21, 12, 32, 44);
   vector<int>temp= obj.get(3);
   vector<int>temp2 = obj.get(10);
   cout << weekday(temp[0], temp[1], temp[2]) << endl;
   cout << weekNumber(temp[0], temp[1], temp[2]) << endl;
   cout << differenceBetweenYears(temp[0], temp[1], temp[2], temp2[0], temp2[1], temp2[2])<<endl;
   cout << stats(2021, 13) << endl;
    return 0;
}
