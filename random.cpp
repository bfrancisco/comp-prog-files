#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int x = 1; x <= 1060; x++){
        if (x % 11 == 9 and
            x % 14 == 13 and
            x % 9 == 7){
            cout << x << endl;
        }
    }

    return 0;
}