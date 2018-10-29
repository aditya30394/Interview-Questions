// Geeks for geeks link - https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
#include <iostream>

uint64_t FibRecursive(uint64_t n);
uint64_t FibIterative(uint64_t n);
uint64_t FibEfficient(uint64_t n);
void power(int F[2][2], uint64_t n);
void multiply(int F[2][2], int M[2][2]);

int main()
{
    std::cout<<FibRecursive(9)<<std::endl;
    std::cout<<FibIterative(9)<<std::endl;
    std::cout<<FibEfficient(9)<<std::endl;
    return 0;
}

void power(int F[2][2], uint64_t n)
{
    if(n<=1)
        return;
    int M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0)
       multiply(F, M);
}

void multiply(int F[2][2], int M[2][2])
{
    int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
//O(n^2)
uint64_t FibRecursive(uint64_t n)
{
    if(n<=1)
        return n;
    else
        return FibRecursive(n-1) + FibRecursive(n-2);
}

//O(n)
uint64_t FibIterative(uint64_t n)
{
    if(n<=1)
        return n;
    uint64_t a=0,b=1,c;
    for(uint64_t i=2;i<=n;++i)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}

//O(log n)
uint64_t FibEfficient(uint64_t n)
{
    if(n==0)
        return n;
    int F[2][2] = {{1,1},{1,0}};
    power(F,n-1);
    return F[0][0];
}
