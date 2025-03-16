#include "usuario.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario {
  char nome[MAX_TAM_NOME];
  char cpf[MAX_TAM_CPF];
  Data *dataNasc;
  char telefone[20];
  char genero[12];
  char setor[12];
  int qntdTickets;
};

Usuario *criaUsuario(char *nome, char *cpf, Data *dataNasc, char *telefone,
                     char *genero, char *setor) {
  Usuario *u = (Usuario *)calloc(1, sizeof(Usuario));

  strcpy(u->nome, nome);
  strcpy(u->cpf, cpf);
  u->dataNasc = dataNasc;
  strcpy(u->telefone, telefone);
  strcpy(u->genero, genero);
  strcpy(u->setor, setor);
  u->qntdTickets = 0;

  return u;
};

Usuario *leUsuario() {
  char nome[MAX_TAM_NOME];
  char cpf[MAX_TAM_CPF];
  Data *dataNasc;
  char telefone[20];
  char genero[12];
  char setor[12];

  scanf(" %[^\n]\n", nome);
  scanf(" %[^\n]\n", cpf);
  dataNasc = leData();
  scanf(" %[^\n]\n", telefone);
  scanf(" %[^\n]\n", genero);
  scanf(" %[^\n]\n", setor);

  Usuario *u = criaUsuario(nome, cpf, dataNasc, telefone, genero, setor);

  return u;
};

Usuario *buscaCPFusuario(char *cpf, void **dados, int qntdUsuarios) {
  Usuario **usuarios = (Usuario **)dados;

  for (int i = 0; i < qntdUsuarios; i++) {
    if (strcmp(cpf, usuarios[i]->cpf) == 0) {
      return usuarios[i];
    }
  }
  return NULL;
};

int comparaCPFusuario(Usuario *u, void **dados, int qntdUsuarios) {
  Usuario **usuarios = (Usuario **)dados;

  for (int i = 0; i < qntdUsuarios; i++) {
    if (strcmp(u->cpf, usuarios[i]->cpf) == 0) {
      return 1;
    }
  }
  return 0;
};

char *getSetor(Usuario *u) {
  if (u == NULL)
    return NULL;
  return u->setor;
};

void setQntdTicketsUsuario(Usuario *u, int qntdTickets) {
  u->qntdTickets = qntdTickets;
};

int getQntdTicketsUsuario(Usuario *u) { return u->qntdTickets; };

void desalocaUsuario(void *dado) {
  Usuario *u = (Usuario *)dado;
  liberaData(u->dataNasc);
  free(u);
};

void notificaUsuario(void *dado) {
  Usuario *u = (Usuario *)dado;

  printf("--------------------\n");
  printf("- Nome: %s\n", u->nome);
  printf("- CPF: %s\n", u->cpf);
  printf("- Data de Nascimento: ");
  imprimeData(u->dataNasc);
  printf("- Telefone: %s\n", u->telefone);
  printf("- Genero: %s\n", u->genero);
  printf("- Setor: %s\n", u->setor);
  printf("- Tickets solicitados: %d\n", u->qntdTickets);
};

Data *getDataNascimentoUsuario(Usuario *u) { return u->dataNasc; };

int calculaMediaIdadeUsuarios(Usuario **usuarios, int qntdUsuarios) {
  if (qntdUsuarios == 0) {
    return 0;
  }

  int soma = 0, media;

  Data *dataBase = criaData(DIA_BASE, MES_BASE, ANO_BASE);

  for (int i = 0; i < qntdUsuarios; i++) {
    soma +=
        calcularDiffAnosData(getDataNascimentoUsuario(usuarios[i]), dataBase);
  }
  liberaData(dataBase);

  media = soma / qntdUsuarios;

  return media;
};