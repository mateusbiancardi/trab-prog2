#ifndef _TECNICO_H
#define _TECNICO_H

#define MAX_TAM_NOME 100
#define MAX_TAM_CPF 15

typedef struct Tecnico Tecnico;

// struct Tecnico {
//   char nome[MAX_TAM_NOME];
//   char cpf[MAX_TAM_CPF];
//   char dataNasc[15];
//   char telefone[20];
//   char genero[12];
//   char atuacao[12];
//   float salario;
//   int tempo;
//   int qntdTickets;
// };

/**
 * @brief Cria um novo técnico.
 *
 * @param nome Nome do técnico.
 * @param cpf CPF do técnico.
 * @param dataNasc Data de nascimento do técnico.
 * @param telefone Telefone do técnico.
 * @param genero Gênero do técnico.
 * @param atuacao Área de atuação do técnico.
 * @param salario Salário do técnico.
 * @param tempo Tempo de disponibilidade
 * @return Ponteiro para o novo técnico criado.
 */
Tecnico *criaTecnico(char *nome, char *cpf, char *dataNasc, char *telefone,
                     char *genero, char *atuacao, float salario,
                     int disponibilidade);

/**
 * @brief Lê os dados de um técnico.
 *
 * @return Ponteiro para o técnico lido.
 */
Tecnico *leTecnico();

/**
 * @brief Compara o CPF de um técnico com os CPFs de outros técnicos.
 *
 * @param t Ponteiro para o técnico a ser comparado.
 * @param tecnicos Array de ponteiros para técnicos.
 * @param qntdTecnicos Quantidade de técnicos no array.
 * @return 1 se o CPF for igual a algum dos técnicos no array, 0 caso contrário.
 */
int comparaCPF(Tecnico *t, Tecnico **tecnicos, int qntdTecnicos);

/**
 * @brief Define a quantidade de tickets de um técnico.
 *
 * @param t Ponteiro para o técnico.
 * @param qntdTickets Quantidade de tickets a ser definida.
 */
void setQntdTicketsTecnico(Tecnico *t, int qntdTickets);

/**
 * @brief Obtém a quantidade de tickets de um técnico.
 *
 * @param t Ponteiro para o técnico.
 * @return Quantidade de tickets do técnico.
 */
int getQntdTicketsTecnico(Tecnico *t);

/**
 * @brief Desaloca a memória de um técnico.
 *
 * @param t Ponteiro para o técnico a ser desalocado.
 */
void desalocaTecnico(Tecnico *t);

/**
 * @brief Notifica um técnico.
 *
 * @param t Ponteiro para o técnico a ser notificado.
 */
void notificaTecnico(Tecnico *t);

#endif