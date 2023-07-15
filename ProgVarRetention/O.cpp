#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    string s; cin >> s;
    vector<int> a;
    for (auto c : s) a.push_back(c - '0');
    
    vector<int> p = {0,1,2,3,4,5,6,7,8,9};
    int ans = -1;
    do {
        // for (auto x : p) cout << x << " "; cout << endl;
        int mp[10];
        for (int i = 0; i < 10; i++){
            mp[p[i]] = i;
        }

        // for (int i = 0; i < 10; i++) cout << mp[i] << " "; cout << endl;
        int place = 0;
        int moves = 0;

        for (auto d : a){
            moves += abs(mp[d] - place);
            place = mp[d];
            moves++;
        }
        ans = max(ans, moves);
        
    }while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    return 0;
}