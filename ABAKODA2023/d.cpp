#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = {x, i+1};
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());

    vector<int> ans(n+5, -1);
    set<int> don;
    for (int i = 0, j = 0; i < n; i+=k, j++){
        ans[i] = a[j].second;
        don.insert(ans[i]);
    }
    for (int i = 1, j = 1; i <= n; i++){
        if (don.find(i) == don.end()){
            ans[j] = i;
            while (ans[j] != -1) j++;
       
        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}