#include <stdio.h>
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
long long dp[21][21][21];

int main()
{
	FILE* output = fopen("pole.out", "w");
	FILE* input = fopen("pole.inp", "r");

	long long r, l, n, test;
	fscanf(input, "%lld", &test);

	for (int t = 0;t < test;t++)
	{
		fscanf(input, "%lld %lld %lld", &n, &l, &r);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l; j++) {
				for (int k = 0; k < l; k++) {
					dp[i][j][k] = 0;
				}
			}
		}
		dp[1][1][1] = 1;
		for (long long i = 1; i < n + 1; i++)
		{
			for (long long j = 1; j < l + 1; j++)
			{
				for (long long k = 1; k < r + 1; k++)
				{
					if (j == k && i == k && i == 1)
						continue;
					else dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);
				}
			}
		}
		fprintf(output, "%lld\n", dp[n][l][r]);
	}
	return 0;
}
