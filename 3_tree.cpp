#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include <string.h>
using namespace std;
#pragma warning (disable:4996)
#pragma execution_character_Set("utf-8")
int stack[50000];
int top = -1;

FILE* inp = fopen("tree.inp", "rt");
FILE* out = fopen("tree.out", "wt");

int isEmpty() {
	if (top == -1)return 1;
	else return 0;
}

void push(int item) {

	stack[++top] = item;
}

int pop() {
	if (isEmpty()) {
		return 0;
	}
	return stack[top--];
}

int main()
{

	int test;

	fscanf(inp, "%d", &test);
	for (int t = 0; t < test; t++)
	{
		char tree[50000] = { '0' };
		int num = 0;
		int T_num = 0;

		if (t == 0)fgetc(inp);
		for (int i = 0; ; i++) {
			fscanf(inp, "%c", &tree[i]);
			fprintf(out, "%c", tree[i]); //그대로 출력
			if (tree[i] == '\n') break;
		}//입력

		fprintf(out, "Preorder\n");

		for (int i = 0;; i++) {
			if (tree[i] == '(') {
				fprintf(out, "r%d\n", num);
				num++;
			}
			else if (tree[i] >= 65 && tree[i] <= 90) {
				fprintf(out, "%c%c", tree[i], tree[i + 1]);
				if (tree[i + 2] >= 48 && tree[i + 2] <= 57) {
					fprintf(out, "%c", tree[i + 2]);

					if (tree[i + 3] >= 48 && tree[i + 3] <= 57) {
						fprintf(out, "%c\n", tree[i + 3]);
					}
					else
					{
						fprintf(out, "\n");
					}

				}
				else
					fprintf(out, "\n");
			}

			if (tree[i] == '\n') break;
		}
		//Preorder
		fprintf(out, "Inorder\n");
		num = 0;
		T_num = 0;
		for (int i = 0;; i++) {

			if (tree[i] == '(') {
				push(num);
				num++;
			}
			else if (tree[i] >= 65 && tree[i] <= 90) {
				fprintf(out, "%c%c", tree[i], tree[i + 1]);
				if (tree[i + 2] >= 48 && tree[i + 2] <= 57) {
					fprintf(out, "%c", tree[i + 2]);

					if (tree[i + 3] >= 48 && tree[i + 3] <= 57) {
						fprintf(out, "%c\n", tree[i + 3]);
					}
					else
					{
						fprintf(out, "\n");
					}

				}
				else
					fprintf(out, "\n");

				if (i > 0 && top == -1) break;
				fprintf(out, "r%d", stack[top]);
				pop();
				fprintf(out, "\n");
			}


			if (tree[i] == '\n') break;
		}

	}//testcase
	return 0;
}