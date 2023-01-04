#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    char last = ' ';
    unordered_set<string> bank;
    bool pas = true;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if ((s[0] != last && last != ' ') || bank.find(s) != bank.end()){
            pas = false;
        }
        last = s.back();
        bank.insert(s);
    }
    if (pas) cout << "Yes"; else cout << "No";

    return 0;
}