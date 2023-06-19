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
 * Problem Name: Streets Ahead
 * Difficulty: 1.9 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, Q;
    cin >> N >> Q;

    unordered_map<string, int> id;

    rep(i, 0, N) {
        string S;
        cin >> S;
        id[S] = i;
    }

    rep(i, 0, Q) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (abs(id[s1] - id[s2]) - 1) << endl;
    }

    return 0;
}
