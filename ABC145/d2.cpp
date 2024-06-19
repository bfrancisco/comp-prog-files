#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int R, C;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    
    if ((R+C)%3){
        cout << 0 << endl;
        return 0;
    }
    if ((R == 1 && C == 1) || min(R,C)*2 == max(R,C)){
        cout << 1 << endl;
        return 0;
    }

    // cout << "HAPPEN" << endl;
    vector<vector<ll>> db;
    vector<vector<pair<int, int>>> coor;
    db.push_back({0, 1, 1, 0});
    coor.push_back({{-1, -1}, {1, 2}, {2, 1}, {-1, -1}});
    int sz = 4;
    int nr, nc, steps;
    for (int z = 0; z < 1000; z++){
        vector<int> a = {0};
        vector<pair<int, int>> b = {{-1, -1}};
        for (int i = 0; i < sz-1; i++){
            steps = (((*db.rbegin())[i] + (*db.rbegin())[i+1]));
            a.push_back(steps);
            if (i == 0){
                nr = (*coor.rbegin())[1].first + 1;
                nc = (*coor.rbegin())[1].second + 2;
            }
            else{
                nr = (*coor.rbegin())[i].first + 2;
                nc = (*coor.rbegin())[i].second + 1;                b.push_back({ (*coor.rbegin())[i].first + 2, (*coor.rbegin())[i].first + 1 });
            }
            b.push_back({nr, nc});
            // cout << nr << " " << nc << endl;
            if (R == nr && C == nc){
                cout << steps << endl;
                return 0;
            }
        }
        a.push_back(0);
        b.push_back({-1, -1});
        sz++;
        db.push_back(a);
        coor.push_back(b);
        
    }
    assert(1==0);
    // for (int i = 0; i < 10; i++){
    //     for (auto e : db[i]) cout << e << " "; cout << endl;

    //     cout << "     ";
    //     for (auto p : coor[i]) cout << p.first << "," << p.second << " "; cout << endl;
    // }




    return 0;
}