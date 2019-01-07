/*
 * Complete the 'countSubarrays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY numbers
 *  2. INTEGER k
 */

long countSubarrays(vector<int> numbers, int k) {
        if (k == 0) return 0;
        long long product = 1;
        long count = 0;
        for (long i = 0, j = 0; j < numbers.size(); j++) {
            product *= numbers[j];
            while (i <= j && product > k) {
                product /= numbers[i++];
            }
            count += j - i + 1;
        }
        return count;
    
}

