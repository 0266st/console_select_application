#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

int wait(float _time);
long rnd = 0;
bool debug;
int main(void) {
	debug = false;
	debug = false;// Debug用(trueがデバッグモード)
	printf("コンソール版ランダム選択アプリケーションVer.Beta\n");
	printf("選択肢を入力してください。(exitを入力して選択肢入力から抜けます)>\n");
	char choise[10][20] = {{},{}, {}, {}, {}, {}, {}, {}, {}, {}};
	int cnt = 1;
	printf("1.");
	if (!scanf_s("%20s", choise[0], 20)) {
		printf("無効な入力です。\n");
		return 0;
	}
	while (1) {
		printf("\n%d.", cnt + 1);
		if (!scanf_s("%20s", choise[cnt], 20)) {
			printf("無効な入力です。\n");
				return 0;
		}
		if (strstr(choise[cnt], "exit")) {
			printf("exitが入力されました。選択に移ります。");
			for (int i = 0; i < 20; i++) {
				choise[cnt][i] = '\0';
			}
			break;
		}
		cnt++;
	}
	printf("これより、ランダムで選択します。選択を始めるには、何かキーを押してください。\n");
	if (!_getch()) {
		printf("GETCHエラー。\n");
		return 0;
	}
	if(!debug) system("cls");
	printf("STEP.1 初期化中...");
	srand((unsigned int)time(NULL));
	printf("完了。");
	wait(7.5);
	if(!debug) system("cls");
	printf("STEP.2 ランダムな値を抽出中...\n");
	for (int i = 0; i < 100; i++) {
		rnd += rand();
		if(debug) printf("debug:rnd:%d\n", rnd);
	}
	wait(7.5);
	if(!debug) system("cls");
	if(debug) printf("STEP.3 算出結果を処理中...");
	rnd = rnd / 100;
	rnd = rnd % cnt;
	if(debug) printf("\ndebug:rnd;%d", rnd);
	printf("\n算出結果:%d. %s\n", rnd+1, choise[rnd]);
	wait(7.5);
	printf("このプログラムは終了しました。何かキーを押して終了してください。\n");
	if (!_getch()) {
		printf("GETCHエラー。\n");
		return 0;
	}
	return 0;
}

int wait(float _time) {
	for (unsigned long i = 0; i < _time * 500000000; i++) {
	}
	return 0;
}