#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

float area(double a, double b, double c){
    double x = min(a, b);
    double y = max(a, b);
    return (x*c) + ((y-x)*c / 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int T[110], V[110];
    T[0] = 0;
    V[0] = 0;
    T[n+1] = 0;
    V[n+1] = 0;
    for (int i = 1; i <= n; i++){
        cin >> T[i] >> V[i];
    }

    int v, t, v0, t0, v1, t1, mxv;
    for (int i = 1; i <= n; i++){
        t = T[i]; v = V[i];
        t0 = T[i-1]; v0 = V[i-1];
        t1 = T[i+1]; v1 = V[i+1];

        if (t < v)
        if (v0 < v){

        }
    }

    

    
    return 0;
}