#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    unordered_map<char, ll> let;
    string letters = "MARCH";
    for (auto c : letters){
        let[c] = 0;
    }

    int n; cin >> n;
    ll ans = 0;

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        if (let.find(s[0]) != let.end())
            let[s[0]]++;
    }
    for (int i = 0; i < 5; i++)
        for (int j = i+1; j < 5; j++)
            for(int k = j+1; k < 5; k++)
                ans += let[letters[i]]*let[letters[j]]*let[letters[k]];
    cout << ans;
    return 0;
}