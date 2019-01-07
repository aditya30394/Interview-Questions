/*
 * Complete the 'calculateTotalRotorConfiguration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER rotorCount
 *  2. INTEGER minRotorValue
 *  3. INTEGER maxRotorValue
 */
int gcd(int a, int b) 
{ 
    return b ? gcd(b, a % b) : a; 
} 
  
int calculateTotalRotorConfiguration(int rotorCount, int minRotorValue, int maxRotorValue) {
    int left = minRotorValue ; 
    int right = maxRotorValue; 
    map<int,int> m;
    int mod = 1e9+7;
    long long ans = 0; 
    for (int i = left; i <= right; i++) 
    { 
        for (int j = left; j <= right; j++) 
            {
                if (i==1&&j==1||(i!=j&&gcd(i, j) == 1)) 
                {
                    m[i]++;
                }
            }
    }
    for(auto i:m)
    {
        long long t=1;
        for(int j=0;j<rotorCount-1;j++)
        {
            t*=((i.second)%mod);
            t=t%(mod);
        }
        ans+=t;
        ans=ans%mod;
    }
    int ans1=ans;
    return ans1; 
}

