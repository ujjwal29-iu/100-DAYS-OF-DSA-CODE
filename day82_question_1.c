// Problem Statement
// Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

// Input:
// - First line: integer n representing the size of the array
// - Second line: n space-separated sorted integers
// - Third line: integer x (the target value)

// Output:
// - Print two integers:
//   1) Index of the lower bound of x
//   2) Index of the upper bound of x

// Example:
// Input:
// 7
// 1 2 4 4 4 5 7
// 4

// Output:
// 2 5

// Explanation:
// For the given array [1, 2, 4, 4, 4, 5, 7] and x = 4:
// - The lower bound is at index 2, which is the first occurrence of 4.
// - The upper bound is at index 5, which is the first element greater than 4 (i.e., 5).

#include <stdio.h>

int lower(int a[], int n, int x){
    int l=0,r=n-1,ans=n;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]>=x){ ans=m; r=m-1; }
        else l=m+1;
    }
    return ans;
}

int upper(int a[], int n, int x){
    int l=0,r=n-1,ans=n;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]>x){ ans=m; r=m-1; }
        else l=m+1;
    }
    return ans;
}

int main(){
    int n,x,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&x);
    printf("%d %d", lower(a,n,x), upper(a,n,x));
    return 0;
}