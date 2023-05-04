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
 * Problem Name: Train Sorting
 * Difficulty: 6.5 (Hard)
 * Categories: Dynamic Programming
 * Algorithms: LIS
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    if(N == 0) { // N = 0 edge-case
        cout << 0 << endl;
        return 0;
    }

    vector<pii> cars(N); // {weight, original index}
    rep(i, 0, N) {
        cin >> cars[i].first;
        cars[i].second = i;
    }

    sort(all(cars)); // sort cars by weight
    vi a(N); // let a[i] = cars[i].second (original index)
    rep(i, 0, N) a[i] = cars[i].second;

    // find LIS and LDS by of a
    vi LIS(N); // LIS[i] = LIS of a[i -> n - 1] starting with i
    vi LDS(N); // LDS[i] = LDS of a[0 -> i] ending with i

    for(int i = N; i --> 0;) {
        int m = 0; // max LIS(j)
        rep(j, i + 1, N) m = max(m, LIS[j] * (a[i] < a[j]));
        LIS[i] = 1 + m;
    }

    rep(i, 0, N) {
        int m = 0; // max LDS(j)
        rep(j, 0, i) m = max(m, LDS[j] * (a[j] > a[i]));
        LDS[i] = 1 + m;
    }

    // take running max of LIS and LDS to remove "start/end with i" requirement
    for(int i = N - 1; i --> 0;) LIS[i] = max(LIS[i], LIS[i + 1]);
    rep(i, 1, N) LDS[i] = max(LDS[i], LDS[i - 1]);

    // result = max(LDS(i) + LIS(i + 1))
    int result = max(LIS[0], LDS[N - 1]);
    rep(i, 0, N - 1) result = max(result, LDS[i] + LIS[i + 1]);

    cout << result << endl;

    return 0;
}
