#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    int r,s,p; cin >> r >> s >> p;
    string t; cin >> t;
    unordered_map<char,char> win;
    unordered_map<char,int> sc;
    win['r'] = 'p'; sc['r'] = r;
    win['p'] = 's'; sc['p'] = p;
    win['s'] = 'r'; sc['s'] = s;
    string a = "";
    int score = 0;
    for (int i = 0; i < n; i++){
        if (i < k){
            a += win[t[i]];
            score += sc[win[t[i]]];
        }
        else{
            if (a[i-k] == win[t[i]]) a += 'z';
            else{
                a += win[t[i]];
                score += sc[win[t[i]]];
            }
        }
    }
    cout << score << endl;
    return 0;
}