#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)

int dp[504][504];
int home_bin[504][504];
int num[504];


int main() {

	FILE* inp = fopen("bin.inp", "rt");
	FILE* out = fopen("bin.out", "wt");

	int test;
	fscanf(inp, "%d\n", &test);

	for (int t = 0; t < test; t++) {

		int home, bin; // home = 집 수, bin = 쓰레기 통 수
		fscanf(inp, "%d %d", &home, &bin);
		for (int i = 1; i < home; i++) {
			for (int j = 1; j < home + 1; j++) {
				dp[i][j] = 0;
				home_bin[i][j] = 0;
				num[i] = 0;
			}
		}//초기화

		for (int i = 1; i <= home; i++) {
			fscanf(inp, "%d", &num[i]);
		}
		//입력 끝

		if (home == bin) { //집 수 == 쓰레기통 수 이면 무조건 값 0
			dp[home][bin] = 0;
			continue;
		}

		std::sort(num, num + home + 1); //오름차순 정렬

		for (int i = 0; i <= home; i++) {
			for (int j = 0; j <= bin; j++) {
				dp[i][j] = 9999999;
				dp[0][i] = 0;
			}
		}//최댓값 세팅

		int ex = 0;
		for (int n = 1; n <= home; n++) {
			for (int m = 1; m <= home; m++) {
				int mid = (n + m) / 2;
				for (int k = n; k <= m; k++) {
					if (num[mid] - num[k] < 0) ex = -(num[mid] - num[k]);
					else ex = num[mid] - num[k];
					home_bin[n][m] += ex;
				}
			}
		}
		// 쓰레기통이 1개일때 초기화값 


		for (int i = 1; i <= home; i++) {
			int x = 9999999;
			for (int j = 1; j <= bin; j++) {
				for (int k = 0; k <= i; k++) { //[1][5]  =>  [1][1] ~ [2][5] 
					if (dp[i - k][j - 1] + home_bin[i - k + 1][i] < x) //dp가 더 작으니까 x 에 대입
						x = dp[i - k][j - 1] + home_bin[i - k + 1][i];
				}
				dp[i][j] = x;
			}
		}

		fprintf(out, "%d\n", dp[home][bin]);

	}
	return 0;
}