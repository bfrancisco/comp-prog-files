#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll x, y, a, b, c, z;

class Comp{
public:
    bool operator()(const pair<ll, int>& ap, const pair<ll, int>& bp){
        if (ap.first != bp.first){
            return ap.first < bp.first;
        }
        // red and green, both has same value. prio is the one with more storage
        if (ap.second < 3 && bp.second < 3 && ap.second != bp.second){
            // red green
            if (ap.second == 1 && bp.second == 2){
                return a > b;
            }
            else{
                return b > a;
            }
        }
        // if no color, highest prio
        if (ap.second == 3){
            return true;
        } 
        else if (bp.second == 3){
            return false;
        }
        
        return ap > bp;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> x >> y >> a >> b >> c;
    z = x+y;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, Comp> APS;
    for (int i = 0; i < a; i++) {ll v; cin >> v; APS.push({v, 1});} // red
    for (int i = a; i < a+b; i++) {ll v; cin >> v; APS.push({v, 2});} // green
    for (int i = a+b; i < a+b+c; i++) {ll v; cin >> v; APS.push({v, 3});} // non,highest prio

    ll ans = 0;
    while ((x+y) && z && !APS.empty()){
        ll val = APS.top().first; 
        int color = APS.top().second;
        APS.pop();
        // cout << "ELEMENT: " << val << " " << color << endl;
        if (x == 0 && color == 1) continue;
        else if (y == 0 && color == 2) continue;
        else if (c == 0 && color == 3) continue;
        ans += val;
        if (color == 1){x--; a--; z--;}
        else if (color == 2){y--; b--; z--;}
        else if (color == 3){c--; z--;}
    } 
    cout << ans << endl;
    return 0;
}