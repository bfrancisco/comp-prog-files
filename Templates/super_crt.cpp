using ll = long long int;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

ll mod(ll x, ll m) { // use this instead of x % m
  if (m == 0) return 0;
  if (m < 0) m *= -1;
  return (x%m + m) % m; // always nonnegative
}
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  if (b==0) {x = 1; y = 0; return a;}
  ll g = extended_euclid(b, a%b, x, y);
  ll z = x - a/b*y;
  x = y; y = z; return g;
}

pll modsolver(ll a, ll b, ll m) {
  ll x, y; ll g = extended_euclid(a, m, x, y);
  if (b % g != 0) return {-1, -1};
  return {mod(x*b/g, m/g), abs(m/g)}; }

pll chinese(ll b1, ll m1, ll b2, ll m2) {
  ll x, y; ll g = extended_euclid(m1, m2, x, y);
  if (b1 % g != b2 % g) return ii(-1, -1);
  ll M = abs(m1 / g * m2);
  return {mod(mod(x*b2*m1+y*b1*m2, M*g)/g,M), M}; }

ii chinese_remainder(ll b[], ll m[], int n) {
  ii ans(0, 1);
  for (int i = 0; i < n; ++i) {
    ans = chinese(b[i],m[i],ans.first,ans.second);
    if (ans.second == -1) break; }
  return ans; }

pll super_chinese(ll a[], ll b[], ll m[], int n) {
  pll ans(0, 1);
  for (int i = 0; i < n; ++i) {
    pll two = modsolver(a[i], b[i], m[i]);
    if (two.second == -1) return two;
    ans = chinese(ans.first, ans.second,
    two.first, two.second);
    if (ans.second == -1) break; }
  return ans; }