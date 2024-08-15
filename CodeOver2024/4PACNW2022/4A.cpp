#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> words;
vector<char> letters;
map<char, set<char>> impo;
vector<set<char>> out;
bool DONE = false;

bool check(vector<set<char>>& dice, int curlets){
    set<char> uniq;
    for (auto di : dice) for (auto c : di){
        uniq.insert(c);
    }
    if (uniq.size() != curlets) return false;
    

    if (curlets < 18) return true;
    for (auto di : dice){
        for (auto c : di) cout << c;
        cout << " ";
    } cout << "\t";

    for (auto word : words){
        set<int> used;
        for (auto ltr : word){
            for (int d = 0; d < 3; d++){
                if (dice[d].find(ltr) != dice[d].end()){
                    used.insert(d);
                }
            }
        }
        if (used.size() != 3) return false;

    }
    return true;
}

void rb(vector<set<char>>& dice){
    int curlets = dice[0].size() + dice[1].size() + dice[2].size();
    if ((!check(dice, curlets)) || DONE){
        return;
    }
    else if (curlets == 18){
        // good dice
        for (int d = 0; d < 3; d++){
            for (auto c : dice[d]){
                out[d].insert(c);
            }
        }
        DONE = true;
        return;
    }
    
    for (int i = 0; i < 18; i++){
        if (dice[curlets%3].find(letters[i]) != dice[curlets%3].end()) continue;
        dice[curlets%3].insert(letters[i]);
        rb(dice);
        dice[curlets%3].erase(letters[i]);
    }

}

int main(){

    cin >> N;
    words.resize(N);
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    set<char> distinct;

    for (auto c : alpha){
        impo[c];
        impo[c].insert(c);
    }

    for (int i = 0; i < N; i++){
        cin >> words[i];
        for (int j = 0; j < 3; j++){
            char c = words[i][j];
            distinct.insert(c);
            int mtch = 0;
            for (char cc : words[i]){
                if  
            }
        }
    }
    
    if (distinct.size() > 18){
        cout << 0 << endl;
        return 0;
    }

    while (distinct.size() < 18){
        for (auto c : alpha){
            if (distinct.find(c) == distinct.end()){
                distinct.insert(c);
                break;
            }
        }
    }

    

    for (auto c : distinct) letters.push_back(c);

    out.resize(3);

    vector<set<char>> dice(3);
    for (int i = 0; i < 3; i++){
        dice[i].insert(words[0][i]);
    }
    rb(dice);

    // cout << endl << endl;
    for (auto di : out){
        for (auto c : di) cout << c;
        cout << " ";
    }
    cout << endl;


    return 0;
}