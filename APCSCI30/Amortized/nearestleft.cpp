#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n+1);
    vector<pair<int, int>> b(n+1);
    a[0] = 0;
    b[0] = {0, 0};
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = {a[i], i};
    }

    sort(b.begin(), b.end());
    for (auto p : b) cout << p.first << " "; cout << endl;
    for (int i = 1; i <= n; i++){
        cout << a[i] << ": ";
        pair<int, int> x = {a[i], 0};
        auto it = lower_bound(b.begin(), b.end(), x);
        it--;
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
    
    

    return 0;
}