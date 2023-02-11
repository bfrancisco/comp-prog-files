#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, a, c; cin >> t >> a >> c;

    while (t > 0 && a > 0){
        if (c==0) t--;
        else if (c==1) a--;
        c = 1 - c;
    }
    if (t==0 && c == 0){
        if (c==0) cout << "Takahashi";
        else cout << "Aoki";
    }
    else if (t == 0) cout << "Aoki";
    else cout << "Takahashi";
    
    return 0;
}