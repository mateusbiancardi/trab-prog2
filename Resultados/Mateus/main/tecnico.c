#include "tecnico.h"
#include "data.h"
#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tecnico {
  char nome[MAX_TAM_NOME];
  char cpf[MAX_TAM_CPF];
  Data *dataNasc;
  char telefone[20];
  char genero[12];
  char atuacao[12];
  float salario;
  int disponibilidade;
  int tempoTrabalhado;

  Ticket **tickets;
  int qntdTickets;
};

Tecnico *criaTecnico(char *nome, char *cpf, Data *dataNasc, char *telefone,
                     char *genero, char *atuacao, float salario,
                     int disponibilidade) {
  Tecnico *t = (Tecnico *)calloc(1, sizeof(Tecnico));
  t->tickets = NULL;

  strcpy(t->nome, nome);
  strcpy(t->cpf, cpf);
  t->dataNasc = dataNasc;
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
  Data *dataNasc;
  char telefone[20];
  char genero[12];
  char atuacao[12];
  float salario;
  int disponibilidade;

  scanf(" %[^\n]\n", nome);
  scanf(" %[^\n]\n", cpf);
  dataNasc = leData();
  scanf(" %[^\n]\n", telefone);
  scanf(" %[^\n]\n", genero);
  scanf(" %[^\n]\n", atuacao);
  scanf("%d\n", &disponibilidade);
  scanf("%f\n", &salario);

  Tecnico *t = criaTecnico(nome, cpf, dataNasc, telefone, genero, atuacao,
                           salario, disponibilidade);

  return t;
};

int comparaCPFtecnico(Tecnico *t, void **dados, int qntdTecnicos) {
  Tecnico **tecnicos = (Tecnico **)dados;

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

void desalocaTecnico(void *dado) {
  Tecnico *t = (Tecnico *)dado;

  free(t->tickets);
  liberaData(t->dataNasc);
  free(t);
};

void notificaTecnico(void *dado) {
  Tecnico *t = (Tecnico *)dado;

  printf("--------------------\n");
  printf("- Nome: %s\n", t->nome);
  printf("- CPF: %s\n", t->cpf);
  printf("- Data de Nascimento: ");
  imprimeData(t->dataNasc);
  printf("- Telefone: %s\n", t->telefone);
  printf("- Genero: %s\n", t->genero);
  printf("- Area de Atuacao: %s\n", t->atuacao);
  printf("- Salario: %.2f\n", t->salario);
  printf("- Disponibilidade: %dh\n", t->disponibilidade);
  printf("- Tempo Trabalhado: %dh\n", t->tempoTrabalhado);
};

Data *getDataNascimentoTecnico(Tecnico *t) { return t->dataNasc; };

int calculaMediaIdadeTecnicos(Tecnico **tecnicos, int qntdTecnicos) {
  if (qntdTecnicos == 0) {
    return 0;
  }

  int soma = 0, media;

  Data *dataBase = criaData(DIA_BASE, MES_BASE, ANO_BASE);

  for (int i = 0; i < qntdTecnicos; i++) {
    soma +=
        calcularDiffAnosData(getDataNascimentoTecnico(tecnicos[i]), dataBase);
  }
  liberaData(dataBase);

  media = soma / qntdTecnicos;

  return media;
};

int getTempoTrabalhado(Tecnico *t) { return t->tempoTrabalhado; };

int calculaMediaTempoTrabalhado(Tecnico **tecnicos, int qntdTecnicos) {
  if (qntdTecnicos == 0) {
    return 0;
  }

  int soma = 0, media;

  for (int i = 0; i < qntdTecnicos; i++) {
    soma += getTempoTrabalhado(tecnicos[i]);
  }

  media = soma / qntdTecnicos;

  return media;
};

void adicionaTicketTecnico(Tecnico *tec, Ticket *tic) {
  tec->tickets = (Ticket **)realloc(tec->tickets,
                                    (tec->qntdTickets + 1) * sizeof(Ticket *));

  tec->tickets[tec->qntdTickets] = tic;
  tec->qntdTickets++;

  int tempoEstimado = getTempoEstimadoTicket(tic);
  tec->disponibilidade -= tempoEstimado;
  tec->tempoTrabalhado += tempoEstimado;
};

void distribuiTicketTecnico(Tecnico **tecnicos, int qntdTecnicos,
                            Ticket *ticket) {
  static int indiceTecnico = 0;

  if (getStatusTicket(ticket) == 'A') {
    char tipoTicket = getTipoTicket(ticket);
    int tempoEstimado = getTempoEstimadoTicket(ticket);

    for (int i = 0; i < qntdTecnicos; i++) {
      int tecnicoIndex = (indiceTecnico + i) % qntdTecnicos;

      if (tempoEstimado <= tecnicos[tecnicoIndex]->disponibilidade) {
        if (strcmp(tecnicos[tecnicoIndex]->atuacao, "TI") == 0 &&
                tipoTicket == 'S' ||
            strcmp(tecnicos[tecnicoIndex]->atuacao, "GERAL") == 0 &&
                tipoTicket != 'S') {
          adicionaTicketTecnico(tecnicos[tecnicoIndex], ticket);
          finalizaTicket(ticket);
          indiceTecnico = (tecnicoIndex + 1) % qntdTecnicos;
          break;
        }
      }
    }
  }
};
