#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n, m; cin >> n >> m;
    unordered_map<string, vector<string>> adj;
    string root;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        adj[s];
        root = s;
    }
    for (int i = 0; i < m; i++){
        string u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // find how many cycles
    int cycles = 0;
    unordered_set<string> vis;
    stack<pair<string, string>> st;
    st.push({root, "AAAAAAA"});
    vis.insert(root);
    while(!st.empty()){
        auto &[s, prev] = st.top();
        st.pop();
        for (auto v : adj[s]){
            if (v == prev) continue;
            if (vis.find(v) != vis.end()){
                cout << s << " " << v << endl;
                cycles++;
            }
            else{
                vis.insert(v);
                st.push({v, s});
            }
        }
    }

    // edg[# of neighbors] = frequency
    unordered_map<int, int> edg;
    for (auto &[s, vec] : adj){
        int sz = vec.size();
        if (edg.find(sz) == edg.end())
            edg[sz] = 1;
        else
            edg[sz]++;
    }

    string ans = "PRANKED";
    if (n >= 5 && edg[1] == 2 && edg[3] == 2 && edg[1]+edg[2]+edg[3] == n && cycles == 1){
        ans = "Alice";
    }
    else if (n >= 5 && edg[4] == 1 && edg[2]+edg[4] == n && cycles == 2){
        ans = "Bob";
    }
    else if (n >= 5 && edg[1] == 2 && edg[1]+edg[2] == n && cycles == 0){
        ans = "Cindy";
    }
    cout << ans << " " << cycles << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}