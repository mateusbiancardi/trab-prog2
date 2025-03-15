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

void notificaFila(Fila *f) {
  // printf("----- FILA DE TICKETS -----\n");
  for (int i = 0; i < f->qtd; i++) {
    notificaTicket(f->tickets[i]);
  }
};
