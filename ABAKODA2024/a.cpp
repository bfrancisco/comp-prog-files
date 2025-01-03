#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

vector<string> words;
ll A, B, C;
string s;

vector<ll> solve(string pttrn, ll sw, ll hirp, ll quak, ll c){
    ll ra, rb, rc;
    if (pttrn == "abc" || pttrn == "bac"){
        ra = min(sw, quak); 
        quak -= min(sw, quak);
        rb = min(hirp, c);
        c -= min(hirp, c);
        rc = min(quak, c);
    }
    else if (pttrn == "acb"){
        ra = min(sw, quak);
        quak -= min(sw, quak);
        rc = min(quak, c);
        c -= min(quak, c);
        rb = min(c, hirp);
    }
    else if (pttrn == "bca"){
        rb = min(c, hirp);
        c -= min(c, hirp);
        rc = min(quak, c);
        quak -= min(quak, c);
        ra = min(sw, quak);
    }
    else if (pttrn == "cab" || pttrn == "cba"){
        rc = min(quak, c);
        quak -= rc;
        c -= rc;
        ra = min(sw, quak);
        rb = min(c, hirp);
    }
    ll score = A*ra + B*rb + C*rc;
    return {score, ra, rb, rc};
}

int main(){
    words.resize(3);
    words[0] = "squawk";
    words[1] = "chirp";
    words[2] = "quack";

    map<char, ll> freq;
    for (auto ch : "squawkchirp") freq[ch] = 0;

    cin >> A >> B >> C;
    cin >> s;

    for (auto ch : s) freq[ch]++;

    ll sw = 1e9, hirp = 1e9, quak = 1e9, c = 1e9;
    sw = min(freq['s'], freq['w']);
    hirp = min(hirp, freq['h']);
    hirp = min(hirp, freq['i']);
    hirp = min(hirp, freq['r']);
    hirp = min(hirp, freq['p']);
    quak = min(quak, freq['q']);
    quak = min(quak, freq['u']);
    quak = min(quak, freq['a']);
    quak = min(quak, freq['k']);
    c = freq['c'];

    // cout << sw << " " << hirp << " " << quak << " " << c << endl;
    // abc, acb, bac, bca, cab, cba
    vector<string> posi = {"abc", "acb", "bac", "bca", "cab", "cba"};

    ll freqA, freqB, freqC;
    ll mx = -1;
    for (auto p : posi){
        vector<ll> tmp = solve(p, sw, hirp, quak, c);
        ll score = tmp[0], ra = tmp[1], rb = tmp[2], rc = tmp[3];
        // cout << "pattern: " << p << endl << "score: " << score << endl << endl;
        if (mx < score){
            mx = score;
            freqA = ra, freqB = rb, freqC = rc;
        }
    }
    while (freqA--) cout << "squawk ";
    while (freqB--) cout << "chirp ";
    while (freqC--) cout << "quack ";
    cout << "\n";

    return 0;
}