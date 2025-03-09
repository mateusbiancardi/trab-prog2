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

Manutencao *criaManutencao(char *nome, char *estado, char *local) {
  Manutencao *m = (Manutencao *)calloc(1, sizeof(Manutencao));

  strncpy(m->nome, nome, MAX_TAM_NOME_MANUTENCAO);
  strncpy(m->estado, estado, MAX_TAM_ESTADO);
  strncpy(m->local, local, MAX_TAM_LOCAL);

  setTempoEstimadoManutencao(m);

  return m;
};

Manutencao *lerManutencao();

/**
 * @brief Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param s Ticket do tipo Manutencao.
 */
void setTempoEstimadoManutencao(Manutencao *s);

/**
 * @brief Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado Ticket do tipo Manutencao.
 * @return Tempo estimado para resolver um ticket do tipo Manutencao.
 */
int getTempoEstimadoManutencao(void *dado);

/**
 * @brief Retorna o tipo do ticket.
 * @return 'M' para Manutencao.
 */
char getTipoManutencao();

/**
 * @brief Desaloca um ticket do tipo Manutencao da memória.
 * @param s Ticket do tipo Manutencao.
 */
void desalocaManutencao(void *s);

/**
 * @brief Imprime um ticket do tipo Manutencao.
 * @param dado Ticket do tipo Manutencao.
 */
void notificaManutencao(void *dado);