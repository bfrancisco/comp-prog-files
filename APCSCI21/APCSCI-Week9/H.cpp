#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; 
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int v = 0;
    int ans = 0;
    for (auto x : a){
        if (x == 0){
            ++ans; v = 0;
        }
        else if (x == 1){
            if (v == 2){
                ++ans; v = 0;
            }
            else{
                v = 2;
            }
        }
        else if (x == 2){
            if (v == 1){
                ++ans; v = 0;
            }
            else{
                v = 1;
            }
        }
        else if (x == 3){
            if (v == 1){
                v = 2;
            }
            else if (v == 2){
                v = 1;
            }
            else{
                v = 0;
            }
        }
    }
    cout << ans;
    
    return 0;
}