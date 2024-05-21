//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
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
//	Nod* st;
//	Nod* dr;
//};
//
//Nod* rotireDreapta(Nod* radacina) {
//	Nod* nod;
//	nod = radacina->st;
//	radacina->st = nod->dr;
//	nod->dr = radacina;
//	return nod;
//}
//
//Nod* rotireStanga(Nod* radacina) {
//	Nod* nod;
//	nod = radacina->dr;
//	radacina->dr = nod->st;
//	nod->st = radacina;
//	return nod;
//}
//
//void inserareArbore(Nod** radacina, Elev e) {
//	if ((*radacina) != NULL) {
//		if ((*radacina)->info.id > e.id) {
//			inserareArbore(&((*radacina)->st), e);
//		}
//		else {
//			inserareArbore(&((*radacina)->dr), e);
//		}
//		int grad = gradEchilibru((*radacina));
//		if (grad == 2)
//		{
//			if (gradEchilibru((*radacina)->st) == 1)
//			{
//				(*radacina) = rotireDreapta((*radacina));
//			}
//			else
//			{
//				(*radacina)->st = rotireStanga((*radacina)->st);
//				(*radacina) = rotireDreapta(*radacina);
//			}
//		}
//		else if (grad == -2)
//		{
//			if (gradEchilibru((*radacina)->dr) == 1)
//			{
//				(*radacina)->dr = rotireDreapta((*radacina)->dr);
//				(*radacina) = rotireStanga((*radacina));
//			}
//			else
//			{
//				(*radacina) = rotireStanga((*radacina));
//			}
//		}
//
//	}
//	else {
//		Nod* nod = (Nod*)malloc(sizeof(Nod));
//		nod->info = e;
//		nod->st = NULL;
//		nod->dr = NULL;
//		*radacina = nod;
//	}
//}
//
//
//int inaltime(Nod* radacina) {
//	if (radacina == NULL)
//		return 0;
//	else {
//		int inaltimeSt = inaltime(radacina->st);
//		int inaltimeDr = inaltime(radacina->dr);
//		return 1 + (inaltimeSt > inaltimeDr ? inaltimeSt : inaltimeDr);
//	}
//}
//
//
//int gradEchilibru(Nod* radacina) {
//	int inaltimeSt = inaltime(radacina->st);
//	int inaltimeDr = inaltime(radacina->dr);
//
//	return inaltimeSt - inaltimeDr;
//}
//
//
//Elev citireElev(FILE* fp) {
//	Elev e;
//	fscanf(fp, "%d", &e.id);
//	fscanf(fp, "%d", &e.nrMedii);
//	e.medii = malloc(sizeof(float) * e.nrMedii);
//	for (int i = 0; i < e.nrMedii; i++) {
//		fscanf(fp, "%f", &(e.medii[i]));
//	}
//	return e;
//}
//
//Nod* citireFisier(char* numeFisier) {
//	Nod* arbore = NULL;
//	if (!numeFisier) {
//		return NULL;
//	}
//	else {
//		FILE* fp = fopen(numeFisier, "r");
//		int nrElevi;
//		fscanf(fp, "%d", &nrElevi);
//
//		for (int i = 0; i < nrElevi; i++) {
//			Elev e = citireElev(fp);
//			inserareArbore(&arbore, e);
//		}
//		fclose(fp);
//	}
//	return arbore;
//}
//
//void afisareElev(Elev e) {
//	printf("Elevul cu id-ul %d are un nr de %d medii, anume mediile: ", e.id, e.nrMedii);
//	for (int i = 0; i < e.nrMedii; i++) {
//		printf("%5.2f", e.medii[i]);
//	}
//	printf("\n");
//}
//
//void afisareInOrder(Nod* arbore) {
//	if (arbore != NULL) {
//		afisareInOrder(arbore->st);
//		afisareElev(arbore->info);
//		afisareInOrder(arbore->dr);
//	}
//}
//
//float calculeazaMedieElev(Elev e) {
//	if (e.nrMedii != 0) {
//		float suma = 0;
//		for (int i = 0; i < e.nrMedii; i++) {
//			suma += e.medii[i];
//		}
//		return suma / e.nrMedii;
//	}
//	else {
//		return 0;
//	}
//}
//
//float calculeazaSumaNote(Nod* arbore, int* nrNote) {
//	if (arbore != NULL) {
//		float suma = 0;
//		for (int i = 0; i < arbore->info.nrMedii; i++) {
//			suma += arbore->info.medii[i];
//		}
//		(*nrNote) += arbore->info.nrMedii;
//		float sumaSt = calculeazaSumaNote(arbore->st, nrNote);
//		float sumaDr = calculeazaSumaNote(arbore->dr, nrNote);
//
//		return suma + sumaDr + sumaSt;
//	}
//	else {
//		return 0;
//	}
//}
//
//float calculeazaMediaGenerala(Nod* arbore) {
//	int nrNote = 0;
//	float suma = calculeazaSumaNote(arbore, &nrNote);
//	printf("\n Numarul de note %d \n", nrNote);
//	if (nrNote > 0) {
//		return suma / nrNote;
//	}
//	else {
//		return 0;
//	}
//}
//
//void afisarePreordine(Nod* radacina) {
//	if (radacina) {
//		afisareElev(radacina->info);
//		afisarePreordine(radacina->st);
//		afisarePreordine(radacina->dr);
//	}
//}
//
//void stergereArbore(Nod** radacina) {
//	if (*radacina) {
//		stergereArbore(&((*radacina)->st));
//		stergereArbore(&((*radacina)->dr));
//		free((*radacina)->info.medii);
//		free(*radacina);
//		*radacina = NULL;
//
//	}
//}
//
//void main()
//{
//	Nod* arbore = NULL;
//	arbore = citireFisier("elevi.txt");
//	printf("media este %5.2f \n", calculeazaMediaGenerala(arbore));
//	stergereArbore(&arbore);
//	afisarePreordine(arbore);
//}