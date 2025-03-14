#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = 1;
    multiset<int> bank = {a[0]};
    for (int i = 1; i < n; i++){
        while (a[i] - *bank.begin() > 5 && !bank.empty()){
            // for (auto e : bank) cout << e << " "; cout << endl;
            bank.erase(bank.begin());
        }
        bank.insert(a[i]);
        ans = max(ans, (int)bank.size());
    }
    cout << ans << endl;


    return 0;

}