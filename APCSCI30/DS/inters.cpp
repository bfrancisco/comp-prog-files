#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<tuple<int, int, int, char>> sweep;
    for (int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) a.push_back({a, b, d, 'V'});
        else{
            a.push_back({a, b, d, 'S'});
            a.push_back({c, b, d, 'E'});
        }
    }

    sort(sweep.begin(), sweep.end());

    set<int> curY;
    int ans = 0;
    for (auto& t : sweep){
        int x = get<0>(t);
        int yone = get<1>(t);
        int ytwo = get<2>(t);
        char con = get<3>(t);

        if (con == 'S'){
            curY.insert(yone);
        }
        else if (con == 'E'){
            curY.erase(yone);
        }
        else if (con == 'V'){
            if (yone > ytwo) swap(yone, ytwo);

            
        }
    }


    return 0;
}