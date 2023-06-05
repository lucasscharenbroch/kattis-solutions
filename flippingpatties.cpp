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
 * Problem Name: Flipping Patties
 * Difficulty: 2.3 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    vi action_count(43201);
    int result = 0;

    rep(i, 0, N) {
        int d, t;
        cin >> d >> t;

        int place = ++action_count[t - d - d];
        int flip = ++action_count[t - d];
        int serve = ++action_count[t];

        result = max(result, (max(max(place, flip), serve) + 1) / 2);
    }

    cout << result << endl;

    return 0;
}
