#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;
    set<char> db;
    for (auto c : s) db.insert(c);
    vector<int> divs;
    for (int d = 1; d < n; d++){
        if (n%d == 0)
            divs.push_back(d);
    }

    int ans = n;
    for (int i = 0; i < n; i++){
        for (auto c : db){
            if (s[i] == c) continue;
            
        }
    }

    return 0;
}