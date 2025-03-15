#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct Data {
  int dia;
  int mes;
  int ano;
};

Data *criaData(int dia, int mes, int ano) {
  Data *d = (Data *)calloc(1, sizeof(Data));

  d->dia = dia;
  d->mes = mes;
  d->ano = ano;

  return d;
};

Data *leData() {
  int dia, mes, ano;

  scanf("%d/%d/%d\n", &dia, &mes, &ano);

  Data *d = criaData(dia, mes, ano);

  return d;
};

void imprimeData(Data *d) { printf("%d/%d/%d\n", d->dia, d->mes, d->ano); };

int calcularDiffAnosData(Data *inicio, Data *fim) {
  int diff = fim->ano - inicio->ano;

  if (fim->mes < inicio->mes ||
      fim->mes == inicio->mes && fim->dia < inicio->dia) {
    diff--;
  }

  return diff;
};

void liberaData(Data *d) { free(d); };