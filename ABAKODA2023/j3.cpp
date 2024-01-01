#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


#define MAXN 50000001
#define sqN 7075
int N, k;
ll expo[sqN][26]; // n**e == exp[n][e]. n==0, n==1, exp[n][e] >= MAXN are garbage

void precompute_power(){
    for (int e = 0; e < 26; e++){
        expo[1][e] = 1;
    }
    for (int i = 2; i < sqN; i++){
        expo[i][0] = 1;
        for (int e = 1; expo[i][e-1] < MAXN; e++){
            expo[i][e] = expo[i][e-1] * (ll)i;
        }
    }
}

int bsearch(int n){
    int l = 1;
    int r = sqN;
    while (r-l > 1){
        int m = (l+r)/2;
        if (expo[m][k] <= n){
            l = m;
        }
        else if (expo[m][k] > n){
            r = m;
        }
    }
    return l;
}

int jolly(int n){
    if (k > 25) return 1;
    int d = bsearch(n); //maxd
    for (; d > 0; d--){
        if (n % d == 0 && n % expo[d][k] == 0){
            return d;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> k;
    for (int i = 0; i < sqN; i++)
        for (int j = 0; j < 26; j++)
            expo[i][j] = 1000000000000;
    precompute_power();

    int ans = 0;
    for (int n = N; n >= 1; n--){
        ans += jolly(n);
        cout << n << " " << jolly(n) << endl;
    }
    cout << ans << endl;
    
    return 0;
}