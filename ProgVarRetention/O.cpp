#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    vector<int> a;
    for (auto c : s) a.push_back(c - '0');

    vector<int> p = {1,2,3,4,5,6,7,8,9};

    map<pair<int, int>, int> freq;
    for (int i = 0; i < s.size()-1; i++){
        if (freq.find({a[i], a[i+1]}) == freq.end())
            freq[{a[i], a[i+1]}]=1;
        else
            freq[{a[i], a[i+1]}]+=1;
    }

    int ans = 1e9*2;
    int mp[9];
    do {
        for (int i = 0; i < 9; i++){
            mp[p[i]] = i;
        }
        int moves = abs(mp[a[0]] - 0) + 1;
        for (auto &[p, f] : freq){
            moves += (abs(mp[p.first] - mp[p.second]) + 1) * f;
        }
        ans = min(ans, moves);
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    return 0;
}