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
 * Problem Name: Distributing Seats
 * Difficulty: 6.1 (Hard)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, R, C;
    cin >> N >> R >> C;

    vector<pii> passengers(N);

    rep(i, 0, N) {
        int r, c, s;
        cin >> r >> c >> s;
        passengers[i].first = max(0, r - s - 1);
        passengers[i].second = min(r + s - 1, R - 1);
    }

    // greedily seat passengers based on their end-of-interval

    sort(all(passengers)); // sort by start-point, then end-point

    int result = 0;
    int p = 0; // position in passengers
    priority_queue<int, vi, std::greater<int>> q; // holds interval entpoints

    rep(row, 0, R) {
        while(p < N && passengers[p].first == row) q.push(passengers[p++].second);

        int seats = C; // remaining seats in row

        while(!q.empty() && q.top() < row) q.pop(); // ignore passed intervals
        while(!q.empty() && seats) { // greedily seat
            seats--, result++;
            q.pop();
        }
    }

    cout << result << endl;

    return 0;
}
