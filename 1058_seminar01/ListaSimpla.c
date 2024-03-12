//#include<stdio.h>
//#include<malloc.h>
//
////lista simpla
//typedef struct Student {
//	char* nume;//%s
//	int id;//%d
//	float medie;//%f
//}Student;
//
////creare Student
//Student creareStudent(char* nume, int id, float medie) {
//	Student s;
//	s.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(s.nume, nume);
//	s.id = id;
//	s.medie = medie;
//
//	return s;
//}
//
////se ia adresa catre urm nod
//typedef struct nod {
//	struct Student info;
//	struct nod* next;
//}nod;
//
////inserare la inceput
////trebuie mai intai creat noul nod si apoi sa il legam
//nod* inserareInceput(nod* cap, Student s) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info = creareStudent(s.nume, s.id, s.medie);
//	nou->next = NULL;
//	if (cap != NULL) {
//		nou->next = cap;
//		cap = nou;
//	}
//	else {
//		cap = nou;
//	}
//
//	return cap;
//}
//
////inserare nod Final
//nod* inserareFinal(nod* cap, Student s) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info = creareStudent(s.nume, s.id, s.medie);
//	nou->next = NULL;
//
//	if (cap != NULL) {
//		nod* aux = cap;
//		while (aux->next != NULL)
//			aux = aux->next;
//
//		aux->next = nou;
//	}
//	else {
//		cap = nou;
//	}
//
//	return cap;
//}
//
////afisarea sau parcurgerea
//void afisare(nod* cap) {
//	nod* aux = cap;
//	while (aux != NULL) {
//		printf("nume: %s; id = %d; medie: %f \n", aux->info.nume, aux->info.id, aux->info.medie);
//		aux = aux->next;
//	}
//}
//
////dezalocare
//void dezalocare(nod* cap) {
//	nod* aux = cap;
//	while (aux != NULL) {
//		nod* temp = aux->next;
//		free(aux->info.nume);
//		free(aux);
//		aux = temp;
//	}
//}
//
//void main() {
//	//main
//}