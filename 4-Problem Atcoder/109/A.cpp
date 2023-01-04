#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c; cin >> a >> b;
    for (c=1; c <= 3; c++)
        if ((a*b*c) % 2 == 1)
            {cout << "Yes"; return 0;}
    cout << "No";
    return 0;
}