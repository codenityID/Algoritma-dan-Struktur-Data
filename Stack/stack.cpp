#include <iostream>
#include "ADT/stack.h"
using namespace std;


int main(){
	Stack S;
	infotype X;
	CreateEmpty(&S);

	for (int i = 0; i < 7; i++)
		Push(&S,i);

	while(!IsEmpty(S))
		Pop(&S,&X),cout<<X<<endl;

	return 0;

}