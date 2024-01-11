#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n, m;
vvl F;
vvl dp;

ll solve(ll i, ll j) {
  if (dp[i][j] < 0) {
    dp[i][j] =
        max({solve(i - 1, j), solve(i, j - 1), solve(i - 1, j - 1)}) + F[i][j];
  }

  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;

  F = vvl(n + 1, vl(m + 1));
  for (auto i = 1; i <= n; ++i) {
    for (auto j = 1; j <= m; ++j) {
      cin >> F[i][j];
    }
  }

  dp = vvl(n + 1, vl(m + 1, -1));
  for (auto i = 0; i <= n; ++i) {
    dp[i][0] = 0;
  }
  for (auto j = 0; j <= m; ++j) {
    dp[0][j] = 0;
  }
  dp[1][1] = F[1][1];

  const auto ans = solve(n, m);
  cout << ans;

  return 0;
}