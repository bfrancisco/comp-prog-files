#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    ll sm = n*(n+1)/2;
    if (sm % 2) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;

    set<int> a;

    ll tmp = sm/2;
    ll hi = n;
    while (tmp > 0){
        if (tmp - hi >= 0){
            tmp -= hi;
            a.insert(hi);
            hi--;
        }
        else{
            a.insert(tmp);
            break;
        }
    }


    int i = 1;
    vector<int> b;
    cout << a.size() << endl;
    for (auto e : a){
        // cout << "cur: " << e << "   ";
        while (i != e){
            // cout << i << " ";
            b.push_back(i);
            i++;
        }
        // cout << endl;
        cout << e << " ";
        i++;
    }

    cout << endl << b.size() << endl;
    for (auto e : b) cout << e << " "; cout << endl;

    
    return 0;
}