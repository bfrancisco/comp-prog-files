#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    int a[100010];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int ans = 1e9;
    for (int i = 0; i < n-k+1; i++){
        // cout << a[i] << " ";
        ans = min(ans, a[i+k-1] - a[i]);
    }
    cout << ans; 
}