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
 * Problem Name: Recycling
 * Difficulty: 5.2 (Medium)
 * Categories: 
 * Algorithms: 
 */

int main() {
    init_cin();

    ll N;
    cin >> N;

    vector<ll> nums(N);

    rep(i, 0, N) cin >> nums[i];

    vector<pair<ll, ll>> stack;
    ll s = 1, e = 1, r = nums[0];

    rep(i, 0, N) {
        ll range_start = i; // start-index of largest contiguous range of numbers in nums
                            // greater or equal to nums[i] that ends at index i
                            // (get this from the stack or set to i)

        while(sz(stack) && stack.back().first > nums[i]) {
            auto [height, start] = stack.back();
            range_start = start;
            stack.pop_back();

            ll score = height * (i - start);
            if(score > r || score == r && start < s) s = start + 1, e = i, r = score;
        }

        if(!sz(stack) || stack.back().first != nums[i]) stack.push_back(pair<ll, ll>(nums[i], range_start));
    }

    while(sz(stack)) {
            auto [height, start] = stack.back();
            stack.pop_back();

            ll score = height * (N - start);
            if(score > r || score == r && start < s) s = start + 1, e = N, r = height * (N - start);
    }

    cout << s << " " << e << " " << r << endl;

    return 0;
}
