#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string s; cin >> s;

    if (n == 1) { cout << 2; return 0; }
    if (n == 2 && s[0] != s[1]) { cout << 1; return 0; }
    
    int consec = 0;
    for (int i = 0; i < n-1; i++){
        if (s[i] == s[i+1]){
            consec = 1;
            break;
        }
    }
    if (consec) { cout << 2; return 0; }

    map<char, int> db;
    db['A'] = 0; db['B'] = 0; db['C'] = 0;
    int gud = 1;
    db[s[0]]++; db[s[1]]++; db[s[2]]++;
    for (int i = 3; i < n; i++){
        if (!(db['A'] && db['B'] && db['C'])){
            gud = 0;
            break;
        }
        db[s[i]]++;
        db[s[i-3]]--;
    }
    if (!(db['A'] && db['B'] && db['C'])){
        gud = 0;
    }
    cout << 1 - gud;

    return 0;
}