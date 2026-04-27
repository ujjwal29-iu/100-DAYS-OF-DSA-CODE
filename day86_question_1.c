// Problem Statement
// Find the integer square root of a given non-negative integer using Binary Search.

// Input:
// - First line: an integer n

// Output:
// - Print the integer square root of n

// Examples:
// Input:
// 64

// Output:
// 8

// Input:
// 20

// Output:
// 4

// Input:
// 1

// Output:
// 1

#include <stdio.h>

int main(){
    long long n;
    scanf("%lld",&n);
    long long l=0,r=n,ans=0;
    while(l<=r){
        long long m=(l+r)/2;
        if(m*m<=n){ ans=m; l=m+1; }
        else r=m-1;
    }
    printf("%lld",ans);
    return 0;
}