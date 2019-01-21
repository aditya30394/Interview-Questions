/*
123. Best Time to Buy and Sell Stock III
Hard

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

//O(1) space
// Assume you have zero money and are using credit. You want to minimize the credit and maximize the sell
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = numeric_limits<int>::min(), buy2 = numeric_limits<int>::min();
        int sell1 =0, sell2=0;
        
        for(int p:prices)
        {
            buy1 = max(buy1, -p);
            sell1 = max(sell1, buy1+p);
            buy2 = max(buy2, sell1-p);
            sell2 = max(sell2, buy2+p);
        }
        
        return sell2;
        
    }
};


//O(n) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price_so_far = numeric_limits<int>::max(), max_profit=0;
        vector<int>forward;
        
        for(int& p:prices)
        {
            int profit_today = p-min_price_so_far;
            min_price_so_far = min(min_price_so_far, p);
            max_profit = max(max_profit, profit_today);
            forward.push_back(max_profit);
        }
        
        int max_price_so_far = numeric_limits<int>::min();
        
        for(int i=prices.size()-1; i>=0;--i)
        {
            max_price_so_far = max(max_price_so_far, prices[i]);
            max_profit = max(max_profit, max_price_so_far-prices[i]+(i-1>=0?forward[i-1]:0));
        }
        
        return max_profit; 
    }
};

