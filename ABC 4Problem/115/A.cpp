#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int d; cin >> d;
    if (d == 25)
        cout << "Christmas";
    else if (d == 24)
        cout << "Christmas Eve";
    else if (d == 23)
        cout << "Christmas Eve Eve";
    else if (d == 22)
        cout << "Christmas Eve Eve Eve";
    return 0;
}