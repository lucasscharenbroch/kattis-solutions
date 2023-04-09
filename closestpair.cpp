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
 * Problem Name: Closest Pair (closestpair2) and Closest Pair (Uniform) (closestpair1)
 * Difficulty: 6.4 / 7.8 (Hard)
 * Categories: Divide and Conquer
 * Algorithms: 
 */

struct point {
    double x, y;
    point() { }
    point(double x, double y) : x(x), y(y) { }
};

typedef pair<point, point> ppp;

double dist(const point& a, const point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double dist(const ppp& p) {
    return dist(p.first, p.second);
}

ppp solve(const vector<point>& pts, const vi& y) {
    /* ~ ~ ~ ~ ~ Base-Cases ~ ~ ~ ~ ~ */

    if(sz(pts) == 2) return ppp(pts[0], pts[1]);
    if(sz(pts) == 3) {
        ppp p1(pts[0], pts[1]), p2(pts[1], pts[2]), p3(pts[0], pts[2]);
        double d = min(dist(p1), min(dist(p2), dist(p3)));
        if(d == dist(p1)) return p1;
        if(d == dist(p2)) return p2;
        return p3;
    }

    int mid = sz(pts) / 2;

    /* ~ ~ ~ ~ ~ Divide ~ ~ ~ ~ ~ */

    vector<point> pts_l(pts.begin(), pts.begin() + mid), pts_r(pts.begin() + mid, pts.end());
    vi y_l, y_r;

    // fill y_l and y_r with y
    rep(i, 0, sz(y)) {
        if(y[i] < mid) y_l.push_back(y[i]);
        else y_r.push_back(y[i] - mid);
    }

    ppp left_closest = solve(pts_l, y_l);
    ppp right_closest = solve(pts_r, y_r);

    /* ~ ~ ~ ~ ~ Conquer ~ ~ ~ ~ ~ */

    double dl = dist(left_closest), dr = dist(right_closest);
    double d = min(dl, dr);
    ppp closest = d == dl ? left_closest : right_closest;

    // consider middle strip
    vi strip_indices;
    double midline = (pts[mid - 1].x + pts[mid].x) / 2.0;
    rep(i, 0, sz(y)) if(abs(midline - pts[y[i]].x) <= d) strip_indices.push_back(y[i]);

    rep(i, 0, sz(strip_indices)) {
        rep(j, i + 1, min(sz(strip_indices), i + 8)) {
            if(dist(pts[strip_indices[i]], pts[strip_indices[j]]) >= d) continue;
            closest.first = pts[strip_indices[i]];
            closest.second = pts[strip_indices[j]];
            d = dist(closest);
        }
    }

    return closest;
}

int main() {
    init_cin();

    while(true) {
        int N;
        cin >> N;
        if(N == 0) break;

        vector<point> pts(N);
        rep(i, 0, N) cin >> pts[i].x >> pts[i].y;

        sort(all(pts), [](point& a, point& b) { return a.x < b.x; } );

        vi y; // indices of points in pts, sorted by y-value
        rep(i, 0, N) y.push_back(i);
        sort(all(y), [&](int& a, int& b) { return pts[a].y < pts[b].y; });

        ppp closest = solve(pts, y);

        cout << setprecision(15); // Wrong Answer when digits are truncated / sci. notation used
        cout << closest.first.x << " " << closest.first.y << " " <<
                closest.second.x << " " << closest.second.y << endl;
    }

    return 0;
}
