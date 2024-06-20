#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
    }

    sort(b.begin(), b.end());
    int himd = b[n/2].first;
    int lomd = b[(n/2) - 1].first;

    // for (auto p : b){
    //     cout << p.first << " " << p.second << endl;
    // }

    for (int i = 0; i < n; i++){
        ans[b[i].second] = (i < n/2 ? himd : lomd);
    }

    for (int i = 0; i < n; i++) cout << ans[i] << endl;
    

    return 0;
}