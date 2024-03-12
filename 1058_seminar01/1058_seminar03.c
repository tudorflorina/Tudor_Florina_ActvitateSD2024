//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//struct Aeroport {
//	int id;
//	char* nume;
//	int nrTerminale;
//}Aeroport;
//
//struct Aeroport* adaugaAeroport(struct Aeroport* vector, struct Aeroport aeroport, int* dimensiune) {
//	struct Aeroport* copie = (struct Aeroport*)malloc(sizeof(struct Aeroport) * ((*dimensiune) + 1));
//
//	copie[(*dimensiune)] = aeroport;
//
//	for (int i = 0; i < (*dimensiune); i++) {
//		copie[i] = vector[i];
//	}
//
//	if (vector) {
//		free(vector);
//	}
//
//	(*dimensiune)++;
//
//	return copie;
//}
//
//struct Aeroport* citireFisier(char* numeFisier, int* nrAeroporturi) {
//	struct Aeroport* vectorAeroporturi;
//	vectorAeroporturi = NULL;
//	FILE* f = fopen(numeFisier, "r");
//
//	if (f != NULL) {
//		(*nrAeroporturi) = 0;
//		char buffer[100];
//		while (fgets(buffer, 99, f)!= NULL) {
//			struct Aeroport aeroport;
//			char delimitator[] = ",\n";
//			char* token = strtok(buffer, delimitator);
//			aeroport.id = atoi(token);
//			token = strtok(NULL, delimitator);//PLEACA DE LA NULL DEOARECE ISI CAUTA APELUL ANTERIOR
//			aeroport.nume = malloc(sizeof(char*) * strlen(token) + 1);
//			strcpy(aeroport.nume, token);
//			token = strtok(NULL, delimitator);
//			aeroport.nrTerminale = atoi(token);
//
//			vectorAeroporturi = adaugaAeroport(vectorAeroporturi, aeroport, nrAeroporturi);
//		}
//		fclose(f);
//	}
//	return vectorAeroporturi;
//}
//
//void afisareAeroport(struct Aeroport* aeroport) {
//	printf("Aeroportul cu ID: %d cu numele: %s are %d terminale", aeroport->id, aeroport->nume, aeroport->nrTerminale);
//}
//
//void AfisareVectorAeroporturi(struct Aeroport* aeroporturi, int dimensiune) {
//	printf("Aeroporturi:");
//	for (int i = 0; i < dimensiune; i++) {
//		afisareAeroport(&aeroporturi[i]);
//	}
//}
//
//void dezalocareVector(struct Aeroport** aeroporturi, int* dim) {
//	for (int i = 0; i < (*dim); i++)
//	{
//		free((*aeroporturi)[i].nume);
//		free(aeroporturi[i]);
//	}
//	free(aeroporturi);
//	(*aeroporturi) = NULL;
//	(*dim) = 0;
//}
//
////sa returneze un anumit aeroport dupa id
//
//struct Aeroport idCautat(struct Aeroport* aeroporturi, int dim, int id) {
//	for (int i = 0; i < dim; i++) {
//		if (aeroporturi[i].id == id)
//			return aeroporturi[i];
//	}
//}
//
//
//void main() {
//	int dimensiune = 3;
//
//	struct Aeroport* aeroporturi = NULL;
//	aeroporturi = citireFisier("Aeroporturi.txt", &dimensiune);
//	AfisareVectorAeroporturi(aeroporturi, dimensiune);
//	dezalocareVector(&aeroporturi, &dimensiune);
//}