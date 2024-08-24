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

    for (int i = 1; i <= N+M; i++){
        dp[i][1] = f(1, i);
        for (int k = 2; k <= K; k++){
            dp[i][k] = dp[i][1];
            for (int j = 1; j < i; j++){
                dp[i][k] = min(dp[i][k], dp[j][k-1] + f(j+1, i));
            }
        }
    }

    cout << setprecision(10) << dp[N+M][K] << endl;


    return 0;
}