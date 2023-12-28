#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void solve(){
    int n; ll sx, sy;
    cin >> n >> sx >> sy;
    vector<pair<ll, char>> HV(n);
    vector<ll> ans(n, 0);
    ll htot = 0, vtot = 0;
    for (int i = 0; i < n; i++){
        ll val; char ori;
        cin >> val >> ori;
        HV[i] = {val, ori};
        if (ori == 'H') htot += val;
        else vtot += val;
    }
    vector<pair<ll, int>> Hsort, Vsort;
    for (int i = 0; i < n; i++){
        if (HV[i].second == 'H'){
            Hsort.push_back({HV[i].first, i});
        }
        else{
            Vsort.push_back({HV[i].first, i});
        }
    }
    sort(Hsort.begin(), Hsort.end(), greater<pair<ll, int>>());
    sort(Vsort.begin(), Vsort.end(), greater<pair<ll, int>>());
    int hsn = Hsort.size(), vsn = Vsort.size();
 
    // check if can reach 0,0
    if (htot < abs(sx) || vtot < abs(sy)) { cout << "NO" << endl; return; }
 
    // case when cant change parity (all are 1)
    if ((!Hsort.empty() && Hsort[0].first == 1ll && hsn%2 != abs(sx)%2ll) || 
        (!Vsort.empty() && Vsort[0].first == 1ll && vsn%2 != abs(sy)%2ll)){
            cout << "NO" << endl; return;
    }
 
    // // starts at origin case
    // if ((sx == 0ll && hsn%2) || (sy == 0ll && vsn%2)){
    //     cout << "NO" << endl; return;
    // }
 
    // case hsn == 1.
    if (hsn == 1){
        ans[Hsort[0].second] = -sx; // negate bc we go to origin
        sx = 0;
    }
    // case hsn == 1.
    if (vsn == 1){
        ans[Vsort[0].second] = -sy; // negate bc we go to origin
        sy = 0;
    }
 
    // case hsn >= sx. 
    if (hsn > 1 && hsn >= abs(sx)){
        if (hsn%2 != abs(sx)%2ll){
            // assert(Hsort[0].first > 1);
            ans[Hsort[0].second] = 2ll * (sx >= 0 ? -1ll : 1ll); // towards origin
            sx += 2ll * (sx >= 0 ? -1ll : 1ll);
            for (int i = 1; i < hsn; i++){
                if (sx > 0) { ans[Hsort[i].second]--; sx--; }
                else        { ans[Hsort[i].second]++; sx++; }
            }
        }
        else{
            for (int i = 0; i < hsn; i++){
                if (sx > 0) { ans[Hsort[i].second]--; sx--; }
                else        { ans[Hsort[i].second]++; sx++; }
            }
        }
    }
    // case vsn >= sy.
    if (vsn > 1 && vsn >= abs(sy)){
        if (vsn%2 != abs(sy)%2ll){
            // assert(Vsort[0].first > 1);
            ans[Vsort[0].second] = 2ll * (sy >= 0 ? -1ll : 1ll); // towards origin
            sy += 2ll * (sy >= 0 ? -1ll : 1ll);
            for (int i = 1; i < vsn; i++){
                if (sy > 0) { ans[Vsort[i].second]--; sy--; }
                else        { ans[Vsort[i].second]++; sy++; }
            }
        }
        else{
            for (int i = 0; i < vsn; i++){
                if (sy > 0) { ans[Vsort[i].second]--; sy--; }
                else        { ans[Vsort[i].second]++; sy++; }
            }
        }
    }
 
    // case hsn < sx. go to origin and do hsn >= sx case
    if (hsn > 1 && hsn < abs(sx)){
        int i = 0;
        if (sx < 0){
            for (; i < hsn; i++){
                // from left
                if (sx + Hsort[i].first < 0){
                    sx += Hsort[i].first;
                    ans[Hsort[i].second] += Hsort[i].first;
                    // Hsort[i].first = 0;
                }
                else if (sx + Hsort[i].first >= 0){
                    // Hsort[i].first -= abs(sx);
                    ans[Hsort[i].second] += abs(sx);
                    sx = 0;
                    break;
                }
            }
        }
        else if (sx > 0){
            for (; i < hsn; i++){
                // from right
                if (sx - Hsort[i].first > 0){
                    sx -= Hsort[i].first;
                    ans[Hsort[i].second] -= Hsort[i].first;
                    // Hsort[i].first = 0;
                }
                else if (sx - Hsort[i].first <= 0){
                    // Hsort[i].first -= abs(sx);
                    ans[Hsort[i].second] -= abs(sx);
                    sx = 0;
                    break;
                }
            }
        }
        i++;
        if (hsn%2 != i%2 && i < hsn){
            // adjust highest element then do the +1 -1
            sx += 1ll*(ans[Hsort[0].second] > 0 ? -1ll : 1ll);
            ans[Hsort[0].second] += 1ll*(ans[Hsort[0].second] > 0 ? -1ll : 1ll);
            
        }
        for (; i < hsn; i++){
            if (sx > 0) { ans[Hsort[i].second]--; sx--; }
            else        { ans[Hsort[i].second]++; sx++; }
        }
    }
    // case vsn < sy. go to origin and do vsn >= sy case
    if (vsn > 1 && vsn < abs(sy)){
        int i = 0;
        if (sy < 0){
            for (; i < vsn; i++){
                // from left
                if (sy + Vsort[i].first < 0){
                    sy += Vsort[i].first;
                    ans[Vsort[i].second] += Vsort[i].first;
                    // Vsort[i].first = 0;
                }
                else if (sy + Vsort[i].first >= 0){
                    // Vsort[i].first -= abs(sy);
                    ans[Vsort[i].second] += abs(sy);
                    sy = 0;
                    break;
                }
            }
        }
        else if (sy > 0){
            for (; i < vsn; i++){
                // from right
                if (sy - Vsort[i].first > 0){
                    sy -= Vsort[i].first;
                    ans[Vsort[i].second] -= Vsort[i].first;
                    // Vsort[i].first = 0;
                }
                else if (sy - Vsort[i].first <= 0){
                    // Vsort[i].first -= abs(sy);
                    ans[Vsort[i].second] -= abs(sy);
                    sy = 0;
                    break;
                }
            }
        }
        i++;
        if (vsn%2 != i%2 && i < vsn){
            // adjust highest element then do the +1 -1
            sy += 1ll*(ans[Vsort[0].second] > 0 ? -1ll : 1ll);
            ans[Vsort[0].second] += 1ll*(ans[Vsort[0].second] > 0 ? -1ll : 1ll);
            
        }
        for (; i < vsn; i++){
            if (sy > 0) { ans[Vsort[i].second]--; sy--; }
            else        { ans[Vsort[i].second]++; sy++; }
        }
    }
    
    int pas = 1;
    for (auto e : ans){
        if (e == 0) pas = 0;
    }
    if (!pas){ cout << "NO" << endl; return; }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
        // assert(ans[i] != 0);
        if (HV[i].second == 'H'){
            cout << abs(ans[i]) << " " << (ans[i] > 0 ? "E" : "W") << endl;
        }
        else{
            cout << abs(ans[i]) << " " << (ans[i] > 0 ? "N" : "S") << endl;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
 
    return 0;
}