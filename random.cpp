#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    tuple<int, pair<int, int>, char> t;
    t = {1, {1, 1}, '#'};

    cout << get<1>(t).first;

    return 0;
}