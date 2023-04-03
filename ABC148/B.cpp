#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    string a, b; cin >> a >> b;

    for (int i = 0; i < n; i++){
        cout << a[i] << b[i];
    }
    
    return 0;
}   