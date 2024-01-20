#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        if (c=='1') a[i] = 1;
    }
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        if (c=='1') b[i] = 1;
    }
    int ans = 0;
    int A = 0;
    int B = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            if (a[i] == 1){
                A++;
            }
            else{
                B++;
            }
        }
    }

    cout << max(A,B) << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}