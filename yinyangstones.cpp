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
 * Problem Name: Yin and Yang Stones
 * Difficulty: 1.7 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    string S;
    cin >> S;

    int white = 0, black = 0;

    rep(i, 0, sz(S)) white += S[i] == 'W', black += S[i] == 'B';

    cout << (white == black) << endl;

    return 0;
}
