#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int LIMIT = 300010;
    int n; cin >> n;
    int legs[LIMIT];
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        legs[x] = 1;
    }
    int s, t;
    cin >> s >> t;



    return 0;
}