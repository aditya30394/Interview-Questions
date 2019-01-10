/*
121. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

// using max difference approach

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
        {
            return 0;
        }
        
        int min_price=INT_MAX;
        int max_profit=0;
        
        for(int i=0;i<n;++i)
        {
            if(min_price>prices[i])
            {
                min_price=prices[i];
            }
            else if(max_profit<prices[i]-min_price)
            {
                max_profit = prices[i]-min_price;
            }
        }
        return max_profit;
    }
};

// Kadane's algorithm

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int max_profit_till_now=0;
        int max_profit=0;
        
        for(int i=1;i<n;++i)
        {
            max_profit_till_now=max(0,max_profit_till_now+prices[i]-prices[i-1]);
            max_profit = max(max_profit,max_profit_till_now);
        }
        return max_profit;
    }
};