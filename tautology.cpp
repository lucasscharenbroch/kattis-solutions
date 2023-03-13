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
 * Problem Name: Tautology
 * Difficulty: 3.1 (Medium)
 * Categories: 
 * Algorithms: 
 */

bool eval(const string& S, int& i, bool p, bool q, bool r, bool s, bool t) {
    switch(S[i++]) {
        // use bitwise operators to avoid short-circuiting (which throws off i)
        case 'N': return !eval(S, i, p, q, r, s, t);
        case 'K': return eval(S, i, p, q, r, s, t) & eval(S, i, p, q, r, s, t);
        case 'A': return eval(S, i, p, q, r, s, t) | eval(S, i, p, q, r, s, t);
        case 'C': return (!eval(S, i, p, q, r, s, t)) | eval(S, i, p, q, r, s, t); // =>
        case 'E': return eval(S, i, p, q, r, s, t) == eval(S, i, p, q, r, s, t);

        case 'p': return p;
        case 'q': return q;
        case 'r': return r;
        case 's': return s;
        case 't': return t;
    }

    assert(false);
}

int main() {
    init_cin();

    while(1) {
        again:
        string S;
        cin >> S;
        if(S == "0") break;

        bool p, q, r, s, t;
        rep(i, 0, 1 << 5) { // brute-force all values of (p, q, r, s, and t)
            p = (i >> 0) & 1;
            q = (i >> 1) & 1;
            r = (i >> 2) & 1;
            s = (i >> 3) & 1;
            t = (i >> 4) & 1;

            int pos = 0;
            if(!eval(S, pos, p, q, r, s, t)) {
                cout << "not" << endl;
                goto again;
            }
        }

        cout << "tautology" << endl;
    }

    return 0;
}
