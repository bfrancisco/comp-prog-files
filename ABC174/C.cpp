#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k; cin >> k;
    int val = 7;
    for (int i = 1; i <= 1000000; i++){
        if (val % k == 0){
            cout << i; return 0;
        }
        val = (val * 10 + 7) % k;
    }

    cout << -1;
    return 0;
}