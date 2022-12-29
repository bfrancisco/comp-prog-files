#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; 
    cin >> n;
    int c[505], s[505], f[505];
    
    for (int i = 0; i < n-1; ++i){
        cin >> c[i] >> s[i] >> f[i];
    }

    int time;
    queue<int> q;
    for (int i = 0; i < n-1; i++){
        time = 0;
        time = s[i] + c[i];

        for (int j = i+1; j < n-1; j++){
            if (time < s[j]) time = s[j];
            if (time % f[j] != 0) time += (f[j] - (time % f[j]));
            time += c[j];
        }
        
        q.push(time);
    }
    while (!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    cout << 0;

    return 0;
}