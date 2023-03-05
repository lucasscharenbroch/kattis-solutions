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
 * Problem Name: Longest Increasing Subsequence
 * Difficulty: 5.5 (Hard)
 * Categories: DP
 * Algorithms: Longest Increasing Subsequence
 */

vector<int> lis(const vector<int>& A, int N) { // returns indices of LIS
    vector<int> parent(N);
    vector<int> last_idx(N + 1); // last_idx[i] holds the index of the last element in LIS of size i
    last_idx[0] = -1;
    int longest = 0; // max size of current LIS

    rep(i, 0, N) {
        // binary search for smallest last_idx whose element is larger than A[i].
        int low = 1, high = longest + 1;
        while(low < high) {
            int mid = (low + high) / 2;

            if(A[last_idx[mid]] < A[i]) low = mid + 1; // < only allows "STRICTLY increasing" s.seq.
            else high = mid;
        }

        parent[i] = last_idx[low - 1];
        last_idx[low] = i;
        longest = max(longest, low);
    }

    // build vector of LIS indices
    vector<int> indices(longest);
    int curr_idx = last_idx[longest];
    for(int i = longest - 1; i >= 0; i--) {
        indices[i] = curr_idx;
        curr_idx = parent[curr_idx];
    }

    return indices;
}

int main() {
    // init_cin();

    int N;
    while(cin >> N) {
        vector<int> A(N);
        rep(i, 0, N) cin >> A[i];

        vector<int> result = lis(A, N);
        cout << sz(result) << endl;
        rep(i, 0, sz(result)) cout << result[i] << ((i == sz(result) - 1) ? "" : " ");
        cout << endl;
    }

    return 0;
}
