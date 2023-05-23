#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int mn = 10000;
void rec(int n){
    // cout << n << endl;
    if (n < 4){
        mn = min(mn, n);
        return;
    }
    rec(n-4);
    if (n >= 7)
        rec(n-7);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    rec(n);
    if (mn == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    
    return 0;
}