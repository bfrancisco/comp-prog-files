#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >>c;

    cout << min(c, b/a);
    
    return 0;
}   