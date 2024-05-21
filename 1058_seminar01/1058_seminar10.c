//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//
//typedef struct Elev Elev;
//typedef struct Nod Nod;
//
//struct Elev {
//	int id;
//	int nrMedii;
//	float* medii;
//};
//
//struct Nod {
//	Elev info;
//	Nod* stanga;
//	Nod* dreapta;
//};
//
//void inserareArbore(Nod** radacina, Elev e) {
//	if ((*radacina) != NULL) {
//
//		if ((*radacina)->info.id > e.id) {
//			inserareArbore(&((*radacina)->stanga), e);
//		}
//		else {
//			inserareArbore(&((*radacina)->dreapta), e);
//		}
//	}
//	else
//	{
//		Nod* nod = (Nod*)malloc(sizeof(Nod));
//		nod->info = e;
//		nod->stanga = NULL;
//		nod->dreapta = NULL;
//		*radacina = nod;
//	}
//}
//
//Elev citireElev(FILE* fp){
//	Elev e;
//	fscanf(fp, "&d", &e.id);
//	fscanf(fp, "&d", &e.nrMedii);
//	float* medii = (float*)malloc(sizeof(float) * e.nrMedii);
//	for (int i = 0; i < e.nrMedii; i++) {
//		fscanf(fp, "%f", &e.medii[i]);
//	}
//	return e;
//}
//
//Nod* citireFisier(char* numeFisier) {
//	Nod* arbore = NULL;
//	if (numeFisier != NULL) {
//		FILE* f = fopen(numeFisier, "r");
//		int nrElevi = 0;
//		fscanf(f, "%d", nrElevi);
//		for (int i = 0; i < nrElevi; i++) {
//			Elev e = citireElev(f);
//			inserareArbore(&arbore, e);
//		}
//	}
//	fclose(numeFisier);
//	return arbore;
//}
//
//void afisareElev(Elev e) {
//	printf("Elevul cu id-ul %d are mediile: ", e.id);
//	for (int i = 0; i < e.nrMedii; i++) {
//		printf("%5.2f", e.medii[i]);
//	}
//	printf("\n");
//}
//
//void afisareArbore(Nod* arbore) {
//	afisareArbore(arbore->dreapta);
//	afisareElev(arbore->info);
//	afisareArbore(arbore->stanga);
//}
//
////sumele le am facut la tabla 
////de completat
//
//void main() {
//	Nod* arbore = citireFisier("Elevi.txt");
//	afisareArbore(arbore);
//}