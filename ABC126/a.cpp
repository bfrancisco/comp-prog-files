#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    string s; cin >> s;    

    for (int i = 0; i < n; i++){
        if (i+1 == k && s[i] - 'A' <= 25){
            cout << (char)(s[i] + 32);
        }
        else cout << s[i];
    }
    cout << endl;
    return 0;
}