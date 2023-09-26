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
    for (int i = 0, j = k; j < n; i++, j++){
        if (a[i] == *itmed){
            if (a[j] >= *itmed){
                
            }
            else{
                
            }
            continue;
        }
        
        // add left rem right


        cout << *itmed << " ";
    }
    cout << endl;
    return 0;
}

// 8 3
// 2 4 3 5 8 1 2 1

// 1 3 3 3 9