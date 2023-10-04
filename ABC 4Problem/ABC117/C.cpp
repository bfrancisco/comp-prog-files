#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; 
    cin >> n >> m;
    int a[100010];
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a, a+m);

    vector<int> dif; 
    for (int i = 1; i < m; i++){
        dif.push_back(abs(a[i] - a[i-1]));
    }

    if (n >= m){
        cout << 0; return 0;
    }

    n -= 1;
    sort(dif.begin(), dif.end());
    int ans = 0;
    for (int i = 0; i < m-n-1; i++){
        ans += dif[i];
        // cout << dif[i] << endl;
    }
    cout << ans;
    return 0;
}