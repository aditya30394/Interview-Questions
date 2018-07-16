/***
 * Given 3 numbers {1, 3, 5}, we need to tell
 * the total number of ways we can form a number 'N'
 * using the sum of the given three numbers.
 * (allowing repetitions and different arrangements).
 * */
package DynamicProgramming;

import java.util.Arrays;

public class TotalWaysToFormN
{
    int solve(int n)
    {
        int ans[] = new int[n+1];
        Arrays.fill(ans,0);
        ans[0]=1;
        for (int i = 1; i <= n; ++i)
        {
            ans[i] = ans[i] + ans[i-1];
            if(i-3>=0)
            {
                ans[i] = ans[i] + ans[i-3];
            }
            if(i-5>=0)
            {
                ans[i] = ans[i] + ans[i-5];
            }
        }
        return ans[n];
    }

    public static void main(String [] args)
    {
        TotalWaysToFormN solver = new TotalWaysToFormN();
        System.out.printf("N is %d and Number of ways is %d\n", 0, solver.solve(0));
        System.out.printf("N is %d and Number of ways is %d\n", 1, solver.solve(1));
        System.out.printf("N is %d and Number of ways is %d\n", 2, solver.solve(2));
        System.out.printf("N is %d and Number of ways is %d\n", 5, solver.solve(5));
        System.out.printf("N is %d and Number of ways is %d\n", 6, solver.solve(6));
        System.out.printf("N is %d and Number of ways is %d\n", 12, solver.solve(12));
        System.out.printf("N is %d and Number of ways is %d\n", 19, solver.solve(19));
    }
}
