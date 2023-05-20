#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    string s; cin >> s;

    // u can only have k number of flips.
    // slide through the bits, then if k flips are done, store contiguous 1s and reset the sliding

    int l = 0, r = 0;
    int ans = 0, count = 0;
    char prev = ' ';
    while (true){
        // cout << l << " " << r << endl;
        if (r == n){
            ans = max(ans, r-l);
            break;
        }
        if (s[r] == prev){
            r++;
            continue;
        }
        if (s[r] == '0'){
            count++;
            if (count > k){
                ans = max(ans, r-l);
                while (count > k){
                    if (s[l] == '0' && s[l+1] == '1'){
                        count--;
                    }
                    l++;
                }
            }
        }
        prev = s[r];
        r++;
    }

    cout << ans << endl;
    return 0;
}