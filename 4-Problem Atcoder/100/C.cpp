#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int a[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int val = a[i]; val%2==0; val/=2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}