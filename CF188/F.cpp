#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll X, Y;

ll r(ll y){
    // cout << y << endl;
    if (y < X) return X-y;
    if (y == X) return 0;

    if (y%2==0) return min(1 + r(y/2), abs(X-y));
    else if (y%2) return min(min(2 + r((y+1)/2), 2 + r((y-1)/2)), abs(X-y));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> X >> Y;
    cout << r(Y) << endl;
    return 0;
}