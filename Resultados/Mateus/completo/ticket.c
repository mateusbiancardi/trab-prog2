#include "ticket.h"
#include <stdlib.h>
#include <string.h>

struct Ticket {
  char *id;
  char *cpfSol;
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

int getTempoEstimadoTicket(Ticket *t) { return t->getTempo(t); };

char getTipoTicket(Ticket *t) { return t->getTipo(); };

char getStatusTicket(Ticket *t) { return t->status; };

void desalocaTicket(Ticket *doc) {
  doc->desaloca(doc);
  free(doc);
};

void notificaTicket(Ticket *doc) { doc->notifica(doc); };