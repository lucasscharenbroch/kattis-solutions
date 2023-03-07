#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void init_cin() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}

/*
 * Problem Name: Conga Line
 * Difficulty: 3.6 (Medium)
 * Categories: Linked List
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, Q;
    cin >> N >> Q;

    // Number couples starting with 1, give every second partner the negative of
    // that number. So names[-i] is the name of i's partner.
    unordered_map<int, string> names;
    unordered_map<int, list<int>::iterator> id_to_pos;
    list<int> line;

    rep(i, 1, N + 1) {
        cin >> names[i];
        cin >> names[-i];
        line.push_back(i);
        id_to_pos[i] = --line.end();
        line.push_back(-i);
        id_to_pos[-i] = --line.end();
    }

    cin >> ws; // skip whitespace

    auto mic_pos = line.begin();

    while(Q--) {
        char i;
        cin.get(i);
        if(i == 'F') mic_pos--;
        else if(i == 'B') mic_pos++;
        else if(i == 'R') {
            int person = *mic_pos;
            mic_pos = line.erase(mic_pos);
            if(mic_pos == line.end()) mic_pos = line.begin();
            line.push_back(person);
            id_to_pos[person] = --line.end();
        } else if(i == 'C') {
            int person = *mic_pos;
            mic_pos = line.erase(mic_pos);
            if(mic_pos == line.end()) mic_pos = line.begin();
            line.insert(next(id_to_pos[-person]), person); // insert person behind their partner
        } else if(i == 'P') {
            cout << names[-(*mic_pos)] << endl;
        } else assert(false);
    }

    cout << endl;

    for(int p : line) {
        cout << names[p] << endl;
    }

    return 0;
}
