#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    set<int> a;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.insert(x);
        if (*(a.begin()) == x) ans++;
    }
    cout << ans << endl;

    return 0;
}