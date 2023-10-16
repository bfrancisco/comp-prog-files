#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
typedef long long int ll;

ll t, n, d, a, ans;

ll dp(ll x, ll y){
    if(x <= y + 1){
        return 1;
    }

    if(y == 1){
        return ceil(log2(x));
    }

    return dp(x/3, y-1) + 1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        cin >> n >> d;
        cout << dp(n, d) << endl;
    }
    return 0;
}