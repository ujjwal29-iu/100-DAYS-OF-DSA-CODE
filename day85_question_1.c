// Problem Statement
// Implement Merge Sort - Implement the algorithm.

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

void merge(int a[], int l, int m, int r){
    int i=l,j=m+1,k=0,temp[100];
    while(i<=m && j<=r){
        if(a[i]<a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=m) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    for(i=l,j=0;i<=r;i++,j++) a[i]=temp[j];
}

void mergesort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}