#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <math.h>
#define PI 3.14159265

using namespace std;

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

//main function
int main(){
	vector <string> a;
	double result2;
	string input;
	string result;

//input example for the user
cout<< "Input example\n\na * b + c log d =\n\n"
	<< "or\n\nsqrt\na\n+\nb\n/\nc\n="
	<< "\n\nAlways add space after one variable for horizontal input"
	<< "\nAlways put (=) in the end\nEnjoy :))\n\n"<<endl;

	//input termination point
	while (input != "="){
		cin>>input;
		a.push_back(input);
	}

	for (int i=0; i<a.size(); i++){
		
		//power function
		if (a.at(i)== "^"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))*str_to_dbl(a.at(i-1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}		
		
		//log10 function
		if (a.at(i)== "log"){
		result = dbl_to_strng(log10(str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}
		
		//normal log function
		if (a.at(i)== "ln"){
		result = dbl_to_strng(log(str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;
		}
		
		//square root function
		if (a.at(i)== "sqrt"){
		result = dbl_to_strng(sqrt(str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}
		
		//sin function
		if (a.at(i)== "sin"){
		result =dbl_to_strng(sin(str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;
		}
		
		//cos function
		if (a.at(i)== "cos"){
		result = dbl_to_strng(cos(str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;
		}
		
		//tan function
		if (a.at(i)== "tan"){
		result = dbl_to_strng(tan(str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}

	}

	for (int i=0; i<a.size(); i++){
		
		//multiplier function
		if (a.at(i)== "*"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))*str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}
		
		//divider function
		if (a.at(i)== "/"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))/str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}
	}

	for (int i=0; i<a.size(); i++){
		
		//addition function
		if (a.at(i)== "+"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))+str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}	
		
		//substraction function
		if (a.at(i)== "-"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))-str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}		
	}

	for (int i=0; i<a.size()-1; i++){
		cout<<a.at(i)<<endl;
	}
	return 0;
}
