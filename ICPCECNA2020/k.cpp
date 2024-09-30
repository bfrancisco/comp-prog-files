#include<bits/stdc++.h>
using namespace std;

const int MXN = 5000;
const int MXM = 20;

int n, m;
int dp[MXN][MXM];

int rec(int v, int rem_box){
    
    for (int )
}

int main(){

    cin >> n >> m;
    int mn = 1e9;
    for (int i = 1; i <= n; i++){
        mn = min(mn, rec(i, m-1));
    }
    

    return 0;
}