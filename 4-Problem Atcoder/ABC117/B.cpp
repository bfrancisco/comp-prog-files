#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int a[11];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int x = 0;
    for (int i = 0; i < n-1; i++) x+=a[i];
    if (x > a[n-1]) cout << "Yes";
    else cout << "No";

    return 0;
}