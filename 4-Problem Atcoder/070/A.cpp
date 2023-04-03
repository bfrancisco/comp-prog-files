#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size() / 2;
    int N = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] != s[N-i-1]) {cout << "No"; return 0;}
    }
    cout << "Yes";
    return 0;
}   