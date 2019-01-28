/*
50. Pow(x, n)
Medium

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/

//EPI solution
class Solution {
public:
    double myPow(double x, int y) {
      double result = 1.0;
      long long power = y;
        if(y<0)
        {
            power=-power;
            x = 1.0/x;
        }
        while(power)
        {
            if(power&1)
            {
                result = result*x;
            }
            power>>=1;
            x*=x;
        }
        return result;
    }
};

public class Solution {
    public double pow(double x, int n) {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
}