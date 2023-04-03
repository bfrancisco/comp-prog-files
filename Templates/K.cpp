#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <set>
using namespace std;
 
long long n, a;
const long long pn = 2000010LL;
vector<long long> factors;
queue<pair<long long, long long>> ans;
set<long long> sortAns;
 
long long np, primes[pn];
bool isp[pn];
 
void sieve(long long pn)
{
    memset(isp, true, sizeof(isp));
    isp[0] = isp[1] = false;
    for (long long i = 2LL; i < pn; i++)
    {
        if (isp[i])
        {
            primes[++np] = i;
            for (long long j = 2LL * i; j < pn; j += i)
            {
                isp[j] = false;
            }
        }
    }
}
 
long long euclid(long long aa, long long b, long long &x, long long &y)
{
    if (b == 0LL)
    {
        x = 1LL;
        y = 0LL;
        return aa;
    }
    long long g = euclid(b, aa % b, x, y);
    long long z = x - aa / b * y;
    x = y;
    y = z;
    return g;
}
 
inline long long mul(long long aaa, long long b, long long m)
{
    aaa %= m;
    if (aaa < 0LL)
        aaa += m;
    b %= m;
    if (b < 0LL)
        b += m;
    long long q = ((long double)aaa * (long double)b) / (long double)m;
    long long r = aaa * b - q * m;
    return (r < 0LL ? r + m : r);
}
inline long long pwr(long long aaa, long long nnn, long long m)
{
    long long anss(1LL);
    while (nnn)
    {
        if (nnn & 1LL)
        {
            anss = mul(anss, aaa, m);
        }
        if (nnn >>= 1LL)
        {
            aaa = mul(aaa, aaa, m);
        }
    }
    return anss % m;
}
 
long long myrand(long long nnn)
{
    return rand() % nnn * rand() % nnn * rand() % nnn;
}
 
bool ispmiller(long long p)
{
    if (p < 2LL)
    {
        return false;
    }
    if (p == 2LL)
    {
        return true;
    }
    if (p % 2LL == 0LL)
    {
        return false;
    }
    long long s = p - 1LL;
    s >>= __builtin_ctzll(s);
    for (long long i = 0LL; i < 60LL; i++)
    {
        long long val = pwr(myrand(p - 1LL) + 1LL, s, p), temp = s;
        while (temp != p - 1LL && 1LL < val && val < p - 1LL)
        {
            val = mul(val, val, p);
            temp <<= 1LL;
        }
        if (val != p - 1LL && temp % 2LL == 0LL)
        {
            return false;
        }
    }
    return true;
}
 
inline long long pollard(long long nnn)
{
    if (nnn == 1LL)
    {
        return 1LL;
    }
    if (nnn % 2LL == 0LL)
    {
        return 2LL;
    }
    long long c = myrand(nnn - 1LL) + 1LL, x = myrand(nnn - 2LL) + 2LL, y = x;
    long long d = 1LL;
    while (d == 1LL)
    {
        x = mul(x, x, nnn) + c;
        if (x >= nnn)
        {
            x -= nnn;
        }
        y = mul(y, y, nnn) + c;
        if (y >= nnn)
        {
            y -= nnn;
        }
        y = mul(y, y, nnn) + c;
        if (y >= nnn)
        {
            y -= nnn;
        }
        long long k, kk;
        d = euclid((long long)abs(x - y), (long long)nnn, k, kk);
        if (d == nnn)
        {
            return (ispmiller(nnn) ? nnn : pollard(nnn));
        }
    }
    return d;
}
 
long long mod(long long x, long long m)
{
    return (x % m + m) % m;
}
 
long long fastExp(long long i, long long j, long long k)
{
    if (j == 0LL)
        return 1LL;
    if (j & 1LL)
        return mod((fastExp(i, j - 1LL, k) * i), k);
    i = fastExp(i, j / 2LL, k);
    return mod((i * i), k);
}
 
