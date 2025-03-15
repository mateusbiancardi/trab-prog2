#ifndef _OUTROS_H
#define _OUTROS_H

#define MAX_TAM_DESCRICAO_OUTROS 500
#define MAX_TAM_LOCAL 25

typedef struct Outros Outros;

/**
 * @brief Cria um novo objeto do tipo Outros.
 *
 * @param descricao Descrição do objeto.
 * @param local Local onde o objeto está localizado.
 * @param dificuldade Nível de dificuldade associado ao objeto.
 * @param tempoEstimado Tempo estimado para completar a tarefa associada ao
 * objeto.
 * @return Ponteiro para o novo objeto do tipo Outros.
 */
Outros *criaOutros(char *descricao, char *local, int dificuldade);

/**
 * @brief Lê e retorna uma instância da classe Outros.
 *
 * Esta função é responsável por ler os dados e criar uma instância
 * da classe Outros com base nos dados de entrada.
 *
 * @return Um ponteiro para uma instância da classe Outros.
 */
Outros *lerOutros();

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Outros.
 * O tempo estimado depende da categoria e impacto.
 * @param o  Ticket do tipo Outros
 */
void setTempoEstimadoOutros(Outros *o);

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 * @return  Tempo estimado para resolver um ticket do tipo Outros
 */
int getTempoEstimadoOutros(void *dado);

/**
 * @brief  Retorna o tipo do ticket.
 * @return  'O' para Outros
 */
char getTipoOutros();

/**
 * @brief  Desaloca um ticket do tipo Outros da memória.
 * @param o  Ticket do tipo Outros
 */
void desalocaOutros(void *o);

/**
 * @brief  Imprime um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 */
void notificaOutros(void *dado);

#endif
