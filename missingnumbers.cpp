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
 * Problem Name: Missing Numbers
 * Difficulty: 1.7 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vector<bool> said(201);
    int last = 0;

    rep(i, 0, N) {
        int x;
        cin >> x;
        last = max(last, x);
        said[x] = true;
    }

    vi missed;

    rep(i, 1, last + 1) {
        if(!said[i]) missed.push_back(i);
    }

    if(sz(missed)) {
        rep(i, 0, sz(missed)) cout << missed[i] << endl;
    } else cout << "good job" << endl;

    return 0;
}
