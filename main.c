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
			//printf("%d ", x); shows order in which columns were printed
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

//sorting algorithm
void sort() {
	int x = 39;

	for (int i = 0; i < 40; i++) {// y
		int count_row = 0;
		for (int j = 0; j < 40; j++) {// x
			if (a[i][j] == 'X') {
				for (int z = 39; z > -1; z--) {
					if (a[z][x] == 'X') {
						count_row++;
					}
					else if (a[z][x] == ' ') {
						break;
					}
				}
				for (int n = 39; n > i-1; n--) {
					a[n][x] = 'X';
				}
				for (int n = 0; n < (40-count_row); n++) {
					a[n][j] = ' ';
				}
				//printf(" %d ", count_row);
				break;
			}
		}
		system("cls");
 		show_table();
		Sleep(125);
		x--;
	}
};

int main() {
	//random number generator
	srand(time(NULL));

	//generator loop
	table_generator();
	while (1) {
		//menu
		system("cls");
		show_table();
		printf("\n\n1 - generate again\n2 - sort\n3 - exit\n= ");
		int option = 0;
		scanf_s("%d", &option); //exit the program
		if (option == 1) { table_generator(); }
		else if (option == 2) { sort(); }
		else if (option == 3) { break; }
		else { continue; }
	}
}
