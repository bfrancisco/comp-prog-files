#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string n, m; cin >> n >> m;
    int ans = 1;

    while (n != m && (n.size() <= min(100, (int)m.size()))){
        vector<int> db(10, 0);
        for (auto c : n){
            db[c-'0']++;
        }
        string newn = "";
        for (int i = 0; i < 10; i++){
            if (db[i] > 0){
                newn += to_string(db[i]) + to_string(i);
            }
        }
        n = newn;
        ans++;
    }

    if (n==m) cout << ans << endl;
    else if (n.size() <= 100) cout << "Does not appear" << endl;
    else cout << "I’m bored" << endl;

    return 0;
}