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
 * Problem Name: Boiling Vegetables
 * Difficulty: 3.4 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    double T;
    int N;
    cin >> T >> N;

    priority_queue<pair<double, pair<double, int>>> q;
    double min_weight = 1e7;
    double epsilon = 1e-6;

    rep(i, 0, N) {
        double w;
        cin >> w;
        min_weight = min(min_weight, w);
        q.push(pair<double, pair<double, int>>(w, pair<double, int>(w, 1)));
    }

    int num_cuts = 0;

    // repeatedly add a cut vegetable with the heaviest pieces
    while(min_weight / q.top().first < T - epsilon) {
        auto [weight, cuts] = q.top().second; q.pop();
        cuts++; num_cuts++;
        q.push(pair<double, pair<double, int>>(weight / cuts, pair<double, int>(weight, cuts)));
        min_weight = min(min_weight, weight / cuts);
    }

    cout << num_cuts << endl;

    return 0;
}
