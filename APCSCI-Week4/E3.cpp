#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int getCountH(string s){
    int h;
    for (char c : s){
        if (c == 'h') h++;
    }
    return h;
}

vector<int> getScore(string s, int i){
    int h = getCountH(s);
    // ret[0] - score, ret[1] = 1 if s, 0 if h, ret[2] - key of s
    vector<int> ret = {0, 0, i};
    if (s.front() == 's') ret[1] = 1;
    
    for (char c : s){
        if (c == 's') ret[0] += h;
        else h--;
    }
    return ret;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; 
    cin >> n;

    ll counts = 0, counth = 0, allh = 0;
    vector<vector<int>> strs;
    map<int, string> db;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        int flags = 0, flagh = 0;
        vector<int> vec;
        db[i] = s;
        for (char c : s){
            if (c == 's') flags = 1;
            else flagh = 1;
        }
        
        if (!flagh) counts += s.size();
        else if (!flags) counth += s.size();
        else{
            vec = getScore(s, i);
            strs.push_back(vec);
        }
    }
    sort(strs.begin(), strs.end(), greater());
    int m = strs.size();
    // int zeroi, m = strs.size();
    // for (int i = 0; i < m; i++){
    //     if (strs[i][0] == 0 && strs[i][1] == 0){
    //         zeroi = i;
    //         break;
    //     }
    // }
    // sort(strs.begin() + zeroi, strs.end());

    // cout << endl;
    // for (auto v : strs){cout << v[0] << " " << v[1] << " " << db[v[2]] << endl;} cout << endl;

    for (auto v : strs){
        allh += getCountH(db[v[2]]);
    }

    allh += counth;

    ll ans = 0, zeroi = 0;
    //ans += (counts * allh);
    for (int i = 0; i < counts; i++) ans += allh;
    // cout << counts << ' ' << allh << ' ' << ans << endl;
    for (int i = 0; i < m; i++){
        zeroi = i;
        if (strs[i][0] == 0 && strs[i][1] == 0) break;
        string s = db[strs[i][2]];
        for (char c : s){
            if (c == 's') ans += allh;
            else allh--;
        }
    }

    for (int j = m-1; j >= zeroi; j--){
        string s = db[strs[j][2]];
        for (char c : s){
            if (c == 's') ans += allh;
            else allh--;
        }
    }
    cout << ans;

    return 0;
}