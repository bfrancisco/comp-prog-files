#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    if (n==0){
        cout << 0 << endl;
        return 0;
    }

    ll mul = 1;
    vector<int> ans;

    while(n != 0){
        if (n % abs(mul*2)){n-=mul; ans.push_back(1);}
        else ans.push_back(0);
        mul *= -2;
    }
    
    for (int i = ans.size()-1; i >= 0; i--){
        cout << ans[i];
    }
    

    return 0;
}