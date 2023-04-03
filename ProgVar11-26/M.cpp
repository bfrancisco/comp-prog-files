#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<int> graph[100001];
int ded[100001];
int ret;

int dfs(int x){
    // cout << x << endl;
    if (! ded[x]) return x;
    
    for (int next : graph[x]){
        ret = dfs(next);
        return ret;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 100001; i++){
        ded[i] = 0;
    }
    int Q, t, x;
    cin >> Q;
    int mn = 2;
    while (Q--){
        cin >> t >> x;
        if (t==1){
            graph[x].push_back(mn);
            mn++;
        }
        else if (t==2){
            ded[x] = 1;
            cout << dfs(1) << endl;
        }
    }

    return 0;
}