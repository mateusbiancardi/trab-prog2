#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario {
  char nome[MAX_TAM_NOME];
  char cpf[MAX_TAM_CPF];
  char dataNasc[15];
  char telefone[20];
  char genero[12];
  char setor[12];
  int qntdTickets;
};

Usuario *criaUsuario(char *nome, char *cpf, char *dataNasc, char *telefone,
                     char *genero, char *setor) {
  Usuario *u = (Usuario *)calloc(1, sizeof(Usuario));

  strcpy(u->nome, nome);
  strcpy(u->cpf, cpf);
  strcpy(u->dataNasc, dataNasc);
  strcpy(u->telefone, telefone);
  strcpy(u->genero, genero);
  strcpy(u->setor, setor);
  u->qntdTickets = 0;

  return u;
};

Usuario *leUsuario() {
  char nome[MAX_TAM_NOME];
  char cpf[MAX_TAM_CPF];
  char dataNasc[15];
  char telefone[20];
  char genero[12];
  char setor[12];

  scanf(" %[^\n]\n", nome);
  scanf(" %[^\n]\n", cpf);
  scanf(" %[^\n]\n", dataNasc);
  scanf(" %[^\n]\n", telefone);
  scanf(" %[^\n]\n", genero);
  scanf(" %[^\n]\n", setor);

  Usuario *u = criaUsuario(nome, cpf, dataNasc, telefone, genero, setor);

  return u;
};

int comparaCPF(Usuario *u, Usuario **usuarios, int qntdUsuarios) {
  for (int i = 0; i < qntdUsuarios; i++) {
    if (strcmp(u->cpf, usuarios[i]->cpf) == 0) {
      return 1;
    }
  }
  return 0;
};

void setQntdTicketsUsuario(Usuario *u, int qntdTickets) {
  u->qntdTickets = qntdTickets;
};

int getQntdTicketsUsuario(Usuario *u) { return u->qntdTickets; };

void desalocaUsuario(Usuario *u) { free(u); };

void notificaUsuario(Usuario *u) {
  printf("--------------------\n");
  printf("- Nome: %s\n", u->nome);
  printf("- CPF: %s\n", u->cpf);
  printf("- Data de Nascimento: %s\n", u->dataNasc);
  printf("- Telefone: %s\n", u->telefone);
  printf("- Genero: %s\n", u->genero);
  printf("- Setor: %s\n", u->setor);
  printf("- Tickets solicitados: %d\n", u->qntdTickets);
};