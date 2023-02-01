#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int a[200001];
    int num = 1;
    int ans = 0;
    bool good = false;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        if (a[i] == num){
            num++; good = true;
        }
        else{
            ans++;
        }
    }

    if (good) cout << ans;
    else cout << -1;
    
    return 0;
}   