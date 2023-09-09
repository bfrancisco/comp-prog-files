#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;
    s += 'b';
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n+1; i++){
        if (s[i] == 'a'){
            count++;
        }
        else{
            if (count >= 2){
                ans += count;
            }
            count = 0;
        }
    }
    cout << ans << endl;

    return 0;
}