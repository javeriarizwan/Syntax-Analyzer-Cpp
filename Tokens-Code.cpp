#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool is_letter(char ch);
bool is_digit(char ch);
bool is_delimiter(char ch);
void lexical(string str, ofstream & myFile);

int main(){
	string filename = "C:\\Users\\Javeria Rizwan\\Desktop\\code2.txt";
	ifstream inputFile(filename);
	ofstream myFile;
	myFile.open("output.txt");

	if (!inputFile.is_open()) {
		cout << "Error opening file. Exiting..." << endl;
		return 1;
	}

	string str;
	while (getline(inputFile, str)) {
		//	cout<<str<<endl;
		lexical(str, myFile);
	}

	inputFile.close();
	myFile.close();
	return 0;
}

bool is_letter(char ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool is_digit(char ch){
	return ch >= '0' && ch <= '9';
}

bool is_delimiter(char ch){
	//return ch == ' ' || ch == '\t' || ch == '\n';
	return 1;
}
void identifier(int i, int j, string lexeme){
	cout << "Identifier: ";
	for (int m = 0; m<i - 1; m++){
		cout << lexeme[m];
	}
	cout << endl;
}

void lexical(string str, ofstream & myFile){
	int state = 0;
	int i = 0;
	int j = 0;
	int r = 0;
	string lexeme = "";
	char ch = '\0';

	while (str[j] != '\0'){
		ch = str[j];
		//	if(str[i]!=' ')
		lexeme += ch;
		//		cout<<"Ch  "<<ch<<"end"<<endl;
		//		cout<<"Lex  "<<lexeme<<endl;
		j++;
		i++;
		//	cout<<ch<<endl;
		switch (state){
		case 0:
			if (is_letter(ch)){
				state = 1;
			}
			else if (is_digit(ch)){
				state = 3;
			}
			else if (ch == '+'){
				state = 0;
				cout << "+ : " << ch << endl;
				//	myFile << "+ : "<< ch<< endl;
				myFile << ch << endl;
				cout << endl;
				//myFile<<endl;
				lexeme = "";
				i = 0;
			}
			else if (ch == ','){
				state = 0;
				cout << ", : " << ch << endl;
				//	myFile << "+ : "<< ch<< endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;
				lexeme = "";
				i = 0;
			}

			else if (ch == '='){
				state = 0;
				cout << "= : " << ch << endl;
				//	myFile << "= : "<< ch<< endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;

				if (str[j] == '='){
					cout << "= : " << str[j] << endl;
					//	myFile << "= : "<< str[j]<< endl;
					myFile << str[j] << endl;
					cout << "Relop" << endl;
					//	myFile << "Relop"<< endl;
					cout << endl;
					//	myFile<<endl;
					j++;
				}
				lexeme = "";
				i = 0;
			}

			else if (ch == ';'){
				state = 0;
				cout << "; : " << ch << endl;
				//	myFile << "; : "<< ch <<endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;
				lexeme = "";
				i = 0;
			}

			else if (ch == '/'){
				state = 0;
				cout << "/ : " << ch << endl;
				//	myFile << "/ : "<< ch <<endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;
				lexeme = "";
				i = 0;
			}

			else if (ch == '*'){
				state = 0;
				cout << "* : " << ch << endl;
				//	myFile << "* : "<< ch <<endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;
				lexeme = "";
				i = 0;
			}

			else if (ch == '|'){
				state = 0;
				cout << "| : " << ch << endl;
				//	myFile << "| : "<< ch <<endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;

				if (str[j] == '|'){
					cout << "| : " << ch << endl;
					myFile << "| : " << ch << endl;
					cout << "OR Operator" << endl;
					myFile << "OR Operator" << endl;
					cout << endl;
					//	myFile<<endl;
					j++;
				}
				else if (str[j != '|']){
					cout << "ERROR Expected '|'" << endl;
					myFile << "ERROR Expected '|'" << endl;
					cout << endl;
					//		myFile<<endl;
				}
				lexeme = "";
				i = 0;
			}

			else if (ch == '&'){
				state = 0;
				cout << "& : " << ch << endl;
				myFile << "& : " << ch << endl;
				cout << endl;
				myFile << endl;

				if (str[j] == '&'){
					cout << "& : " << ch << endl;
					myFile << "& : " << ch << endl;
					cout << "AND Operator" << endl;
					myFile << "AND Operator" << endl;
					cout << endl;
					//	myFile<<endl;
					j++;
				}
				else if (str[j != '&']){
					cout << "ERROR Expected '&'" << endl;
					myFile << "ERROR Expected '&'" << endl;
					cout << endl;
					//	myFile<<endl;
				}
				lexeme = "";
				i = 0;
			}

			else if (ch == '('){
				state = 0;
				cout << "( : " << ch << endl;
				//	myFile << "( : "<< ch<< endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;
				lexeme = "";
				i = 0;
			}

			else if (ch == ')'){
				state = 0;
				cout << ") : " << ch << endl;
				//	myFile << ") : "<< ch<<endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;
				lexeme = "";
				i = 0;
			}

			else if (ch == '{'){
				state = 0;
				cout << "{ : " << ch << endl;
				//	myFile << "{ : "<< ch  << endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;
				lexeme = "";
				i = 0;
			}

			else if (ch == '!'){
				state = 0;
				cout << "! : " << ch << endl;
				myFile << "! : " << ch << endl;
				cout << endl;
				myFile << endl;

				if (str[j] == '='){
					cout << "= : " << str[j] << endl;
					myFile << "= : " << str[j] << endl;
					cout << "Relop" << endl;
					//	myFile << "Relop"<< endl;
					cout << endl;
					myFile << endl;
					j++;
				}
				lexeme = "";
				i = 0;
			}

			else if (ch == '}'){
				state = 0;
				cout << "} : " << ch << endl;
				//	myFile << "} : "<< ch << endl;
				myFile << ch << endl;
				cout << endl;
				myFile << endl;
				lexeme = "";
				i = 0;
			}

			else if (ch == '<'){
				state = 0;
				cout << "< : " << ch << endl;
				//	myFile << "< : "<< ch <<endl;
				myFile << ch << endl;
				cout << endl;
				//	myFile<<endl;

				if (str[j] == '='){
					cout << "= : " << str[j] << endl;
					//	myFile << "= : "<< str[j]<< endl;
					myFile << ch << endl;
					cout << "Relop" << endl;
					//	myFile << "Relop"<< endl;
					cout << endl;
					//	myFile<<endl;
					j++;
				}
				lexeme = "";
				i = 0;
			}

			else if (ch == '>'){
				state = 0;
				cout << "> : " << ch << endl;
				myFile << "> : " << ch << endl;
				cout << endl;
				//	myFile<<endl;

				if (str[j] == '='){
					cout << "= : " << str[j] << endl;
					//	myFile << "= : "<< str[j]<< endl;
					myFile << ch << endl;
					cout << "Relop" << endl;
					//	myFile << "Relop"<< endl;
					cout << endl;
					//	myFile<<endl;
					j++;
				}
				lexeme = "";
				i = 0;
			}

			else if (is_delimiter(ch)){
				state = 0;
				/*	cout<<"Delim"<<endl;
				myFile<<"Delim"<<endl;
				cout<<endl;
				myFile<<endl;*/
				lexeme = "";
				i = 0;
			}

			else{
				cout << "Error" << endl;
				myFile << "Error" << endl;
				cout << endl;
				myFile << endl;
				lexeme = "";
				i = 0;
			}
			break;

		case 1:
			if (lexeme == "while" || lexeme == "if" || lexeme == "else" || lexeme == "return" || lexeme == "break" || lexeme == "continue" || lexeme == "int" || lexeme == "float" || lexeme == "void" || lexeme == "main" || lexeme == "for"){
				cout << "Keyword : " << lexeme << endl;
				//myFile << "Keyword : " << lexeme << endl;
				myFile << lexeme << endl;

				cout << endl;
				//	myFile<<endl;

				state = 0;
				i = 0;
				lexeme = "";
			}

			else if ((is_letter(ch) || is_digit(ch)) || ch == '_'){
				state = 1;
			}

			else if (!(is_letter(ch)) || !(is_digit(ch)) || !(ch == '_')){
				//	identifier(i,j,lexeme);
				cout << "Identifier : ";
				//	myFile << "Identifier : ";
				//	myFile << ch<<endl;
				myFile << "id";
				for (int m = 0; m<i - 1; m++){
					cout << lexeme[m];
					//myFile<<lexeme[m];
				}

				cout << endl;
				cout << endl;
				myFile << endl;
				//	myFile<<endl;

				lexeme = "";
				j--;
				i = 0;
				state = 0;
				//lexeme=lexeme[i-1];
			}


			/*else{

			cout << "Identifier: " << lexeme << endl;
			lexeme = "";
			state = 0;
			}*/

			break;

		case 3:
			if (is_digit(ch)){
				state = 3;
			}

			else if (ch == '.'){
				state = 4;
			}

			else{
				if (!is_digit(ch)){
					cout << "Number : ";
					//	myFile << "Number : ";
					myFile << "num";
					for (int m = 0; m<i - 1; m++){
						cout << lexeme[m];
						//	myFile<<lexeme[m];
					}

					cout << endl;
					cout << endl;
					//	myFile<<endl;
					myFile << endl;

					lexeme = "";
					j--;
					i = 0;
					state = 0;
				}

				/*	state = 0;
				cout << "Number: " << lexeme << endl;
				lexeme = "";
				i=0;
				}*/
			}
			break;

		case 4:
			if (ch == 'E'){
				state = 5;
			}

			else if (!is_digit(ch)){
				cout << "Number : ";
				//	myFile << "Number : ";
				for (int m = 0; m<i - 1; m++){
					cout << lexeme[m];
					//		myFile<<lexeme[m];
				}

				cout << endl;
				cout << endl;
				//	myFile<<endl;
				myFile << endl;

				lexeme = "";
				j--;
				i = 0;
				state = 0;
			}
			break;

		case 5:

			if (/*ch=='+'||*/ch == '-'){
				state = 6;
			}

			else if (!is_digit(ch)){
				cout << "Number : ";
				//	myFile << "Number : ";
				for (int m = 0; m<i - 1; m++){
					cout << lexeme[m];
					//	myFile<<lexeme[m];
				}

				cout << endl;
				cout << endl;
				//	myFile<<endl;
				myFile << endl;

				lexeme = "";
				j--;
				i = 0;
				state = 0;
			}
			break;

		case 6:

			if (is_digit(ch)){
				state = 7;
			}

			break;

		case 7:

			if (is_digit(ch)){
			}

			else if (!is_digit(ch)){
				cout << "Number : ";
				//	myFile << "Number : ";

				for (int m = 0; m<i - 1; m++){
					cout << lexeme[m];
					myFile << lexeme[m];
				}

				cout << endl;
				cout << endl;
				//	myFile<<endl;
				myFile << endl;

				lexeme = "";
				j--;
				i = 0;
				state = 0;
			}
			break;
		}
	}
}