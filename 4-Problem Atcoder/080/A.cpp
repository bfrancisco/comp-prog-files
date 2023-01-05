#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, a, b; cin >> n >> a >> b;
    cout << min(a*n, b);

    return 0;
}