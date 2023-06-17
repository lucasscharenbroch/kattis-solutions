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
 * Problem Name: Repetitive Song
 * Difficulty: 2.7 (Easy)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    int N;
    cin >> N;

    unordered_map<string, int> last_occurrence;

    int result = 0;

    rep(i, 0, N) {
        string S;
        cin >> S;

        if(last_occurrence[S]) result = max(result, N - (1 + i - last_occurrence[S]));
        last_occurrence[S] = i + 1;
    }

    cout << result << endl;

    return 0;
}
