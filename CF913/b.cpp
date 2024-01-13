#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    string s; cin >> s;
    
    int low = 0;
    int hi = 0;
    vector<char> a;
    string z = "acdefghijklmnopqrstuvwxyz";
    set<char> lets;
    for (auto c : z) lets.insert(c); 

    for (int i = s.size()-1; i >= 0; i--){
        if (s[i] == 'b'){
            low -= 1;
        }
        else if (s[i] == 'B'){
            hi -= 1;
        }
        else if (lets.find(s[i]) != lets.end()){
            if (low >= 0) a.push_back(s[i]);
            low = min(0, low+1);
        }
        else{
            if (hi >= 0) a.push_back(s[i]);
            hi = min(0, hi+1);
        }
    }
    reverse(a.begin(), a.end());
    for (auto e : a) cout << e;
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}