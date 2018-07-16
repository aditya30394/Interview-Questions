/***
 https://www.spoj.com/problems/COINS/
 In Byteland they have a very strange monetary system.

 Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).

 You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

 You have one gold coin. What is the maximum amount of American dollars you can get for it?
 Editorial: https://www.hackerearth.com/practice/algorithms/dynamic-programming/state-space-reduction/practice-problems/algorithm/bytelandian-gold-coins/editorial/
 ***/

package DynamicProgramming;

import java.util.HashMap;

public class BytelandianGoldCoins
{
    private HashMap<Long, Long> map;

    public long MaxValueOfCoin(long n)
    {
        if(n==0)
            return 0;
        if(map.containsKey(n))
            return map.get(n);

        map.put(n, Math.max(n, MaxValueOfCoin(n / 2)
                + MaxValueOfCoin(n / 3)
                + MaxValueOfCoin(n / 4)));
        return map.get(n);
    }

    public BytelandianGoldCoins()
    {
        map = new HashMap<>();
    }
    public static void main(String args[])
    {
        BytelandianGoldCoins coin = new BytelandianGoldCoins();
        System.out.println(coin.MaxValueOfCoin(12));
        System.out.println(coin.MaxValueOfCoin(12345));
        System.out.println(coin.MaxValueOfCoin(4512345));
        System.out.println(coin.MaxValueOfCoin(98781245));
        System.out.println(coin.MaxValueOfCoin(542768));
    }
}

