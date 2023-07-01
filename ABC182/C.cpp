#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    vector<int> a;
    for (auto c : s) a.push_back(c - '0');
    vector<int> db(3, 0);
    int all = 0;
    for (auto d : a) {db[d%3]++; all += d%3;}
    all %= 3;
    if (all == 0) cout << 0 << endl;
    else if (all == 1){
        if (db[1] >= 1 && s.size() > 1) cout << 1 << endl;
        else if (db[2] >= 2 && s.size() > 2) cout << 2 << endl;
        else cout << -1 << endl;
    }
    else if (all == 2){
        if (db[2] >= 1 && s.size() > 1) cout << 1 << endl;
        else if (db[1] >= 2 && s.size() > 2) cout << 2 << endl;
        else cout << -1 << endl;
    }

    return 0;
}