#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int ans = 0;
    while (n >= 500){
        ans+=1000;
        n -= 500;
    }
    while (n >= 5){
        ans += 5;
        n -= 5;
    }
    cout << ans << endl;

    return 0;
}