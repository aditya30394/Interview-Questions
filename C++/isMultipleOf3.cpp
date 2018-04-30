/*
Write an Efficient Method to Check if a Number is Multiple of 3

Geeksforgeeks link - https://www.geeksforgeeks.org/write-an-efficient-method-to-check-if-a-number-is-multiple-of-3/
*/

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
    
    while(n)
    {
        if(n & 1)
         ++odd;
        
        n = n>>1;
        if(n & 1)
         ++even;
        
        n = n>>1;
    }
    return (isMultipleOf3(abs(odd-even)));
}

int main()
{

    cout<<isMultipleOf3(298431)<<endl;
    cout<<isMultipleOf3(331)<<endl;
    cout<<isMultipleOf3(256431)<<endl;
    cout<<isMultipleOf3(3313561)<<endl;
    cout<<isMultipleOf3(29843458991)<<endl;
    cout<<isMultipleOf3(879695331)<<endl;
}
