#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, x, y, time = 0; 
    cin >> n;
    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++){
        cin >> x >> y;
        a.push_back(make_pair(y, x));
    }
    sort(a.begin(), a.end());

    int pas = 1;
    for (auto p : a){
        if (time + p.second > p.first) {pas = 0; break;}
        time += p.second;
    }
    pas ? cout << "Yes" : cout << "No";

    return 0;
}