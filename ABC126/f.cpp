#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, k; cin >> m >> k;
    if (k != 0) { cout << -1 << endl; return 0; }

    for (int i = 0; i < (1 << m); i++){
        cout << i << " " << i << " ";
    }
    cout << endl;

    return 0;
}