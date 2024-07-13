#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int n;

bool valid(int x){
    return (0 <= x && x < n);
}

int main(){

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
        vector<int> elim;
        vector<pair<int, int>> opsR, opsL;
        map<int, pair<int, int>> np;

        for (int i = 1; i <= n; i++){
            if (done.find(i) != done.end()) continue;
            if (a[pnt[i].first] > a[i] || a[pnt[i].second] > a[i]){
                // pnt[pnt[i].second].first = pnt[i].first; // right elem
                // pnt[pnt[i].first].second = pnt[i].second; // left elem
                opsR.push_back({pnt[i].second, pnt[i].first});
                opsL.push_back({pnt[i].first, pnt[i].second});

                // if ()
                elim.push_back(a[i]);
                done.insert(i);
                happen = true;
            }
        }

        for (auto [q, w] : opsR){
            pnt[q].first = min(pnt[q].first, w);
            cout << q << " " << w << endl;
        }cout << endl;
        for (auto [q, w] : opsL){
            pnt[q].second = max(pnt[q].second, w);
            cout << q << " " << w << endl;
        }

        for (int i = 1; i <= n; i++){
            if (done.find(i) != done.end()) continue;
            cout << i << " " << a[i] << " ( " << pnt[i].first << " " << pnt[i].second << " )" << endl; 
        }cout << endl;

        if (!happen) break;


        out.push_back(elim);
    }

    cout << out.size() << endl;
    for (auto v : out){
        for (auto e : v) cout << e << " "; cout << endl;
    }
    for (int i = 1; i <= n; i++){
        if (done.find(i) == done.end()){
            cout << a[i] << " ";
        }
    }
    cout << endl;
    

    return 0;
}