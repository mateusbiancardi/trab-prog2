#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_LOCAL 100
#define MAX_TAM_ESTADO 20

typedef struct Manutencao Manutencao;

/**
 * @brief Aloca uma estrutura Manutencao na memória e inicializa os parâmetros
 * necessários.
 * @param nome Nome da Manutencao
 * @param estado Estado da Manutencao
 * @param local Local da manutencao
 * @return Uma estrutura Manutencao inicializada.
 */
Manutencao *criaManutencao(char *nome, char *estado, char *local);

/**
 * @brief Lê da entrada padrão um ticket do tipo Manutencao.
 * @return Um chamado do tipo Manutencao.
 */
Manutencao *lerManutencao();

/**
 * @brief Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param m Ticket do tipo Manutencao.
 */
void setTempoEstimadoManutencao(Manutencao *m);

/**
 * @brief Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado Ticket do tipo Manutencao.
 * @return Tempo estimado para resolver um ticket do tipo Manutencao.
 */
int getTempoEstimadoManutencao(void *dado);

/**
 * @brief Retorna o tipo do ticket.
 * @return 'M' para Manutencao.
 */
char getTipoManutencao();

/**
 * @brief Desaloca um ticket do tipo Manutencao da memória.
 * @param m Ticket do tipo Manutencao.
 */
void desalocaManutencao(void *m);

/**
 * @brief Imprime um ticket do tipo Manutencao.
 * @param dado Ticket do tipo Manutencao.
 */
void notificaManutencao(void *dado);

#endif