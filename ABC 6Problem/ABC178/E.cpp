#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,a,b;
    cin >> n;
    int bnd = 2000000001;
    int addmx = -bnd, addmn = bnd, submx = -bnd, submn = bnd; 
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        addmx = max(addmx, a+b);
        submx = max(submx, a-b);
        addmn = min(addmn, a+b);
        submn = min(submn, a-b);
    }

    cout << max(addmx - addmn, submx - submn) << endl;


    return 0;
}