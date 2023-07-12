#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,k,q; cin >> n >> k >> q;
    int qq = q;
    vector<int> a(n+1,0);
    while(qq--){
        int x; cin >> x;
        a[x]++;
    }

    for (int i = 1; i <= n; i++){
        cout <<  ((q-a[i]) < k ? "Yes" : "No") << endl;
        // cout << a[i] << " ";
    }
        
    
    return 0;
}