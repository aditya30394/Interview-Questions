/*
135. Candy
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.

*/
/*
To use two variables 'up' and 'down' to count the steps of continuous up and down respectively, and a 'peak' representing the peak before going down. In the below example:

[0, 1, 20, 9, 8, 7]
Scan from left to right, first child is given 1 candy;
the second child is given 2 candies, and up=1;
the third child is given 3 candies, and up=2; peak=2;
the fourth child is given 1 candy, and down=1; and third child still has 3 candies since peak=2;
the fifth child is given 1 candy, and down=2; and the previous child needs 1 more candy now but the third child no need more;
the sixth child is given 1 candy, and down=3; and both the fifth and fourth child needs 1 more candy now, and the peak, the third child need 1 more as well.
*/

// LAZY UPDATE Strategy
public int Candy(int[] ratings) {
    if (ratings.Length == 0) return 0;
    int ret = 1;
    int up = 0, down = 0, peak = 0;
    for (int i = 1; i < ratings.Length; i++) {
        if (ratings[i - 1] < ratings[i]) {
            peak = ++up;
            down = 0;
            ret += 1 + up;
        } else if (ratings[i - 1] == ratings[i])  {
            peak = up = down = 0;
            ret += 1;
        } else {
            up = 0;
            down++;
            ret += 1 + down + (peak >= down ? -1 : 0);
        }
    }

    return ret;
}

// given solution
class Solution {
    private: 
     int count(int n)
     {
         return n*(n+1)/2;
     }
public:
    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1)
        {
            return n;
        }
        
        int old_slope=0, new_slope=0, up=0, down=0, candy=0;
        
        for(int i=1;i<n;++i)
        {
            new_slope = (ratings[i]>ratings[i-2])?1:(ratings[i]<ratings[i-1]?-1:0);
            
            if((old_slope>0 && new_slope==0) || (old_slope<0 && new_slope>=0))
            {
                candy += count(up)+count(down)+max(up,down);
                up=0;
                down=0;
            }
            
            switch(new_slope)
            {
                case 0: ++candy; break;
                case 1: ++up; break;
                case -1: ++down; break;
            }
            old_slope = new_slope;
        }
        candy+= count(up)+count(down)+max(up,down)+1;
        return candy;
    }
};