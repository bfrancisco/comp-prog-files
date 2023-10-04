#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c; cin >> a >> b >> c;

    if (a > b) cout << "Takahashi";
    else if (a < b) cout << "Aoki";
    else if (c == 0) cout << "Aoki";
    else cout << "Takahashi";
    
    return 0;
}