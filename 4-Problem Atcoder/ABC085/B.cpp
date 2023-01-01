#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    unordered_set<int> a;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.insert(x);
    }
    cout << a.size();

    return 0;
}