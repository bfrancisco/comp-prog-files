#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> v;
    v.push_back(a[0]);
    
    for (int i = 1; i < n; i++){
        if (a[i] > v.back())
            v.push_back(a[i]);
        else{
            int j = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[j] = a[i];
        }
    }

    cout << v.size() << endl;
    
    return 0;
}