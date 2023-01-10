#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int a, b, q, n;
vector<pair<ll, pair<char, ll>>> st;

ll bisearch(ll val){
    int l = 2;
    int r = n-3;

    while (r-l > 1){
        int mid = (r+l) / 2;
        if (st[mid].first == val){
            return st[mid].second.second;
        }
        else if (st[mid].first < val){
            l = mid;
        }
        else if (st[mid].first > val){
            r = mid;
        }
    }
    return min( abs(val - st[l].first) + st[l].second.second , abs(val - st[r].first) + st[r].second.second );

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b >> q;
    n = a+b+4;
    ll MAX = 1e13;
    st.push_back({-MAX, {'S', MAX}});
    st.push_back({-MAX, {'T', MAX}});
    for (int i = 0; i < a; i++){
        ll x; cin >> x;
        st.push_back({x, {'S', MAX}});
    }
    for (int i = 0; i < b; i++){
        ll x; cin >> x;
        st.push_back({x, {'T', MAX}});
    }

    sort(st.begin(), st.end());
    st[0].first = MAX;
    st[1].first = MAX;
    st.push_back({MAX, {'S', MAX}});
    st.push_back({MAX, {'T', MAX}});

    // for (auto e : st){
    //     cout << e.first << " " << e.second.first << " " << e.second.second << endl;
    // }
    // int pause; cin >> pause;

    int s = 2, t = 2;
    while (s < n-2 && t < n-2){
        if (s < t){
            st[s].second.second = min(st[s].second.second, st[t].first - st[s].first);
            st[t].second.second = min(st[t].second.second, st[t].first - st[s].first);
            s++;
        }
        else if (t < s){
            st[t].second.second = min(st[t].second.second, st[s].first - st[t].first);
            st[s].second.second = min(st[s].second.second, st[s].first - st[t].first);
            t++;
        }
        else if (s == t){
            if (st[s].second.first == 'T'){
                while(st[s].second.first != 'S') s++;
            }
            else if (st[s].second.first == 'S'){
                while(st[t].second.first != 'T') t++;
            }
        }
    }

    // reverse
    s = n-3;
    t = n-3;
    while (s > 1 && t > 1){
        if (s < t){
            st[s].second.second = min(st[s].second.second, st[t].first - st[s].first);
            st[t].second.second = min(st[t].second.second, st[t].first - st[s].first);
            t--;
        }
        else if (t < s){
            st[t].second.second = min(st[t].second.second, st[s].first - st[t].first);
            st[s].second.second = min(st[s].second.second, st[s].first - st[t].first);
            s--;
        }
        else if (s == t){
            if (st[s].second.first == 'T'){
                while(st[s].second.first != 'S') s--;
            }
            else if (st[s].second.first == 'S'){
                while(st[t].second.first != 'T') t--;
            }
        }
    }

    // for (auto e : st){
    //     cout << e.first << " " << e.second.first << " " << e.second.second << endl;
    // }

    while (q--){
        ll x; cin >> x;
        cout << bisearch(x) << endl;
    }
    return 0;
}   