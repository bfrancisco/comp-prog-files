#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x; cin >> x;
    if (x==3 || x==5 || x==7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}