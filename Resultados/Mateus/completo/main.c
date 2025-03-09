#include "usuario.h"
#include <stdlib.h>

int main() {
  int qntdUsuarios = 5;
  Usuario **usuarios = (Usuario **)calloc(qntdUsuarios, sizeof(Usuario *));

  Usuario *u = leUsuario(usuarios, qntdUsuarios);
  notificaUsuario(u);
  desalocaUsuario(u);
}