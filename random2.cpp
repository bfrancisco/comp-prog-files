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

    ordered_set s;
    s.insert(1);
    s.insert(9);
    s.insert(5);
    s.insert(3);
    s.insert(7);

    cout << s.order_of_key(5) << endl;
    cout << s.order_of_key(7) << endl;
    cout << s.order_of_key(0) << endl;
    cout << s.order_of_key(10) << endl;

    return 0;
}