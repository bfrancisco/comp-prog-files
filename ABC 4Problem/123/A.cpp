#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> a(5, 0);
    for (int i = 0; i < 5; i++){
        cin >> a[i];
    }

    int k; cin >> k;
    string ans = "Yay!";
    for (int i = 0; i < 4; i++){
        for (int j = i+1; j < 5; j++){
            if (a[j] - a[i] > k)
                ans = ":(";
        }
    }

    cout << ans << endl;

    return 0;
}