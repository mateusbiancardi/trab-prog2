#include "fila.h"
#include "ticket.h"
#include <stdlib.h>

struct Fila {
  void **tickets;
  int qtd;
};

Fila *criaFila() {
  Fila *f = (Fila *)calloc(1, sizeof(Fila));

  f->tickets = (void **)calloc(1, sizeof(void *));
  f->qtd = 0;

  return f;
};

void desalocaFila(Fila *f) {

  Ticket *t;
  for (int i = 0; i < f->qtd; i++) {
    t = (Ticket *)f->tickets[i];
    desalocaTicket(t);
  }

  free(f->tickets);
  free(f);
};

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser
 * inserido sempre na última posição. Obviamente, essa função também faz a
 * manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de
 * ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket
 * ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser
 * resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver
 * ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver
 * ticket.h)
 */
void insereTicketFila(Fila *f, char *cpfSol, void *dado,
                      func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo,
                      func_ptr_notifica notifica, func_ptr_desaloca desaloca) {
  Ticket *t;
  t = (Ticket *)dado;
  f->tickets = (void **)realloc(f->tickets, sizeof(void *) * (f->qtd++));

  f->tickets[f->qtd] = t;
  f->qtd++;
};

/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f) { return f->qtd; };

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
int getQtdTicketsPorStatusNaFila(Fila *f, char status);

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser
 * recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i);

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f);