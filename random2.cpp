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
    int ar=2, ac=2, br=2, bc=2;
    // cin >> ar >> ac >> br >> bc;
    int MN = -20, MX = 20;
    vvll A(2, vll(2)), B(2, vll(2));
    
    for (int i = MN; i <= MX; i++)
        for (int j = MN; j <= MX; j++)
            for (int k = MN; k <= MX; k++)
                for (int l = MN; l <= MX; l++){
                    A[0][0] = i;
                    A[0][1] = j;
                    A[1][0] = k;
                    A[1][1] = l;
                    vvll AA = multiply(A, A);
                    set<int> bank;
                    for (int i = 0; i < 2; i++)
                        for (int j = 0; j < 2; j++)
                            bank.insert(AA[i][j]);
                    if (bank.size() == 1 && AA[0][0] == 4){
                        for (int i = 0; i < ar; i++){
                            for (int j = 0; j < ac; j++)
                                cout << AA[i][j] << " ";
                            cout << endl;
                        }
                        cout << endl;
                    }
                }
    return 0;
}
