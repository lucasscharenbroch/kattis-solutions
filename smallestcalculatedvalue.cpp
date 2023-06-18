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
 * Problem Name: Smallest Calculated Value
 * Difficulty: 3.4 (Medium)
 * Categories: 
 * Algorithms: Backtracking
 */

int result = INT_MAX;

void calculate(vi& nums, int i, int carry_in) {
    if(i == 0) return calculate(nums, i + 1, nums[i]);
    if(i == sz(nums)) {
        if(carry_in >= 0) result = min(result, carry_in);
        return;
    }

    calculate(nums, i + 1, carry_in + nums[i]);
    calculate(nums, i + 1, carry_in - nums[i]);
    calculate(nums, i + 1, carry_in * nums[i]);
    if(nums[i] != 0 && carry_in % nums[i] == 0) calculate(nums, i + 1, carry_in / nums[i]);
}

int main() {
    init_cin();

    vi a(3);
    cin >> a[0] >> a[1] >> a[2];

    calculate(a, 0, 0);
    cout << result << endl;

    return 0;
}
