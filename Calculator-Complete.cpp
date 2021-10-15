#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265

using namespace std;

//inclass function
class Convert{
	public:
		//string to double converter
		double str_to_dbl(string str){
			stringstream ss(str);
			double dbl;
			ss>>dbl;
			return dbl;
		}
		
		//double to string converter
		string dbl_to_strng(double dbl){
			ostringstream ss;
			string strng;
			ss<<dbl;
			strng = ss.str();
			return strng;
		}
		
		strtodbl();	
};	

//constructor
Convert::strtodbl(){
}

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
		tmp = next;
	}

	*headRef = NULL;
	cout<<"All history has been deleted."<<endl;
}

void history::printHistory(Node* node){
	while (node!=NULL){
		cout << node->history << endl;
        node = node->next;
	}
}



//main function
int main(){
	vector <string> a;
	double result2;
	string input;
	string result;
	Convert convert;
	history history;
	Node *head = NULL;
	string History = "";
	string instruction;
	int num;

//input example for the user
cout<< "Input example\n\na * b + c log d =\n\n"
	<< "\n\nAlways add space after one variable for input"
	<< "\nAlways put (=) in the end\nHistory will be shown in the end\nEnjoy :))\n\n"<<endl;

cout<<"Times of calculator uses: ";
cin>>num;

for(int i = 0; i<num; i++){
	
	
	//input termination point
	while (input != "="){
		cin>>input;
		a.push_back(input);
		History += input;
	}

	for (int i=0; i<a.size(); i++){
		
		//power function
		if (a.at(i)== "^"){
		result = convert.dbl_to_strng(pow(convert.str_to_dbl(a.at(i-1)),convert.str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}		
		
		//log10 function
		if (a.at(i)== "log"){
		result = convert.dbl_to_strng(log10(convert.str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}
		
		//normal log function
		if (a.at(i)== "ln"){
		result = convert.dbl_to_strng(log(convert.str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;
		}
		
		//square root function
		if (a.at(i)== "sqrt"){
		result = convert.dbl_to_strng(sqrt(convert.str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}
		
		//sin function
		if (a.at(i)== "sin"){
		result =convert.dbl_to_strng(sin(convert.str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;
		}
		
		//cos function
		if (a.at(i)== "cos"){
		result = convert.dbl_to_strng(cos(convert.str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;
		}
		
		//tan function
		if (a.at(i)== "tan"){
		result = convert.dbl_to_strng(tan(convert.str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}

	}

	for (int i=0; i<a.size(); i++){
		
		//multiplier function
		if (a.at(i)== "*"){
		result = convert.dbl_to_strng(convert.str_to_dbl(a.at(i-1))*convert.str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}
		
		//divider function
		if (a.at(i)== "/"){
		result = convert.dbl_to_strng(convert.str_to_dbl(a.at(i-1))/convert.str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}
	}

	for (int i=0; i<a.size(); i++){
		
		//addition function
		if (a.at(i)== "+"){
		result = convert.dbl_to_strng(convert.str_to_dbl(a.at(i-1))+convert.str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}	
		
		//substraction function
		if (a.at(i)== "-"){
		result = convert.dbl_to_strng(convert.str_to_dbl(a.at(i-1))-convert.str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}		
	}

	for (int i=0; i<a.size()-1; i++){
		cout<<a.at(i)<<endl;
		History += a.at(i);
		History += "\n";
	}
	input = "";
	a.erase(a.begin(),a.end());
}
	
	history.insertHistory(&head,History);
	cout<<"Do you want to see the history?(Y/N) ";
	cin>>instruction;
	
	if(instruction == "Y" || "y"){
		history.printHistory(head);
		instruction = "";	
	}
	cout<<"Thank you for using our calculator.\n";
	history.deleteHistory(&head);
	
	return 0;
}
