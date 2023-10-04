#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
vector<pair<double, double>> a; 

struct sort_second {
    bool operator()(pair<double,double> &left, <double,double> &right) {
        return left.second < right.second;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        double a, b; cin >> a >> b; 
        a[i] = {a, b};
    }

    sort(a.begin(), a.end(), sort_second());

    

    return 0;
}