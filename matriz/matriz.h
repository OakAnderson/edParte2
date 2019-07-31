/* TAD: matriz m por n */

/* Tipo exportado */
typedef struct matriz Matriz;

/* Função cria
** Operação que cria uma matriz de dimensão m por n
*/
Matriz* mat_cria( int m, int n );

/* Função libera
** Operação que libera a memória ocupada para a matriz
*/
void mat_libera( Matriz* mat );

/* Função acessa
** Operação que acessa o elemento da linha i e da coluna j da matriz
*/
float mat_acessa( Matriz* mat, int i, int j );

/* Função atribui
** Operação que atribui o elemento da linha i e da coluna j da matriz;
*/
void mat_atribui( Matriz* mat, int i, int j, float v );

/* Função linhas
** Operação que retorna o número de linhas da matriz
*/
int mat_linhas( Matriz* mat );

/* Função colunas
**  Operação que retorna o número de colunas da matriz
*/
int mat_colunas( Matriz* mat );

/* Função mostra
** Operação que mostra na tela a matriz m por n
*/
void mat_mostra( Matriz* mat );