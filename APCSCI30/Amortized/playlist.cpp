#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    set<int> bank;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = 0;
    for (; r < n; r++){
        if (bank.find(a[r]) == bank.end()){
            bank.insert(a[r]);
        }
        else{
            ans = max(ans, r-l);
            while(a[l] != a[r]){
                bank.erase(a[l]);
                l++;
            }
            l++;
        }
    }
    ans = max(ans, r-l);

    cout << ans << endl;
    

    return 0;
}