#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct{
    bool operator()(int a, int b) const { return abs(a) < abs(b);}
}
abscomp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a = 3;
    a *= 5 + 1;
    cout << a << endl;
    return 0;
}