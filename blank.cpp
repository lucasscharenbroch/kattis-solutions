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
 * Problem Name: Blank Queue
 * Difficulty: 2.9 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, T;
    cin >> N >> T;

    vector<pii> people(N);

    rep(i, 0, N) cin >> people[i].first >> people[i].second;
    vector<bool> min_avail(T, true);

    // sort in nonincreasing order by cash
    sort(all(people), greater<pii>());

    int result = 0;

    // assign people with most cash first, place people at latest possible time
    rep(i, 0, N) {
        auto [c, t] = people[i];
        for(int j = t; j >= 0; j--) {
            if(!min_avail[j]) continue;
            min_avail[j] = false;
            result += c;
            break;
        }
    }

    cout << result << endl;

    return 0;
}
