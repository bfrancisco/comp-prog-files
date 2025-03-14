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
    db.push_back({0, 0});
    int n = 0;
    for (int i = 0; i < in; i++){
        int x;
        cin >> x;
        if (db[db.size()-1].first == x){
            db[db.size()-1].second++;
        }
        else{
            db.push_back({x, 1});
            n++;
        }
    }    

    // cout << n << endl;
    // for (auto [x, f] : db)cout << x << " " << f << endl; cout << endl;

    vector<int> L(n+1), R(n+1);
    L[0] = 0, R[0] = 0;
    for (int i = 1; i <= n; i++){
        L[i] = i-1;
        R[i] = (i+1 == n+1 ? 0 : i+1);
    }

    set<pair<int, int>, comp> szes;
    for (int i = 1; i <= n; i++){
        szes.insert({db[i].second, i});
    }

    // for (auto p : szes) cout << p.first << " " << p.second << " | " << db[p.second].first << endl; cout << endl;

    int ans = 0;
    while (!szes.empty()){
        
        auto p = *szes.begin();
        int sz, ind;
        sz = p.first;
        ind = p.second;

        if (sz == 0 && ind == 0) break;
        szes.erase({sz, ind});

        // cout << "\t" << sz << " " << ind << endl;

        R[L[ind]] = R[ind];
        L[R[ind]] = L[ind];

        if (db[L[ind]].first == db[R[ind]].first){
            int updated_freq = db[L[ind]].second + db[R[ind]].second;
            int retain_val = db[L[ind]].first;
            
            // erase right
            szes.erase({db[R[ind]].second, R[ind]});

            // update left
            szes.erase({db[L[ind]].second, L[ind]});
            szes.insert({updated_freq, L[ind]});
            db[L[ind]].second = updated_freq;
            
            // update pointers
            R[L[ind]] = R[R[ind]];
            L[R[R[ind]]] = L[ind];
        }
        ans++;

        // for (auto p : szes) cout << p.first << " " << p.second << " | " << db[p.second].first << endl; cout << endl;
    }

    cout << ans << endl;




    return 0;
}