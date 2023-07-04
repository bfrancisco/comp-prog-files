#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x, y; cin >> x >> y;
    if (x==y) cout << x;
    else if ((x+y)%3 == 0) cout << 0;
    else if ((x+y)%3 == 1) cout << 2;
    else if ((x+y)%3 == 2) cout << 1;

    return 0;
}