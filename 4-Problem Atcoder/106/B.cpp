#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int ans = 0;
    for (int i = 105; i <= n; i += 2){
        int d = 0;
        for (int j = 1; j <= i; j++){
            if (i%j == 0)
                d++;
        }
        if (d == 8)
            ans++;
    }
    cout << ans << endl;
    return 0;
}