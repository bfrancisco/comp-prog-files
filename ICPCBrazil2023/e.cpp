#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    unordered_map<int, int> vtoi;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        vtoi[a[i]] = i;
        if (freq.find(a[i]) == freq.end()){
            freq[a[i]] = 1;
        }
        else{
            freq[a[i]]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (freq[a[i]] == 0) continue;
        int j = i;
        int good = 1;
        while(good && freq[a[j]] > 0){
            freq[a[j]]--;
            if (vtoi.find(a[j]-1) == vtoi.end() || vtoi[a[j] - 1] < vtoi[a[j]]) { good = 0; break; }
            j = vtoi[a[j] - 1];
        }
        ans++;


    }
    cout << ans << endl;

    return 0;
}