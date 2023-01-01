#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n, y, a=0, b=0, c;
    cin >> n >> y;
    c = y / 1000;

    if (c < n){
        cout << "-1 -1 -1";
        return 0;
    }
    // cout << c << endl;
    while (a+b+c > n){
        bool pas = false;
        if (a+b+c-4 >= n && c-5 >= 0)
            {c -= 5; b++; pas = true;}
        if (!pas) break;
        // cout << c << endl;
    }

    while (a+b+c > n){
        bool pas = false;
        if (a+b+c-1 >= n && b-2 >= 0)
            {b -= 2; a++; pas = true;}
        if (!pas) break;
        // cout << c << endl;
    }
    
    if (a+b+c == n) cout << a << " " << b << " " << c;
    else cout << "-1 -1 -1";
    return 0;   
}