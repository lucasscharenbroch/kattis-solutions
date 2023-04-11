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
 * Problem Name: Dance Pad
 * Difficulty: 3.8 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int move_to_int(char m) {
    if(m == 'U') return 0;
    if(m == 'H') return 1;
    if(m == 'N') return 2;
    if(m == 'V') return 3;
}

int main() {
    init_cin();

    int N;
    cin >> N;

    vector<pii> moves(N); // moves[i].second == -1 if it uses only one foot
    rep(i, 0, N) {
        string m;
        cin >> m;

        moves[i].first = move_to_int(m[0]);
        moves[i].second = sz(m) == 1 ? -1 : move_to_int(m[1]);

        // assign in increasing order for easier check later
        if(moves[i].second != -1 && moves[i].first > moves[i].second) 
            swap(moves[i].first, moves[i].second);
    }

    vector<vi> next_used(4, vi(N, INT_MAX)); // holds index of next occurrence of respective move
    for(int i = N - 1; i > 0; i--) {
        next_used[0][i - 1] = moves[i].first == 0 || moves[i].second == 0 ? i : next_used[0][i];
        next_used[1][i - 1] = moves[i].first == 1 || moves[i].second == 1 ? i : next_used[1][i];
        next_used[2][i - 1] = moves[i].first == 2 || moves[i].second == 2 ? i : next_used[2][i];
        next_used[3][i - 1] = moves[i].first == 3 || moves[i].second == 3 ? i : next_used[3][i];
    }

    int result = 0;
    int l = 3, r = 1; // foot positions

    rep(i, 0, N) {
        if(moves[i].second == -1) {
            if(l == moves[i].first || r == moves[i].first) continue; // don't need to move
            // don't move the foot on the arrow that will be used sooner
            result++;
            if(next_used[l][i] > next_used[r][i]) l = moves[i].first;
            else r = moves[i].first;
        } else {
            if(l > r) swap(l, r); // move to increasing order for less checks
            if(l == moves[i].first && r == moves[i].second) continue;

            result++;
            if(l == moves[i].first) { r = moves[i].second; continue; }
            if(l == moves[i].second) { r = moves[i].first; continue; }
            if(r == moves[i].first) { l = moves[i].second; continue; }
            if(r == moves[i].second) { l = moves[i].first; continue; }

            // neither l nor r matches.
            result++;
            l = moves[i].first;
            r = moves[i].second;
        }
    }

    cout << result << endl;

    return 0;
}
