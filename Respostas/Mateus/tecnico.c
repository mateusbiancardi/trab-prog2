#include "tecnico.h"
#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tecnico {
  char nome[MAX_TAM_NOME];
  char cpf[MAX_TAM_CPF];
  char dataNasc[15];
  char telefone[20];
  char genero[12];
  char atuacao[12];
  float salario;
  int disponibilidade;
  int tempoTrabalhado;

  Ticket **tickets;
  int qntdTickets;
};

Tecnico *criaTecnico(char *nome, char *cpf, char *dataNasc, char *telefone,
                     char *genero, char *atuacao, float salario,
                     int disponibilidade) {
  Tecnico *t = (Tecnico *)calloc(1, sizeof(Tecnico));
  t->tickets = (Ticket **)calloc(1, sizeof(Ticket *));

  strcpy(t->nome, nome);
  strcpy(t->cpf, cpf);
  strcpy(t->dataNasc, dataNasc);
  strcpy(t->telefone, telefone);
  strcpy(t->genero, genero);
  strcpy(t->atuacao, atuacao);
  t->salario = salario;
  t->disponibilidade = disponibilidade;
  t->tempoTrabalhado = 0;
  t->qntdTickets = 0;

  return t;
};

Tecnico *leTecnico() {
  char nome[MAX_TAM_NOME];
  char cpf[MAX_TAM_CPF];
  char dataNasc[15];
  char telefone[20];
  char genero[12];
  char atuacao[12];
  float salario;
  int disponibilidade;

  scanf(" %[^\n]\n", nome);
  scanf(" %[^\n]\n", cpf);
  scanf(" %[^\n]\n", dataNasc);
  scanf(" %[^\n]\n", telefone);
  scanf(" %[^\n]\n", genero);
  scanf(" %[^\n]\n", atuacao);
  scanf("%d\n", &disponibilidade);
  scanf("%f\n", &salario);

  Tecnico *t = criaTecnico(nome, cpf, dataNasc, telefone, genero, atuacao,
                           salario, disponibilidade);

  return t;
};

int comparaCPF(Tecnico *t, Tecnico **tecnicos, int qntdTecnicos) {
  for (int i = 0; i < qntdTecnicos; i++) {
    if (strcmp(t->cpf, tecnicos[i]->cpf) == 0) {
      return 1;
    }
  }
  return 0;
};

void setQntdTicketsTecnico(Tecnico *t, int qntdTickets) {
  t->qntdTickets = qntdTickets;
};

int getQntdTicketsTecnico(Tecnico *t) { return t->qntdTickets; };

void desalocaTecnico(Tecnico *t) {
  for (int i = 0; i < t->qntdTickets; i++) {
    desalocaTicket(t->tickets[i]);
  }
  free(t->tickets);
  free(t);
};

void notificaTecnico(Tecnico *t) {
  printf("--------------------\n");
  printf("- Nome: %s\n", t->nome);
  printf("- CPF: %s\n", t->cpf);
  printf("- Data de Nascimento: %s\n", t->dataNasc);
  printf("- Telefone: %s\n", t->telefone);
  printf("- Genero: %s\n", t->genero);
  printf("- Area de Atuacao: %s\n", t->atuacao);
  printf("- Salario: %.2f\n", t->salario);
  printf("- Disponibilidade: %dh\n", t->disponibilidade);
  printf("- Tempo Trabalhado: %dh\n", t->tempoTrabalhado);
};
