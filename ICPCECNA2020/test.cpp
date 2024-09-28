#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
ll MOD = 1000000007;

ll mod(ll x){
    return (x%MOD+MOD) % MOD;
}

vvll multiply(vvll& A, vvll& B){
    int p = A.size(), q = A[0].size(), r = B[0].size();
    vvll AB(p, vll(r));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < r; k++){
                AB[i][k] += mod(A[i][j] * B[j][k]);
                AB[i][k] = mod(AB[i][k]);
            }
    return AB;
}

int main(){
    vector<vector<ll>> a = {{2, 3}, {4, 5}};
    vector<vector<ll>> b = {{2, 3}};
    vector<vector<ll>> mul = multiply(a, b);

    for (auto row : mul){
        for (auto e : row) cout << e << " ";
        cout << endl;
    }


    return 0;
}