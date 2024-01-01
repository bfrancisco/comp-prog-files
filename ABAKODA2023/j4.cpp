#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


#define MAXN 50000001
#define sqN 7075
int N, k;
ll expo[sqN][26]; // n**e == exp[n][e]. n==0, n==1, exp[n][e] >= MAXN are garbage
vector<int> jollies;

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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < sqN; i++)
        for (int j = 0; j < 26; j++)
            expo[i][j] = 1000000000000;
    precompute_power();

    cin >> N >> k;
    jollies.assign(N+1, 1);
    if (k > 25){
        cout << N << endl;
        return 0;
    }

    for (int d = 2; d < sqN; d++){
        if (expo[d][k] > N) continue;    
        int dk = expo[d][k];
        for (int i = expo[d][k]; i <= N; i += dk){
            jollies[i] = d;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++){
        ans += jollies[i];
    }
    cout << ans << endl;
    
    return 0;
}