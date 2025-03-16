#ifndef _TECNICO_H
#define _TECNICO_H

#include "data.h"
#include "ticket.h"
#define MAX_TAM_NOME 100
#define MAX_TAM_CPF 15
#define DIA_BASE 18
#define MES_BASE 2
#define ANO_BASE 2025

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
Tecnico *criaTecnico(char *nome, char *cpf, Data *dataNasc, char *telefone,
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
 * @param dados Array de ponteiros de void.
 * @param qntdTecnicos Quantidade de técnicos no array.
 * @return 1 se o CPF for igual a algum dos técnicos no array, 0 caso contrário.
 */
int comparaCPFtecnico(Tecnico *t, void **dados, int qntdTecnicos);

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
void desalocaTecnico(void *dado);

/**
 * @brief Notifica um técnico.
 *
 * @param t Ponteiro para o técnico a ser notificado.
 */
void notificaTecnico(void *dado);

/**
 * @brief Obtém a data de nascimento de um técnico.
 *
 * @param u Ponteiro para o técnico.
 * @return Data* Ponteiro para a data de nascimento do técnico.
 */
Data *getDataNascimentoTecnico(Tecnico *u);

/**
 * @brief Calcula a média de idade dos tecnicos.
 *
 * @param tecnicos Array de ponteiros para os tecnicos.
 * @param qntdTecnicos Número de tecnicos no array.
 * @return int Média de idade dos tecnicos.
 */
int calculaMediaIdadeTecnicos(Tecnico **tecnicos, int qntdTecnicos);

/**
 * @brief Obtém o tempo trabalhado de um técnico.
 *
 * @param t Ponteiro para o técnico.
 * @return int Tempo trabalhado do técnico.
 */
int getTempoTrabalhado(Tecnico *t);

/**
 * @brief Calcula a média de tempo trabalhado dos técnicos.
 *
 * @param tecnicos Array de ponteiros para os técnicos.
 * @param qntdTecnicos Número de técnicos no array.
 * @return int Média de tempo trabalhado dos técnicos.
 */
int calculaMediaTempoTrabalhado(Tecnico **tecnicos, int qntdTecnicos);

/**
 * @brief Adiciona um ticket ao técnico.
 *
 * @param tec Ponteiro para o técnico.
 * @param tic Ponteiro para o ticket a ser adicionado.
 */
void adicionaTicketTecnico(Tecnico *tec, Ticket *tic);

/**
 * @brief Distribui um ticket entre os técnicos disponíveis.
 *
 * @param tecnicos Array de ponteiros para os técnicos.
 * @param qntdTecnicos Número de técnicos no array.
 * @param ticket Ponteiro para o ticket a ser distribuído.
 * @return int Índice do técnico ao qual o ticket foi atribuído.
 */
void distribuiTicketTecnico(Tecnico **tecnicos, int qntdTecnicos,
                            Ticket *ticket);

#endif