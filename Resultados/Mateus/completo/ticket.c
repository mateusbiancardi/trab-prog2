#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket {
  char id[MAX_TAM_ID];
  char cpfSol[MAX_TAM_CPF];
  void *dado;
  char status;
  func_ptr_tempoEstimado getTempo;
  func_ptr_tipo getTipo;
  func_ptr_notifica notifica;
  func_ptr_desaloca desaloca;
};

Ticket *criaTicket(char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                   func_ptr_tipo getTipo, func_ptr_notifica notifica,
                   func_ptr_desaloca desaloca) {
  Ticket *t = (Ticket *)calloc(1, sizeof(Ticket));

  if (!t){
    return NULL;
  }

  strcpy(t->cpfSol, cpfSol);
  t->dado = dado;
  t->getTempo = getTempo;
  t->getTipo = getTipo;
  t->notifica = notifica;
  t->desaloca = desaloca;
  t->status = 'A';

  return t;
};

void setIDTicket(Ticket *d, char *id) { strcpy(d->id, id); };

void finalizaTicket(Ticket *t) { t->status = 'F'; };

char *getCPFSolicitanteTicket(Ticket *t) { return t->cpfSol; };

int getTempoEstimadoTicket(Ticket *t) { return t->getTempo(t->dado); };

char getTipoTicket(Ticket *t) { return t->getTipo(); };

char getStatusTicket(Ticket *t) { return t->status; };

void desalocaTicket(Ticket *doc) {
    doc->desaloca(doc->dado);
    free(doc);
};

void notificaTicket(Ticket *doc) {
  printf("---------TICKET-----------\n");
  printf("- ID: %s\n", doc->id);
  printf("- Usuario solicitante: %s\n", doc->cpfSol);

  doc->notifica(doc->dado);

  printf("- Status: ");
  if (doc->status == 'A') {
    printf("Aberto\n");
  } else {
    printf("Finalizado\n");
  }
  printf("-------------------------\n");
};