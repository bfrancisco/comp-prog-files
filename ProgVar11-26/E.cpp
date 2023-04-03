#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

queue<pair<int, int>> q;
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

        if (order == d){
            if (t < ans) ans = t + 10;
            else{
                if (!q.empty()){
                    ans += 10;
                    q.pop();
                }
                while (!q.empty()){
                    int qt, qd;
                    qt = q.front().first;
                    qd = q.front().second;
                    q.pop();
                    ans = qt + 10;
                }
                ans = max(ans + 10, t + 10);
            }
        }
        else{
            if (t < ans) q.push(make_pair(t, d));
            else{
                while (!q.empty()){
                    int qt, qd;
                    qt = q.front().first;
                    qd = q.front().second;
                    q.pop();

                    ans = max(ans, qt + 10);
                    // cout << ans << endl;
                }
                ans = t + 10;
                order = 1 - order;
            }
        }
        // cout << ans << endl;
    }
    while (!q.empty()){
        
        int qt, qd;
        qt = q.front().first;
        qd = q.front().second;
        // cout << "asd" << endl;
        q.pop();
        // cout << qt << " " << qd << endl;
        ans = max(ans + 10, qt + 10);
        // cout << ans << endl;
    }
    cout << ans << endl;
    

    
    return 0;
}