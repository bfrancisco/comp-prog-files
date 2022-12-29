#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    unordered_set<char> bag;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        char s; cin >> s;
        bag.insert(s);
    }
    if (bag.size() == 3)
        cout << "Three";
    else
        cout << "Four";

    return 0;
}