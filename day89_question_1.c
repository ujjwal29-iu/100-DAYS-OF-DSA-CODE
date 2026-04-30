// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

// Input Format
// n m
// n space-separated integers representing pages in books

// Output Format
// Print the minimum possible value of the maximum pages assigned to any student.

// Sample Input
// 4 2
// 12 34 67 90

// Sample Output
// 113

// Explanation
// One optimal allocation is:
// Student 1: 12 + 34 + 67 = 113
// Student 2: 90

#include <stdio.h>

int can(int a[], int n, int m, int maxp){
    int students=1,sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>maxp) return 0;
        if(sum+a[i]>maxp){
            students++; sum=a[i];
        } else sum+=a[i];
    }
    return students<=m;
}

int main(){
    int n,m,a[100];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int l=0,r=0,ans=0;
    for(int i=0;i<n;i++) r+=a[i];
    while(l<=r){
        int mid=(l+r)/2;
        if(can(a,n,m,mid)){ ans=mid; r=mid-1; }
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}