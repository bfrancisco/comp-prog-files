#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    int x = b*10 + c;
    if (x % 4 == 0)
        cout << "YES";
    else 
        cout << "NO";
    
    return 0;
}   