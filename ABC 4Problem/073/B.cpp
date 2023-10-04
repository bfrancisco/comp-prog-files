#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; 
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ans += (b-a)+1;
    }
    cout << ans << endl;

    return 0;
}