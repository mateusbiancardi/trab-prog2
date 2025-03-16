#include "software.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Software {
  char nome[MAX_TAM_NOME_SOFTWARE];
  char categoria[MAX_TAM_CAT];
  int impacto;
  char motivo[MAX_TAM_MOTIVO];
  int tempoEstimado;
};

Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo) {
  Software *s = (Software *)calloc(1, sizeof(Software));

  strncpy(s->nome, nome, MAX_TAM_NOME_SOFTWARE);
  strncpy(s->categoria, categoria, MAX_TAM_CAT);
  s->impacto = impacto;
  strncpy(s->motivo, motivo, MAX_TAM_MOTIVO);

  setTempoEstimadoSoftware(s);

  return s;
};

Software *lerSoftware() {
  char nome[MAX_TAM_NOME_SOFTWARE];
  char categoria[MAX_TAM_CAT];
  int impacto;
  char motivo[MAX_TAM_MOTIVO];

  scanf("%[^\n]\n", nome);
  scanf("%[^\n]\n", categoria);
  scanf("%d\n", &impacto);
  scanf("%[^\n]\n", motivo);

  Software *s = criaSoftware(nome, categoria, impacto, motivo);

  return s;
}

void setTempoEstimadoSoftware(Software *s) {
  int horasCat = TEMPO_ESTIMADO_DUVIDA;
  if (strcmp(s->categoria, "BUG") == 0) {
    horasCat = TEMPO_ESTIMADO_BUG;
  } else if (strcmp(s->categoria, "OUTROS") == 0) {
    horasCat = TEMPO_ESTIMADO_OUTROS;
  }

  s->tempoEstimado = horasCat + s->impacto;
};

int getTempoEstimadoSoftware(void *dado) {
  Software *s = (Software *)dado;

  return s->tempoEstimado;
};

char getTipoSoftware() { return 'S'; };

void desalocaSoftware(void *s) {
  Software *sw = (Software *)s;

  free(sw);
};

void notificaSoftware(void *dado) {
  Software *s = (Software *)dado;

  printf("- Tipo: Software\n");
  printf("- Nome do software: %s\n", s->nome);
  printf("- Categoria: %s\n", s->categoria);
  printf("- Nível do impacto: %d\n", s->impacto);
  printf("- Motivo: %s\n", s->motivo);
  printf("- Tempo estimado: %dh\n", getTempoEstimadoSoftware(s));
};
