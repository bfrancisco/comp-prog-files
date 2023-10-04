#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0;

    for (auto x : s){
        if (x == '1') a++;
        else b++;
    }

    cout << n - abs(a-b);
    
    return 0;
}   