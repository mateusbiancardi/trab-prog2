#include "dados.h"
#include "tecnico.h"
#include "usuario.h"
#include <stdio.h>
#include <string.h>

int main() {
  char escolha;
  Dados *tecnicos = criaDados();
  Dados *usuarios = criaDados();

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
      }
    }
  }
  liberaDados(usuarios, desalocaUsuario);
  liberaDados(tecnicos, desalocaTecnico);

  return 0;
}