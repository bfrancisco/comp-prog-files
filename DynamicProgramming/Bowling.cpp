#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/lecture-15-dynamic-programming-part-1-srtbot-fib-dags-bowling/
// 38:00 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> v(n), B(n+5, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = n; i >= 0; i--){
        B[i] = max({B[i+1], 
                    B[i+1] + v[i], 
                    (i+1 < n ? B[i+2] + v[i]*v[i+1] : (int)-1e9)});
    }
    cout << B[0] << endl;

    return 0;
}