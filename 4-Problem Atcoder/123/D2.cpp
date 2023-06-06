#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int x, y, z, K;
ll A[1000], B[1000], C[1000];
vector<ll> AB;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> x >> y >> z >> K;
    for (int i = 0; i < x; i++) cin >> A[i];
    for (int i = 0; i < y; i++) cin >> B[i];
    for (int i = 0; i < z; i++) cin >> C[i];

    sort(A, A+x, greater<ll>());
    sort(B, B+y, greater<ll>());
    sort(C, C+z, greater<ll>());

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            AB.push_back(A[i] + B[j]);
        }
    }
    sort(AB.begin(), AB.end(), greater<ll>());

    vector<ll> sums;
    for (int i = 0; i < min(K, x*y); i++){
        for (int j = 0; j < z; j++){
            sums.push_back(AB[i] + C[j]);
        }
    }
    sort(sums.begin(), sums.end(), greater<ll>());

    for (int i = 0; i < K; i++)
        cout << sums[i] << endl;
    


    return 0;
}