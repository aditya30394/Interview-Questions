void calculateRecursive(int n, int &m, int &result,
                        vector<int> &bundleQuantities, vector<int> &bundleCosts,
                        int position, int count)

{

  if (position == m || n == 0)

  {

    if (count > result)

      result = count;

    return;
  }

  for (int i = 0; i <= n / bundleCosts[position]; i++)

  {

    calculateRecursive(n - i * bundleCosts[position], m, result,
                       bundleQuantities, bundleCosts, position + 1,
                       count + i * bundleQuantities[position]);
  }
}

int budgetShopping(int n, vector<int> bundleQuantities, vector<int> bundleCosts) {
  // base cases
  int m = bundleCosts.size();
   if (n == 0 || m == 0 || bundleCosts.size() == 0 || bundleQuantities.size() == 0 || bundleQuantities.size() != bundleCosts.size())
      return 0;

  int result = 0;

  calculateRecursive(n, m, result, bundleQuantities, bundleCosts, 0, 0);

  return result;
}