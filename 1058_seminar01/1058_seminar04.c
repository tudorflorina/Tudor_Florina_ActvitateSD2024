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
//void citireFisierMatrice(char* numeFisier, int* nraeroporturiLinie, int nrClustere, struct Aeroporturi** aeroporturi) {
//	FILE* f = fopen(numeFisier, "r");
//
//	if (f != NULL) {
//		char buffer[100];
//		while (fgets(buffer, 99, f) != NULL) {
//			struct Aeroport aeroport;
//			char delimitator[] = ",\n";
//			char* token = strtok(buffer, delimitator);
//			aeroport.id = atoi(token);
//			token = strtok(NULL, delimitator);//PLEACA DE LA NULL DEOARECE ISI CAUTA APELUL ANTERIOR
//			aeroport.nume = malloc(sizeof(char*) * strlen(token) + 1);
//			strcpy(aeroport.nume, token);
//			token = strtok(NULL, delimitator);
//			aeroport.nrTerminale = atoi(token);
//			int poz = aeroport.nrTerminale % 2;
//
//			aeroporturi[poz] = adaugaAeroport(aeroporturi[poz], aeroport, &(nraeroporturiLinie[poz]));
//		}
//		fclose(f);
//	}
//	return aeroporturi;
//}
//
//void afisareAeroport(struct Aeroport* aeroport) {
//	printf("%d.%s are %d terminale", aeroport->id, aeroport->nume, aeroport->nrTerminale);
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
//void afisareMatrice(struct Aeroport** matrice, int nrClustere, int* nrColoane) {
//	for (int i = 0; i < nrClustere; i++) {
//		for (int j = 0; j < nrColoane[i]; j++) {
//			afisareAeroport(&matrice[i][j]);
//		}
//		printf("\n");
//	}
//}
//
////functie care sa calculeze nr mediu de termnale pentru aeroporturile cu nr par de terminale
//float mediaTerminalePare(struct Aeroport** aeroporturi, int nrClustere, int* nrAeroporturi, int paritate) {
//		paritate = paritate % 2;
//		int suma = 0;
//		for (int i = 0; i < nrAeroporturi[paritate]; i++) {
//			suma += aeroporturi[paritate][i].nrTerminale;
//		}
//		if (nrAeroporturi[paritate]) {
//			return suma / nrAeroporturi[paritate];
//		}
//		return 0;
//}
//
//void dezalocareMatrice(struct Aeroport** matrice, int** nrColoane, int* nrClustere)
//{
//	for (int i = 0; i < (*nrClustere); i++) {
//		dezalocareVector(&((*matrice)[i]), (&((*nrColoane)[i])));
//	}
//	free(*matrice);
//	(*matrice) = NULL;
//	free(*nrColoane);
//	(*nrColoane) = NULL;
//}
//
//
//void main() {
//	struct Aeroport** aeroporturi;
//	int nrLinii = 2; //cele ce au un nr impar de intrati intr un cluster celalalt in alt cluster
//	int* nrColoane = (int*)malloc(sizeof(int) * nrLinii + 1);
//
//	aeroporturi = (struct Aeroport**)malloc(sizeof(struct Aeoport*) * nrLinii);
//	for (int i = 0; i < nrLinii; i++) {
//		nrColoane[i] = 0;
//		aeroporturi[i] = NULL;
//	}
//	
//	citireFisierMatrice("Aeroporturi.txt", nrColoane, nrLinii, aeroporturi);
//	afisareMatrice(aeroporturi, nrLinii, nrColoane);
//	float medie = mediaTerminalePare(aeroporturi, nrLinii , nrColoane, 12);
//	printf("Media %5.2f", medie);
//	dezalocareMatrice(aeroporturi, nrColoane, nrLinii);
//}