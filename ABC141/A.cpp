#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string a[3] = {"Sunny", "Cloudy", "Rainy"};
    string s; cin >> s;
    if (s==a[0]) cout << a[1];
    else if (s==a[1]) cout << a[2];
    else cout << a[0];

    return 0;
}