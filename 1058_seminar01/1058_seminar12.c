#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Metrou Metrou;
typedef struct NodPrincipal NodPrincipal;
typedef struct NodSecundar NodSecundar;

struct Metrou {
	int serie;
	int nrStatie;
	char* magistrala;
};

struct NodSecundar {
	NodPrincipal* nod;
	NodSecundar* next;
};

struct NodPrincipal {
	Metrou info;
	NodPrincipal* next;
	NodSecundar* vecini;
};

//functie initializare Metrou
Metrou creareMetrou(int serie, int nrStatii, const char* magistrala) {
	Metrou m;
	m.serie = serie;
	m.nrStatie = nrStatii;
	m.magistrala = (char*)malloc(sizeof(char) * strlen(magistrala) + 1);
	strcpy_s(m.magistrala, strlen(magistrala) + 1, magistrala);
	return m;
}

//inserare la inceput in lista principala
void inserarePrincipala(NodPrincipal** cap, Metrou m) {
	NodPrincipal* nou = (NodPrincipal*)malloc(sizeof(NodPrincipal));
	nou->info = m;
	nou->next = *cap;
	nou->vecini = NULL;
	*cap = nou;
}

//functie de cautare Nod dupa serie
NodPrincipal* cautaNodDupaSerie(NodPrincipal* graf, int serie) {
	while (graf && graf->info.serie != serie) {
		graf = graf->next;
	}
	return graf;
}

//inserare la final in lista secundara
NodSecundar* inserareSecundar(NodSecundar* cap, NodPrincipal* nod) {
	NodSecundar* nou = (NodSecundar*)malloc(sizeof(NodSecundar));
	nou->next = NULL;
	nou->nod = nod;
	if (cap) {
		NodSecundar* p = cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
		return cap;
	}
	else {
		return nou;
	}
}

//functie de inserare muchie
void inserareMuchie(NodPrincipal* graf, int serieStart, int serieStop) {
	NodPrincipal* nodStart = cautaNodDupaSerie(graf, serieStart);
	NodPrincipal* nodStop = cautaNodDupaSerie(graf, serieStop);
	if (nodStart && nodStop) {
		nodStart->vecini = inserareSecundar(nodStart->vecini, nodStop);
		nodStop->vecini = inserareSecundar(nodStop->vecini, nodStart);
	}
}



void main() {
	NodPrincipal* graf = NULL;
	inserarePrincipala(&graf, creareMetrou(4, 4, "M2"));
	inserarePrincipala(&graf, creareMetrou(3, 7, "M1"));
	inserarePrincipala(&graf, creareMetrou(2, 2, "M4"));
	inserarePrincipala(&graf, creareMetrou(1, 5, "M5"));
	inserarePrincipala(&graf, creareMetrou(0, 9, "M6"));

	inserareMuchie(graf, 0, 1);
	inserareMuchie(graf, 1, 2);
	inserareMuchie(graf, 1, 3);
	inserareMuchie(graf, 1, 4);
	inserareMuchie(graf, 2, 3);


}