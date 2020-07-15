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

			if (polygon[i] == '\0') { //������ �Է� �϶� �Ǵ� �� ����

				if (polygon[i - 1] == 'R' && polygon[0] == 'R') {
					S = (S + 3) % 4;
					if (S == 1) H = 0; //��
					else if (S == 2) W = 0; //�Ʒ�
					else if (S == 3)H = 0; //����	
					else if (S == 4)W = 0;//��

				}
				break;
			}

			if (polygon[i] == 'L') S = (S + 1) % 4; // +1 �� 90��
			else if (polygon[i] == 'R') {
				S = (S + 3) % 4; // +3�� 270��
				if (i > 0) { // i > 0 �϶� (ó�� ���� �ϰ�� ������ ó�� ���� ��)
					if (polygon[i - 1] == 'R') { // i(��������) �ٷ� ��(i-1)�� ������ ���� �Ǵ�
						if (S == 1) H = 0; //��
						else if (S == 2) W = 0; //�Ʒ�
						else if (S == 3)H = 0; //����	
						else if (S == 4)W = 0;//��
					}
					else continue; //i�� 'R' �̰� i-1 �� 'L'�϶�
				}
			}

		}//for
		int result = W + H;
		fprintf(out, "%d\n", result);
	}

	return 0;
}