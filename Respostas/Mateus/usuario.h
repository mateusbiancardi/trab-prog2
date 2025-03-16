#ifndef _USUARIO_H
#define _USUARIO_H

#include "data.h"
#define MAX_TAM_NOME 100
#define MAX_TAM_CPF 15
#define DIA_BASE 18
#define MES_BASE 2
#define ANO_BASE 2025

typedef struct Usuario Usuario;

/**
 * @brief Aloca uma estrutura Usuario na memória e inicializa os parâmetros
 * necessários
 * @param nome Nome do usuário
 * @param cpf CPF do usuário
 * @param dataNasc Data de nascimento do usuário
 * @param telefone Telefone do usuário
 * @param genero Gênero do usuário
 * @param setor Setor do usuário
 * @return Uma estrutura Usuario inicializada.
 */
Usuario *criaUsuario(char *nome, char *cpf, Data *dataNasc, char *telefone,
                     char *genero, char *setor);

/**
 * @brief Lê um usuário de uma lista de usuários.
 *
 * Lê um usuário da entrada padrão e compara com os usuários existentes,
 * se encontrar um CPF igual retorna NULL
 *
 * @param usuarios Um ponteiro para um array de ponteiros de usuários.
 * @param qntdUsuarios O número de usuários no array.
 * @return Um ponteiro para o usuário lido da lista.
 */
Usuario *leUsuario();

Usuario *buscaCPFusuario(char *cpf, void **dados, int qntdUsuarios);

/**
 * @brief Compara o CPF de um usuário com uma lista de usuários.
 *
 * Esta função compara o CPF de um usuário fornecido com os CPFs de uma
 * lista de usuários.
 *
 * @param u Ponteiro para o usuário cujo CPF será comparado.
 * @param usuarios Ponteiro para um array de ponteiros de usuários.
 * @param qntdUsuarios Número de usuários na lista.
 * @return Retorna 1 se o CPF do usuário fornecido for encontrado na lista,
 * caso contrário, retorna 0.
 */
int comparaCPFusuario(Usuario *u, void **dados, int qntdUsuarios);

/**
 * @brief Define a quantidade de tickets para um usuário.
 *
 * @param u Ponteiro para o objeto Usuario.
 * @param qntdTickets A quantidade de tickets a ser definida para o usuário.
 */
void setQntdTicketsUsuario(Usuario *u, int qntdTickets);

/**
 * @brief Desaloca a memória alocada para um objeto do tipo Usuario.
 *
 * Esta função libera a memória associada ao objeto Usuario apontado por 'u'.
 * Após a chamada desta função, o ponteiro 'u' não deve mais ser utilizado.
 *
 * @param u Ponteiro para o objeto Usuario a ser desalocado.
 */
void desalocaUsuario(void *dado);

/**
 * @brief Notifica (imprime) um Usuario.
 * @param u Usuario a ser notificado.
 */
void notificaUsuario(void *dado);

char *getSetor(Usuario *u);

/**
 * @brief Obtém a quantidade de tickets de um usuário.
 *
 * @param u Ponteiro para o usuário.
 * @return int Quantidade de tickets do usuário.
 */
int getQntdTicketsUsuario(Usuario *u);

/**
 * @brief Obtém a data de nascimento de um usuário.
 *
 * @param u Ponteiro para o usuário.
 * @return Data* Ponteiro para a data de nascimento do usuário.
 */
Data *getDataNascimentoUsuario(Usuario *u);

/**
 * @brief Calcula a média de idade dos usuários.
 *
 * @param usuarios Array de ponteiros para os usuários.
 * @param qntdUsuarios Número de usuários no array.
 * @return int Média de idade dos usuários.
 */
int calculaMediaIdadeUsuarios(Usuario **usuarios, int qntdUsuarios);

/**
 * @brief Compara dois usuários com base no ranking.
 *
 * Esta função compara dois usuários fornecidos com base no ranking.
 *
 * @param usuario1 Ponteiro para o primeiro usuário a ser comparado.
 * @param usuario2 Ponteiro para o segundo usuário a ser comparado.
 * @return int Retorna um valor negativo se usuario1 tiver um ranking menor que
 * usuario2, zero se forem iguais, ou um valor positivo se usuario1 tiver um
 * ranking maior que usuario2.
 */
int comparaRankingUsuario(const void *usuario1, const void *usuario2);

/**
 * @brief Notifica (imprime) o ranking dos usuários.
 *
 * Esta função imprime o ranking dos usuários fornecidos.
 *
 * @param usuarios Array de ponteiros para os usuários.
 * @param qntdUsuarios Número de usuários no array.
 */
void notificaRankingUsuario(Usuario **usuarios, int qntdUsuarios);

#endif