#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> R,G,B;
    map<int, int> idR, idG, idB;
    for (int i = 0; i < n; i++){
        int r,g,b,id;
        cin >> r >> g >> b >> id;
        id = -id;
        R.push_back({r, id});
        G.push_back({g, id});
        B.push_back({b, id});
        *idtoR[id] = &R[i];
        *idtoG[id] = &G[i];
        *idtoB[id] = &B[i];
    }

    sort(R.begin(), R.end());
    sort(G.begin(), G.end());
    sort(B.begin(), B.end());


    cout << *(lower_bound(R.begin(), R.end(), 360))

    return 0;
}