#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a[101];
    int n; n=3;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += abs(a[i] - a[i-1]);

    cout << ans;

    return 0;
}