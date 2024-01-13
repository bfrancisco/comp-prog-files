#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m; cin >> m;
    map<int, int> db;
    for (int i = 0; i <= 29; i++) db[i] = 0;

    while(m--){
        int c, bit;
        cin >> c >> bit;
        
        if (c == 1) db[bit]++;
        else{
            int gud = 1;
            int have = 0;
            for (int i = 0; i <= 29; i++){
                have = (int)have/2 + db[i];

                if (bit & (1 << i)){
                    if (have) have--;
                    else { gud = 0; break; }
                }
                
            }
            
            cout << (gud ? "YES" : "NO") << endl;
        }
    }

    return 0;
}