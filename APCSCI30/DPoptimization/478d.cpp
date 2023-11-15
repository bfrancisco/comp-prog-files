#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll MOD = 1e9 + 7;
int f(int x){
    return x*(x+1)/2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int r, g;
    cin >> r >> g;
    if (r > g) swap(r, g);
    int total = r+g;
    int h = 1;
    while (f(h) <= total) h++;
    h--;
    vector<ll> dp(r+1);
    dp[0] = 1; // 1 way to place 0 reds
    
    

    return 0;
}