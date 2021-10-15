#include <iostream>
#include <string>

#include "history.h"
using namespace std;

void history::insertHistory(Node** headRef, string newHistory){
	Node* newNode = new Node();
	newNode->history = newHistory;
	newNode->next = (*headRef);
	(*headRef) = newNode;
	}

void history::deleteHistory(Node** headRef){
	Node* tmp = *headRef;
	Node* next = NULL;

	while (tmp!=NULL){
		next = tmp->next;
		free(tmp);
	}

	*headRef = NULL;
}

void history::printHistory(Node* node){
	while (node!=NULL){
		cout << node->history << endl;
        node = node->next;
	}
	if (node == NULL){
		cout<<"History has been deleted"<<endl;
	}
}


