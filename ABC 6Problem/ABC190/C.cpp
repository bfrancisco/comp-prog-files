#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    unordered_set<int> nodes;
    for (int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        nodes.insert(u);
        nodes.insert(v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int k; cin >> k;

    vector<pair<int, int>> bin;

    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        bin.push_back({a, b});
    }

    int ans = 0;
    for (int bit = 0; bit < pow(2, k); bit++){
        unordered_set<int> choice;
        for (int i = 0; i < k; i++){
            if (bit & (1 << i)){
                choice.insert(bin[i].first);
            }
            else{
                choice.insert(bin[i].second);
            }
        }

        //check
        int cnt = 0;
        for (auto u : nodes){
            for (auto v : graph[u]){
                if (choice.find(u) != choice.end() && choice.find(v) != choice.end()){
                    cnt++;
                }
            }
        }
        
        ans = max(ans, cnt);
    }

    ans /= 2;
    cout << ans;
    return 0;
    
}