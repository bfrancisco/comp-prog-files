#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    pair<int, int> ar[100010];
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ar[i] = {b, a};
    }

    sort(ar, ar+m);
    int ans = 0;
    int cut = 0;
    for (int i = 0; i < m; i++){
        // cout << ar[i].first << endl;
        if (ar[i].second > cut){    
            ans++;
            cut = ar[i].first - 1;
        }
    }
    cout << ans;

    return 0;
}