//#include<iostream>
//#include<string.h>
//
//using namespace std;
//
//void main() {
//	int x = 10;
//	int* p = &x; //p este o adresa
//	cout << x << endl;
//	cout << &x << endl;
//
//	cout << *p << endl;//valoarea de la adresa p
//	cout << p << endl;//adresa lui x 
//	cout << &p << endl;
//
//	x = 40;
//	*p = 50;
//	cout << x << endl;
//
//	int y = 100;
//	p = &y;
//	cout << y << endl;
//	cout << &y << endl;
//
//	int* q = &x;
//	int** pointer = &q;
//	cout << &q << endl;
//	cout << **pointer << endl;
//
//	//vector dinamic - o sa ai o dim - nr de elemente din vector; si o sa mai am vectorul in sine - adresa primului element
//	//orice tip de data se masoara cu sizeof
//	int dim = 5;
//	float* vect = (float*)malloc(sizeof(float) * dim);  //malloc returneaza void si are nevoie de cast
//	char* cuvant = (char*)malloc(sizeof(char) * strlen("cuvant") + 1); //se pune +1 pentru ca la final avem /0 sa arate ca s-a terminat sirul
//
//	//in loc de for avem o functie care face acelasi lucru dar muta litere dintr-o parte in alta
//	strcpy(cuvant, "cuvant");
//
//	for (int i = 0; i < dim; i++) {
//		vect[i] = 7;
//	}
//
//	//free(vect);
//	//dim = 10;
//	//float* vect = (float*)malloc(sizeof(float) * dim);
//	//for (int i = 0; i < dim; i++) {
//	//	vect[i] = 7;
//	//}
//
//	//vector static - vectorul static se aloca singur
//	float vector[5];//nu schimbam dimensiunea va ramane 5 pana la sfarsit
//	//nu trebuie sa alocam memorie, isi aloca singur
//	vector[0] = 11;
//	vector[1] = 12;
//	vector[2] = 13;
//	vector[3] = 14;
//	vector[4] = 15;
//
//	//copierea dintr-un vector in altul
//	for (int i = 0; i < dim; i++) {
//		cout << vect[i] << " ";
//	}
//
//	for (int i = 0; i < dim; i++) {
//		vect[i] = vector[i];
//	}
//
//	for (int i = 0; i < dim; i++) {
//		cout << vect[i] << " ";
//	}
//
//	float* aux = vector;
//	cout << *vector << endl;
//	cout << *aux << endl;
//
//	cout << vector[0] << endl;
//	cout << vector[3] << endl;
//	cout << *(vector + 3) << endl;
//	//operatiuni cu pointeri
//	aux++;
//	aux--;
//
//
//
//	//ce nu ai voie sa faci
//	aux + 5; //se iese dn zona de memorie
//	//&(vector+3)
//}