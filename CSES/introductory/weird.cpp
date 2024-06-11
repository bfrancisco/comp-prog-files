#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void rec(ll n){
    cout << n << " ";
    if (n==1) return;

    if (n%2) rec(n*3+1);
    else rec(n/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;

    rec(n);
    cout << endl;

    return 0;
}