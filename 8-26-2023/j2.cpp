#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<string> s;
    for (int ii = 0; ii < 52; ii++){
        string x; cin >> x;
        s.push_back(x);
        for (auto c : s) cout << c << " "; cout << endl;
        int i = 0;
        while ((int)s.size()-4-i >= 0){
            // cout << (int)s.size()-4-i << " " << (int)s.size()-i-1 << endl;
            if (s[(int)s.size()-4-i].front() == s[(int)s.size()-i-1].front()){
                cout << "ONE" << endl;
                s.pop_back(); s.pop_back(); s.pop_back(); s.pop_back(); 
            }
            else if (s[(int)s.size()-4-i].back() == s[(int)s.size()-i-1].back()){
                cout << "TWO" << endl;
                s.pop_back();
                string last = s.back(); s.pop_back();
                string first = s.back(); s.pop_back();
                s.pop_back();
                s.push_back(first); s.push_back(last);
            }
            i++;
        }
    }

    cout << (int)s.size() << " ";
    for (auto c : s) cout << c << " "; cout << endl;

    return 0;
}