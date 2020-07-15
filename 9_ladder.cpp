#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
FILE* out = fopen("ladder.out", "wt");
FILE* inp = fopen("ladder.inp", "rt");
vector < vector <long long> > ladder(51);
long long sorted[10003];
/*
void merge(long long start, long long mid, long long end, long long x) {

	long long i = start;
	long long j = mid + 1;
	long long k = start;

	while (i <= mid && j <= end) {
		if (ladder[x][i] >= ladder[x][j]) {
			sorted[k] = ladder[x][i];
			i++;
		}
		else {
			sorted[k] = ladder[x][j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (long long t = j; t <= end; t++) {
			sorted[k] = ladder[x][t];
			k++;
		}
	}
	else {
		for (long long t = i; t <= mid; t++) {
			sorted[k] = ladder[x][t];
			k++;
		}
	}

	for (long long t = start; t <= end; t++) {
		ladder[x][t] = sorted[t];
	}

}

void merge_sort(long long start, long long end, long long x) {
	if (start < end) {
		long long mid = (start + end) / 2;
		merge_sort(start, mid, x);
		merge_sort(mid + 1, end, x);
		merge(start, mid, end, x);
	}
}
*/
int main() {

	long long test;
	long long x1, y1, x2, y2;
	long long start_x, start_y;
	long long end_x, end_y;

	vector < vector <long long> > location(10003); // 좌표 4개

	fscanf(inp, "%lld", &test);
	for (long long i = 0; ;i++) {
		fscanf(inp, "%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)break;
		location[i].push_back(x1);
		location[i].push_back(y1);
		location[i].push_back(x2);
		location[i].push_back(y2);

		ladder[x1].push_back(y1);
		ladder[x2].push_back(y2);

	}//input


	for (long long i = 0; i < test; i++) {
		sort(ladder[i].begin(), ladder[i].end(), greater<long long>());
	} //내림차순 정렬

	/*
	for (long long i = 0; i < test; i++) {
		merge_sort( 0, ladder[i].size()-1, i);
	} //내림차순 정렬
	*/
	long long index;
	long long flag;
	long long result[51] = { 0 };

	for (long long z = 0;z < test; z++) {
		start_x = z; //처음 시작은 무조건 0번 사다리부터
		start_y = ladder[z].front();
		long long exit = -1;

		while (1) {
			//x도 같이 봐야함!!!
			for (long long i = 0; ; i++) {
				if ((start_x == location[i][0] && start_y == location[i][1]) || (start_x == location[i][2] && start_y == location[i][3]))
				{
					index = i;
					if (start_y == location[i][1] && start_x == location[i][0])flag = 1;
					else if (start_y == location[i][3] && start_x == location[i][2]) flag = 3;
					break;
				} // 1이 y1자리이므로 해당하는 i를 index에 넣기
			}

			if (flag == 1) {
				start_x = location[index][2];
				start_y = location[index][3];
			}
			else if (flag == 3) {
				start_x = location[index][0];
				start_y = location[index][1];
			}

			if (start_y == ladder[start_x].back()) {
				exit = 0;
				result[start_x] = z;
				break;
			}
			if (exit == 0) break;


			for (long long i = 0; i < ladder[start_x].size(); i++) {

				if (start_y == ladder[start_x][i]) {
					index = i;
					break;
				}
			}
			start_y = ladder[start_x][index + 1];

		}

	}//z

	for (long long i = 0; i < test; i++) {
		fprintf(out, "%lld ", result[i]);
	}
	return 0;
}