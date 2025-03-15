#ifndef _USUARIO_H
#define _USUARIO_H

#define MAX_TAM_NOME 100
#define MAX_TAM_CPF 15

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
Usuario *criaUsuario(char *nome, char *cpf, char *dataNasc, char *telefone,
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
int comparaCPF(Usuario *u, Usuario **usuarios, int qntdUsuarios);

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
void desalocaUsuario(Usuario *u);

/**
 * @brief Notifica (imprime) um Usuario.
 * @param u Usuario a ser notificado.
 */
void notificaUsuario(Usuario *u);

/**
 * @brief Obtém a quantidade de tickets de um usuário.
 *
 * @param u Ponteiro para o usuário.
 * @return int Quantidade de tickets do usuário.
 */
int getQntdTicketsUsuario(Usuario *u);

#endif