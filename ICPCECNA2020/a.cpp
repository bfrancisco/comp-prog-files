#include<bits/stdc++.h>
using namespace std;
using ll = long long;


map<string, vector<string>> adj;

void get_ascendants(vector<string>& asc, string child){
    for (auto par : adj[child]){
        asc.push_back(par);
        get_ascendants(asc, par);
    }
}

void direct_desc(string a, string b, int ascore, int bscore){
    if (bscore == 1){
        cout << b << " is the child of " << a << endl;
    }
    else{
        cout << b << " is the ";
        for (int i = 0; i < bscore-2; i++) cout << "great ";
        cout << "grandchild of " << a << endl;
    }
}

string suf(int x){
    if (11 <= x%100 && x%100 <= 13){
        return to_string(x) + "th";
    }
    if (x%10==1){
        return to_string(x) + "st";
    }
    if (x%10==2){
        return to_string(x) + "nd";
    }
    if (x%10==3){
        return to_string(x) + "rd";
    }
    return to_string(x) + "th";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t, q;
    cin >> t >> q;
    for (int i = 0; i < t; i++){
        string parent;
        cin >> parent;
        int x;
        cin >> x;
        while (x--){
            string child;
            cin >> child;
            adj[child].push_back(parent);
        }
    }

    while (q--){
        string a, b;
        cin >> a >> b;
        vector<string> ascend_a = {a}, ascend_b = {b};
        get_ascendants(ascend_a, a);
        get_ascendants(ascend_b, b);
        set<string> s_ascend_a, s_ascend_b;
        for (auto e : ascend_a) s_ascend_a.insert(e);
        for (auto e : ascend_b) s_ascend_b.insert(e);

        string lca;
        for (int i = 0; i < ascend_a.size(); i++){
            if (s_ascend_b.find(ascend_a[i]) != s_ascend_b.end()){
                lca = ascend_a[i];
                break;
            }
        }

        int ascore = 0, bscore = 0;
        while (ascend_a[ascore] != lca) ascore++;
        while (ascend_b[bscore] != lca) bscore++;

        // cout << ascore << " " << bscore << endl;
        int mn = min(ascore, bscore);
        int mx = max(ascore, bscore);
        
        if (mn == 0){
            if (mn == ascore) direct_desc(a, b, ascore, bscore);
            else direct_desc(b, a, bscore, ascore);
        }
        else if (mn == 1 && mn == mx){
            cout << a << " and " << b << " are " << "siblings" << endl;
        }
        else{
            cout << a << " and " << b << " are " << suf(mn-1) << " cousins";
            if (abs(ascore-bscore)){
                cout << ", " << abs(ascore-bscore) << " time";
                if (abs(ascore-bscore) > 1) cout << "s";
                cout << " removed";
            } 
            
            
            cout << endl; 
        }
    }
    

    return 0;
}