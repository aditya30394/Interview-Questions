/*
Write an Efficient Method to Check if a Number is Multiple of 3

Geeksforgeeks link - https://www.geeksforgeeks.org/write-an-efficient-method-to-check-if-a-number-is-multiple-of-3/
 */
import static java.lang.Math.abs;

public class IsMultipleOf3 {
    static boolean IsNMultipleOf3(int n)
    {
        if(n<0)
            n=-n;
        if(n==0)
            return true;
        if(n==1)
            return false;

        int odd=0;
        int even=0;
        while(n!=0)
        {
            if((n&1)!=0)
                ++odd;
            n=n>>1;
            if((n&1)!=0)
                ++even;
            n=n>>1;
        }
        return IsNMultipleOf3(abs(odd-even));
    }

    public static void main(String[] args)
    {
        System.out.println(IsNMultipleOf3(0));
        System.out.println(IsNMultipleOf3(17));
        System.out.println(IsNMultipleOf3(18));
        System.out.println(IsNMultipleOf3(9987501));
        System.out.println(IsNMultipleOf3(546981));
    }
}
