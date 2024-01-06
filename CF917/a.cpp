#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    int neg = 0;
    int pos = 0;
    int zer = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 0) zer++;
        else if (x < 0) neg++;
        else pos++;
    }
    if (zer){
        cout << 0 << endl;
    }
    else if (neg%2==0){
        cout << "1\n1 0" << endl;
    }
    else{
        cout << 0 << endl;
    }
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