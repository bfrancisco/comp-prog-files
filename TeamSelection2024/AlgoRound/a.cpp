#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int N;
double M;
vector<int> X, Y, T;
// vector<pair<int, pair<int, int>>> db;
double DIV = 10000;
// int MXR = 10;

bool can(ll intv){
    double v = (double)intv / DIV;

    // prio: lowest time --> nearest
    vector<tuple<int, double, int, int>> db;
    double x, y;
    for (int i = 0; i < N; i++){
        tuple<int, double, int, int> data(T[i], );
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    X.resize(N);
    Y.resize(N);
    T.resize(N);
    // db.resize(N);
    for (int i = 0; i < N; i++){
        cin >> X[i] >> Y[i] >> T[i];
        // cin >> db[i].second.first >> db[i].second.second >> db[i].first;
    }
    cin >> M;

    // bsearch the velocity
    ll l, r, mid, want;
    // divide by 10000 when computing
    l = 1; // 0.0001
    r = 1e15;

    while (l < r){
        mid = l + (r-l)/2;

        if (can(mid)){
            r = mid;
        }
        else{
            l = mid+1;
            want = mid+1;
        }
    }

    cout << setprecision(5) << (double)want / DIV << endl;



    return 0;
}