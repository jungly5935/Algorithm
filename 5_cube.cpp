#include <stdio.h>
#include <stdlib.h>

using namespace std;
#pragma warning (disable:4996)

int main()
{
	FILE* out = fopen("cube.out", "wt");
	FILE* inp = fopen("cube.inp", "rt");

	int i = 0;
	int t = 0;
	while (1) {
		char dice[12] = { '0', };
		char dice2[6] = { '0', };
		i = 0;
		int flag = 0;
		int r = 0, g = 0, b = 0;
		int r2 = 0, g2 = 0, b2 = 0;

		if (t != 0)fgetc(inp);

		for (int i = 0; i < 12; i++) fscanf(inp, "%c", &dice[i]);

		for (int i = 0; i < 6; i++) {
			if (dice[i] == 'r') r++;
			if (dice[i] == 'g') g++;
			if (dice[i] == 'b') b++;
		}

		for (int i = 6; i < 12; i++) {
			if (dice[i] == 'r')r2++;
			if (dice[i] == 'g')g2++;
			if (dice[i] == 'b')b2++;

		}

		if (r == 0 && g == 0 && b == 0) break; //종료조건

		if (r == r2 && g == g2 && b == b2) { flag = 0; }
		else { //문자 수 틀리면 false
			fprintf(out, "FALSE\n");
			t++;
			continue;
		}

		if (dice[0] == dice[6] && dice[1] == dice[7] && dice[2] == dice[8] && dice[4] == dice[10] && dice[3] == dice[9] && dice[5] == dice[11]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[6] && dice[1] == dice[8] && dice[2] == dice[10] && dice[4] == dice[9] && dice[3] == dice[7] && dice[5] == dice[11]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[6] && dice[1] == dice[10] && dice[2] == dice[9] && dice[4] == dice[7] && dice[3] == dice[8] && dice[5] == dice[11]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[6] && dice[1] == dice[9] && dice[2] == dice[7] && dice[4] == dice[8] && dice[3] == dice[10] && dice[5] == dice[11]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}

		else if (dice[0] == dice[11] && dice[1] == dice[10] && dice[2] == dice[8] && dice[4] == dice[7] && dice[3] == dice[9] && dice[5] == dice[6]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[11] && dice[1] == dice[9] && dice[2] == dice[10] && dice[4] == dice[8] && dice[3] == dice[7] && dice[5] == dice[6]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[11] && dice[1] == dice[7] && dice[2] == dice[9] && dice[4] == dice[10] && dice[3] == dice[8] && dice[5] == dice[6]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[11] && dice[1] == dice[8] && dice[2] == dice[7] && dice[4] == dice[9] && dice[3] == dice[10] && dice[5] == dice[6]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}

		else if (dice[0] == dice[9] && dice[1] == dice[10] && dice[2] == dice[11] && dice[4] == dice[7] && dice[3] == dice[6] && dice[5] == dice[8]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[9] && dice[1] == dice[6] && dice[2] == dice[10] && dice[4] == dice[11] && dice[3] == dice[7] && dice[5] == dice[8]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[9] && dice[1] == dice[7] && dice[2] == dice[6] && dice[4] == dice[10] && dice[3] == dice[11] && dice[5] == dice[8]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[9] && dice[1] == dice[11] && dice[2] == dice[7] && dice[4] == dice[6] && dice[3] == dice[10] && dice[5] == dice[8]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[8] && dice[1] == dice[10] && dice[2] == dice[6] && dice[4] == dice[7] && dice[3] == dice[11] && dice[5] == dice[9]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[8] && dice[1] == dice[11] && dice[2] == dice[10] && dice[4] == dice[6] && dice[3] == dice[7] && dice[5] == dice[9]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[8] && dice[1] == dice[7] && dice[2] == dice[11] && dice[4] == dice[10] && dice[3] == dice[6] && dice[5] == dice[9]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[8] && dice[1] == dice[6] && dice[2] == dice[7] && dice[4] == dice[11] && dice[3] == dice[10] && dice[5] == dice[9]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}

		else if (dice[0] == dice[7] && dice[1] == dice[11] && dice[2] == dice[8] && dice[4] == dice[6] && dice[3] == dice[9] && dice[5] == dice[10]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[7] && dice[1] == dice[9] && dice[2] == dice[11] && dice[4] == dice[8] && dice[3] == dice[6] && dice[5] == dice[10]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[7] && dice[1] == dice[6] && dice[2] == dice[9] && dice[4] == dice[11] && dice[3] == dice[8] && dice[5] == dice[10]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[7] && dice[1] == dice[8] && dice[2] == dice[6] && dice[4] == dice[9] && dice[3] == dice[11] && dice[5] == dice[10]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}

		else if (dice[0] == dice[10] && dice[1] == dice[11] && dice[2] == dice[9] && dice[4] == dice[6] && dice[3] == dice[8] && dice[5] == dice[7]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[10] && dice[1] == dice[8] && dice[2] == dice[11] && dice[4] == dice[9] && dice[3] == dice[6] && dice[5] == dice[7]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[10] && dice[1] == dice[6] && dice[2] == dice[8] && dice[4] == dice[11] && dice[3] == dice[9] && dice[5] == dice[7]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else if (dice[0] == dice[10] && dice[1] == dice[9] && dice[2] == dice[6] && dice[4] == dice[8] && dice[3] == dice[11] && dice[5] == dice[7]) {
			fprintf(out, "TRUE\n");
			t++;
			continue;
		}
		else {
			fprintf(out, "FALSE\n");
		}

	}//testcase
	return 0;
}