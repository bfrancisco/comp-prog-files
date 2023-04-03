#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll n, ans = 0;

void rec(string s){
    if (s != "" && stoll(s) > n) return;
    int a=0,b=0,c=0;
    for (auto d : s){
        if (d == '3') a++;
        else if (d == '5') b++;
        else if (d == '7') c++;
    }
    if (a && b && c) ans += 1;
    rec(s + '3');
    rec(s + '5');
    rec(s + '7');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    rec("");
    cout << ans;
    return 0;
}