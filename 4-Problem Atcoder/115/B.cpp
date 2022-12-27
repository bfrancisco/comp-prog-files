#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int a[15];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);

    int ans = a[n-1]/2;
    for (int i = 0; i < n-1; i++)
        ans += a[i];
    cout << ans;
}