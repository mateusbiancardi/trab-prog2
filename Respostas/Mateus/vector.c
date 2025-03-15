#include "vector.h"
#include "stdlib.h"

struct Vector {
  data_type *vetor;
  int tam;
};

Vector *VectorConstruct() {
  Vector *v = (Vector *)calloc(1, sizeof(Vector));

  if (v == NULL) {
    exit(1);
  }

  v->vetor = NULL;
  v->tam = 0;

  return v;
};

void VectorPushBack(Vector *v, data_type val) {
  v->vetor = (data_type *)realloc(v->vetor, (v->tam + 1) * sizeof(data_type));
  v->vetor[v->tam] = val;
  v->tam++;
};

data_type VectorGet(Vector *v, int i) { return v->vetor[i]; };

int VectorSize(Vector *v) { return v->tam; };

void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
  for (int i = 0; i < v->tam; i++) {
    destroy(v->vetor[i]);
  }
  free(v->vetor);
  free(v);
};
