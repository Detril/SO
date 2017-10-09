/* //////////////////////////////////////////////////////////////////
// Nome: André Ferrari Moukarzel						NUSP: 9298166
// Nome: Henrique Cerquinho								NUSP: 9793700
///////////////////////////////////////////////////////////////////*/

#include "defineClas.h"


void *defineClas(ciclista *clas, int n, int num_voltas) {
    int i, j, ini, fim, v, k;
    ciclista atual;

    /* Ordena por volta */
	for (i = 1; i < n; i++){
		atual = clas[i];

        j = i - 1;
		while (j >= 0 && clas[j].volta < atual.volta) {
			clas[j + 1] = clas[j];
            j--;
        }
		clas[j+1] = atual;
	}

    /* Ordena por posição
    // Aqui ordenaremos o vetor por "blocos" de numero de voltas iguais, pois
    // se apenas ordenassemos novamente por posição, desordenariamos
    // por volta */
    for (v = num_voltas, k = 0; v >= 0; v = clas[k].volta) {
        /* k será a primeira posiçao do vetor que o v é diferente.
        // Assim, usaremos ele para determinar os intervalos de ordenação */
        ini = k;
        while (v == clas[k].volta)
            k++;
        fim = k - 1;

        for (i = ini + 1; i <= fim && i < n; i++) {
            atual = clas[i];

            j = i - 1;
            while (j >= ini && clas[j].pos < atual.pos) {
                clas[j + 1] = clas[j];
                j--;
            }
            clas[j+1] = atual;
        }
    }
    return NULL;
}