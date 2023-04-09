#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int a[100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int g = a[0];
    for (int i = 1; i < n; i++)
        g = gcd(g, a[i]);
    
    cout << g << endl;
    

    return 0;
}