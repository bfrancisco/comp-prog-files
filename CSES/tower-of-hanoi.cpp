#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void f(int n, int cur, int nex, int tem){
    if (n <= 0) return;

    f(n-1, cur, tem, nex);
    cout << cur << " " << nex << endl;
    f(n-1, tem, nex, cur);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    cout << pow(2, n) - 1 << endl;
    f(n,1,3,2);


    return 0;
}