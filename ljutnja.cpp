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
 * Problem Name: Ljutnja
 * Difficulty: 4.8 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int candy, N;
    cin >> candy >> N;

    vi demands(N);
    rep(i, 0, N) cin >> demands[i];

    // sort in nonincreasing order
    sort(all(demands), greater<int>());
    demands.push_back(0); // sentinal value

    int level = demands[0]; // current demand of all indices < i
    rep(i, 1, N + 1) {
        if(demands[i] == level) continue;
        if(i * (ll)(level - demands[i]) < (ll)candy) { // possible to bring level down to demands[i]
            candy -= i * (level - demands[i]);
            level = demands[i];
            continue;
        }

        // otherwise, divide remaining candy equally among first i elements.
        rep(j, 0, i) {
            int dec = candy / (i - j) + ((candy % (i - j)) != 0); // ceil of candy / (i - j)
            demands[j] = level - dec;
            candy -= dec;
        }

        break;
    }

    ll result = 0;
    rep(i, 0, N) result += demands[i] * (ll)demands[i];

    cout << result << endl;

    return 0;
}
