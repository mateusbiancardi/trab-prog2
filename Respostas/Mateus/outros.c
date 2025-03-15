#include "outros.h"
#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Outros {
  char descricao[MAX_TAM_DESCRICAO_OUTROS];
  char local[MAX_TAM_LOCAL];
  int dificuldade;
  int tempoEstimado;
};

Outros *criaOutros(char *descricao, char *local, int dificuldade) {
  Outros *o = (Outros *)calloc(1, sizeof(Outros));

  strcpy(o->descricao, descricao);
  strcpy(o->local, local);
  o->dificuldade = dificuldade;
  setTempoEstimadoOutros(o);

  return o;
};

Outros *lerOutros() {
  char descricao[MAX_TAM_DESCRICAO_OUTROS];
  char local[MAX_TAM_LOCAL];
  int dificuldade;
  int tempoEstimado;

  scanf("%[^\n]\n", descricao);
  scanf("%[^\n]\n", local);
  scanf("%d\n", &dificuldade);

  Outros *o = criaOutros(descricao, local, dificuldade);

  return o;
};

void setTempoEstimadoOutros(Outros *o) { o->tempoEstimado = o->dificuldade; };

int getTempoEstimadoOutros(void *dado) {
  Outros *o = (Outros *)dado;

  return o->tempoEstimado;
};

char getTipoOutros() { return 'O'; };

void desalocaOutros(void *o) {
  Outros *outros = (Outros *)o;

  free(outros);
};

void notificaOutros(void *dado) {
  Outros *o = (Outros *)dado;

  printf("- Tipo: Outros\n");
  printf("- Descricao: %s\n", o->descricao);
  printf("- Local: %s\n", o->local);
  printf("- Nivel de Dificuldade: %d\n", o->dificuldade);
  printf("- Tempo Estimado: %dh\n", o->tempoEstimado);
};
