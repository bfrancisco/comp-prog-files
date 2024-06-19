#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

double f(double x, double y, double xx, double yy){
    return sqrtf((x-xx)*(x-xx) + (y-yy)*(y-yy));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<double> X(n), Y(n);
    for (int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
    }

    vector<int> perm(n);
    for (int i = 0; i < n; i++){
        perm[i] = i;
    }

    double tot = 0;
    double denom = 0;
    do{
        // for (auto e : perm) cout << e << " "; cout << endl;
        for (int i = 0; i < n-1; i++){
            tot += f(X[perm[i]], Y[perm[i]], X[perm[i+1]], Y[perm[i+1]]);
        }
        denom++;
    }while(next_permutation(perm.begin(), perm.end()));
    
    cout << setprecision(10) << tot / denom << endl;
    return 0;
}