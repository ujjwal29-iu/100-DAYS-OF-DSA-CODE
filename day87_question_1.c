// Problem Statement
// Implement Binary Search Iterative - Implement the algorithm.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the sorted array or search result

// Example:
// Input:
// 5
// 64 34 25 12 22

// Output:
// 12 22 25 34 64

#include <stdio.h>

int main(){
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int t=a[i]; a[i]=a[j]; a[j]=t;
            }
        }
    }
    int x; scanf("%d",&x);
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==x){ printf("%d",m); return 0; }
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    printf("-1");
    return 0;
}