#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;



void solve(){
    int n, m; cin >> n >> m;

    vector<int> seats(m+1, -1);
    vector<int> st;
    int le=0, ri=0;

    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        if (x == 0)
            st.push_back(i);
        else if (x==-1)
            le++;
        else
            ri++;
    }

    sort(st.begin(), st.end());
    int stn = st.size();
    for (int i = 0; i < stn; i++){
        seats[st[i]] = 0;
    }
    int ans = stn;

    if (stn > 1){
        int md = st[stn/2] - 1;
        int ans2 = stn, ans3 = stn;
        while(le > 0 && md > 0){
            if (seats[md] == -1){
                seats[md] = 1;
                ans2++;
            }
        }
        while(ri > 0 && md > 0){
            if (seats[md] == -1){
                seats[md] = 1;
                ans2++;
            }
        }
        if (stn%2==0){
            
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}