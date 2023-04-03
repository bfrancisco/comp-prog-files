#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int d, n; cin >> d >> n;
    vector<int> a(d), b(d);

    for (int i = 0; i < d; i++) cin >> a[i];
    for (int i = 0; i < d; i++) cin >> b[i];
    for (int i = 0; i < n; i++){
        bool pas = true;
        for (int j = 0; j < d; j++){
            int x; cin >> x;
            if (x < a[j]-b[j] || x > a[j])
                pas = false;
        }
        if (pas) cout << "SUS" << endl;
        else cout << "INNOCENT" << endl;
    }
    return 0;
}