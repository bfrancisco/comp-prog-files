#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(int t){
    int s, d, k;
    cin >> s >> d >> k;
    
    int bun = s*2 + d*2;
    int pat = s + d*2;
    if (bun >= k+1 && pat >= k){
        cout << "Case #" << t << ": " << "YES" << endl; 
    }
    else{
        cout << "Case #" << t << ": " << "NO" << endl; 

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