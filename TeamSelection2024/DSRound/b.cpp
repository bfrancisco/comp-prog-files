#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){

    int n, K;
    cin >> n >> K;

    vector<vector<string>> pref(n);
    for (int i = 0; i < n; i++){
        int sz;
        cin >> sz;
        pref[i].resize(sz);
        for (int j = 0; j < sz; j++){
            cin >> pref[i][j];
        }
    }
    vector<int> pnt(n, 0);

    int p;
    cin >> p;

    vector<string> peep(p);
    for (int i = 0; i < p; i++){
        cin >> peep[i];
    } 
    int peepi = 0;

    set<string> done;
    vector<vector<string>> out(n);
    for (int k = 0; k < K; k++){
        // cout << "K: " << k << endl;
        for (int i = 0; i < n; i++){
            // cout << i << endl;

            // cout << "POINTERS "; for (auto x : pnt) cout << x << " "; cout << endl;

            while (pnt[i] < pref[i].size() && done.find(pref[i][pnt[i]]) != done.end()){
                // cout << pnt[i] << endl;
                pnt[i]++;
            }
            // cout << pnt[i] << " " << pref[i].size() << endl;
            if (pnt[i] < pref[i].size()){
                out[i].push_back(pref[i][pnt[i]]);
                done.insert(pref[i][pnt[i]]);
                // cout << "i: " << i << " " << "pick: " << pref[i][pnt[i]] << endl;
                pnt[i]++;
            }

            else{
                // cout << "WA" << endl;
                while (done.find(peep[peepi]) != done.end()){
                    peepi++;
                }
                // cout << peepi << endl;
                out[i].push_back(peep[peepi]);
                done.insert(peep[peepi]);
                peepi++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (auto s : out[i]){
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}