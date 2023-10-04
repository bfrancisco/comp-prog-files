#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >>c;

    for (int i = min(a, b); i > 0; i--){
        if (b%i == 0 && a%i == 0){
            if (c==1) {cout << i; break;}
            else c--;
        }
        
    }
    
    return 0;
}   