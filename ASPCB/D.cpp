#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;

int n;
int ans = 0;
string moves = "123";
vector<int> a;

void rec(string s){
    if (s.size() == n){
        
        int you = 0, enemy = 0;
        for (int i = 0; i < n; i++){
            if (a[i] == 1){
                if (s[i] == '2') enemy++;
                else if (s[i] == '3') you++;
            }
            else if (a[i] == 2){
                if (s[i] == '1') you++;
                else if (s[i] == '3') enemy++;
            }
            else if (a[i] == 3){
                if (s[i] == '1') enemy++;
                else if (s[i] == '2') you++;
            }
        }
        if (you > enemy) ans++;
        // cout << s << " " << you << " " << enemy << endl;
        return;
    }

    for (auto c : moves){
        s.push_back(c);
        rec(s);
        s.pop_back();
    }
}

int main() {
    
    cin >> n;
    a.resize(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    rec("");
    cout << ans << endl;
    return 0;
}