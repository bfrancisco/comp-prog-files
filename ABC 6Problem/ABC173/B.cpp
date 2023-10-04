#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int ac = 0, wa = 0, tl = 0, re = 0;
    while(n--){
        string s; cin >> s;
        if (s == "AC") ac++;
        else if (s == "WA") wa++;
        else if (s == "TLE") tl++;
        else re++;
    }

    cout << "AC x " << ac << endl;
    cout << "WA x " << wa << endl;
    cout << "TLE x " << tl << endl;
    cout << "RE x " << re << endl;


    return 0;
}