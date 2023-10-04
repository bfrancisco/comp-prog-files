#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x; cin >> x;
    unordered_set<int> s;

    s.insert(x);
    int ans = 1;
    while (true){
        ans++;
        x = x%2 ? 3*x + 1 : x/2;
        if (s.find(x) != s.end()) break;
        s.insert(x);
    } 
    cout << ans << endl;

    return 0;
}