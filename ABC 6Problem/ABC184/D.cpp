#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

double dp[110][110][110];

double solve(int a,int b, int c){
    // cout << a << b << c << endl;
    if (dp[a][b][c] > 0) return dp[a][b][c];
    if (a == 100 || b == 100 || c == 100) return 0;
    int denom = a+b+c;
    
    double add = 0;
    add += (solve(a+1,b,c) + 1) * a / denom;
    add += (solve(a,b+1,c) + 1) * b / denom;
    add += (solve(a,b,c+1) + 1) * c / denom;
    dp[a][b][c] = add;

    return add;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a,b,c; cin >> a >> b >> c;
    cout.precision(10);
    cout << fixed << solve(a,b,c);

    return 0;
}