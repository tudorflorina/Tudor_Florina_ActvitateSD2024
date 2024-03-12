//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//
//
//typedef struct Animal {
//	int varsta;
//	double greutate;
//	char* nume;
//
//}Animal;
//
//Animal creareAnimal(int varsta, double greutate, char* nume) {
//	Animal a;
//	a.varsta = varsta;
//	a.greutate = greutate;
//	a.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy(a.nume, nume);
//
//	return a;
//
//}
//
//typedef struct nod {
//	struct nod* prev;
//	struct Animal info;
//	struct nod* next;
//}nod;
//
//typedef struct LD {
//	nod* prim;
//	nod* ultim;
//}LD;
//
//LD inserareFinal(LD lista, Animal a) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->prev = lista.ultim;
//
//	nou->info = creareAnimal(a.varsta, a.greutate, a.nume);
//	nou->next = NULL;
//
//	if (lista.ultim) {
//		lista.ultim->next = nou;
//		//nou->prev = ultim;
//		lista.ultim = nou;
//	}
//	else {
//
//		lista.prim = lista.ultim = nou;
//	}
//
//	return lista;
//
//}
//
//
//
//
//LD inserareImceput(LD lista, Animal a) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->prev = NULL;
//	nou->info = creareAnimal(a.varsta, a.greutate, a.nume);
//	nou->next = NULL;
//
//	if (lista.prim) {
//		nou->next = lista.prim;
//		lista.prim->prev = nou;
//		lista.prim = nou;
//
//	}
//	else {
//		lista.prim = nou;
//		lista.ultim = nou;
//	}
//
//	return lista;
//}
//
//
////afisare sau traversare
//void afisareInceput(LD lista) {
//	if (lista.prim) {
//		nod* aux = lista.prim;
//		while (aux) {
//			printf("%d, %lf, %s \n", aux->info.varsta, aux->info.greutate, aux->info.nume);
//			aux = aux->next;
//
//		}
//	}
//	else {
//		printf(" %s \n", "NULL");
//
//	}
//}
//
//
//void afisareFinal(LD lista) {
//	if (lista.ultim) {
//		nod* aux = lista.ultim;
//		while (aux) {
//			printf("%d, %lf, %s\n", aux->info.varsta, aux->info.greutate, aux->info.nume);
//			aux = aux->prev;
//
//		}
//	}
//}
//
//void dezalocare(LD lista) {
//	if (lista.prim) {
//		nod* aux = lista.prim;
//		while (aux) {
//			nod* temp = aux->next;
//			free(aux->info.nume);
//			free(aux);
//			aux = temp;
//		}
//	}
//}
//
////numaram elmentele din lista
//int numarareelemente(LD lista) {
//	int contor = 0;
//	if (lista.prim) {
//		nod* aux = lista.prim;
//		while (aux) {
//			contor++;
//			aux = aux->next;
//
//		}
//	}
//
//	return contor;
//}
//
////numram elem cu anumit criteriu
//int numarareelementeDupaCriteriu(LD lista, const char* criteriu) {
//	int contor = 0;
//	if (lista.prim) {
//		nod* aux = lista.prim;
//		while (aux) {
//			if (strcmp(aux->info.nume, criteriu) == 0) {
//
//
//				contor++;
//			}
//
//			aux = aux->next;
//
//		}
//	}
//
//	return contor;
//}
//
//
//int numarareelementeDupaPrag(LD lista, double prag) {
//	int contor = 0;
//	if (lista.prim) {
//		nod* aux = lista.prim;
//		while (aux) {
//			if (aux->info.greutate >= prag) {
//
//
//				contor++;
//			}
//
//			aux = aux->next;
//
//		}
//	}
//
//	return contor;
//}
//
////coversie la vector-lista intreaga
//Animal* conversieLaVector(LD lista) {
//	int dim = numarareelemente(lista);
//	Animal* vector = (Animal*)malloc(sizeof(Animal) * dim);
//	int contor = 0;
//	nod* aux = lista.prim;
//	while (aux) {
//
//		vector[contor] = creareAnimal(aux->info.varsta, aux->info.greutate, aux->info.nume);
//		aux = aux->next;
//		contor++;
//	}
//
//	return vector;
//}
//
////punem in vector anumite elemente
//Animal* saveazaInVector(LD lista, const char* numeCautat) {
//	int dim = numarareelementeDupaCriteriu(lista, numeCautat);
//	Animal* vector = (Animal*)malloc(sizeof(Animal) * dim);
//	int contor = 0;
//	nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.nume, numeCautat) == 0) {
//			vector[contor] = creareAnimal(aux->info.varsta, aux->info.greutate, aux->info.nume);
//			contor++;
//		}
//		aux = aux->next;
//	}
//
//	return vector;
//}
//
//void afisareAnimal(Animal a) {
//
//	printf("%d, %lf, %s\n", a.varsta, a.greutate, a.nume);
//}
//
////cautare in lista 
//void cautare(LD lista, const char* numeCautat) {
//	nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.nume, numeCautat) == 0) {
//			afisareAnimal(aux->info);
//		}
//		aux = aux->next;
//	}
//}
//
////modificare
//void modificare(LD lista, const char* numeDeModificat, const char* numeNou) {
//	nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.nume, numeDeModificat) == 0) {
//			//dezaloc pt ca este char*
//			free(aux->info.nume);
//			//aloc din nou memorie dupa noul nume
//			aux->info.nume = (char*)malloc(sizeof(char) * strlen(numeNou) + 1);
//			strcpy(aux->info.nume, numeNou);
//		}
//		aux = aux->next;
//	}
//}
//
//
//void main() {
//	int nr;
//	Animal a;
//	LD lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//
//	char buffer[30];
//
//	FILE* f = fopen("Date.txt", "rt");
//	fscanf(f, "%d", &nr);
//
//
//	for (int i = 0; i < nr; i++) {
//		fscanf(f, "%d", &a.varsta);
//		fscanf(f, "%lf", &a.greutate);
//
//		fscanf(f, "%s", buffer);
//		a.nume = (char*)malloc(sizeof(char) * strlen(buffer) + 1);
//		strcpy(a.nume, buffer);
//
//		lista = inserareFinal(lista, a);
//
//		free(a.nume);
//
//	}
//
//	fclose(f);
//	afisareFinal(lista);
//
//	//afisareInceput(lista);
//	//dezalocare(lista);
//	//lista.prim = NULL;
//	//lista.ultim = NULL;
//	//afisareInceput(lista);
//
//	int numar = numarareelemente(lista);
//	printf("%d\n ", numar);
//
//	int numarelem = numarareelementeDupaCriteriu(lista, "Pisica");
//	printf("%d\n ", numarelem);
//
//	int numarelem1 = numarareelementeDupaPrag(lista, 5);
//	printf("%d\n ", numarelem1);
//
//	//Animal* vector = (Animal*)malloc(sizeof(Animal) * numar);
//
//	Animal* vector = conversieLaVector(lista);
//
//	for (int i = 0; i < numar; i++) {
//		afisareAnimal(vector[i]);
//	}
//
//	Animal* vector1 = saveazaInVector(lista, "Pisica");
//
//	for (int i = 0; i < numarelem; i++) {
//		afisareAnimal(vector1[i]);
//	}
//	cautare(lista, "Caine");
//
//	modificare(lista, "Pisica", "Sarpeeee");
//	afisareFinal(lista);
//}