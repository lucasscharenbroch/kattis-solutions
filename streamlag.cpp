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
 * Problem Name: Stream Lag
 * Difficulty: 3.2 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    int result = 0;

    rep(i, 0, N) {
        int t, p;
        cin >> t >> p;

        result = max(result, t - p);
    }

    cout << result << endl;

    return 0;
}
