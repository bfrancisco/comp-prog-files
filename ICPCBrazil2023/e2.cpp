#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    unordered_map<int, int> bank;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (bank.find(a[i]) == bank.end()){
            if (bank.find(a[i]-1) == bank.end()){
                bank[a[i]-1] = 1;
            }
            else{
                bank[a[i]-1]++;
            }
            ans++;
        }
        else{
            bank[a[i]]--;
            if (bank[a[i]] == 0){ bank.erase(a[i]); }
            if (bank.find(a[i]-1) == bank.end()){
                bank[a[i]-1] = 1;
            }
            else{
                bank[a[i]-1]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}