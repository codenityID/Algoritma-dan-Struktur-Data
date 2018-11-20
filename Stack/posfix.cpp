#include <iostream>
#include "ADT/stack.h"
using namespace std;

bool isOperand(char c){
	return (
		c == '+' or 
		c == '-' or
		c == '/' or
		c == '*'
	);
}

void printToTop(Stack S){
	for (int i = 1; i <= Top(S); i++)
		cout<<(S).T[i];
}

void posfix(string token){
	//Buat Stack
	Stack S1,S2;
	CreateEmpty(&S1);
	CreateEmpty(&S2);

	char X;
	for (int j = 0; j < token.length(); j++){
		if(isOperand(token[j]))
			Push(&S2,token[j]);
		else{
			if(token[j]==')')
				Pop(&S2,&X),Push(&S1,X);
			else if(token[j]!='(')
				Push(&S1,token[j]);
		}
	}
	printToTop(S1);
}

int main(){
	
	string token;
	cin>>token;
	posfix(token);

}