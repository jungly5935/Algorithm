#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)

int area[4001][4001];
int paper_x[4001];
int paper_y[4001];
int paper_x2[4001];
int paper_y2[4001];
int cnt1[4001], cnt2[4001];

int main() {

	FILE* out = fopen("paper.out", "wt");
	FILE* inp = fopen("paper.inp", "rt");

	int test;
	fscanf(inp, "%d", &test);

	int x, y, width, height;
	vector <int> paperX;
	vector <int> paperY;

	for (int t = 0, i = 0; t < test; t++, i++) {
		fscanf(inp, "%d %d %d %d", &x, &y, &width, &height);
		paperX.push_back(x);
		paperY.push_back(y);
		paperX.push_back(x + width);
		paperY.push_back(y + height);
		paper_x[i] = x, paper_x2[i] = x + width;
		paper_y[i] = y, paper_y2[i] = y + height;

	}//입력

	sort(paperX.begin(), paperX.end()); sort(paperY.begin(), paperY.end());
	paperX.erase(unique(paperX.begin(), paperX.end()), paperX.end()); paperY.erase(unique(paperY.begin(), paperY.end()), paperY.end());
	//paperX.insert(paperX.begin(), 0); paperY.insert(paperY.begin(), 0); //정렬

	int num = 1; //종이 순서
	for (int k = 0; k < test; k++, num++) {
		int x1, x2, y1, y2;
		for (int m = 0; m < paperX.size(); m++) {
			if (paperX[m] == paper_x[k]) {
				x1 = m;
				break;
			}
		}
		for (int m = 0; m < paperX.size(); m++) {
			if (paperX[m] == paper_x2[k]) {
				x2 = m;
				break;
			}
		}
		for (int m = 0; m < paperY.size(); m++) {
			if (paperY[m] == paper_y[k]) {
				y1 = m;
				break;
			}
		}
		for (int m = 0; m < paperY.size(); m++) {
			if (paperY[m] == paper_y2[k]) {
				y2 = m;
				break;
			}
		}
		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				/*if ((paperX[i] >= paper_x[k] && paperX[i] < paper_x2[k]) && (paperY[j] >= paper_y[k] && paperY[j] < paper_y2[k])) {*/
				   //cnt2[area[j][i]]++;
				area[i][j] = num; //1,2,3겹치는 면적 표시
				cnt1[num] += 1; //칠해진 칸 개수!
			}
		}
	}
	for (int i = 0; i < paperX.size(); i++) {
		for (int j = 0; j < paperY.size(); j++) {
			if (area[i][j] != 0)   cnt2[area[i][j]]++;
		}
	}
	int paperNO = 0, paper_half = 0, paperO = 0;
	for (int k = 1; k <= test; k++) {
		if (cnt2[k] == 0) paperNO++;
		else if (cnt1[k] == cnt2[k]) paperO++;
		else paper_half++;
	}
	fprintf(out, "%d %d %d", paperNO, paper_half, paperO);


	return 0;
}