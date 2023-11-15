#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;

ll mod(ll x){
    return (x%MOD+MOD) % MOD;
}

struct Matrix {
    ll a[2][2];
    Matrix() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                a[i][j] = 0;
            }
        }
    }
    Matrix operator *(Matrix other) {
        Matrix product = Matrix();
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < (2); j++) {
                for(int k = 0; k < (2); k++) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                    product.a[i][k] = mod(product.a[i][k]);
                }
            }
        }
        return product;
    }
};
Matrix expo_power(Matrix a, long long n) {
    Matrix res = Matrix();
    res.a[0][0] = res.a[1][1] = 1;
    while(n) {
        if(n % 2) {
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll a, b, n, x;
    cin >> a >> b >> n >> x;
    Matrix m;
    m.a[0][0] = a;
    m.a[0][1] = b;
    m.a[1][0] = 0;
    m.a[1][1] = 1;
    Matrix res = expo_power(m, n);
    ll ans = mod(mod(res.a[0][0] * x) + res.a[0][1]);
    cout << ans << endl;

    return 0;
}