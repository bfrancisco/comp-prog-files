#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, a, b; cin >> n >> a >> b;
    priority_queue<int> q;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        q.push(x);
    }

    int ans = 0;
    int deltab = 0;
    while (!q.empty()){
        int hi1 = q.top(); q.pop();
        cout << deltab << endl;
        if (hi1 - deltab <= 0) break;

        if (q.size() == 0){
            ans += (hi1-deltab+a-1)/a;
            break;
        }
        
        int hi2 = q.top();
        // cout << hi1 << " " << hi2 << endl;
        if (hi1 == hi2){
            if (hi1-deltab - a > 0)
                q.push(hi1 - (a-b));
            ans++;
            deltab += b;
            
            continue;
        }

        int dif = max(0, hi1-deltab) - max(0, hi2-deltab);
        int toadd = min((dif+(a-b)-1) / (a-b), (hi1-deltab+a-1)/a); 
        
        if (hi1-deltab - toadd*a > 0)
            q.push(hi1 - toadd*(a-b));
        ans += toadd;
        deltab += toadd * b;
    }
    cout << ans << endl;
    
    
    
    return 0;
}