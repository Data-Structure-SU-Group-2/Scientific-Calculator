#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#define PI 3.14159265

using namespace std;

double str_to_dbl(string str){
	stringstream ss(str);
	double dbl;
	ss>>dbl;
	return dbl;
}

string dbl_to_strng(double dbl){
	ostringstream ss;
	string strng;
	ss<<dbl;
	strng = ss.str();
	return strng;
}

int main(){
	vector <string> a;
	double result2;
	string input;
	string result;

cout<< "inputnya kek gini yak, misal\n"
	<< "a\n+\nb\n/\nc\n*\nd\n+\nsin\n30\n=\n"
	<< "cobain noh dibawah\n"<<endl;

	while (input != "="){
		cin>>input;
		a.push_back(input);
	}

	for (int i=0; i<a.size(); i++){
		if (a.at(i)== "sin"){
		
		result =dbl_to_strng(sin(str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;
		}

		if (a.at(i)== "cos"){
		result = dbl_to_strng(cos(str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;
		}

		if (a.at(i)== "tan"){
		result = dbl_to_strng(tan(str_to_dbl(a.at(i+1))*PI/180));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}
		
		if (a.at(i)== "sqrt"){
		result = dbl_to_strng(sqrt(str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}
		
		if (a.at(i)== "log"){
		result = dbl_to_strng(log10(str_to_dbl(a.at(i+1))));
		a.at(i+1)=result;
		a.erase(a.begin()+i);
		i=0;}
		
		

	}

	for (int i=0; i<a.size(); i++){
		if (a.at(i)== "*"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))*str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}
		if (a.at(i)== "/"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))/str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}		
	}

	for (int i=0; i<a.size(); i++){
		if (a.at(i)== "+"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))+str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}	
		if (a.at(i)== "-"){
		result = dbl_to_strng(str_to_dbl(a.at(i-1))-str_to_dbl(a.at(i+1)));
		a.at(i+1)=result;
		a.erase(a.begin()+i-1,a.begin()+i+1);
		i = 0;
		}		
	}

	for (int i=0; i<a.size(); i++){
		cout<<a.at(i)<<endl;
	}
	
	return 0;
}
