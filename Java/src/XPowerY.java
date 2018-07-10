/*
 * Given two integers x and n, write a function to compute x^n.
 *
 * Geeksforgeeks - https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
 * */
public class XPowerY {
    /* Recursive Function to calculate x raised to the power n in O(log n)*/
    public float PowerRecursive(float x, int n) {
        if (n == 0) {
            return 1;
        }
        float temp = PowerRecursive(x, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            if (n > 0) {
                return x * temp * temp;
            } else {
                return (temp * temp) / x;
            }
        }
    }

    /* Iterative Function to calculate x raised to the power y in O(log y)*/
    public long PowerIterative(int x, int y) {
        long ans = 1;
        while (y > 0) {
            // If y is odd, multiply x with result
            if (y % 2 == 1) {
                ans = ans * x;
            }
            // y must be even now
            y = y >> 1; // y = y/2
            x = x * x; // x = x*2
        }
        return ans;
    }

    public static void main(String[] args) {
        XPowerY test = new XPowerY();
        System.out.println(test.PowerRecursive(2, -3));
        System.out.println(test.PowerRecursive(3.8f, -5));
        System.out.println(test.PowerRecursive(5.0f, 5));
        System.out.println(test.PowerIterative(-2, 3));
        System.out.println(test.PowerIterative(3, 4));
    }
}

