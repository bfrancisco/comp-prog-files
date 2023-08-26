#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<string> s;
    s.push_back("!@");
    s.push_back("#$");
    s.push_back("%^");
    s.push_back("*(");
    
    for (int ii = 0; ii < 52; ii++){
        string card; cin >> card;
        s.push_back(card);
        for (auto c : s) cout << c << " "; cout << endl;
        for (int j = 0; j < s.size()-3; j++){
            if (s.size()-4-j < 0) break;
            cout << j << endl;
            if (s[s.size()-4-j][0] == s[s.size()-1-j][0]){
                // cout << "ONE" << endl;
                s.pop_back();
                s.pop_back();
                s.pop_back();
                s.pop_back();
            }
            else if (s[s.size()-4-j][1] == s[s.size()-1-j][1]){
                // cout << "TWO" << endl;
                s.pop_back();
                string last = s.back();
                s.pop_back();
                string first = s.back();
                s.pop_back();
                s.pop_back();
                s.push_back(first);
                s.push_back(last);
            }
        }
    }

    cout << (int)s.size() - 4 << " ";
    for (int i = 4; i < s.size(); i++){
        cout << s[i] << " ";
    } cout << endl;

    return 0;
}