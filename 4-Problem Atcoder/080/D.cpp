#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, C;
    cin >> n >> C;
    
    int s[200005];
    int t[200005];
    int c[200005];
    int mx[200005];

    for (int i = 0; i < n; i++){
        cin >> s[i] >> t[i] >> c[i];
    }

    for (int i = 1; i <= C; i++){
        int dif[200005]; 
        for (int j = 0; j < 200005; j++) dif[j] = 0;
        for (int j = 0; j < n; j++){
            if (c[j] == i){
                dif[s[j]*2 - 1] ++;
                dif[t[j]*2] --;
            }
        }
        for (int j = 1; j < 200005; j++){
            dif[j] += dif[j-1];
        }
        for (int j = 0; j < 200005; j++){
            if (dif[j] > 0) mx[j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < 200005; i++) ans = max(ans, mx[i]);
    cout << ans;
    return 0;
}