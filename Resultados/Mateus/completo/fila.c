#include "fila.h"
#include "ticket.h"
#include <stdio.h>
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

void insereTicketFila(Fila *f, char *cpfSol, void *dado,
                      func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo,
                      func_ptr_notifica notifica, func_ptr_desaloca desaloca) {

  f->tickets = (void **)realloc(f->tickets, sizeof(void *) * (f->qtd + 1));
  f->tickets[f->qtd] =
      criaTicket(cpfSol, dado, getTempo, getTipo, notifica, desaloca);

  f->qtd++;
  char id[20];
  snprintf(id, sizeof(id), "Tick-%d", f->qtd);
  setIDTicket(f->tickets[f->qtd - 1], id);
};

int getQtdTicketsNaFila(Fila *f) { return f->qtd; };

int getQtdTicketsPorStatusNaFila(Fila *f, char status) {
  int qntd = 0;

  for (int i = 0; i < f->qtd; i++) {
    if (getStatusTicket(f->tickets[i]) == status) {
      qntd++;
    }
  }

  return qntd;
};

Ticket *getTicketNaFila(Fila *f, int i) { return f->tickets[i]; };

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f) {
  // printf("----- FILA DE TICKETS -----\n");
  for (int i = 0; i < f->qtd; i++) {
    notificaTicket(f->tickets[i]);
  }
};

// ----- FILA DE TICKETS -----
// ---------TICKET-----------
// - ID: Tick-1
// - Usuario solicitante: 255.942.213-22
// - Tipo: Outros
// - Descricao: RECOLHER COBRA QUE APARECEU NA ENTRADA DO PREDIO
// - Local: PASSARELA DA INFORMATICA
// - Nivel de Dificuldade: 5
// - Tempo Estimado: 5h
// - Status: Finalizado
// -------------------------