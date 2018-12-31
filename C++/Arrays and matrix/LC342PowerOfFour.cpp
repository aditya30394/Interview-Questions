/*
LC342 Power if Four

We know from Binomial Theroem that (1+X)^n = C(n,0) + C(n,1)*X + C(n,2)*X^2 + C(n,3)*X^3 +.........+ C(n,n)*X^n
Put X=3, we get 4^n = 1 + C(n,1)*3 + C(n,2)*3^2 + C(n,3)*3^3 +.........+ C(n,n)*3^n
by moving 1 left side, we get 4^n - 1 = C(n,1)*3 + C(n,2)*3^2 + C(n,3)*3^3 +.........+ C(n,n)*3^n
i.e (4^n - 1) = 3 * [ C(n,1) + C(n,2)*3 + C(n,3)*3^2 +.........+ C(n,n)*3^(n-1) ]
This implies that (4^n - 1) is multiple of 3.

*/

class Solution {
public:
    bool isPowerOfFour(int n) {
     
        return n>0 && ((n&(n-1))==0) && ((n-1)%3==0);
    }
};