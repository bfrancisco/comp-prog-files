#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;

    stack<int> st;
    int l = 0, r;
    for (int i = 0; i < n; i++){
        if (s[i] == '(') st.push(1);
        else{
            if (st.empty()) l++;
            else st.pop();
        }
    }
    r = st.size();
    while (l--) cout << '(';
    cout << s;
    while (r--) cout << ')';

    return 0;
}   