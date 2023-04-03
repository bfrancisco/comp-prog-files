#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<string> a;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end(), greater());

    for (string ss : a){cout << ss << endl;} cout << endl;
    vector<char> conc;
    
    // find index of lexicographically least s string
    int indS = 0; 
    int hs = 0;
    if (a[0].front() == 's'){
        for (int i = 0; i < n; i++){
            if (a[i].front() == 's') indS++;
            else break;
        }
    }
    else indS = -1;

    if (indS != -1){
        for (int i = indS-1; i >= 0; i--){
            //cout << a[i] << endl;
            for (char c : a[i]){
                conc.push_back(c);
                if (c == 'h') hs++;
            }
        }
    }
    
    for (int i = indS; i < n; i++){
        for (char c : a[i]){
            conc.push_back(c);
            if (c == 'h') hs++;
        }
    }

    //for (auto c : conc) cout << c;
    //cout << hs;
    int ans = 0;
    for (auto c : conc){
        if (c == 's') ans += hs;
        else hs--;
    }
    cout << ans;


    return 0;
}