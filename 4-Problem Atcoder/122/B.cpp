#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    set<char> s = {'A', 'C', 'G', 'T'};
    string a; cin >> a;

    int ans = 0;
    int ANS = 0;
    for (char c : a){
        if (s.find(c) != s.end())
            ans++;
        else
            ans = 0;
        ANS = max(ans, ANS);
    }

    cout << ANS << endl;

    return 0;
}