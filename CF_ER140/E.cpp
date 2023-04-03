#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m, i;
ll ans = 0;
int c[300010];
ll x; 
unordered_map<int, pair<ll, bool>> cost;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> c[i];
    for (i = 1; i < m+1; i++)
        cin >> x;
        cost[i] = {x, false};

    ans += cost[0].first;
    cost[0].second = true;
    
    return 0;
}