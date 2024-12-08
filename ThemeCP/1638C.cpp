#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<int> q;
    int mx = 0;
    for (int i = 0; i < n; i++){
        while (!q.empty() && q.top() > a[i]){
            q.pop();
        }
        mx = max(mx, a[i]);
        q.push(mx);
    }

    cout << q.size() << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--) solve();

    return 0;
}