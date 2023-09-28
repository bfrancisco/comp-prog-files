#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> s;
    for (int i = 0; i < k; i++){
        s.insert(a[i]);
    }
    auto itmed = s.begin();
    for (int i = 0; i < (k-1)/2; i++) itmed++;

    cout << *itmed << " ";
    // for (auto e : s) cout << e << " "; cout << endl;
    for (int i = 0, j = k; j < n; i++, j++){
        s.insert(a[j]);
        if (a[i] == *itmed){
            if (a[j] >= *itmed) itmed++;
            else itmed--;
        }
        // pop right push left
        else if (a[i] >= *itmed && a[j] < *itmed){
            itmed--;
        }
        // pop left push right
        else if (a[i] < *itmed && a[j] >= *itmed){
            itmed++;
        }
        if (lower_bound(s.begin(), s.end(), a[i]) == itmed){
            itmed++; 
        }
        s.erase(lower_bound(s.begin(), s.end(), a[i]));

        cout << *itmed << " ";
        // for (auto e : s) cout << e << " "; cout << endl;

    }
    cout << endl;
    return 0;
}

