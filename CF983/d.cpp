#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;

    int i = 2;
    vector<int> nextpars;
    vector<int> p(n, -1);
    int val;
    int firstpar = 0;

    // until 1 gets 2nd edge
    while (true){
        if (i == n-1){
            p[i++] = 1;
            break;
        }
        cout << "? " << 1 << " " << i << endl;
        cin >> val;

        if (val == 1){
            nextpars.push_back(i);
            p[i++] = 0;
        }
        else if (val == 0){
            p[i++] = 1;
            break;
        }
        else{ assert(1==0); }
    }


    while (i < n){
        
    }

    cout << "! ";
    for (int i = 1; i < n; i++) cout << i << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}