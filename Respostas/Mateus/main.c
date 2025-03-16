#include "dados.h"
#include "fila.h"
#include "manutencao.h"
#include "outros.h"
#include "software.h"
#include "tecnico.h"
#include "usuario.h"
#include <stdio.h>
#include <string.h>

void limpaString(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  // Remove o caractere de nova linha se presente
  if (i > 0 && str[i - 1] == '\n') {
    str[i - 1] = '\0';
  }
}

int main() {
  char escolha = 'X';
  Dados *tecnicos = criaDados();
  Dados *usuarios = criaDados();
  Fila *fila = criaFila();

  while (escolha != 'F') {
    scanf("%c\n", &escolha);

    if (escolha == 'T') {
      Tecnico *t;
      t = leTecnico();

      void **dados = retornaTodosDados(tecnicos);

      if (comparaCPFtecnico(t, dados, tamanhoDados(tecnicos)) == 1) {
        desalocaTecnico(t);
      } else {
        adicionaDado(tecnicos, t);
      }

    } else if (escolha == 'U') {
      Usuario *u;
      u = leUsuario();

      void **dados = retornaTodosDados(usuarios);

      if (comparaCPFusuario(u, dados, tamanhoDados(usuarios)) == 1) {
        desalocaUsuario(u);
      } else {
        adicionaDado(usuarios, u);
      }
    } else if (escolha == 'A') {
      char cpf[MAX_TAM_CPF];
      char tipo[30];

      scanf(" %[^\n]\n", cpf);
      scanf(" %[^\n]\n", tipo);

      if (strcmp(tipo, "MANUTENCAO") == 0) {
        Usuario **users = (Usuario **)retornaTodosDados(usuarios);
        Usuario *user;

        user = buscaCPFusuario(cpf, (void **)users, tamanhoDados(usuarios));
        Manutencao *m = lerManutencao(getSetor(user));

        if (user != NULL) {
          setTempoEstimadoManutencao(m, getSetor(user));
          setQntdTicketsUsuario(user, getQntdTicketsUsuario(user) + 1);

          insereTicketFila(fila, cpf, m, getTempoEstimadoManutencao,
                           getTipoManutencao, notificaManutencao,
                           desalocaManutencao);
        } else {
          desalocaManutencao(m);
        }

      } else if (strcmp(tipo, "SOFTWARE") == 0) {
        Usuario **users = (Usuario **)retornaTodosDados(usuarios);
        Usuario *user;

        user = buscaCPFusuario(cpf, (void **)users, tamanhoDados(usuarios));
        Software *s = lerSoftware();

        if (user != NULL) {
          setTempoEstimadoSoftware(s);
          setQntdTicketsUsuario(user, getQntdTicketsUsuario(user) + 1);

          insereTicketFila(fila, cpf, s, getTempoEstimadoSoftware,
                           getTipoSoftware, notificaSoftware, desalocaSoftware);
        } else {
          desalocaSoftware(s);
        }
      }

      else if (strcmp(tipo, "OUTROS") == 0) {
        Usuario **users = (Usuario **)retornaTodosDados(usuarios);
        Usuario *user;

        user = buscaCPFusuario(cpf, (void **)users, tamanhoDados(usuarios));
        Outros *o = lerOutros();

        if (user != NULL) {
          setTempoEstimadoOutros(o);
          setQntdTicketsUsuario(user, getQntdTicketsUsuario(user) + 1);
          insereTicketFila(fila, cpf, o, getTempoEstimadoOutros, getTipoOutros,
                           notificaOutros, desalocaOutros);
        } else {
          desalocaOutros(o);
        }
      }
    } else if (escolha == 'E') {
      char escolha2[20];
      scanf(" %[^\n]\n", escolha2);

      if (strcmp(escolha2, "USUARIOS") == 0) {

        printf("----- BANCO DE USUARIOS -----\n");
        printaDados(usuarios, notificaUsuario);
        printf("----------------------------\n\n");

      } else if (strcmp(escolha2, "TECNICOS") == 0) {

        printf("----- BANCO DE TECNICOS -----\n");
        printaDados(tecnicos, notificaTecnico);
        printf("----------------------------\n\n");
      } else if (strcmp(escolha2, "NOTIFICA") == 0) {

        printf("----- FILA DE TICKETS -----\n");
        notificaFila(fila);
        printf("---------------------------\n\n");
      }
    }
  }
  liberaDados(usuarios, desalocaUsuario);
  liberaDados(tecnicos, desalocaTecnico);
  desalocaFila(fila);

  return 0;
}

// ----- FILA DE TICKETS -----
// ---------TICKET-----------
// - ID: Tick-1
// - Usuario solicitante: 791.680.245-68
// - Tipo: Software
// - Nome do software: OUTLOOK
// - Categoria: BUG
// - Nível do impacto: 4
// - Motivo: EMAILS NAO ESTAO SENDO ENVIADOS
// - Tempo estimado: 7h
// - Status: Aberto
// -------------------------

// ---------------------------