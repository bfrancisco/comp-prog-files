#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int N = n;
    int m = 0;
    while (n){
        m += n%10;
        n /= 10;
    }
    if (N % m == 0) cout << "Yes";
    else cout << "No";
    return 0;
}