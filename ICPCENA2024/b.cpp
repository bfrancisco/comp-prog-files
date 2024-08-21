#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

const int MAXN = 1000, MAXM = 1000, MAXK = 100;
int N, M, K;
double s;
vector<double> pnts, cumu, squa;
double dp[MAXN+MAXM+1][MAXK+1];

double f(int l, int r){
    double z = r-l+1;
    double xi = cumu[r] - cumu[l-1];
    double x2 = squa[r] - squa[l-1];
    double xb = xi / z;
    double y = (s/2) * (s/2) * z;

    return x2 - xb*(double)2*xi + z*xb*xb + y;
}

void opt(int pi, int k, double cur){
    if (k == K){
        dp[pi][k] = cur + (pi < N+M ? f(pi+1, N+M) : 0);
        return;
    }

    for (int i = pi+1; i <= N+M; i++){
        opt(i, k+1, f(pi+1, i));
    }
}

int main(){
    cin >> N >> M >> K >> s;
    pnts.assign(N+M+1, 0);
    cumu.assign(N+M+1, 0);
    squa.assign(N+M+1, 0);
    for (int i = 1; i <= N+M; i++){
        cin >> pnts[i];
    }
    sort(pnts.begin(), pnts.end());

    for (int i = 1; i <= N+M; i++){
        cumu[i] = cumu[i-1] + pnts[i];
        squa[i] = squa[i-1] + pnts[i]*pnts[i];
    }

    // for (int i = 1; i <= N+M; i++) cout << pnts[i] << " "; cout << endl;
    // for (int i = 1; i <= N+M; i++) cout << cumu[i] << " "; cout << endl;
    // for (int i = 1; i <= N+M; i++) cout << squa[i] << " "; cout << endl;

    // cout << setprecision(10) << f(1, 3) + f(4, 8) << endl;
    memset(dp, 1e9, sizeof(dp));
    opt(0, 1, 0);

    double ans = 1e9;
    for (int i = 1; i <= N+M; i++){
        ans = min(ans, dp[i][K]);
    }
    cout << setprecision(10) << ans << endl;


    return 0;
}