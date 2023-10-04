#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b; cin >> a >> b;
    if (a <= b)
        cout << a;
    else if (a > b)
        cout << a - 1;

    return 0;
}