#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, c;
    cin >> n >> c;
    unordered_map<vector<char>, int> bank;
    string letters = "asdfghjklqwertyuiopzxcvbnm";
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        vector<char> builder(c);
        int asti = -1;
        for (int i = 0; i < c; i++){
            if (s[i] == '*') { asti = i; continue; }
            builder[i] = s[i];
        }
        for (auto let : letters){
            builder[asti] = let;
            if (bank.find(builder) == bank.end()){
                bank[builder] = 1;
            }
            else{
                bank[builder]++;
            }
        }
    }

    // convert bank to v p vc,i
    vector<pair<vector<char>, int>> lbank;
    for (auto& [v, f] : )

    return 0;
}