/*
 * Given two integers x and n, write a function to compute x^n.
 *
 * Geeksforgeeks - https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
 * */

 #include <iostream>
 using namespace std;

 /* Recursive Function to calculate x raised to the power n in O(log n)*/
float PowerRecursive(float x, int n)
{
    if(n==0)
    {
        return 1;
    }
    float temp = PowerRecursive(x, n/2);
    if(n%2==0)
    {
        return temp*temp;
    }
    else
    {
        if(n>0)
        {
            return x*temp*temp;
        }
        else
        {
            return (temp*temp)/x;
        }
    }
}

/* Iterative Function to calculate x raised to the power y in O(log y)*/
int PowerIterative(int x, uint32_t y)
{
    int ans = 1;
    while(y>0)
    {
        // If y is odd, multiply x with result
        if(y&1)
        {
            ans=ans*x;
        }
        // y must be even now
        y=y>>1; // y = y/2
        x=x*x;
    }
    return ans;
}

 int main()
 {
     cout<<PowerRecursive(2,4)<<endl;
     cout<<PowerRecursive(2,-3)<<endl;
     cout<<PowerRecursive(3.53,7)<<endl;
     cout<<PowerIterative(1,2)<<endl;
     cout<<PowerIterative(-2,5)<<endl;
     cout<<PowerIterative(7,3)<<endl;
 }
