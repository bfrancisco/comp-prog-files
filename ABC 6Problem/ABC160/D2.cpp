#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, x, y; cin >> n >> x >> y;
    int m = y-x;
    vector<int> ans(n);
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            int dif = j-i;
            ans[min({j-i, abs(x-i)+abs(y-j)+1, abs(y-i)+abs(j-x)+1})]++;
        }
        
    }
    for (int v = 1; v < n; v++){
        cout << ans[v] << endl;
    }
    return 0;
}