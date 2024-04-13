#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    map<int, int> db;
    for (int i = 2; i <= 100000; i++){
        db[i] = 0;
    }
    for (int i = 2; i <= 100000; i++){
        for (int d = 2; d <= i; d++){
            if (i %d == 0){
                db[i]++;
            }
        }
    }
    int mx = 0;
    int n = 0;
    for (auto &[k, v] : db){
        if (mx < v){
            mx = v;
            n = k;
        }
    }

    cout << n << " " << mx << endl;

    return 0;
}