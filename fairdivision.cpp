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
 * Problem Name: Fair Division
 * Difficulty: 3.3 (Medium)
 * Categories: Greedy
 * Algorithms: 
 */

int main() {
    init_cin();

    int T;
    cin >> T;
    while(T--) {
        int P, N;
        cin >> P >> N;

        vector<pii> a(N); // a[i] = (budget, -index)

        rep(i, 0, N) {
            cin >> a[i].first;
            a[i].second = -i;
        }

        sort(all(a));

        vi pay(N); // amount person i pays
        int base = P / N; // minimal amount each person should pay (if they can afford it)

        rep(i, 0, N) {
            base = (i == 0 || a[i - 1].first) ? base : P / (N - i);
            int p = min(base, a[i].first);
            a[i].first -= p;
            pay[-a[i].second] += p;
            P -= p;
        }

        // subtract additional cents from largest, then low-indexed persons (backwards in a)
        for(int i = N; i --> 0;) {
            if(!P) break;
            if(!a[i].first) goto impossible;
            a[i].first--, pay[-a[i].second]++, P--;
        }

        rep(i, 0, N) cout << pay[i] << (i == N - 1 ? "\n" : " ");
        continue;
        impossible:
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
