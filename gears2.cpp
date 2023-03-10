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
 * Problem Name: Gears
 * Difficulty: 3.6 (Medium)
 * Categories: Graph
 * Algorithms: BFS
 */

int main() {
    init_cin();

    int N;
    cin >> N;
    vector<pii> coords(N);
    vi radii(N);

    rep(i, 0, N) cin >> coords[i].first >> coords[i].second >> radii[i];

    vector<pii> ratios(N); // ratios of gear turns to source (the 0th gear) turns. (0 if not calculated)
    ratios[0] = {1, 1};

    // BFS from source gear
    unordered_map<int, bool> vis;
    queue<int> q;
    vis[0] = true;
    q.push(0);

    while(q.size()) {
        int n = q.size();
        while(n--) {
            int curr = q.front(); q.pop();

            // check all other gears for unvisited neighbors
            double x = coords[curr].first, y = coords[curr].second, r = radii[curr];
            rep(i, 0, N) {
                double x1 = coords[i].first, y1 = coords[i].second, r1 = radii[i];
                double dx = x - x1, dy = y - y1;
                double dist = sqrt((dx * dx) + (dy * dy));

                if(abs(dist - (r + r1)) > 0.00001) continue; // gears aren't tangent

                if(!vis[i]) q.push(i);
                vis[i] = true;

                // compute ratio, and ensure that (if this neighbor has been visited)
                // the ratio matches the other ratio
                int a = ratios[curr].first * radii[i];
                int b = -ratios[curr].second * radii[curr];

                int g;
                while((g = gcd(a, b)) != 1) a /= g, b /= g;

                if(ratios[i].first != 0 && (ratios[i].first != a || ratios[i].second != b)) {
                    cout << -1 << endl; // found a conflicting gear: source cannot turn
                    return 0;
                }

                ratios[i].first = a, ratios[i].second = b;
            }
        }
    }

    if(ratios[N - 1].first == 0) cout << 0 << endl; // target doesn't turn
    else cout << ratios[N - 1].first << " " << ratios[N - 1].second << endl;

    return 0;
}
