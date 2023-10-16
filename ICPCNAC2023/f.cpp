#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isperfect(ll n){
    ll root = 1;
    while (root * root < n){
        root++;
        if (root * root == n) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll area = 0;
    vector<pair<int, int>> AB(4);
    for (int i = 0; i < 4; i++){
        ll a, b; cin >> a >> b;
        AB[i] = {a, b};
        area += a * b;
    }
    // cout << area << endl;
    if (!isperfect(area)){
        cout << 0 << endl; return 0;
    }
    // cout << "GOOD AREA" << endl;
    ll root = 1;
    while (root * root < area)
        root++;

    sort(AB.begin(), AB.end());
    bool gud = false;
    // if 0, rotate. if 1, do not
    do{
        for (int bit = 0; bit < (1<<4); bit++){
            vector<ll> r(4), c(4);
            for (int i = 0; i < 4; i++){
                if (bit & (1 << i)){
                    r[i] = AB[i].first;
                    c[i] = AB[i].second;
                }
                else{
                    r[i] = AB[i].second;
                    c[i] = AB[i].first;
                }
            }
            // 1-indexed
            int cases = 17;
            vector<ll> top(cases+1), dow(cases+1), lef(cases+1), rig(cases+1);
            // 1
            top[1] = c[0] + c[1];
            dow[1] = c[2] + c[3];
            lef[1] = r[0] + r[2];
            rig[1] = r[1] + r[3];
            // 2
            top[2] = c[0];
            dow[2] = c[1] + c[2] + c[3];
            lef[2] = r[0] + r[1];
            rig[2] = r[0] + r[3];
            // 3
            top[3] = c[0] + c[1];
            dow[3] = c[0] + c[3];
            lef[3] = r[0];
            rig[3] = r[1] + r[2] + r[3];
            // 4
            top[4] = c[0] + c[1];
            dow[4] = c[3] + c[1];
            lef[4] = r[0] + r[2] + r[3];
            rig[4] = r[1];
            // 5
            top[5] = c[0] + c[1] + c[2];
            dow[5] = c[3];
            lef[5] = r[0] + r[3];
            rig[5] = r[2] + r[3];
            // 6
            top[6] = c[0] + c[1] + c[2] + c[3];
            dow[6] = c[0] + c[1] + c[2] + c[3];
            lef[6] = r[0];
            rig[6] = r[3];
            // 7
            top[7] = c[0];
            dow[7] = c[3];
            lef[7] = r[0] + r[1] + r[2] + r[3];
            rig[7] = r[0] + r[1] + r[2] + r[3];
            // 8
            top[8] = c[0] + c[1] + c[2];
            dow[8] = c[3] + c[1] + c[2];
            lef[8] = r[0] + r[3];
            rig[8] = r[2];
            // 9
            top[9] = c[0] + c[1] + c[2];
            dow[9] = c[0] + c[3] + c[2];
            lef[9] = r[0];
            rig[9] = r[2];
            // 10
            top[10] = c[0] + c[1] + c[2];
            dow[10] = c[0] + c[1] + c[3];
            lef[10] = r[0];
            rig[10] = r[2] + r[3];
            // 11
            top[11] = c[0] + c[1];
            dow[11] = c[3];
            lef[11] = r[0] + r[2] + r[3];
            rig[11] = r[1] + r[2] + r[3];
            // 12
            top[12] = c[0];
            dow[12] = c[3];
            lef[12] = r[0] + r[1] + r[3];
            rig[12] = r[0] + r[2] + r[3];
            // 13
            top[13] = c[0];
            dow[13] = c[2] + c[3];
            lef[13] = r[0] + r[1] + r[2];
            rig[13] = r[0] + r[1] + r[3];
            // 14
            top[14] = c[0];
            dow[14] = c[1] + c[3];
            lef[14] = r[0] + r[1];
            rig[14] = r[0] + r[2] + r[3];
            // 15
            top[15] = c[0];
            dow[15] = c[2] + c[3];
            lef[15] = r[0] + r[1] + r[2];
            rig[15] = r[0] + r[3];
            // 16
            top[16] = c[0] + c[1];
            dow[16] = c[3];
            lef[16] = r[0] + r[3];
            rig[16] = r[1] + r[2] + r[3];
            // 17
            top[17] = c[0] + c[1];
            dow[17] = c[3];
            lef[17] = r[0] + r[2] + r[3];
            rig[17] = r[1] + r[3];

            for (int i = 1; i <= cases; i++){
                if (top[i]==root && top[i]==dow[i] && lef[i]==root && lef[i]==rig[i]){
                    gud = true;
                    break;
                }
            }
        }
        if (gud) break;
    } while(next_permutation(AB.begin(), AB.end()));
    

    cout << (gud ? 1 : 0) << endl;
    return 0;
}
