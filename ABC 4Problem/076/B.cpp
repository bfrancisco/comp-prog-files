#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k, x = 1; cin >> n >> k;
    
    while (n--){
        if (2*x <= x+k) x *= 2;
        else x += k;
    }
    cout << x;
    return 0;
}