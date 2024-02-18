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
 
void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> freq_b, ini_freq_a;
 
    for (int i = 0; i < n; i++){
        int tym = takeTime();
        ini_freq_a[tym]++;
        a[i] = tym;
    }
    for (int i = 0; i < n; i++){
        int tym = takeTime();
        freq_b[tym]++;
        b[i] = tym;
    }

    int ans = 100000;
    int matches = 0;
    for (auto &[v, f_b] : freq_b){
        if (ini_freq_a.find(v) == ini_freq_a.end()) continue;
        matches += min(ini_freq_a[v], f_b);
    }
    ans = min(ans, n-matches);
    
    unordered_set<int> done;
    done.insert(0);
    int adjst, i, j, k, new_ai;
 
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            adjst = b[j] - a[i];
            if (adjst < 0) adjst += MOD;
            if (done.find(adjst) != done.end()) continue;
            done.insert(adjst);
 
            unordered_map<int, int> freq_a;
            matches = 0;
 
            for (k = 0; k < n; k++){
                new_ai = a[k] + adjst;
                if (new_ai >= MOD) new_ai -= MOD;
                freq_a[new_ai]++;
            }
            
            for (auto &[v, f_b] : freq_b){
                if (freq_a.find(v) == freq_a.end()) continue;
                matches += min(freq_a[v], f_b);
            }
            ans = min(ans, n-matches);
        }
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