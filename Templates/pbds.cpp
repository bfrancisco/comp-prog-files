#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ordered_set s;
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.order_of_key(3); // index when 3 is inserted OR how many values are to the left of 3
    s.find_by_order(0); // what is in index i
    cout << s.order_of_key(3) << endl;
    cout << s.order_of_key(4) << endl;

    return 0;
}