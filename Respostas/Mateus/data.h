
#ifndef _DATA_H
#define _DATA_H

#include <stdio.h>

typedef struct Data Data;

/**
 * @brief Função que cria uma data alocando a memória necessária e inicializando
 * seus valores.
 *
 * @param dia inteiro representando o dia
 * @param mes inteiro representando o mês
 * @param ano inteiro representando o ano
 * @return Data*
 */
Data *criaData(int dia, int mes, int ano);

/**
 * @brief Função que lê uma data a partir da ENTRADA PADRÃO, de acordo com a
 * especificação, e retorna um ponteiro para a data criada. Dica: veja os casos
 * de teste para entender o formato de entrada.
 *
 * @return Data*
 */
Data *leData();

/**
 * @brief Função que imprime uma data no terminal, de acordo com a
 * especificação.
 *
 * @param d Ponteiro para Data a ser impressa
 */
void imprimeData(Data *d);

/**
 * @brief Função que calcula a diferença de anos entre duas datas da mesma forma
 que calculamos aniversários.
 * Exemplo: 25/12/1990 e 10/12/2025 = 34 anos

 * @param inicio Data de início
 * @param fim Data de fim
 * @return int diferença de anos entre as duas datas
 */
int calcularDiffAnosData(Data *inicio, Data *fim);

/**
 * @brief Função que libera a memória alocada para uma data.
 *
 * @param d Ponteiro para Data a ser liberada
 */
void liberaData(Data *d);

#endif