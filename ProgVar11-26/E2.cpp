#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool hasp = false;
int n, t, d, order, ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    // vector<pair<int, int>> a;

    cin >> t >> d;
    order = d;
    ans = t + 10;
    // cout << ans << endl;
    for (int i = 1; i < n; i++){
        cin >> t >> d;
        // a.push_back({t, d});

        if(t>ans && hasp){
            hasp = false;
            ans += 10;
            order = 1 - order;
        }

        if (order == d){
            if (t < ans) ans = t + 10;
            else{
                if (hasp){
                    ans += 10;
                    hasp = false;
                }
                ans = max(ans + 10, t + 10);
            }
        }
        else{
            if (t < ans) {
                hasp = true;
            }
            else{
                if (hasp){
                    ans += 10;
                    hasp = false;
                }
                ans = max(ans, t + 10);
                order = 1 - order;
            }
        }
        // cout << ans << endl;
    }
    if (hasp){
        
        ans += 10;
    }
    cout << ans << endl;
    

    
    return 0;
}