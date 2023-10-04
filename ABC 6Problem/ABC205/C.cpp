#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c; cin >> a >> b >> c;

    if (c%2){
        if (a==b) cout << "=";
        else if (a>b) cout << ">";
        else cout << "<";
    }
    else{
        if (abs(a) == abs(b)) cout << "=";
        else if (abs(a) > abs(b)) cout << ">";
        else cout << "<";
    }
    return 0;
}