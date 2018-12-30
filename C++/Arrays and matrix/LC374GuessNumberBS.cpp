/*
374. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example :

Input: n = 10, pick = 6
Output: 6
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
       
        int l=1,h=n,m=0;
        
        while(l<=h)
        {
            m=l + (h - l) / 2;
            int ans = guess(m);
            if(ans==0)
            {
                return m;
            }
            else if(ans==-1)
            {
                h=m-1;
            }
            else
            {
                l=m+1;
            }
            
        }
        return -1;
        
    }
};