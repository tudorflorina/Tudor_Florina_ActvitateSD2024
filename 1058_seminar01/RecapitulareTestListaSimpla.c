//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//
////lista simpla
//typedef struct Student Student;
//typedef struct Nod Nod;
//
////structura Student
//struct Student {
//	char* numeStudent;
//	int id;
//	float medie;
//};
//
////crearea unui student
//Student initializareStudent(char* nume, int id, float medie) {
//	Student s;
//	s.numeStudent = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy(s.numeStudent, nume);
//	s.id = id;
//	s.medie = medie;
//	return s;
//}
//
////structura Nod
//struct Nod {
//	Student info;
//	Nod* next;
//};
//
////inserare la inceput
////mai intai se creeaza noul nod apoi se adauga
//Nod* inserareInceput(Nod* cap, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.numeStudent, s.id, s.medie);
//	nou->next = NULL;
//	if (cap != NULL) {
//		nou->next = cap;
//		cap = nou;
//	}
//	else
//	{
//		cap = nou;
//	}
//	return cap;
//}
//
////inserare la final
//Nod* inserareFinal(Nod* cap, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.numeStudent, s.id, s.medie);
//	nou->next = NULL;
//	if (cap != NULL) {
//		Nod* aux = cap;
//		while (aux->next != NULL) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else {
//		cap = nou;
//	}
//
//	return cap;
//}
//
//
//
////afisare lista
//
//void afisareLista(Nod* cap) {
//	Nod* aux = cap;
//	while (aux != NULL) {
//		printf("nume: %s; id = %d; medie: %5.2f \n", aux->info.numeStudent, aux->info.id, aux->info.medie);
//		aux = aux->next;
//	}
//}
//
////dezalocare
//void dezalocare(Nod* cap) {
//	Nod* aux = cap;
//	while (aux != NULL) {
//		Nod* temp = aux->next;
//		free(aux->info.numeStudent);
//		free(aux);
//		aux = temp;
//	}
//}
//
////cautarea unui Student dupa ID
//Student* cautareDupaID(Nod* cap, int id) {
//	Nod* aux = cap;
//	while (aux != NULL) {
//		if (aux->info.id == id) {
//			return &(aux->info);
//		}
//		aux = aux->next;
//	}
//	return NULL; // Studentul nu a fost găsit
//}
//
////sa se stearga un anumit nod dupa id
//Nod* stergereDupaID(Nod* cap, int id) {
//	Nod* aux = cap;
//	Nod* prev = NULL;
//
//	while (aux != NULL) {
//		if (aux->info.id == id) {
//			if (prev == NULL) { // Dacă nodul de șters este primul
//				cap = aux->next;
//			}
//			else {
//				prev->next = aux->next;
//			}
//			free(aux->info.numeStudent);
//			free(aux);
//			return cap; // Returnăm lista actualizată
//		}
//		prev = aux;
//		aux = aux->next;
//	}
//
//	return cap; // Returnăm lista neschimbată, deoarece nu am găsit ID-ul
//}
//
////numar total de studenti
//int numarTotalStudenti(Nod* cap) {
//	int numar = 0;
//	Nod* aux = cap;
//	while (aux != NULL) {
//		numar++;
//		aux = aux->next;
//	}
//	return numar;
//}
//
//
////actualizare medie
//void actualizareMedieDupaID(Nod* cap, int id, float nouaMedie) {
//	Nod* aux = cap;
//	while (aux != NULL) {
//		if (aux->info.id == id) {
//			aux->info.medie = nouaMedie;
//			return; // Am actualizat media și putem ieși din funcție
//		}
//		aux = aux->next;
//	}
//}
//
////sortare dupa medie
//void sortareDupaMedie(Nod* cap) {
//	int schimbat;
//	Nod* aux;
//	Student temp;
//
//	if (cap == NULL) {
//		return; // Nu există nimic de sortat
//	}
//
//	do {
//		schimbat = 0;
//		aux = cap;
//
//		while (aux->next != NULL) {
//			if (aux->info.medie > aux->next->info.medie) {
//				// Schimbăm pozițiile studenților
//				temp = aux->info;
//				aux->info = aux->next->info;
//				aux->next->info = temp;
//				schimbat = 1;
//			}
//			aux = aux->next;
//		}
//	} while (schimbat);
//}
//
////inserare dupa un id
//Nod* inserareDupaID(Nod* cap, int id, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.numeStudent, s.id, s.medie);
//	nou->next = NULL;
//
//	Nod* aux = cap;
//	while (aux != NULL) {
//		if (aux->info.id == id) {
//			nou->next = aux->next;
//			aux->next = nou;
//			return cap;
//		}
//		aux = aux->next;
//	}
//
//	// Dacă nu găsim ID-ul, inserăm la finalul listei
//	if (cap == NULL) {
//		cap = nou;
//	}
//	else {
//		Nod* temp = cap;
//		while (temp->next != NULL) {
//			temp = temp->next;
//		}
//		temp->next = nou;
//	}
//	return cap;
//}
//
////concatenare a doua liste
//Nod* concatenareListe(Nod* lista1, Nod* lista2) {
//	if (lista1 == NULL) {
//		return lista2;
//	}
//	if (lista2 == NULL) {
//		return lista1;
//	}
//
//	Nod* aux = lista1;
//	while (aux->next != NULL) {
//		aux = aux->next;
//	}
//	aux->next = lista2;
//
//	return lista1;
//}
//
//
////copierea unei liste
//Nod* copiereLista(Nod* cap) {
//	Nod* nouaLista = NULL;
//	Nod* aux = cap;
//	while (aux != NULL) {
//		nouaLista = inserareFinal(nouaLista, aux->info);
//		aux = aux->next;
//	}
//	return nouaLista;
//}
//
//
//
//void main() {
//	Student s = initializareStudent("Florina", 2808, 5.75);
//	Student s1 = initializareStudent("Andrei", 3107, 8.345);
//	Student s2 = initializareStudent("Denis", 1505, 9.567);
//	printf("nume: %s; id = %d; medie: %5.2f \n", s.numeStudent, s.id, s.medie);
//
//	Nod* lista = NULL;
//
//	lista = inserareInceput(lista, s);
//	lista = inserareInceput(lista, s1);
//	lista = inserareFinal(lista, s2);
//
//	afisareLista(lista);
//
//	// Testam functia de cautare dupa ID
//	printf("\nCautare dupa ID:\n");
//	Student* studentCautat = cautareDupaID(lista, 3107);
//	if (studentCautat != NULL) {
//		printf("Studentul cu ID-ul 3107 a fost gasit: %s\n", studentCautat->numeStudent);
//	}
//	else {
//		printf("Studentul cu ID-ul 3107 nu a fost gasit.\n");
//	}
//
//	// Testam functia de stergere dupa ID
//	printf("\nStergere dupa ID:\n");
//	lista = stergereDupaID(lista, 2808);
//	afisareLista(lista);
//
//	// Testam functia de numarare a studentilor
//	printf("\nNumarul total de studenti: %d\n", numarTotalStudenti(lista));
//
//	// Testam funcția de actualizare a mediei dupa ID
//	printf("\nActualizare medie:\n");
//	actualizareMedieDupaID(lista, 1505, 9.0);
//	afisareLista(lista);
//
//	// Testam functia de sortare dupa medie
//	printf("\nSortare dupa medie:\n");
//	sortareDupaMedie(lista);
//	afisareLista(lista);
//
//	// Testam functia de inserare dupa un ID dat
//	printf("\nInserare dupa ID:\n");
//	Student s3 = initializareStudent("Maria", 2001, 7.5);
//	lista = inserareDupaID(lista, 3107, s3);
//	afisareLista(lista);
//
//	// Testam functia de concatenare a doua liste
//	printf("\nConcatenare a doua liste:\n");
//	Nod* lista2 = NULL;
//	Student s4 = initializareStudent("Diana", 1010, 6.8);
//	lista2 = inserareInceput(lista2, s4);
//	lista = concatenareListe(lista, lista2);
//	afisareLista(lista);
//
//	// Testam functia de copiere a unei liste
//	printf("\nCopierea unei liste:\n");
//	Nod* listaCopie = copiereLista(lista);
//	afisareLista(listaCopie);
//
//	// Dezalocam memoria pentru lista originala si pentru lista copie
//	dezalocare(lista);
//	dezalocare(listaCopie);
//}
