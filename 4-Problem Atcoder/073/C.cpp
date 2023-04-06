#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    unordered_set<int> s;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (s.find(x) == s.end()){
            s.insert(x);
        }
        else{
            s.erase(x);
        }
    }

    cout << s.size() << endl;

    return 0;
}