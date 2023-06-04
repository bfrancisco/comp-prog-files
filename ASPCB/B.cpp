#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;

void solve(){
    unordered_set<int> s;
    for (int i = 0; i < 9; i++){
        int n; cin >> n;
        s.insert(n);
    }
    for (int i = 0; i < 10; i++){
        if (s.find(i) == s.end()){
            cout << i;
            return;
        }
    }
}

int main() {
    
    int t; cin >> t;
    while(t--) solve();
    cout << endl;
    return 0;
}