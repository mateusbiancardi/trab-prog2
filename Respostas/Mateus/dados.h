#ifndef _DADOS_H_
#define _DADOS_H_

/**
 * Estrutura de dados genérica.
 */
typedef struct Dados Dados;

/**
 * Cria uma nova estrutura de dados.
 *
 * @return Ponteiro para a nova estrutura de dados.
 */
Dados *criaDados();

/**
 * Adiciona um novo dado à estrutura.
 *
 * @param v Ponteiro para a estrutura de dados.
 * @param val Ponteiro para o valor a ser adicionado.
 */
void adicionaDado(Dados *v, void *val);

/**
 * Retorna um dado da estrutura.
 *
 * @param v Ponteiro para a estrutura de dados.
 * @param i Índice do dado a ser retornado.
 * @return Ponteiro para o dado.
 */
void *retornaDado(Dados *v, int i);

/**
 * Retorna o tamanho da estrutura de dados.
 *
 * @param v Ponteiro para a estrutura de dados.
 * @return Tamanho da estrutura de dados.
 */
int tamanhoDados(Dados *v);

/**
 * Libera a memória alocada para a estrutura de dados.
 *
 * @param v Ponteiro para a estrutura de dados.
 * @param destroy Função para destruir os dados armazenados.
 */
void liberaDados(Dados *v, void (*destroy)(void *));

/**
 * Imprime os dados da estrutura.
 *
 * @param v Ponteiro para a estrutura de dados.
 * @param printa Função para imprimir os dados armazenados.
 */
void printaDados(Dados *v, void (*printa)(void *));

#endif
