/*
This program prints out all the possible permutations of a given string.
The function permute() takes the string, starting index, and the ending index as argument.

Time Complexity - O(n*n!)

T(n) = n * (O(1)+T(n-1)+O(1))
     = O(n!)

But std::cout takes O(n) so overall we get O(n*n!) as time complexity
*/

#include<iostream>
using namespace std;
void swap(string &s, int l, int r);
void permute(string &s, int l, int r);

int main(){
	string a("ABCDE");
	permute(a,0, a.length()-1);

	return 0;
}

void swap(string &s, int l, int r){
	char a = s[l];
	s[l]=s[r];
	s[r]=a;
	return;
}

void permute(string &s, int l, int r){
	if(l==r){
		cout<<s<<endl;
	}else{
		for(int i=l; i<=r; ++i){
			swap(s,l,i);
			permute(s,l+1,r);
			swap(s,l,i);
		
		}
	}
}
