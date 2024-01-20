#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m; cin >> n >> m;
    if (n==1 && n==m) cout << 1 << endl;
    else if (n==1) cout << m-2 << endl;
    else if (m==1) cout << n-2 << endl;
    else if (n==2 || m==2) cout << 0 << endl;
    else cout << (n-2)*(m-2) << endl; 
    return 0;
}