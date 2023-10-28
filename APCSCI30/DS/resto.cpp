#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    map<int, int> db;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if (db.find(a) == db.end()) db[a] = 1;
        else db[a]++;
        
        if (db.find(b) == db.end()) db[b] = -1;
        else db[a]--;
    }

    int cur = 0;
    int ans = 0;
    for (auto& [k, v] : db){
        cur += v;
        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}