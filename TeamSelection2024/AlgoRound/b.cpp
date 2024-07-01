#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    int thresh = k/2;
    vector<vector<string>> db(n);
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        while (t--){
            string s; cin >> s;
            db[i].push_back(s);
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++){
        bool good = true;
        map<string, int> cur;
        vector<int> goodi;
        for (int i = 0; i < n; i++){   
            if (bit & (1 << i)){
                // for (auto topic : db[n-i-1]){
                //     cur[topic]++;
                // }
                goodi.push_back(n-i-1);
            }
        }
        if (goodi.size() != k) continue;


        for (auto i : goodi){
            for (auto topic : db[i]){
                cur[topic]++;
            }
        }


        for (auto& [topic, cnt] : cur){
            if (cnt > thresh){
                good = false;
                break;
            }
        }
        if (good) {
            ans++;
            // cout << bit << endl;
        }
    }
    cout << ans << endl;

    return 0;
}