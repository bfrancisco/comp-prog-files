// https://atcoder.jp/contests/dp/tasks/dp_p

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int rb(string s, int n){
    // "fibonacci seq, where f(1) = 2, f(2) = 3 ..."
    if (n==2) return 2;
    if (s.size() == n){
        for (int i = 1; i < n; i++){
            if (s[i] == 'B' && s[i-1] == s[i]){
                return 0;
            }
        }
        cout << s << endl;
        return 1;
    }
    return rb(s+'W', n) + rb(s+'B', n);
}

int rec(){
    // rec(a, b) = 
}

void solve(){
    int n; cin >> n;
    // cout << rb("-", n+1) << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();    
    return 0;
}