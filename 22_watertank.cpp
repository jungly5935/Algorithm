#include <stdio.h>
#include<queue>
#define MAX 1099
#pragma warning (disable:4996)
using namespace std;


int n, m, h, result;
int water[MAX][MAX];
int a[MAX][MAX], b[MAX][MAX];

int max(int a, int b) {
	int m = 0;
	if (a > b)m = a;
	else m = b;
	return m;
}
struct Data {
	int x, y, h;
	bool operator<(const Data& x)const {
		return h > x.h; //기본적으로 max hip (제일큰게 제일위로)
	}
};

priority_queue <Data> pq;

void Insert(int x, int y, int h) {
	Data temp;
	if (water[x][y]) return;
	temp.x = x;
	temp.y = y;
	temp.h = h;
	pq.push(temp);
}


int main() {

	FILE* out = fopen("watertank.out", "wt");
	FILE* inp = fopen("watertank.inp", "rt");

	int test;

	fscanf(inp, "%d", &test);


	for (int t = 0; t < test; t++) {
		fscanf(inp, "%d %d %d", &n, &m, &h);
		result = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				a[i][j] = 0, b[i][j] = 0, water[i][j] = 0;
			}
		}//초기화

		for (int i = 1; i <= n + 1; i++) {
			for (int j = 1; j <= m; j++) { //세로+1 * m만큼 반복
				fscanf(inp, "%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m + 1; j++) { //세로 * m+1만큼 반복
				fscanf(inp, "%d", &b[i][j]);
			}
		}

		for (int i = 1; i <= n + 1; i++) {
			for (int j = 1; j <= m; j++) { //세로+1 * m만큼 반복
				if (a[i][j] == -1) {
					a[i][j] = h;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m + 1; j++) { //세로 * m+1만큼 반복
				if (b[i][j] == -1) {
					b[i][j] = h;
				}
			}
		}
		//벽 높이 초기화

		for (int i = 1; i <= n; i++) {
			Insert(i, 1, b[i][1]); //왼쪽
			Insert(i, m, b[i][m + 1]); //오른쪽
			water[i][0] = water[i][m + 1] = true;
		}
		for (int i = 1; i <= m; i++) {
			Insert(1, i, a[1][i]); //위쪽
			Insert(n, i, a[n + 1][i]); //아래쪽
			water[0][i] = water[n + 1][i] = true;
		}
		//바깥쪽 벽 체크 완료


		Data temp;
		int x, y, h;
		while (pq.size()) {

			temp = pq.top(); //현재 제일 작은 값이 top에있음
			pq.pop();

			if (water[temp.x][temp.y] == 1)continue;//이미 처리 끝났으면 할필요x
			water[temp.x][temp.y] = 1;


			x = temp.x;
			y = temp.y;
			h = temp.h;

			Insert(x - 1, y, max(h, a[x][y])); //바로 위에있는 것 등록.. 4 4이고 구멍2면 4 등록 (둘중 큰것 등록)
			Insert(x + 1, y, max(h, a[x + 1][y])); //밑쪽
			Insert(x, y - 1, max(h, b[x][y])); // 왼쪽
			Insert(x, y + 1, max(h, b[x][y + 1])); //오른쪽

			result += h;
		}
		fprintf(out, "%d\n", result);

	}//test


	fclose(inp);
	fclose(out);
	return 0;
}