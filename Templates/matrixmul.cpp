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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int ar, ac, br, bc;
    cin >> ar >> ac >> br >> bc;
    vvll A(ar, vll(ac)), B(br, vll(bc));
    for (int i = 0; i < ar; i++)
        for (int j = 0; j < ac; j++)
            cin >> A[i][j];

    for (int i = 0; i < br; i++)
        for (int j = 0; j < bc; j++)
            cin >> B[i][j];       

    vvll AB = multiply(A, B);
    for (int i = 0; i < ar; i++){
        for (int j = 0; j < ac; j++)
            cout << AB[i][j] << " ";
        cout << endl;
    }    
    return 0;
}