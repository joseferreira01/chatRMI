/* Tipo: Funcionário */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tipo: Funcionário */
struct funcionario {
	char *nome;
	int idade;
	int matricula;
};

//typedef struct funcionario Funcionario; //Redeclarado no Funcionario.c

/*Tipo criado para armazenar informações de Funcionários de uma empresa.
 O Campo Matrícula deve ser usado como Chave para a identificação única
 de um Funcionário no conjunto*/
typedef struct funcionario Funcionario;

/***********************************************************/
/******************* Funções exportadas *******************/

/* Função cria - Aloca e retorna um Funcionário */
Funcionario* cria_Funcionario(void);

/* Função atualiza nome - Insere um Novo nome para um Funcionário */
void atualiza_nome_Func(Funcionario* func, char *nome);

/* Função atualiza matricula - Insere uma Nova matrícula para um Funcionário */
void atualiza_mat_Func(Funcionario* func, int val);

/* Função atualiza idade - Atualiza a idade do Funcionário */
void atualiza_idade_Func(Funcionario* func, int val);

/* Função libera - Libera um Funcionário da memória */
void libera_Func(Funcionario* func);

/* Função acessa nome - Retorna o nome do funcionário
  Retorno : String  */
char* acessa_nome_Func(Funcionario* func);

/* Função acessa matricula - Retorna a matrícula do Funcionário
   Retorno: int */
int acessa_mat_Func(Funcionario* func);

/* Função acessa idade - Retorna a idade do Funcionário
  Retorno: int*/
int acessa_idade_Func(Funcionario* func);

/* Função imprime - Imprime Informações do Funcionário
  Retorno: int*/
void imprime_Func(Funcionario* func);

/* Preenche Funcionario - recebe os dados do usuário e preenche um Funcionario
  Retorno: int*/
int preenche_Func(Funcionario* func);
