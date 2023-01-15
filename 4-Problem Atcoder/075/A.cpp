#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int v[300];
    for (int i = 0; i < 300; i++) v[i] = 0;
    for (int i = 0; i < 3; i++){
        int x; cin >> x;
        v[x+100]++;
    }
    for (int i = 0; i < 201; i++)
        if (v[i] == 1)
            cout << i - 100;

    return 0;
}   