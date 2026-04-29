// Problem Statement
// Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

// Input Format
// n k
// n space-separated integers representing stall positions

// Output Format
// Print the maximum possible minimum distance between any two cows.

// Sample Input
// 5 3
// 1 2 8 4 9

// Sample Output
// 3

// Explanation
// Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3.

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){ return (*(int*)a-*(int*)b); }

int can(int a[], int n, int k, int dist){
    int count=1,last=a[0];
    for(int i=1;i<n;i++){
        if(a[i]-last>=dist){
            count++; last=a[i];
        }
    }
    return count>=k;
}

int main(){
    int n,k,a[100];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    int l=1,r=a[n-1]-a[0],ans=0;
    while(l<=r){
        int m=(l+r)/2;
        if(can(a,n,k,m)){ ans=m; l=m+1; }
        else r=m-1;
    }
    printf("%d",ans);
    return 0;
}