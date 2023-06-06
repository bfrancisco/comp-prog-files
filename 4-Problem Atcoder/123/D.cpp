#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int x, y, z, K;
ll A[1000], B[1000], C[1000];
set<tuple<int, int, int>> bank;
vector<ll> sums;
int a,b,c;

void rb(int i, int j, int k){
    if (bank.find(make_tuple(i,j,k)) != bank.end()) return;
    // cout << i << " " << j << " " << k << " : " << A[i] + B[j] + C[k] << endl;
    bank.insert(make_tuple(i,j,k));
    sums.push_back(A[i] + B[j] + C[k]);

    if (i+1 < a){
        rb(i+1,j,k);
    }
    if (j+1 < b){
        rb(i,j+1,k);
    }
    if (k+1 < c){
        rb(i,j,k+1);
    }
}

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

    int thresh = 57;
    a = x, b = min(y, thresh), c = min(z, thresh);
    rb(0,0,0);
    a = min(x, thresh), b = y;
    rb(0,0,0);
    b = min(y, thresh), c = z;
    rb(0,0,0);

    sort(sums.begin(), sums.end(), greater<ll>());

    for (int i = 0; i < K; i++){
        cout << sums[i] << endl;
    }
    


    return 0;
}