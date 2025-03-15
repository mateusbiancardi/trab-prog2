#include "manutencao.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

struct Manutencao {
  char nome[MAX_TAM_NOME_MANUTENCAO];
  char estado[MAX_TAM_ESTADO];
  char local[MAX_TAM_LOCAL];
  int tempoEstimado;
};

Manutencao *criaManutencao(char *nome, char *estado, char *local, char *setor) {
  Manutencao *m = (Manutencao *)calloc(1, sizeof(Manutencao));

  strncpy(m->nome, nome, MAX_TAM_NOME_MANUTENCAO);
  strncpy(m->estado, estado, MAX_TAM_ESTADO);
  strncpy(m->local, local, MAX_TAM_LOCAL);

  setTempoEstimadoManutencao(m, setor);

  return m;
};

Manutencao *lerManutencao(char *setor) {
  char nome[MAX_TAM_NOME_MANUTENCAO];
  char estado[MAX_TAM_ESTADO];
  char local[MAX_TAM_LOCAL];

  scanf("%[^\n]\n", nome);
  scanf("%[^\n]\n", estado);
  scanf("%[^\n]\n", local);

  Manutencao *m = criaManutencao(nome, estado, local, setor);

  return m;
};

void setTempoEstimadoManutencao(Manutencao *s, char *setor) {
  int numSetor, numEstado;

  if (strcmp(s->estado, "RUIM") == 0) {
    numEstado = TEMPO_ESTIMADO_RUIM;
  } else if (strcmp(s->estado, "REGULAR") == 0) {
    numEstado = TEMPO_ESTIMADO_REGULAR;
  } else if (strcmp(s->estado, "BOM") == 0) {
    numEstado = TEMPO_ESTIMADO_BOM;
  }

  if (strcmp(setor, "RH") == 0) {
    numSetor = TEMPO_ESTIMADO_RH;
  } else if (strcmp(setor, "FINANCEIRO") == 0) {
    numSetor = TEMPO_ESTIMADO_FINANCEIRO;
  } else if (strcmp(setor, "P&D") == 0) {
    numSetor = TEMPO_ESTIMADO_PD;
  } else if (strcmp(setor, "VENDAS") == 0) {
    numSetor = TEMPO_ESTIMADO_VENDAS;
  } else if (strcmp(setor, "MARKETING") == 0) {
    numSetor = TEMPO_ESTIMADO_MARKETING;
  }
};

int getTempoEstimadoManutencao(void *dado) {
  Manutencao *m = (Manutencao *)dado;

  return m->tempoEstimado;
};

char getTipoManutencao() { return 'M'; };

void desalocaManutencao(void *m) {
  Manutencao *manu = (Manutencao *)m;

  free(manu);
};

void notificaManutencao(void *dado) {
  Manutencao *m = (Manutencao *)dado;

  printf("- Tipo: Manutencao\n");
  printf("- Nome do item: %s\n", m->nome);
  printf("- Estado de conservacao: %s\n", m->estado);
  printf("- Local: %s\n", m->local);
  printf("- Tempo estimado: %dh\n", getTempoEstimadoManutencao(m));
};
