#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    int n = s.size();
    map<string, int> db;
    string cons = "bcdfghjklmnpqrstvwxyz";
    for (int i = 0; i < 21; i++){
        for (int j = i+1; j < 21; j++){
            string ab, ba;
            ab += cons[i]; ba += cons[j];
            ab += cons[j]; ba += cons[i];
            db[ab] = 0;
            db[ba] = 0;
        }
    }
    for (int i = 0; i < n-1; i++){
        string cc;
        cc += s[i]; cc += s[i+1];
        if (db.find(cc) != db.end())
            db[cc]++;
    }

    vector<string> ans(n, "NO");
    for (auto &[cc, v] : db){
        if (ans[n-v-1] == "NO")
            ans[n-v-1] = cc;
    }

    for (auto x : ans) cout << x << " "; cout << endl;

    return 0;
}