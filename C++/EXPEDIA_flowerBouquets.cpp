int flowerBouquets(int p, int q, string s) {
    int n = s.length();
    vector<int>dp(n+1,0);
    // if we have 01 or 10 we have a chance of forming a combination
    if(n<2)
        return 0;

    if ((s[0] == '0' && s[1] == '1') || (s[0] == '1' && s[1] == '0'))
    {
      dp[1] = q;
    }
    for(int i=2; i<n;i++)
    {
        if (s[i] == '1') 
        {
            // check if preceeding is zero, if so, then that is a combination
            if (s[i - 1] == '0') {
            // dp[i-1] for case of not including
            // q+dp[i-2] for case of including
            dp[i] = max(dp[i - 1], q + dp[i - 2]);
            }
            else 
            {
                
            dp[i] = dp[i - 1];
            }
        }
        else
        {
            if (s[i - 1] == '0' && s[i - 2] == '0') 
            {
            // 000 combination can be made
            dp[i] = max(dp[i - 3] + p, dp[i - 1]);
            } else if (s[i - 1] == '1') 
            {
                dp[i] = max(dp[i - 2] + q, dp[i - 1]);
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
    }
    return dp[n-1];
}