#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, n; cin >> h >> n;
    int po = 0;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        po += x;
    }

    if (po >= h) cout << "Yes";
    else cout << "No";
    
    return 0;
}   