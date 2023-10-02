#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    map<pair<int, int>, int> atoi;
    map<int, pair<int, int>> itoa;
    for (int i = 0; i < n; i++){
        int x, h; cin >> x >> h;
        a[i] = {x, h};
        atoi[a[i]] = i;
        itoa[i] = a[i];
    }

    sort(a.begin(), a.end());

    vector<int> fall(n);
    fall[n-1] = 1;
    for (int i = n-2; i >= 0; i--){
        int val = a[i].first + a[i].second;

        if (a[i+1].first+a[i+1].second >= val && val-1 >= a[i+1].first){
            fall[i] = fall[i+1] + 1;
            continue;
        }

        int j = (lower_bound(a.begin()+i, a.end(), make_pair(val, 0))) - a.begin();
        fall[i] = j-i;
    }

    for (auto e : fall) cout << e << " "; cout << endl;

    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[atoi[a[i]]] = fall[i];
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl; 

    return 0;
}