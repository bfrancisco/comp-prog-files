#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, c; cin >> m >> c;
    vector<pair<int, int>> monument(m);
    for (int i=0; i<m; i++){
        cin >> monument[i].first >> monument[i].second;
    }
    
    vector<pair<int, int>> orig_church(c);
    for (int i=0; i<c; i++){
        cin >> orig_church[i].first >> orig_church[i].second;
    }

    map<int, set<int>> monu_x, monu_y;
    for (int i = 0; i < m; i++){
        monu_x[mounment[i].first].insert(monument[i].second);
        monu_y[monument[i].second].insert(monument[i].first);
    }
    
    vector<pair<int, int>> church; // no mighty
    for (int i = 0; i < c; i++){
        int x, y;
        x = orig_church[i].first;
        y = orig_church[i].second;
        int is_mighty = 0;
        if ((monu_x.find(x) != monu_x.end() && (int)monu_x[x].size() >= 2) ||
            (monu_y.find(y) != monu_y.end() && (int)monu_y[y].size() >= 2)){
            is_mighty = 1;
        }

        if (!is_mighty){
            church.push_back({x, y});
        }
    }    





    return 0;
}