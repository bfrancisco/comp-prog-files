#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
const int MOD = 43200; // 11*60^2 + 59*60 + 59 + 1
 
int takeTime(){
    string anlg; cin >> anlg;
    int tym = 0;
    tym += (anlg[0] == '1' && anlg[1] == '2' ? 0 : (anlg[0]-'0')*10 + (anlg[1]-'0')) * 60*60; 
    tym += ((anlg[3]-'0')*10 + (anlg[4]-'0')) * 60; 
    tym += (anlg[6]-'0')*10 + (anlg[7]-'0');
    
    return tym;
}

int n;
int a[MOD], b[MOD];

void solve(){
    cin >> n;
    map<int, int> freq_a, freq_b;
 
    for (int i = 0; i < n; i++){
        int tym = takeTime();
        freq_a[tym]++;
        a[i] = tym;
    }
    for (int i = 0; i < n; i++){
        int tym = takeTime();
        freq_b[tym]++;
        b[i] = tym;
    }

    int ans = n-1;
    int adjst, i, j, k, new_ai, matches;
    
    set<int> adjsts;
    adjsts.insert(0);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            adjsts.insert((b[j]-a[i]) % MOD);
        }
    }

    for (auto &adjst : adjsts){
        matches = 0;
        for (auto&[v, f_a] : freq_a){
            new_ai = (v + adjst) % MOD;
            if (freq_b.find(new_ai) != freq_b.end()){
                matches += min(f_a, freq_b[new_ai]);
            }
        }
        ans = min(ans, n-matches);
    }
    cout << ans << endl;
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