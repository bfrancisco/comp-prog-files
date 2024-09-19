#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(){

    ordered_set s;
    s.insert(1);
    s.insert(3);
    s.insert(4);
    int x; cin >> x;
    cout << s.order_of_key(x) << endl;

    return 0;
}