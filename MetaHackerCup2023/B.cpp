#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(int t){
    int r, c, a, b; cin >> r >> c >> a >> b;

    if (r <= c){
        cout << "Case #" << t << ": NO" << endl;
    }
    else{
        cout << "Case #" << t << ": YES" << endl;
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