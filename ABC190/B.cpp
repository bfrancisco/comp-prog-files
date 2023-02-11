#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; ll s, d;
    cin >> n >> s >> d;

    bool pas = false;
    for (int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;

        if (x < s && y > d){
            pas = true;
        }
    }

    if (pas) cout << "Yes";
    else cout << "No";
    return 0;
    
}