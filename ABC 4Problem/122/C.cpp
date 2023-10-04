#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> prefix(n, 0);
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i-1];
        if (s[i-1] == 'A' && s[i] == 'C')
            prefix[i]++;
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--; b--;
        cout << prefix[b] - prefix[a] << endl;

    }

    return 0;
}