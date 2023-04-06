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

    sort(a, a+n);
        


    return 0;
}