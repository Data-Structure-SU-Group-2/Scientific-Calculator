#ifndef HISTORYH
#define HISTORYH

#include <iostream>
#include <string>
using namespace std;

struct Node{
	string history;
	Node* next;
};

class history {
	public:
         void insertHistory(Node** headRef, string newHistory);
         void deleteHistory(Node** headRef);
         void printHistory(Node* node);
};

#endif
