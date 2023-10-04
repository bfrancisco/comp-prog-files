#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string ans = "AGC";
    if (n < 1200) ans = "ABC";
    else if (n >= 1200 && n < 2800) ans = "ARC";
    cout << ans << endl; 
    
    return 0;
}