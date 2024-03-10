#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct fraction {
    int a, b;

    fraction(int x, int y){
        int gcd = __gcd(x, y);
        a = x/gcd;
        b = y/gcd;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int d, i, j;
    for (d = 1; d <= 3; d++){
        vector<int> done(n);
        for (i = 0; i < n; i++){
            if (done[i]) continue;
            for (j = 0; j < n; j++){
                if (i == j || done[j]) continue;

                fraction slope = fraction(y[j]-y[i], x[j]-x[i]);
                
            }
        }
    }    

    return 0;
}