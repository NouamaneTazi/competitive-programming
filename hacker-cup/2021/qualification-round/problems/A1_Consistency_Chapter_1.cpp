#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF int(1e9) + 5
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const char MINCHAR = 'A';
const int ALPHABET = 26;

vv32 dist(ALPHABET, v32(ALPHABET, INF));

bool is_vowel(char c)
{
    const string VOWELS = "AEIOU";
    return VOWELS.find(c) == string::npos;
}

void build_changes()
{
    for (int a = 0; a < ALPHABET; a++)
        for (int b = 0; b < ALPHABET; b++)
            if (is_vowel(char(MINCHAR + a)) ^ is_vowel(char(MINCHAR + b)))
                dist[a][b] = 1;
}

void read_changes()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        dist[str[0] - MINCHAR][str[1] - MINCHAR] = 1;
    }
}
void solve()
{
    string S;
    cin >> S;

    build_changes();
    // read_changes();

    for (int i = 0; i < ALPHABET; i++)
    {
        dist[i][i] = 0;
    }

    for (int k = 0; k < ALPHABET; k++)
        for (int i = 0; i < ALPHABET; i++)
            for (int j = 0; j < ALPHABET; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int64_t best = INF;
    for (int c = 0; c < ALPHABET; c++)
    {
        int64_t sum = 0;
        for (auto &ch : S)
        {
            sum += dist[ch - MINCHAR][c];
        }
        best = min(best, sum);
    }

    cout << (best < INF ? best : -1) << ln;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}