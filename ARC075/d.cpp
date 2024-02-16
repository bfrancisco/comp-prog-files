#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, a, b; cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    int deltab = 0;
    for (int i = 0; i < n-1; i++){
        if (v[i]-deltab <= 0) break;
        if (v[i] == v[i+1]){
            ans += 1;
            deltab += b;
            continue;
        }

        int dif = max(0, v[i]-deltab) - max(0, v[i+1]-deltab);
        int toadd = min((dif+(a-b)-1) / (a-b), (v[i]-deltab+a-1)/a); 
        ans += toadd;
        deltab += toadd * b;
        cout << ans << " " << dif << endl; 
    }

    if (v[n-1]-deltab > 0){
        ans += (v[n-1]+a-1) / a;
    }
    cout << ans << endl;
    
    
    return 0;
}