long long tonelli(long long y, long long p)
{
    long long s = 0LL;
    long long q = p - 1LL;
 
    while ((q & 1LL) == 0LL)
    {
        q /= 2LL;
        ++s;
    }
 
    if (s == 1LL)
    {
        long long r = fastExp(y, (p + 1LL) / 4LL, p);
        if (mod((r * r), p) == y)
        {
            return r;
        }
        return -1LL;
    }
 
    long long z = 1LL;
    while (fastExp(++z, (p - 1LL) / 2LL, p) != p - 1LL)
        ;
 
    long long c = fastExp(z, q, p);
    long long r = fastExp(y, (q + 1LL) / 2LL, p);
    long long t = fastExp(y, q, p);
    long long m = s;
 
    while (t != 1LL)
    {
        long long tt = t;
        long long i = 0LL;
        while (tt != 1LL)
        {
            tt = mod((tt * tt), p);
            ++i;
            if (i == m)
            {
                return -1LL;
            }
        }
 
        long long b = fastExp(c, fastExp(2, m - i - 1LL, p - 1LL), p);
        long long b2 = mod((b * b), p);
 
        r = mod((r * b), p);
        t = mod((t * b2), p);
        c = b2;
        m = i;
    }
 
    if (mod((r * r), p) == y)
    {
        return r;
    }
 
    return -1LL;
}
 
long long bez(long long c, long long d, long long p1, long long p2)
{
    long long bez1 = 0LL;
    long long bez2 = 0LL;
    long long x = euclid(p1, p2, bez1, bez2);
    x++;
 
    return mod(mod(mod(d * bez1, p1 * p2) * p1, p1 * p2) + mod(mod(c * bez2, p1 * p2) * p2, p1 * p2), p1 * p2);
}
 
void update(long long f, long long i, long long j)
{
    long long len = ans.size();
    if (f == 2LL)
    {
        ans.push({2LL, 0LL});
        ans.push({2LL, 1LL});
        return;
    }
 
    if (len == 0LL)
    {
        ans.push({f, i});
        ans.push({f, j});
        return;
    }
    
    for (long long k = 0LL; k < len; k++)
    {
        ans.push({f * ans.front().first, bez(ans.front().second, i, ans.front().first, f)});
        ans.push({f * ans.front().first, bez(ans.front().second, j, ans.front().first, f)});
        ans.pop();
    }
}
 
void solve(long long f)
{
    long long inv = fastExp(2LL, f - 2LL, f);
    long long r = tonelli(mod(1LL - 4LL * a, f), f);
 
    if (r == -1 || (a%2LL==1LL && f==2LL))
    {
        cout << 0LL << endl;
        exit(0LL);
    }
    
    update(f, mod(inv * mod(1LL - r, f), f), mod(inv * mod(1LL + r, f), f));
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> n >> a;
    long long nn = n;
 
    sieve(1000000);
    for (long long i = 1LL; i <= np && primes[i] * primes[i] <= n; i++)
    {
        if (nn % primes[i] == 0LL)
        {
            nn /= primes[i];
            factors.push_back(primes[i]);
        }
    }
 
    if (ispmiller(nn))
    {
        factors.push_back(nn);
    }
    else if (nn > 1LL)
    {
        long long x = pollard(nn);
        assert(x > 1000000LL);
        factors.push_back(x);
        factors.push_back(nn / x);
    }
 
    for (auto i : factors)
    {
        solve(i);
    }
 
    while (!ans.empty())
    {
            sortAns.insert(ans.front().second);
        ans.pop();
    }
    
    if (sortAns.size() > 1000000LL)
    {
        cout << "ABSOLUTELY WAY TOO MANY" << endl;
        return 0;
    }
 
    cout << sortAns.size() << endl;
 
    for (auto &i : sortAns)
    {
        cout << i << endl;
    }
 
    return 0;
}