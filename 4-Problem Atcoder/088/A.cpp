#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, a; cin >> n >> a;

    if (a >= (n%500)) cout << "Yes";
    else cout << "No";

    return 0;
}