/***
https://www.spoj.com/problems/COINS/
In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?
Editorial: https://www.hackerearth.com/practice/algorithms/dynamic-programming/state-space-reduction/practice-problems/algorithm/bytelandian-gold-coins/editorial/
***/
#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

map<int, long long> dp;

long long MaxValueOfCoin(long long int n){
    if(n==0) return 0;

    if(dp[n]!=0) return dp[n];

    long long aux=MaxValueOfCoin(n/2)+MaxValueOfCoin(n/3)+MaxValueOfCoin(n/4);

    dp[n] = std::max(n, aux);
    return dp[n];
}

int main() {
    long long n = 12;
    printf("N is %lld and answer is %lld\n", n, MaxValueOfCoin(n));
    n = 12345;
    printf("N is %lld and answer is %lld\n", n, MaxValueOfCoin(n));
    n = 4512345;
    printf("N is %lld and answer is %lld\n", n, MaxValueOfCoin(n));
    n = 98781245;
    printf("N is %lld and answer is %lld\n", n, MaxValueOfCoin(n));
    n = 542768;
    printf("N is %lld and answer is %lld\n", n, MaxValueOfCoin(n));
	return 0;
}
