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
 * Problem Name: Collecting Beepers
 * Difficulty: 4.6 (Medium)
 * Categories: Dynamic Programming
 * Algorithms: Traveling Salesman Problem
 */

vector<vi> memo;

int tour_length(int curr, int vis, vector<vi>& dist) {
    if(memo[curr][vis] != -1) return memo[curr][vis];

    int length = INT_MAX;

    rep(i, 0, sz(dist) - 1) {
        if((vis >> i) & 1) continue;
        length = min(length, dist[curr][i] + tour_length(i, vis | (1 << i), dist));
    }

    if(length == INT_MAX) length = dist[curr][sz(dist) - 1]; // distance to home

    return memo[curr][vis] = length;
}

int main() {
    init_cin();

    int T;
    cin >> T;

    while(T--) {
        int _, N, r, c;
        cin >> _ >> _; // ignore grid size
        cin >> r >> c >> N; // r, c = home pos
        N++;

        memo.assign(N, vi((int) pow(2, N), -1));
        vector<pii> coords(N);
        coords[N - 1].first = r, coords[N - 1].second = c; // coords[N] = start pos
        rep(i, 0, N - 1) cin >> coords[i].first >> coords[i].second;

        vector<vi> dist(N, vi(N));

        rep(i, 0, N) rep(j, 0, N) {
            dist[i][j] = abs(coords[i].first - coords[j].first) +
                         abs(coords[i].second - coords[j].second);
        }

        cout << tour_length(N - 1, 0, dist) << endl;
    }

    return 0;
}
