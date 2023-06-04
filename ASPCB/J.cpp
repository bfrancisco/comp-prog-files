#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;


int main() {
    // 1000000000
    int l = 1, r = 1000000000, m;
    // int ans;
    // int m;
    while (r-l > 0){
        // cout << l << " " << r << endl;
        m = (r+l) / 2;
        cout << "throw " << m << endl;
        fflush(stdout);

        string res; cin >> res;

        if (res == "break"){
            break;
        }
        else if (res == "survive"){
            l = m+1;
        }
        else if (res == "orbit"){
            r = m-1;
        }
        else{
            return 0;
        }
    }
    m = (r+l) / 2;
    if (m == 0) m = 1;
    else if (m > 1000000000) m = 1000000000;
    cout << "answer " << m << endl;
    fflush(stdout); 
    
    return 0;
}