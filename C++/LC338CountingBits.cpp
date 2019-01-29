/*
338. Counting Bits
Medium

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/


/*
Explanation:
https://leetcode.com/problems/counting-bits/discuss/119131/C++-Easy-to-Understand-Solution

There is one imporant observation we can make about the number of bits in each number.

Each Power of 2 has exactly only 1 bit. (2 : 0010 , 4: 0100, 8:1000, 16:10000)
Each number after the power of 2 follows a pecular pattern :
0 → 0
1 → 0
2 → 1 + dp[0] Nearest Power of 2
3 → 1 + dp[1] 1 greater than nearest
4 → 1 + dp[0] Nearest
5 → 1+ dp[1] 1 greater than nearest
6 → 1+ dp[2] 2 greater than nearest
7 → 1+ dp[3] 3 greater than nearest
8 → 1+ dp[0] Nearest
9 → 1+ dp[1]
10 → 1+ dp[2]
11 → 1+ dp[3]
12 → 1+ dp[4]
You can easily see the pattern here.

class Solution {
public:
    
    //Function to check whether the number is a power of 2 or now
    inline bool ispowerof2(int n){
        return (n & (n-1)) == 0;
    }
    
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        
        dp[0]=0;
        
        if(num>=1) 
            dp[1]=1;

        int curr=2;
        int nearest=2;
        while(curr<=num)
        {
            //nearest stores the nearest power of 2 less than current element (nearest of 5 is 4, nearest of 13 is 8..)
            nearest = ispowerof2(curr) ? curr  : nearest; 
            dp[curr] = 1 + dp[curr-nearest]; // 1 stands for dp[nearest]
            curr++;
        }
        
        return dp;
    }
};
Just take note of the bool ispowerof2(n) method here. It uses bit operation to find whether it is power of 2. More tricks here. The reference is here
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1,1);
        bits[0]=0;
        
        int nearest = 0;
        for(int i=2;i<=num;++i)
        {
            nearest = ((i&(i-1))==0)? i:nearest;
            bits[i] = 1 +bits[i-nearest];
        }
        return bits;
    }
};


// Another clever solution
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1,1);
        bits[0]=0;
        
        for(int i=2;i<=num;++i)
        {
            bits[i]=bits[i/2];
            if(i&1) ++bits[i];
        }
        return bits;
    }
};