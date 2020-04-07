#include<map>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 2e3 + 10;
#define ll long long
int i, j, k;
int n, m, q;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
map<int, int>mp;
int a[maxn][maxn], dp[maxn][maxn], f[maxn][maxn];
int g[maxn];
int main() {
	while (cin >> n >> m) {
		for (i = 1; i <= n; i++) {
			a[i][0] = 0;
			f[i][0] = 0;
			for (j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		}
		for (i = 1; i <= n; i++) {
			for (j = 0; j <= m; j++) {
				dp[i][j] = 0;
				for (int k = 0; k <= j; k++) {
					if (dp[i][j] < a[i][k] + dp[i - 1][j - k]) {
						dp[i][j] = a[i][k] + dp[i - 1][j - k];
						f[i][j] = k;
					}
				}
			}
		}
		int temp = m;
		for (i = n; i > 0; --i) {
			g[i] = f[i][temp];
			temp -= g[i];
		}
		for (i = 1; i <= n; i++)
			cout << "The " << i << "th" << " project invest:" << g[i] << endl;
		printf("%d\n", dp[n][m]);
	}
	return 0;
}
/*
4 5
11 12 13 14 15
0 5 10 15 20
2 10 30 32 40
20 21 22 23 24
*/
