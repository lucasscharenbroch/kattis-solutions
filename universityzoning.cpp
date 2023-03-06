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
 * Problem Name: University Zoning 
 * Difficulty: 2.7 (Easy)
 * Categories: 
 * Algorithms: 
 */

typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plpl;

int main() {
    init_cin();


    int R, C, F, S, G;
    cin >> R >> C >> F >> S >> G;

    vector<priority_queue<ll, vll, greater<ll>>> faculty_cells(F); // prioritize top-leftmost cell
    priority_queue<plpl, vector<plpl>, greater<plpl>> student_q; // {id : {location (r * C + c), faculty}}
    vi quotas(F);

    rep(i, 0, F) {
        int K;
        cin >> K;
        while(K--) {
            ll r, c;
            cin >> r >> c;
            r--, c--; // adjust for 1-based-indexing
            faculty_cells[i].push(r * C + c);
        }
    }

    rep(i, 0, S) {
        ll r, c, d, f;
        cin >> r >> c >> d >> f;
        r--, c--, f--; // adjust for 1-based-indexing

        student_q.push(plpl(d, pll(r * C + c, f)));
    }

    rep(i, 0, F) {
        cin >> quotas[i];
    }

    vector<priority_queue<ll, vll, greater<ll>>> distances(F);
    while(!student_q.empty()) {
        plpl curr = student_q.top(); student_q.pop();
        ll f = curr.second.second;
        ll r = curr.second.first / C;
        ll c = curr.second.first % C;

        ll dest_cell = faculty_cells[f].top(); faculty_cells[f].pop();
        ll dr = dest_cell / C;
        ll dc = dest_cell % C;

        ll dist = abs(r - dr) + abs(c - dc);

        distances[f].push(dist);
    }

    vector<ll> faculty_costs(F, 0); // cost for faculty to fulfill quota
    rep(i, 0, F) {
        while(quotas[i]--) {
            faculty_costs[i] += distances[i].top(); distances[i].pop();
        }
    }

    sort(all(faculty_costs));

    // return the sum of the G smallest faculty_costs
    ll result = 0;
    rep(i, 0, G) {
        result += faculty_costs[i];
    }

    cout << result << endl;

    return 0;
}
