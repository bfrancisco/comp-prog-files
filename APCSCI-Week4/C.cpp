#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, x, wait = 0; 
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    //for (int x : a) {cout << x << " ";} cout << endl;
    
    int ans = 0;
    for (int x : a){
        if (wait <= x) {ans++; wait += x;}
    }

    cout << ans;

    return 0;
}