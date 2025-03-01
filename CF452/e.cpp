#include<bits/stdc++.h>
using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const { 
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first; 
    }
};

int main(){
    int in; cin >> in;
    vector<pair<int, int>> db;
    db.push_back({0, 1});
    int n = 0;
    for (int i = 0; i < in; i++){
        int x;
        cin >> x;
        if (db[db.size()-1].first == x){
            db[db.size()-1].second += 1;
        }
        else{
            db.push_back({x, 1});
            n++;
        }
    }    

    // cout << n << endl;
    // for (auto [x, f] : db)cout << x << " " << f << endl; cout << endl;

    vector<int> L(n+1), R(n+1);
    for (int i = 1; i <= n; i++){
        L[i] = i-1;
        R[i] = (i+1 == n+1 ? 0 : i+1);
    }

    set<pair<int, int>, comp> szes;
    for (int i = 1; i <= n; i++){
        szes.insert({db[i].second, i});
    }

    // for (auto p : szes){
    //     cout << p.first << " " << p.second << endl;
    // }

    int ans = 0;
    while (!szes.empty()){
        auto p = *szes.begin();
        int sz, ind;
        sz = p.first;
        ind = p.second;

        // delete
        // if merge, left element absorbs
        // if (db[L[ind]].first == db[R[ind]].first){
        //     int rr = R[R[ind]];
        //     if (rr > 0){
        //         R[L[ind]] = rr;
        //     }
        //     L[rr] = L[ind];

        //     szes.erase({sz, ind});
        //     R[ind]
        // }

        R[L[ind]] = R[ind];
        L[R[ind]] = L[ind];
        szes.erase({sz, ind});
        
        ans++;
    }

    cout << ans << endl;




    return 0;
}