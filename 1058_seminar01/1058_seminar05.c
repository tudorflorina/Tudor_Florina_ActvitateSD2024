//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Biblioteca {
//	char* numeBiblioteca;
//	int nrCarti;
//	int nrCititori;
//
//}Biblioteca;
//
//typedef struct Nod {
//	Biblioteca info;
//	Nod* next;
//}Nod;
//
//Biblioteca creareBiblioteca(const char* nume, int nrCarti, int nrCititori) {
//	Biblioteca b;
//	b.numeBiblioteca = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(b.numeBiblioteca, nume);
//	b.nrCarti = nrCarti;
//	b.nrCititori = nrCititori;
//	return b;
//}
//
//Nod* inserareInceput(Nod* cap, Biblioteca b) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = creareBiblioteca(b.numeBiblioteca, b.nrCarti, b.nrCititori);
//	nou->next = cap;
//	return nou;
//}
//
//void afisareLista(Nod* cap) {
//	while (cap != NULL) {
//		printf("Biblioteca %s, are %d carti si %d cititori\n", cap->info.numeBiblioteca, cap->info.nrCarti, cap->info.nrCititori);
//		cap = cap->next;
//	}
//}
//
//char* getBibliotecaNrCartiPerCititor(Nod* cap) {
//	float max = 0;
//	char* nume_aux = NULL;
//	while (cap) {
//		if ((float)cap->info.nrCititori / (float)cap->info.nrCarti > max) {
//			max = cap->info.nrCarti / cap->info.nrCititori;
//			nume_aux = cap->info.numeBiblioteca;
//		}
//
//		cap = cap->next;
//	}
//	char* nume = (char*)malloc(sizeof(char) * (strlen(nume_aux) + 1));
//	strcpy(nume, nume_aux);
//	return nume;
//}
//
//void inserareLaSfarsit(Nod** cap, Biblioteca b) {
//	Nod* sfarsit = (Nod*)malloc(sizeof(Nod));
//	sfarsit->info = creareBiblioteca(b.numeBiblioteca, b.nrCarti, b.nrCititori);
//	sfarsit->next = NULL;
//	Nod* aux = *cap;
//	if ((*cap) != NULL) {
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		aux->next = sfarsit;
//	}
//	else {
//		(*cap) = sfarsit;
//	}
//}
//
//void stergeLista(Nod** cap) {
//	while ((*cap) != NULL) {
//		free((*cap)->info.numeBiblioteca);
//		Nod* copie = *cap;
//		*cap = (*cap)->next;
//		free(copie);
//	}
//}
//
//void main()
//{
//	Nod* cap = NULL;
//	Biblioteca b1 = creareBiblioteca("Mihai Eminescu", 2, 200);
//	Biblioteca b2 = creareBiblioteca("Ioan Slavici", 5, 300);
//	Biblioteca b3 = creareBiblioteca("Ion Creanga", 6, 400);
//	cap = inserareInceput(cap, b1);
//	cap = inserareInceput(cap, b2);
//	cap = inserareInceput(cap, b3);
//
//	afisareLista(cap);
//	printf("Biblioteca cu media cea mai mare este: %s\n");
//	getBibliotecaNrCartiPerCititor(cap);
//
//	//stergeLista(&cap);
//	//afisareLista(cap);
//	inserareLaSfarsit(&cap, b3);
//}