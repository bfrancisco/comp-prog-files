#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<char> good(n, 'e');
    int ans = 0;
    while (k--){
        int move = 0; // left
        int pas = 1;
        for (int i = 0; i < n; i++){
            if (good[i] != 'e'){
                move = (good[i] == 'L' ? 0 : 1);
                continue;
            }
            // L good
            if (s[i] == 'L'){
                if (move == 0)
                    good[i] = 'L';
                else{
                    good[i] = 'R';
                    pas = 0;
                    break;
                }
            }
            else if (s[i] == 'R'){
                if (move == 1)
                    good[i] = 'R';
                else{
                    good[i] = 'L';
                    pas = 0;
                    break;
                }
            }
            move = 1 - move;
        }
        if (pas)
            ans++;
    }
    cout << ans << endl;
    return 0;
}