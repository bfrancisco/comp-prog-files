#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct{
    bool operator()(int a, int b) const { return abs(a) < abs(b);}
}
abscomp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), abscomp);
    for (int i = 0; i < n; i++) cout << a[i] << endl;
    return 0;
}