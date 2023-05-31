#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int a[200001];

ll f(ll x){
    // cout << x << endl;
    if (x<=1){
        return 1;
    }
    return 2 * f(x/2) + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);
    for (int i = 0; i < n; i++){
        
    }

    return 0;
}