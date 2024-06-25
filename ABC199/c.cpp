#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;
    s = '*' + s;
    int q; cin >> q;
    int tama = 1;
    while (q--){
        int t, a, b; cin >> t >> a >> b;
        if (t == 2){
            tama = 1 - tama;
        }
        else{
            if (tama){
                swap(s[a], s[b]);
            }
            else{
                int na, nb;
                na = (a <= n ? a+n : a-n);
                nb = (b <= n ? b+n : b-n);
                swap(s[na], s[nb]);
            }
        }
        // cout << s << endl;
    }

    if (tama){
        for (int i = 1; i <= n*2; i++){
            cout << s[i];
        }
    }
    else{
        for (int i = n+1; i <= n*2; i++){
            cout << s[i];
        }
        for (int i = 1; i <= n; i++){
            cout << s[i];
        }
    }
    
    return 0;
}