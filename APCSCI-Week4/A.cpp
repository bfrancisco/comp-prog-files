#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, x, y; cin >> n;
    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (x > y){ x ^= y; y ^= x; x ^= y;}
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end());
    
    //for (auto p : a){cout << p.first << " " << p.second << "\n";}

    vector<int> out;
    int nail, l = 0;
    while (l < n){
        x = a[l].first;
        y = a[l].second;
        nail = y;
        while (l+1 < n && a[l+1].first <= nail){
            l++;
            if (a[l].second < nail) nail = a[l].second;
        }

        out.push_back(nail);
        l++;
    }

    cout << out.size() << endl;
    for (int nail : out) cout << nail << " ";

    return 0;
}