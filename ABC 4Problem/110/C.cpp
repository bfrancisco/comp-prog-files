#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    map<char, vector<int>> freq1, freq2;
    string lets = "abcdefghijklmnopqrstuvwxyz";

    for (char c : lets){
        freq1[c] = {};
        freq2[c] = {};
    }

    string s, t; cin >> s >> t;
    int n = s.size();

    for (int i = 0; i < n; i++){
        freq1[s[i]].push_back(i);
        freq2[t[i]].push_back(i);
        if (freq1[s[i]] != freq2[t[i]]){
            cout << "No"; return 0;
        }
    }

    cout << "Yes";
    return 0;
}