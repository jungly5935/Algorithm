#include <stdio.h>
#pragma warning(disable:4996)
#define compare(x,y,z) ((x)<(z)?((x)<(y)?(x):(y)):((y)<(z)?(y):(z)))

int cube[201][201][201];

FILE* out = fopen("cube.out", "wt");
FILE* inp = fopen("cube.inp", "rt");

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int test;
	int x, y;
	int i, j, k;
	for (i = 1; i < 200; i++) {
		for (j = 1; j < 200; j++) {
			for (k = 1; k < 200; k++) {
				if (i == j && j == k) {
					cube[i][j][k] = 1;
					continue;
				}

				int sum1 = 99999, sum2 = 99999, sum3 = 99999;
				for (int z = 1; z < k; z++) {
					x = k - z;
					y = z;
					if ((cube[i][j][x] + cube[i][j][y]) < sum3) sum3 = cube[i][j][x] + cube[i][j][y];
				}
				for (int z = 1; z < j; z++) {
					x = j - z;
					y = z;

					if ((cube[i][x][k] + cube[i][y][k]) < sum2) sum2 = cube[i][x][k] + cube[i][y][k];
				}
				for (int z = 1; z < i; z++) {
					x = i - z;
					y = z;
					if ((cube[x][j][k] + cube[y][j][k]) < sum1) sum1 = cube[x][j][k] + cube[y][j][k];
				}

				cube[i][j][k] = compare(sum1, sum2, sum3); //x y z 값중 가장 작은 값
				cube[i][k][j] = cube[j][i][k] = cube[j][k][i] = cube[k][i][j] = cube[k][j][i] = cube[i][j][k]; //i j k 같은것끼리

			}//k
		}//j
	}//i

	int w, l, h;
	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++) {
		fscanf(inp, "%d %d %d", &w, &l, &h);
		fprintf(out, "%d\n", cube[w][l][h]);
	}
	return 0;
}