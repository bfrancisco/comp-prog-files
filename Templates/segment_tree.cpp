#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int getMid(int s, int e) {return s + (e-s) / 2;}

void updateUtil(int *st, int ss, int se, int i , int diff, int si){
    if (i < ss || i > se) return;

    st[si] = st[si] + diff;
    if (se != ss){
        int mid = getMid(ss, se);
        updateUtil(st, ss, mid, i, diff, 2*si+1);
        updateUtil(st, mid+1, se, i, diff, 2*si+2);
    }
}

void update(int arr[], int * st, int n, int i, int new_val){
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateUtil(st, 0, n-1, i, diff, 0);
}

int getSum(int *st, int ss, int se, int qs, int qe, int si){
    if (qs <= ss && qe >= se)
        return st[si];
    
    if (se < qs || ss > qe)
        return 0;

    int mid = getMid(ss, se);
    return getSum(st, ss, mid, qs, qe, 2*si+1) +
        getSum(st, mid+1, se, qs, qe, 2*si+2);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si){
    if (ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
            constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int *constructST(int arr[], int n){
    int x = (int)(ceil(log2(n)));

    int max_size = 2*(int)pow(2, x) - 1;

    int *st = new int[max_size];

    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}