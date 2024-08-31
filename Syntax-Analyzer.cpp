#include<iostream>
#include<string>
#include<fstream>
using namespace std;


int c = -1;
void matchString(string &look_ahead, string str, string arr[21]);
void stmt(string &look_ahead, string arr[21]);
void stmtSet(string &look_ahead, string arr[21]);
void decStmt(string &look_ahead, string arr[21]);
void type(string &look_ahead, string arr[21]);
void s(string &look_ahead, string arr[21]);
void assignStmt(string &look_ahead, string arr[21]);
void exp(string &look_ahead, string arr[21]);
void idList(string &look_ahead, string arr[21]);
void L(string &look_ahead, string arr[21]);
void OPR(string &look_ahead, string arr[21]);
void OP(string &look_ahead, string arr[21]);
void OPR(string &look_ahead, string arr[21]);

string next(string arr[21]){
	//	cout<<"Before C "<<arr[count]<<endl;
	c++;
	//	cout<<"After C "<<arr[count]<<endl;
	return arr[c];
}

void program(string &look_ahead, string arr[21]){
	if (look_ahead == "void"){
		//	cout<<"L "<<look_ahead<<endl;
		matchString(look_ahead, "void", arr);
		//	cout<<"L "<<look_ahead<<endl;
		matchString(look_ahead, "main", arr);
		matchString(look_ahead, "(", arr);
		matchString(look_ahead, ")", arr);
		matchString(look_ahead, "{", arr);
		stmtSet(look_ahead, arr);
		//	cout<<look_ahead;
		matchString(look_ahead, "}", arr);
	}

}

void matchString(string &look_ahead, string str, string arr[21]){
	if (look_ahead == str){
		look_ahead = next(arr);
	}
	else{
		cout << "Error" << endl;
		exit(0);
	}
}

void stmtSet(string &look_ahead, string arr[21]){
	//cout<<look_ahead<<endl;
	stmt(look_ahead, arr);
	s(look_ahead, arr);
}

void s(string &look_ahead, string arr[21]){
	if (look_ahead == "int" || look_ahead == "float" || look_ahead == "id"){
		stmtSet(look_ahead, arr);
	}
	else{
		return;
	}
}
void stmt(string &look_ahead, string arr[21]){
	if (look_ahead == "int" || look_ahead == "float"){
		decStmt(look_ahead, arr);
	}
	else if (look_ahead == "id"){
		assignStmt(look_ahead, arr);
	}
}

void assignStmt(string &look_ahead, string arr[21]){
	if (look_ahead == "id"){
		matchString(look_ahead, "id", arr);
		matchString(look_ahead, "=", arr);
		exp(look_ahead, arr);
		matchString(look_ahead, ";", arr);
	}
}

void exp(string &look_ahead, string arr[21]){
	OPR(look_ahead, arr);
	OP(look_ahead, arr);
	OPR(look_ahead, arr);

}
void  OPR(string &look_ahead, string arr[21]){
	if (look_ahead == "id"){
		matchString(look_ahead, "id", arr);
	}
	else if (look_ahead == "num"){
		matchString(look_ahead, "num", arr);
	}
}

void OP(string &look_ahead, string arr[21]){
	if (look_ahead == "+"){
		matchString(look_ahead, "+", arr);
	}
	else if (look_ahead == "*"){
		matchString(look_ahead, "*", arr);
	}
}
void decStmt(string &look_ahead, string arr[21]){
	type(look_ahead, arr);
	idList(look_ahead, arr);
	matchString(look_ahead, ";", arr);

}

void idList(string &look_ahead, string arr[21]){
	matchString(look_ahead, "id", arr);
	L(look_ahead, arr);
}

void L(string &look_ahead, string arr[21]){
	if (look_ahead == ","){
		//	cout<<look_ahead;
		matchString(look_ahead, ",", arr);
		idList(look_ahead, arr);
	}
	else{
		return;
	}
}

void type(string &look_ahead, string arr[21]){
	if (look_ahead == "int"){
		matchString(look_ahead, "int", arr);
	}
	else if (look_ahead == "float"){
		matchString(look_ahead, "float", arr);
	}
}
int main(){


	string filename = "C:\\Users\\Javeria Rizwan\\Desktop\\output.txt";
	ifstream inputFile(filename);
	ofstream myFile;

	if (!inputFile.is_open()) {
		cout << "Error opening file. Exiting..." << endl;
		return 1;
	}

	string str;
	string arr[21] = {};
	int i = 0;
	while (getline(inputFile, str)){
		//	cout<<str<<endl;
		arr[i] = str;
		//cout<<arr[i];
		i++;
	}

	string look_ahead;
	look_ahead = arr[0];
	//cout<<arr[3]<<endl;
	next(arr);
	program(look_ahead, arr);
	cout << "No Errors" << endl;

	/*	(getline(inputFile, str));
	cout<<str<<endl;
	(getline(inputFile, str));
	cout<<str<<endl;*/
	//	program(str,inputFile,str);


	return 0;
}