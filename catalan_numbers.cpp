/*
                              CATALAN NUMBERS
                    1 1 2 5 14 42 132 429 1430 ......
            The number of valid paranthesis sequence of length n.such that no prefix of length less than n is a valid paranthesis sequence.
            Cn = (1/(n+1))*nCr(2*n,n)
*/

const int MAXN = 105;
const int mod = 1000000007;

inline int add(int x, int y) { int ret = x + y; if (ret >= mod) ret -= mod; return ret; }
inline int sub(int x, int y) { int ret = (x - y); if (ret < 0) ret += mod; return ret; }
inline int mul(int x, int y) { int ret = (1ll * x * y) % mod; return ret; }
int exp(int a, int b) { int ret = 1; while (b) { if (b & 1) ret = mul(ret, a); a = mul(a, a); b >>= 1;} return ret; }
int dv(int a, int b) { int ret = exp(b, mod - 2); ret = mul(ret, a); return ret; }

vector<int> catalan(MAXN), fc(2 * MAXN), inv(2 * MAXN);

fc[0] = 1;
for (int i = 1; i < 2 * MAXN; i++)
	fc[i] = mul(fc[i - 1], i);
inv[2 * MAXN - 1] = exp(fc[2 * MAXN - 1], mod - 2);
for (int i = 2 * MAXN - 2; i >= 0; i--)
	inv[i] = mul(inv[i + 1], i + 1);

for (int i = 0; i + 1 < MAXN; i++) {
	catalan[i + 1] = mul(fc[2 * i], inv[i]);
	catalan[i + 1] = mul(catalan[i + 1], inv[i]);
	catalan[i + 1] = dv(catalan[i + 1], i + 1);
}