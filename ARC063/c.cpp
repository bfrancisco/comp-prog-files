#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {cin >> a[i]; sm += a[i];}
    sort(a.begin(), a.end());
    if (sm%10==0){
        for (int i = 0; i < n; i++){
            if (a[i] % 10) {sm -= a[i]; break;}
        }
    }
    cout << (sm%10 ? sm : 0) << endl;
    
    return 0;
}