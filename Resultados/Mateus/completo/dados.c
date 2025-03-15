#include "dados.h"
#include "stdlib.h"

struct Dados {
  void **dado;
  int tam;
};

Dados *criaDados() {
  Dados *v = (Dados *)calloc(1, sizeof(Dados));

  if (v == NULL) {
    exit(1);
  }

  v->dado = NULL;
  v->tam = 0;

  return v;
};

void adicionaDado(Dados *v, void *val) {
  v->dado = (void **)realloc(v->dado, (v->tam + 1) * sizeof(void *));
  v->dado[v->tam] = val;
  v->tam++;
};

void *retornaDado(Dados *v, int i) { return v->dado[i]; };

void *retornaTodosDados(Dados *v) { return v->dado; };

int tamanhoDados(Dados *v) { return v->tam; };

void liberaDados(Dados *v, void (*destroy)(void *)) {
  for (int i = 0; i < v->tam; i++) {
    destroy(v->dado[i]);
  }
  free(v->dado);
  free(v);
};

void printaDados(Dados *v, void (*printa)(void *)) {
  for (int i = 0; i < v->tam; i++) {
    printa(v->dado[i]);
  }
};
