#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;

bool valid(int x){
    return (0 <= x && x < n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> a(n+2);
    vector<pair<int, int>> pnt(n+2);
    a[0] = a[n+1] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pnt[i] = {i-1, i+1};
    }

    vector<vector<int>> out;
    set<int> done;
    while (true){
        bool happen = false;
        vector<int> toadd;
        vector<int> torem;
        for (int i = 1; i <= n; i++){
            if (done.find(i) != done.end()) continue;
            if (a[pnt[i].first] > a[i] || a[pnt[i].second] > a[i]){
                torem.push_back(i);
                toadd.push_back(a[i]);
                done.insert(i);
                happen = true;
            }
        }

        for (int i = torem.size()-1; i >= 0; i--){
            pnt[pnt[torem[i]].first].second = pnt[torem[i]].second;
            pnt[pnt[torem[i]].second].first = pnt[torem[i]].first;
            // cout << "RIGHT OF " << a[pnt[i].first] << " is " << a[pnt[i].second] << endl;
        }
        // for (int i = 0; i < torem.size(); i++){
        //     pnt[pnt[torem[i]].second].first = pnt[torem[i]].first;
        // }

        // for (int i = 1; i <= n; i++){
        //     // if (done.find(i) != done.end()) continue;
        //     cout << i << " " << a[i] << " ( " << pnt[i].first << " " << pnt[i].second << " )" << endl; 
        // }cout << endl;

        if (!happen) break;

        out.push_back(toadd);

    }
    
    cout << out.size() << "\n";
    for (auto v : out){
        for (auto e : v) cout << e << " "; cout << "\n";
    }
    for (int i = 1; i <= n; i++){
        if (done.find(i) == done.end()){
            cout << a[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}