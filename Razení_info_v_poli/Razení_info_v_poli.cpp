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

int main() {
	int pole1[5] = { 2,4,3,2,1 };
	int pole2[5] = { 0,1,4,3,2 };

	printf("Zadano:\n");
	printf("POLE1: ");
	výpis(&pole1, 5);
	printf("POLE2: ");
	výpis(&pole2, 5);
	printf("\n");

	qsort(pole1, 5, sizeof(*pole1), porovnej);
	qsort(pole2, 5, sizeof(*pole2), porovnej);

	printf("Serazeno:\n");
	printf("POLE1: ");
	výpis(&pole1, 5);
	printf("POLE2: ");
	výpis(&pole2, 5);
	printf("\n");

	printf("POLE1: ");
	vyskyt(&pole1);
	printf("\n");
	printf("POLE2: ");
	vyskyt(&pole2);
	printf("\n");
	printf("POLE2: ");
}