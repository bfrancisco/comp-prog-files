#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b; cin >> a >> b;

    for (int i = 1; i <= 3; i++){
        if (a != i && b != i){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}   