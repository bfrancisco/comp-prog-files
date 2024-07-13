#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    vector<int> L(N+1), R(N+1);
    L[0] = 0;
    R[0] = 0;
    for (int i = 0; i < N; i++){
        L[i+1] = a[i] + L[i];
    }
    for (int i = N-1; i >= 0; i--){
        R[N-i] = a[i] + R[N-i-1];
    }
    
    // for (auto e : L) cout << e << " "; cout << endl;
    // for (auto e : R) cout << e << " "; cout << endl;
    while (Q--){
        int x; cin >> x;
        bool good = false;
        for (int i = 0; i <= N; i++){
            int y = x - L[i];
            // cout << y << endl;
            if (y < 0) continue;
            int ind = lower_bound(R.begin(), R.end(), y) - R.begin();

            if (0 <= ind && ind <= N && R[ind] == y && ind <= N-i){
                cout << "Yes" << "\n";
                good = true;
                break;
            }
        }
        if (!good){
            cout << "No" << "\n";
        }
    }

    


    return 0;
}