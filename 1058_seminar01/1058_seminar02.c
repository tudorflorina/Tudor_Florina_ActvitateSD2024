//#include<stdio.h>
//#include<malloc.h>
//
//struct Calculator
//{
//	char* serie; 
//	float pret;
//	int numarPorturi;
//}Calculator;
//
//struct Calculator initializare(const char* serie, float pret, int nrPorturi) {
//	struct Calculator c;
//	c.serie = (char*)malloc(sizeof(char) * strlen(serie) + 1);
//	strcpy(c.serie, serie);
//	c.numarPorturi = nrPorturi;
//	c.pret = pret;
//	return c;
//}
//
//void afisareCalculator(struct Calculator calculator) {
//	printf("Calculatorul cu seria %s, costa %5.2f si are %d porturi\n", calculator.serie, calculator.pret, calculator.numarPorturi);
//}
//
//
//void afisareVectorCalculatoare(struct Calculator* vector, int nrCalculatoare) {
//	if (nrCalculatoare > 0 && vector != NULL) {
//		for (int i = 0; i < nrCalculatoare; i++) {
//			afisareCalculator(vector[i]);
//		}
//	}
//}
//
//struct Calculator* copiazaNCalculatoare(struct Calculator* calculatoare, int nrCalculatoare, int nrCalculatoareCopaiate) {
//	struct Calculator* copiate = (struct Calculator*)malloc(sizeof(struct Calculator) * nrCalculatoareCopaiate);
//	for (int i = 0; i < nrCalculatoareCopaiate; i++) {
//		copiate[i] = calculatoare[i];
//		copiate[i].serie = (char*)malloc(sizeof(char) * (1 + strlen(calculatoare[i].serie)));
//		strcpy(copiate[i].serie, calculatoare[i].serie);
//	}
//
//	return copiate;
//}
//
//struct Calculator* copiazaCalculatoareCuMultePorturi(struct Calculator* calculatoare, int nrCalculatoare,
//	int pragNrPorturi, int* nrCalculatoarePorturi) {
//	*nrCalculatoarePorturi = 0;
//	for (int i = 0; i < nrCalculatoare; i++) {
//		if (calculatoare[i].numarPorturi > pragNrPorturi) {
//			(*nrCalculatoarePorturi)++;
//		}
//	}
//	struct Calculator* v = (struct Calculator*)malloc(sizeof(struct Calculator) * (*nrCalculatoarePorturi));
//
//	int k = 0;
//	for (int i = 0; i < nrCalculatoare; i++) {
//		if (calculatoare[i].numarPorturi > pragNrPorturi) {
//			v[k++] = initializare(calculatoare[i].serie, calculatoare[i].pret, calculatoare[i].numarPorturi);
//		}
//	}
//	return v;
//
//}
//
////de cautat pretul unui vector in vector
//
//void dezalocare(struct Calculator** vector, int* dim) {
//	for (int i = 0; i < (*dim); i++) {
//		free((*vector)[i].serie);
//	}
//	free(*vector);
//	*vector = NULL;
//	*dim = 0;
//}
//
//void main() {
//	//int v[10];  declarare vector
//	//int* v1;
//	int nrCalculatoare = 5;
//	struct Calculator* calculatoare = (struct Calculator*)malloc(sizeof(struct Calculator) * nrCalculatoare);
//	for (int i = 0; i < nrCalculatoare; i++) {
//		calculatoare[i] = initializare("123456789", i * 20 + 10, i + 1);
//	}
//
//	afisareVectorCalculatoare(calculatoare, nrCalculatoare);
//
//	int nrCalculatoareCopiate = 3;
//
//	struct Calculator* calculatoareCopiate = copiazaNCalculatoare(calculatoare, nrCalculatoare, nrCalculatoareCopiate);
//
//	printf("\n\n");
//
//	struct Calculator* calculatoareCopiatee = copiazaNCalculatoare(calculatoareCopiate,nrCalculatoare, nrCalculatoareCopiate);
//
//	afisareVectorCalculatoare(calculatoareCopiatee, nrCalculatoareCopiate);
//
//	int nrCalculatoarePorturi = 0;
//	struct Calculator* calculatoarePorturi = copiazaCalculatoareCuMultePorturi(calculatoare, nrCalculatoare,
//		4, &nrCalculatoarePorturi);
//
//	printf("\n\n");
//
//	afisareVectorCalculatoare(calculatoarePorturi, nrCalculatoarePorturi);
//
//	dezalocare(calculatoare, nrCalculatoare);
//}