//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct BazaDeDate {
//	unsigned int id;
//	char* nume;
//	int nrElemente;
//
//}BazaDeDate;
//
//BazaDeDate creareBd(unsigned int id, const char* nume, int nrElemente) {
//	BazaDeDate b;
//	b.id = id;
//	b.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy(b.nume, nume);
//	b.nrElemente = nrElemente;
//	return b;
//}
//
//typedef struct nod {
//	BazaDeDate info;
//	struct nod* next;
//}nod;
//
//typedef struct hastable {
//	int dim;
//	nod** vector;
//}hastable;
//
////cheia de inserare id - numeric -pozitia la care inserez
//int functieHash(hastable tabela, unsigned int id) {
//	return id % tabela.dim;
//}
//
//
////cheia de inserare sa fie nume
//int functieHash1(hastable tabela, const char* nume) {
//	return strlen(nume) % tabela.dim;
//}
//
//
//int inserareHash(hastable tabela, BazaDeDate b) {
//	int pozitie = 0;
//	if (tabela.vector) {
//		pozitie = functieHash(tabela, b.id);
//		nod* nou = (nod*)malloc(sizeof(nod));
//		nou->info = creareBd(b.id, b.nume, b.nrElemente);
//		nou->next = NULL;
//
//		if (tabela.vector[pozitie] == NULL) {
//			tabela.vector[pozitie] = nou;
//		}
//		else {
//			nod* aux = tabela.vector[pozitie];
//			while (aux->next) {
//				aux = aux->next;
//			}
//			aux->next = nou;
//		}
//	}
//
//	return pozitie;
//}
//
//void afisareTabela(hastable tabela) {
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				printf("Pozitia: %d\n", i);
//				nod* aux = tabela.vector[i];
//				while (aux) {
//					printf("id: %u, nume:%s, nrElem:%d \n", aux->info.id, aux->info.nume, aux->info.nrElemente);
//					aux = aux->next;
//				}
//			}
//		}
//	}
//}
//
//void dezalocare(hastable tabela) {
//	for (int i = 0; i < tabela.dim; i++) {
//		if (tabela.vector[i]) {
//			nod* aux = tabela.vector[i];
//			while (aux) {
//				free(aux->info.nume);
//				nod* temp = aux->next;
//				free(aux);
//				aux = temp;
//			}
//		}
//	}
//	free(tabela.vector);
//}
//
////val totala de la o anumita pozitie specificata
//int numarultotaldeElemente(hastable tabela, unsigned int id) {
//	int suma = 0;
//	int poz = functieHash(tabela, id);//3
//	if (tabela.vector) {
//		//de ce nu merge for 
//		if (tabela.vector[poz]) {
//			nod* aux = tabela.vector[poz];
//			while (aux) {
//				suma += aux->info.nrElemente;
//				aux = aux->next;
//			}
//		}
//
//	}
//
//	return suma;
//}
//
//
//int calculNrElemente(hastable tabela, const char* numeSpecificat) {
//	int suma = 0;
//
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i] != NULL) {
//				nod* aux = tabela.vector[i];
//				while (aux) {
//					if (strcmp(aux->info.nume, numeSpecificat)) {
//						suma += aux->info.nrElemente;
//					}
//					aux = aux->next;
//				}
//			}
//		}
//	}
//
//	return suma;
//}
//
//void main() {
//	BazaDeDate d;
//	hastable tabela;
//	tabela.dim = 10;
//	tabela.vector = (nod**)malloc(sizeof(nod*) * tabela.dim);
//	for (int i = 0; i < tabela.dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//	char buffer[100];
//	char delimitator[] = ",\n";
//	FILE* f = fopen("Baze.txt", "r");
//	while (fgets(buffer, sizeof(buffer), f)) {
//
//		char* token = strtok(buffer, delimitator);//111
//		d.id = atoi(token);
//		token = strtok(NULL, delimitator);//Baza Angajati
//		d.nume = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy(d.nume, token);
//		token = strtok(NULL, delimitator);//987
//		d.nrElemente = atoi(token);
//
//		inserareHash(tabela, d);
//
//		free(d.nume);
//	}
//	fclose(f);
//
//	afisareTabela(tabela);
//	//dezalocare(tabela);
//
//	int suma = numarultotaldeElemente(tabela, 111);
//	printf("%d\n", suma);
//	int suma1 = calculNrElemente(tabela, "HR");
//	printf("%d", suma1);
//}