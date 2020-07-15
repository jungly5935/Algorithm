#include<stdio.h>
#pragma warning(disable:4996)
long long sorted[100000];
long long cnt;
long long U, V, S;
long long num;
FILE* out = fopen("inv.out", "wt");
FILE* inp = fopen("inv.inp", "rt");
// MergeSort의 merge() 과정에서, 오른편 값이 선택될 때, 왼쪽편 블럭의 인덱스인 i 이후에 얼마나 값이 있는가가, 해당 오른편 값에 대한 Inversion 쌍 수량이 된다.
void merge(long long inv[], long long left, long long mid, long long right) {
	long long i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {

		if (inv[i] <= inv[j]) {
			sorted[k++] = inv[i++];
		}
		else { // inv[i] > inv[j]
			sorted[k++] = inv[j++];
			cnt = cnt + (mid - i + 1);
		}
	}
	if (i > mid) {
		for (l = j; l <= right; l++)
		{
			sorted[k++] = inv[l];
		}
	}
	else {
		for (l = i; l <= mid; l++)
		{
			sorted[k++] = inv[l];
		}
	}

	for (l = left; l <= right; l++) {
		inv[l] = sorted[l];
	}
}

void sort(long long inv[], long long left, long long right) {
	long long mid;
	if (left < right) {
		mid = (left + right) / 2;
		sort(inv, left, mid);
		sort(inv, mid + 1, right);
		merge(inv, left, mid, right);

	}
}

int main() {

	long long answer;
	long long test;
	fscanf(inp, "%lld", &test);
	for (long long t = 0; t < test; t++) {

		long long inv[100000] = { 0 };
		cnt = 0;
		U = 0, V = 0;
		fscanf(inp, "%lld", &num);

		for (long long i = 0; i < num; i++) {
			fscanf(inp, "%lld", &inv[i]);
		}
		sort(inv, 0, num - 1);

		/*
		for (long long i = 0; i < num; i++) {
			for (long long j = 0; j < num; j++) {

				if (j < i && inv[j] > inv[i])cnt++;

			}
		}
		*/
		fprintf(out, "%lld\n", cnt);
	}//test
	return 0;
}