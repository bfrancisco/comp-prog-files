#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    int n = s.size();

    // A T G C
    vector<int> A(n+1, 0), T(n+1, 0), G(n+1, 0), C(n+1, 0);
    for (int i = 0; i < n; i++){
        A[i+1] = A[i] + (s[i] == 'A');
        T[i+1] = T[i] + (s[i] == 'T');
        G[i+1] = G[i] + (s[i] == 'G');
        C[i+1] = C[i] + (s[i] == 'C');
    }

    int q; cin >> q;
    string ss = "ATGC";
    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        vector<pair<int, pair<int,char>>> a;
        for (int j = 0; j < 4; j++){
            a.push_back({0, {4-j, ss[j]}});
        }
        a[0].first = A[r] - A[l-1];
        a[1].first = T[r] - T[l-1];
        a[2].first = G[r] - G[l-1];
        a[3].first = C[r] - C[l-1];
        sort(a.begin(), a.end(), greater<pair<int, pair<int,char>>>());
        for (auto p : a){
            cout << p.second.second;
        }
        cout << endl;
    }



    return 0;
}