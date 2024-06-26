#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(int t){
    ll a, b, c;
    cin >> a >> b >> c;
    if (c < a && c < b){
        cout << "Case #" << t << ": " << 0 << endl;
        return;
    }
    if (2*a < b){
        // prio singles
        cout << "Case #" << t << ": " << c/a << endl;
    }
    else{
        ll d = c/b;
        ll pat = d*2;
        ll bun = d*2;
        c -= d*b;
        pat += (c/a);
        bun += (c/a)*2;
        cout << "Case #" << t << ": " << (bun > pat ? pat : pat-1) << endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);

    return 0;
}