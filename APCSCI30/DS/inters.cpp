#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<tuple<int, int, int, char>> sweep;
    for (int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) sweep.push_back({a, b, d, 'V'});
        else{
            sweep.push_back({a, b, d, 'S'});
            sweep.push_back({c, b, d, 'E'});
        }
    }

    sort(sweep.begin(), sweep.end());

    ordered_set curY;
    ll ans = 0;
    for (auto& t : sweep){
        int x = get<0>(t);
        int yone = get<1>(t);
        int ytwo = get<2>(t);
        char con = get<3>(t);

        if (con == 'S'){
            curY.insert(yone);
        }
        else if (con == 'E'){
            curY.erase(yone);
        }
        else if (con == 'V'){
            if (yone > ytwo) swap(yone, ytwo);
            ans += ll(curY.order_of_key(ytwo)) - ll(curY.order_of_key(yone));
        }
    }
    cout << ans << endl;


    return 0;
}