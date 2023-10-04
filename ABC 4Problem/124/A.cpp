#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b; cin >> a >> b;
    int mx = -1;
    mx = max(mx, 2*a-1);
    mx = max(mx, b*2-1);
    mx = max(mx, a+b);

    cout << mx << endl;

    return 0;
}