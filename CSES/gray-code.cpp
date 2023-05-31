#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string a[1<<17];

int n;
void f(int x){
    if (x > n) return;

    // generate
    for (int i = 0; i < (1<<(x-1)); i++){
        a[i] = "0" + a[i];
    }

    // generate reverse
    int sub = (1<<(x-1)) - 1;
    for (int i = (1<<(x-1)); i < (1<<x); i++){
        a[i] = "1" + a[sub].substr(1);
        sub--;
    }

    f(x+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    a[0] = "0";
    a[1] = "1";
    cin >> n;
    f(2);

    for (int i = 0; i < 1<<n; i++){
        cout << a[i] << endl;
    }

    return 0;
}