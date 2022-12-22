#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k, pos = 0, newN = 0;
    cin >> n >> k;
    vector<int> a;
    //unordered_set<int> bank;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        //if (bank.find(x) != bank.end()) continue;
        //bank.insert(x);
        a.push_back(x);
        newN++;
    }
    sort(a.begin(), a.end());

    //for (int x : a){cout << x << " ";} cout << endl;
    int mid, leftm, i, ans = 0;

    //if (newN == 1){cout << 1; return 0;}

    while (pos < newN){
        leftm = a[pos];
        i = pos;
        while (i+1 < newN && a[i+1] - leftm <= k) {
            mid = a[i+1];
            i++;
        }

        while (i+1 < newN && a[i+1] - mid <= k){
            i++;
        }
        pos = i+1;
        ans++;
    }
    cout << ans << endl;

    return 0;
}