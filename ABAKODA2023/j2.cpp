#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int MAXN = 50000001;
int sqN = 7075;
// sqrt(MAXN) ~= 7071
int N, k;
// n**e == exp[n][e]. n==0, n==1, exp[n][e] >= MAXN are garbage
vector<vector<ll>> expo(sqN);

void precompute_power(){
    for (int i = 2; i < sqN; i++){
        // cout << i << endl;
        expo[i].push_back(1); // x**0 = 1
        for (int e = 1; expo[i][e-1] < MAXN; e++){
            expo[i].push_back(expo[i][e-1] * (ll)i);
        }
    }
}

int jolly(int n){
    if (k > 25) return 1;

    int jol = 1;
    for (int d = 2; d*d <= n; d++){
        if ((int)expo[d].size() < k || expo[d][k] > n) break;
        if (n % d == 0 && n % expo[d][k] == 0){
            jol = max(jol, d);
        }
    }
    // cout << n << " " << jol << endl;
    return jol;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> k;
    precompute_power();
    cout << "done" << endl;
    int ans = 0;
    for (int n = N; n >= 1; n--){
        ans += jolly(n);
        // cout << n << endl;
    }
    cout << ans << endl;
    
    return 0;
}