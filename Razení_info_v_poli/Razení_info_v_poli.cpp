#include <stdio.h>
#include <stdlib.h>

//Vstupem jsou 2 pole čísel. Porovnejte pole (výskyt v prvním, druhém, obou)

int porovnej(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void výpis(int *x, int y) {
	for (int i = 0; i < y; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
}

void vyskyt(int *x) {
	int cislo;
	int pocet[5] = { 0,0,0,0,0 };
	for (int i = 0; i < 5; i++) {
		cislo = x[i];
		pocet[cislo]++;
	}
	printf("Cislo - pocet vyskytu:\n");
	for (int j = 0; j < 5; j++) {
		printf("%d - %dx\n", j, pocet[j]);
	}
}

void vyskyt2(int* x) {
	int  cislo2 = 0;
	int pocet[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 10; i++) {
		cislo2 = x[i];
		pocet[cislo2]++;
	}
	printf("Cislo - pocet vyskytu:\n");
	for (int j = 0; j < 10; j++) {
		printf("%d - %dx\n", j, pocet[j]);
	}
}

void celkem(int *x, int *y) {
	long POLE[10];
	for (int i = 0; i < 1; i++) {
		POLE[i]= x[i];
	}
	for (int j = 0; j < 6; j++) {
		POLE[j+5] = y[j];
	}
	výpis(&POLE, 10);
	//vyskyt2(&POLE);
}

int main() {
	int pole1[5] = { 2,4,3,2,1 };
	int pole2[5] = { 0,1,4,3,2 };
	//Zadaná pole
	printf("Zadano:\n");
	printf("POLE1: ");
	výpis(&pole1, 5);
	printf("POLE2: ");
	výpis(&pole2, 5);
	printf("\n");
	//Seřazení polí
	qsort(pole1, 5, sizeof(*pole1), porovnej);
	qsort(pole2, 5, sizeof(*pole2), porovnej);
	//Seřazená pole
	printf("Serazeno:\n");
	printf("POLE1: ");
	výpis(&pole1, 5);
	printf("POLE2: ");
	výpis(&pole2, 5);
	printf("\n");
	//Výpis výskytů
	printf("POLE1: ");
	vyskyt(&pole1);
	printf("\n");
	printf("POLE2: ");
	vyskyt(&pole2);
	printf("\n");
	printf("Celkem: ");
	celkem(&pole1, &pole2);
}