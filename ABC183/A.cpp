#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double a,b,c,d; cin >> a >> b >> c >> d;
    cout << ((c-a)/(abs(b)+d))*(abs(b)+a);
    return 0;
}