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
 * Problem Name: Work Stations
 * Difficulty: 3.1 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int N, M;
    cin >> N >> M;

    vector<pii> a(N);

    rep(i, 0, N) {
        cin >> a[i].first >> a[i].second;
        a[i].second += a[i].first; // a[i].second = end of interval
    }

    priority_queue<int, vi, greater<int>> q; // finished end-of-intervals, sorted

    int result = 0;

    sort(all(a)); // sort by start time, then end time

    rep(i, 0, N) {
        auto [s, e] = a[i];

        while(!q.empty() && q.top() + M < s) q.pop();

        if(!q.empty() && q.top() <= s) {
            q.pop();
            result++;
        }

        q.push(e);
    }

    cout << result << endl;
    return 0;
}
