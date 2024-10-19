#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//     y    x / table
char a[40][40];

void table_generator() {
	//makes table empty
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			a[i][j] = ' ';
		}
	}

	int height = -1;

	for (int i = 0; i < 40;) {
		int x = rand() % 40 + 0;
		if (a[39][x] == ' ') {
			printf("%d ", x);
			for (int y = 39; y > height; y--) {
				a[y][x] = 'X';
			}
			height++;
			i++;
		}
	}
};

//Prints table
void show_table() {
	printf("\n\n___");
	for (int i = 0; i <= 39; i++) {
		printf("|%d_", i);
		if (i < 10) { printf("_"); }
	}
	printf("|");
	for (int i = 0; i < 40; i++) {
		printf("\n%d_", i);
		if (i < 10) { printf("_"); }
		for (int j = 0; j < 40; j++) {
			printf("| %c ", a[i][j]);
		}
		printf("|");
	}
};

int main() {
	//random number generator
	srand(time(NULL));

	//generator loop
	while (1) {
		system("cls");

		table_generator();
		show_table();

		//menu
		printf("\n\n1 - generate again\n2 - exit\n= ");
		int option = 0;
		scanf_s("%d", &option);
		if (option == 2) {break;} //exit the program
	}
}