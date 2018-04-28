#include <iostream>


using namespace std;

int isMultipleOf3(int n){
	if(n<0)
	n=-n;
	
	if(n==0)
	return 1;
	if(n==1)
	return 0;
	int odd=0;
	int even=0;
	while(n){
		if(n & 1)
		 ++odd;
		n = n>>1;
		if(n & 1)
		 ++even;
		n = n>>1;

	}

	return (isMultipleOf3(abs(odd-even)));

}

int main(){

cout<<isMultipleOf3(298431)<<endl;
cout<<isMultipleOf3(331)<<endl;

}
