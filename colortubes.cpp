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
 * Problem Name: Color Tubes
 * Difficulty: 6.6 (Hard)
 * Categories: 
 * Algorithms: 
 */

int top(vi& tube) { // returns column of top empty cell in tube (-1 if the tube is full)
    rep(i, 0, 3) if(tube[i]) return i - 1;
    return 2;
}

void move(vector<vi>& tubes, vector<pii>& result, int from, int to) {
    result.push_back(pii(from, to));
    tubes[to][top(tubes[to])] = tubes[from][top(tubes[from]) + 1];
    tubes[from][top(tubes[from]) + 1] = 0;
}

int main() {
    init_cin();

    int N;
    cin >> N;

    vector<vi> tubes(N + 1, vi(3));
    rep(i, 0, N + 1) for(int j = 2; j >= 0; j--) cin >> tubes[i][j];

    vector<pii> result;
    vi empty_cells;

    rep(i, 0, N + 1) rep(j, 0, count(all(tubes[i]), 0)) empty_cells.push_back(i);

    rep(i, 0, N) { // fill N tubes with matching colors
        // clear tubes[i]
        rep(j, 0, sz(empty_cells)) {
            if(empty_cells[j] == i) continue;
            move(tubes, result, i, empty_cells[j]);
        }
        empty_cells.clear();

        // find a color, c, with maximal occurrences in the first and second rows
        vector<pii> colors(N); // contains {score, color} pairs, where
                               // score = 10 * cnt(first-row) + cnt(second-row)
        rep(i, 0, N) colors[i].second = i + 1;

        rep(j, i + 1, N + 1) {
            colors[tubes[j][0] - 1].first += 10;
            colors[tubes[j][1] - 1].first += 1;
        }

        sort(all(colors), greater<pii>());
        int c = colors[0].second; // c = color with highest score

        // find cells with c
        vector<pii> c_cells; // {row, tube}
        rep(j, i + 1, N + 1) rep(k, 0, 3) if(tubes[j][k] == c) c_cells.push_back(pii(k, j));

        sort(all(c_cells)); // consider cells with lowest row first.

        assert(sz(c_cells) == 3);
        assert(c_cells[0].first == 0);
        assert(c_cells[1].first != 2);

        rep(j, 0, 3) {
            auto [r, t] = c_cells[j];
            while(top(tubes[t]) != r - 1) {
                int k = 0;
                for(; k < sz(empty_cells); k++) {
                    if(empty_cells[k] == t) continue; // ignore empty cells on tube t
                    break;
                }
                assert(k != sz(empty_cells));
                move(tubes, result, t, empty_cells[k]);
                empty_cells[k] = t;
            }

            move(tubes, result, t, i);
            empty_cells.push_back(t);
        }

        assert(sz(empty_cells) == 3);
        assert(empty_cells[0] != i);
        assert(empty_cells[1] != i);
        assert(empty_cells[2] != i);
        assert(top(tubes[i]) == -1);
        assert(tubes[i][0] == c && tubes[i][0] == tubes[i][1] && tubes[i][1] == tubes[i][2]);
    }

    cout << sz(result) << endl;
    rep(i, 0, sz(result)) cout << (result[i].first + 1) << " " << (result[i].second + 1) << endl;

    return 0;
}
