#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
const int MOD = 43200; // 11*60^2 + 59*60 + 59 + 1
 
int mod(int x, int m){
    if (m == 0) return 0;
    if (m < 0) m *= -1;
    return (x%m + m) % m;
}

int takeTime(){
    string anlg; cin >> anlg;
    int tym = 0;
    tym += (anlg[0] == '1' && anlg[1] == '2' ? 0 : (anlg[0]-'0')*10 + (anlg[1]-'0')) * 60*60; 
    tym += ((anlg[3]-'0')*10 + (anlg[4]-'0')) * 60; 
    tym += (anlg[6]-'0')*10 + (anlg[7]-'0'); 
    
    return mod(tym, MOD);
}
 
void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    map<int, int> freq_b;
 
    for (int i = 0; i < n; i++){
        int tym = takeTime();
        a[i] = tym;
    }
     for (int i = 0; i < n; i++){
        int tym = takeTime();
        if (freq_b.find(tym) == freq_b.end())
            freq_b[tym] = 1;
        else
            freq_b[tym]++;
        b[i] = tym;
    }
 
    for (auto x : a) cout << x << " "; cout << endl;
    for (auto x : b) cout << x << " "; cout << endl; cout << endl;
    
    int ans = 100000;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
 
            // cout << i << " " << j << endl;
 
            int adjst;
            if (a[i] < b[i])
                adjst = b[i] - a[i];
            else
                adjst = MOD - a[i] + b[i];
            
            adjst = mod(adjst, MOD);

            map<int, int> freq_a;
            for (int k = 0; k < n; k++){
                int new_ai = mod((a[k] + adjst), MOD);
                
                // cout << new_ai << " ";

                if (freq_a.find(new_ai) == freq_a.end())
                    freq_a[new_ai] = 1;
                else
                    freq_a[new_ai]++;
            }
            // cout << endl << endl;

            int matches = 0;
            for (auto &[v, f_b] : freq_b){
                if (freq_a.find(v) == freq_a.end()) continue;
                matches += min(freq_a[v], f_b);
            }
            ans = min(ans, n-matches);
            // cout << ans << endl << endl;
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