#include "dados.h"
#include "fila.h"
#include "gerenciador.h"

int main() {
  Dados *tecnicos = criaDados();
  Dados *usuarios = criaDados();
  Fila *fila = criaFila();

  rodaGerenciador(tecnicos, usuarios, fila);

  desalocaGerenciador(tecnicos, usuarios, fila);

  return 0;
}
