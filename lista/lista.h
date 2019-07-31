/* TAD: lista de inteiros */

typedef struct lista Lista;

/* Função cria
** Operação que cria uma lista vazia
*/
Lista* lst_cria( void );

/* Função libera
** Operação que libera o espaço alocado pela lista
*/
void lst_libera( Lista* l );

/* Função insere
** Operação que insere um elemento na lista
*/
void lst_insere( Lista** l, int i );

/* Função retira
** Operação que retira um elemento da lista
*/
void lst_retira( Lista** l, int v );

/* Função vazia
** Operação que verifica se a lista está vazia
*/
int lst_vazia( Lista* l );

/* Função busca
** Operação que busca um elemento em uma lista
*/
Lista* lst_busca( Lista* l, int v );

/* Função imprime
** Operação que mostra a lista na tela
*/
void lst_imprime( Lista* l );

/* Função insere ordenada
** Operação que insere elementos na lista de forma ordenada
*/
Lista* lst_insere_ordenado( Lista* l, int v );