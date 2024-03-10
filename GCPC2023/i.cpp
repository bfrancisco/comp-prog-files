#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using indexed_set = tree<T,null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    indexed_set <int> os;
    int n; cin >> n; 
    vector <int> arr(n);
    set<int> st;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        st.insert(arr[i]);
    }
    for (int i = 1; i <= (int)1e6 + 2*int(1e5) + 10; i++){
        if (st.find(i) == st.end()) os.insert(i);
    }
 
    int m; cin >> m;
    for (int i = 0; i <m; i++){
        int temp; cin >> temp;
        int t = *os.find_by_order(os.order_of_key(arr[temp-1]));
        cout << t << "\n";
        os.erase(t);
        os.insert(arr[temp-1]);
        arr[temp-1] = t;
    }
}