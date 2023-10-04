#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m, q, a, b, c, d;
ll ans = -1;
vector<vector<int>> vec;

void rec(int chosen[], int arr[], int index, int n, int start, int end){
    if (index == n){
        // for (int i = 0; i < n; i++)
        //     cout << chosen[i] << " ";
        // cout << endl;
        ll score = 0;
        for (auto e : vec){
            if (chosen[e[1]] - chosen[e[0]] == e[2])
                score += e[3];
        }
        ans = max(score, ans);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        rec(chosen, arr, index + 1, n, i, end);
    }
    return;
}

void combRep(int arr[], int m, int n){
    int chosen[n+1];

    rec(chosen, arr, 0, n, 0, m-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> q;
    vec.resize(q);
    for (int i = 0; i < q; i++){
        cin >> a >> b >> c >> d;
        vec[i].push_back(a-1);
        vec[i].push_back(b-1);
        vec[i].push_back(c);
        vec[i].push_back(d);
    }

    int arr[10];
    for (int i = 0; i < m; i++){
        arr[i] = i;
    }
    combRep(arr, m, n);

    cout << ans;
    return 0;
}