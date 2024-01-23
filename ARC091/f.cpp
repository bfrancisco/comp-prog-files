#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int ceil(int a, int b){
    return (a+b-1) / b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int a, k; cin >> a >> k;
        while (a%k != 0){
            int sub = (int)(a/k)+1;
            int nearestdiv = (int)(a/k) * k;
            a = a-sub*(ceil((a-nearestdiv) , sub));
            // cout << sub << " " << nearestdiv << endl;
            // cout << a << endl;
        }
        ans ^= a/k;
    }
    // cout << ans << endl;
    cout << (ans ? "Takahashi" : "Aoki") << endl;
    

    return 0;
}