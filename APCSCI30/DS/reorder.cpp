#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w, n; cin >> h >> w >> n;
    vector<pair<int, int>> pairs(n);
    vector<int> R(n), C(n);

    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        pairs[i] = {a, b};
        R[i] = a; C[i] = b;
    }

    sort(R.begin(), R.end());
    sort(C.begin(), C.end());
    map<int, int> A, B;
    A[R[0]] = 1;
    B[C[0]] = 1;
    for (int i = 1; i < n; i++){
        (R[i-1] == R[i] ? A[R[i]] = A[R[i-1]] : A[R[i]] = A[R[i-1]]+1);
        (C[i-1] == C[i] ? B[C[i]] = B[C[i-1]] : B[C[i]] = B[C[i-1]]+1);
    }

    for (auto [r, c] : pairs){
        cout << A[r] << " " << B[c] << endl;
    }

    
    return 0;
}