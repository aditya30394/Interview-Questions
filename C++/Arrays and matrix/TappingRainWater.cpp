/*
Sliding window problem - front and back approach

An element of array can store water if there are higher bars on left and right. We can find amount of 
water to be stored in every element by finding the heights of bars on left and right sides. The idea 
is to compute amount of water that can be stored in every element of array. For example, consider the
array {3, 0, 0, 2, 0, 4}, we can store two units of water at indexes 1 and 2, and one unit of water at index 2.

A Simple Solution is to traverse every array element and find the highest bars on left and right sides. Take 
the smaller of two heights. The difference between smaller height and height of current element is the amount
 of water that can be stored in this array element. Time complexity of this solution is O(n2).

An Efficient Solution is to prre-compute highest bar on left and right of every bar in O(n) time. 
Then use these pre-computed values to find the amount of water in every array element. Below is C++ implementation of this solution.

*/



// C++ program to find maximum amount of water that can 
// be trapped within given set of bars. 
// Space Complexity : O(1) 

#include<iostream> 
using namespace std; 



/*
An Efficient Solution is to prre-compute highest bar on left and right of every bar in O(n) time. 
Then use these pre-computed values to find the amount of water in every array element. Below is C++ implementation of this solution.
*/

int findWater(int arr[], int n) 
{ 
	int water=0, left_max=0, right_max=0, l=0, h=n-1;
    
    while(l<=h)
    {
        if(arr[l]<arr[h])
        {
            if(arr[l]>left_max)
            {
                left_max=arr[l];
            }
            water+=left_max - arr[l];
            ++l;
        }
        else
        {
            if(right_max<arr[h])
            {
                right_max=arr[h];
            }
            water+= right_max - arr[h];
            --h;
        }
    }
    return water;
} 

int findWaterLessEfficient1(int a[], int n) 
{ 
    int water=0;
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0]=a[0];
    right[n-1]=a[n-1];
    // compressed in one loop
    for(int i=1;i<n;++i)
    {
        left[i]= max(left[i-1], a[i]);
        right[n-1-i] = max(right[n-1-i+1],a[n-1-i]);
    }
    
    for(int i=0;i<n;++i)
    {
        water+=min(left[i],right[i]) - a[i];
    }
    
    
    return water;
}

int findWaterLessEfficient12(int a[], int n) 
{ 
    int water=0;
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0]=a[0];
    right[n-1]=a[n-1];
    // compressed in one loop
    for(int i=1;i<n;++i)
    {
        left[i]= max(left[i-1], a[i]);
    }
    
    for(int i=n-2;i>=0;--i)
    {
        right[i]=max(right[i+1], a[i]);
    }
    
    for(int i=0;i<n;++i)
    {
        water+=min(left[i],right[i]) - a[i];
    }
    
    
    return water;
}

int main() 
{ 
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n); 
} 
