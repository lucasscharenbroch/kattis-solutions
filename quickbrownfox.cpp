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
 * Problem Name: Quick Brown Fox
 * Difficulty: 1.8 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int T;
    cin >> T >> ws;

    while(T--) {
        string s;
        getline(cin, s);

        vi letters(26);
        int num_letters = 0;

        rep(i, 0, sz(s)) {
            int c = tolower(s[i]);
            if(c < 'a' || 'z' < c) continue;
            if(letters[c - 'a'] == 0) {
                num_letters++;
                letters[c - 'a']++;
            }
        }

        if(num_letters == 26) cout << "pangram" << endl;
        else {
            cout << "missing ";
            rep(i, 0, 26) if(!letters[i]) cout << (char)('a' + i);
            cout << endl;
        }
    }

    return 0;
}
