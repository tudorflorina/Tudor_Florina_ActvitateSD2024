#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Comanda Comanda;
typedef struct Nod Nod;
typedef struct Hashtable Hashtable;

struct Comanda {
	unsigned int idComanda;
	char* dataLansareComanda;
	char* dataLivrareProgramata;
	char* numeClient;
	int nrProduse;
	float* pretProdus;
};

Comanda initializareComanda(unsigned int idComanda, char* dataLansareComanda, char* dataLivrareProgramata, char* numeClient, int nrProduse, float* pretProdus) {
	Comanda c;
	c.idComanda = idComanda;
	c.dataLansareComanda = (char*)malloc(sizeof(char) * strlen(dataLansareComanda) + 1);
	strcpy(c.dataLansareComanda, dataLansareComanda);
	c.dataLivrareProgramata = (char*)malloc(sizeof(char) * strlen(dataLivrareProgramata) + 1);
	strcpy(c.dataLivrareProgramata, dataLivrareProgramata);
	c.numeClient = (char*)malloc(sizeof(char) * strlen(numeClient) + 1);
	strcpy(c.numeClient, numeClient);
	c.nrProduse = nrProduse;
	c.pretProdus = (float*)malloc(sizeof(float) * nrProduse);
	for (int i = 0; i < nrProduse; i++) {
		c.pretProdus[i] = pretProdus[i];
	}
	return c;
}

struct Nod {
	Comanda info;
	Nod* next;
};

struct Hashtable {
	int dim;
	Nod** vector;
};

int functieHashNumeric(Hashtable tabela, unsigned int id) {
	return id % tabela.dim;
}

int functieHashChar(Hashtable tabela, char* numeClient) {
	return strlen(numeClient) % tabela.dim;
}

int inserareTabela(Hashtable tabela, Comanda c) {
	int pozitie = 0;
	if (tabela.vector) {
		pozitie = functieHashChar(tabela, c.numeClient);
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->info = initializareComanda(c.idComanda, c.dataLansareComanda, c.dataLivrareProgramata, c.numeClient, c.nrProduse, c.pretProdus);
		nou->next = NULL;
		if(tabela.vector[pozitie] == NULL) {
			tabela.vector[pozitie] = nou;
		}
		else {
			Nod* aux = tabela.vector[pozitie];
			while (aux->next) {
				aux = aux->next;
			}
			aux->next = nou;
		}
	}
	return pozitie;
}

void afisareTabela(Hashtable tabela) {
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				printf("Pozitia %d\n", i);
				Nod* aux = tabela.vector[i];
				while (aux) {
					printf("Id comanda %u, lansata la data %s, livarata la data %s, pe numele %s, cu nr de produse %d\n", aux->info.idComanda, aux->info.dataLansareComanda, aux->info.dataLivrareProgramata, aux->info.numeClient, aux->info.nrProduse);
					for (int j = 0; j < aux->info.nrProduse; j++) {
						printf("Pretul : %5.2f\n", aux->info.pretProdus[j]);
					}
					aux = aux->next;
				}
			}
		}
	}
}

void dezalocare(Hashtable tabela) {
	for (int i = 0; i < tabela.dim; i++) {
		if (tabela.vector[i]) {
			Nod* aux = tabela.vector[i];
			while (aux) {
				free(aux->info.dataLansareComanda);
				free(aux->info.dataLivrareProgramata);
				free(aux->info.numeClient);
				free(aux->info.pretProdus);
				Nod* temp = aux->next;
				free(aux);
				aux = temp;
			}		}
	}
	free(tabela.vector);
}


int numarDeComenzi(Hashtable tabela, char* dataDeLivrare) {
	int numar = 0;
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				Nod* aux = tabela.vector[i];
				while (aux) {
					if (strcmp(aux->info.dataLivrareProgramata, dataDeLivrare) == 0) {
						numar++;
					}
					aux = aux->next;
				}
			}
		}
	}
	return numar;
}


void main() {
	Comanda c;
	Hashtable tabela;
	int nr = 0;
	tabela.dim = 10;
	tabela.vector = (Nod**)malloc(sizeof(Nod*) * tabela.dim);
	for (int i = 0; i < tabela.dim; i++) {
		tabela.vector[i] = NULL;
	}
	char buffer[101];
	FILE* f = fopen("Comenzi.txt", "r");
	fscanf(f, "%d", &nr);
	for (int i = 0; i < nr; i++) {
		fscanf(f, "%u", &c.idComanda);
		fscanf(f, "%s", buffer);
		c.dataLansareComanda = (char*)malloc(sizeof(char) * strlen(buffer) + 1);
		strcpy(c.dataLansareComanda, buffer);
		fscanf(f, "%s", buffer);
		c.dataLivrareProgramata = (char*)malloc(sizeof(char) * strlen(buffer) + 1);
		strcpy(c.dataLivrareProgramata, buffer);
		fscanf(f, "%s", buffer);
		c.numeClient = (char*)malloc(sizeof(char) * strlen(buffer) + 1);
		strcpy(c.numeClient, buffer);
		fscanf(f, "%d", &c.nrProduse);
		c.pretProdus = (float*)malloc(sizeof(float) * c.nrProduse);
		for (int j = 0; j < c.nrProduse; j++) {
			fscanf(f, "%f", &c.pretProdus[j]);
		}
		inserareTabela(tabela, c);
		free(c.dataLansareComanda);
		free(c.dataLivrareProgramata);
		free(c.numeClient);
		free(c.pretProdus);
	}
	fclose(f);
	
	afisareTabela(tabela);

	int numarDeComenz = numarDeComenzi(tabela, "15/04/2024");
	printf("\n");
	printf("%d", numarDeComenz);

	dezalocare(tabela);
}