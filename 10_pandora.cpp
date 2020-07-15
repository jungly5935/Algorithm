#include<stdio.h>
#pragma warning(disable:4996)

FILE* inp = fopen("pandora.inp", "rt");
FILE* out = fopen("pandora.out", "wt");

char polygon[100001];

int main() {

	int test;
	fscanf(inp, "%d\n", &test);
	for (int t = 0; t < test; t++) {

		fscanf(inp, "%s", &polygon);

		int S = 3; // left = 1, down = 2, right = 3, up = 4
		int W = 1;
		int H = 1;

		for (int i = 0; ; i++) {

			if (polygon[i] == '\0') { //마지막 입력 일때 판단 후 종료

				if (polygon[i - 1] == 'R' && polygon[0] == 'R') {
					S = (S + 3) % 4;
					if (S == 1) H = 0; //왼
					else if (S == 2) W = 0; //아래
					else if (S == 3)H = 0; //오른	
					else if (S == 4)W = 0;//위

				}
				break;
			}

			if (polygon[i] == 'L') S = (S + 1) % 4; // +1 은 90도
			else if (polygon[i] == 'R') {
				S = (S + 3) % 4; // +3은 270도
				if (i > 0) { // i > 0 일때 (처음 제외 하고는 무조건 처리 해줄 것)
					if (polygon[i - 1] == 'R') { // i(현재정점) 바로 전(i-1)의 정점을 보고 판단
						if (S == 1) H = 0; //왼
						else if (S == 2) W = 0; //아래
						else if (S == 3)H = 0; //오른	
						else if (S == 4)W = 0;//위
					}
					else continue; //i가 'R' 이고 i-1 이 'L'일때
				}
			}

		}//for
		int result = W + H;
		fprintf(out, "%d\n", result);
	}

	return 0;
}