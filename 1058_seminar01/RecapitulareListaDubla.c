//#define _CRT_SECURE_NO_WARNINGS
//#include<malloc.h>
//#include<string.h>
//#include<stdio.h>
//
//typedef struct Student Student;
//typedef struct Nod Nod;
//typedef struct LD LD;
//
//struct Student {
//	char* numeStudent;
//	int idStudent;
//	float medieStudent;
//};
//
//Student creareStudent(char* numeStudent, int idStudent, float medieStudent) {
//	Student s;
//	s.numeStudent = (char*)malloc(sizeof(char) * strlen(numeStudent) + 1);
//	strcpy(s.numeStudent, numeStudent);
//	s.idStudent = idStudent;
//	s.medieStudent = medieStudent;
//	return s;
//}
//
//struct Nod {
//	Nod* prev;
//	Nod* next;
//	Student info;
//};
//
//struct LD {
//	Nod* prim;
//	Nod* ultim;
//};
//
//LD inserareFinal(LD lista, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->prev = lista.ultim;
//	nou->next = NULL;
//	nou->info = creareStudent(s.numeStudent, s.idStudent, s.medieStudent);
//
//	if (lista.ultim) {
//		lista.ultim->next = nou;
//		lista.ultim = nou;
//	}
//	else
//	{
//		lista.ultim = lista.prim = nou;
//	}
//	return lista;
//}
//
//LD inserareInceput(LD lista, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->prev = NULL;
//	nou->next = lista.prim;;
//	nou->info = creareStudent(s.numeStudent, s.idStudent, s.medieStudent);
//
//	if (lista.prim) {
//		lista.prim->prev = nou;
//		lista.prim = nou;
//	}
//	else
//	{
//		lista.ultim = lista.prim = nou;
//	}
//	return lista;
//}
//
//void afisareInceput(LD lista) {
//	if (lista.prim) {
//		Nod* aux = lista.prim;
//		while (aux) {
//			printf("Studentul %s are id-ul %d si media %5.2f\n", aux->info.numeStudent, aux->info.idStudent, aux->info.medieStudent);
//			aux = aux->next;
//		}
//	}
//	else {
//		printf("Lista este goala.\n");
//	}
//}
//
//void afisareFinal(LD lista) {
//	if (lista.ultim) {
//		Nod* aux = lista.ultim;
//		while (aux) {
//			printf("Studentul %s are id-ul %d si media %5.2f\n", aux->info.numeStudent, aux->info.idStudent, aux->info.medieStudent);
//			aux = aux->prev;
//		}
//	}
//	else {
//		printf("Lista este goala.\n");
//	}
//}
//
//
//void dezalocare(LD lista) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		Nod* temp = aux->next;
//		free(aux->info.numeStudent);
//		free(aux);
//		aux = temp;
//	}
//}
//
////numaram elmentele din lista
//int numarareelemente(LD lista) {
//	int contor = 0;
//	if (lista.prim) {
//		Nod* aux = lista.prim;
//		while (aux) {
//			contor++;
//			aux = aux->next;
//
//		}
//	}
//	return contor;
//}
//
////numarare elem cu anumit criteriu
//int numarareelementeDupaCriteriu(LD lista, const char* criteriu) {
//	int contor = 0;
//	if (lista.prim) {
//		Nod* aux = lista.prim;
//		while (aux) {
//			if (strcmp(aux->info.numeStudent, criteriu) == 0) {
//				contor++;
//			}
//			aux = aux->next;
//		}
//	}
//	return contor;
//}
//
//
//int numarareElementeDupaPrag(LD lista, float prag) {
//	int contor = 0;
//	if (lista.prim) {
//		Nod* aux = lista.prim;
//		while (aux) {
//			if (aux->info.medieStudent >= prag) {
//
//
//				contor++;
//			}
//			aux = aux->next;
//		}
//	}
//	return contor;
//}
//
////coversie la vector-lista intreaga
//Student* conversieLaVector(LD lista) {
//	int dim = numarareelemente(lista);
//	Student* vector = (Student*)malloc(sizeof(Student) * dim);
//	int contor = 0;
//	Nod* aux = lista.prim;
//	while (aux) {
//
//		vector[contor] = creareStudent(aux->info.numeStudent, aux->info.idStudent, aux->info.medieStudent);
//		aux = aux->next;
//		contor++;
//	}
//	return vector;
//}
//
////punem in vector anumite elemente
//Student* saveazaInVector(LD lista, const char* numeCautat) {
//	int dim = numarareelementeDupaCriteriu(lista, numeCautat);
//	Student* vector = (Student*)malloc(sizeof(Student) * dim);
//	int contor = 0;
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.numeStudent, numeCautat) == 0) {
//			vector[contor] = creareStudent(aux->info.numeStudent, aux->info.idStudent, aux->info.medieStudent);
//			contor++;
//		}
//		aux = aux->next;
//	}
//
//	return vector;
//}
//
//void afisareAnimal(Student s) {
//
//	printf("%d, %lf, %s\n", s.idStudent, s.medieStudent, s.numeStudent);
//}
//
////cautare in lista 
//void cautare(LD lista, const char* numeCautat) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.numeStudent, numeCautat) == 0) {
//			afisareAnimal(aux->info);
//		}
//		aux = aux->next;
//	}
//}
//
////modificare
//void modificare(LD lista, const char* numeDeModificat, const char* numeNou) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.numeStudent, numeDeModificat) == 0) {
//			//dezaloc pt ca este char*
//			free(aux->info.numeStudent);
//			//aloc din nou memorie dupa noul nume
//			aux->info.numeStudent = (char*)malloc(sizeof(char) * strlen(numeNou) + 1);
//			strcpy(aux->info.numeStudent, numeNou);
//		}
//		aux = aux->next;
//	}
//}
//
//void main() {
//	int nr;
//	Student s;
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
//		fscanf(f, "%s", buffer);
//		s.numeStudent = (char*)malloc(sizeof(char) * strlen(buffer) + 1);
//		strcpy(s.numeStudent, buffer);
//		fscanf(f, "%d", &s.idStudent);
//		fscanf(f, "%f", &s.medieStudent);
//
//		lista = inserareFinal(lista, s);
//		free(s.numeStudent);
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
//	int numarelem = numarareelementeDupaCriteriu(lista, "Denis");
//	printf("%d\n ", numarelem);
//
//	int numarelem1 = numarareElementeDupaPrag(lista, 5.00);
//	printf("%d\n ", numarelem1);
//
//
//	Student * vector = conversieLaVector(lista);
//
//	for (int i = 0; i < numar; i++) {
//		afisareAnimal(vector[i]);
//	}
//
//	Student * vector1 = saveazaInVector(lista, "Andrei");
//
//	for (int i = 0; i < numarelem; i++) {
//		afisareAnimal(vector1[i]);
//	}
//	cautare(lista, "Florina");
//
//	modificare(lista, "Florina", "Florian");
//	afisareFinal(lista);
//}
