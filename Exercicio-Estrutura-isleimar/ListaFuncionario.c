#include <stdio.h>
#include <stdlib.h>

#include  "Funcionario.h"  //Usa o Tipo Funcionario
#include "ListaFuncionario.h"


struct lista {
	Funcionario* no;
	struct lista* prox;
};
typedef struct lista ListaFuncionario;

/* Função cria Lista- Aloca e retorna uma Lista de Funcionários */
ListaFuncionario* lista_cria (void){

return NULL;

}

/* Função insere no inicio - Insere um Novo Funcionário no inicio da Lista */
ListaFuncionario* lista_insere_inicio (ListaFuncionario* list, Funcionario* func){

	ListaFuncionario* novo = (ListaFuncionario*) malloc(sizeof(ListaFuncionario));
	if(novo!=NULL){

	 novo->no = func;
	 novo->prox = list;

 	 return novo;
   }else printf("Não foi possivel alocar espaco de memoria para o novo no");

	return NULL;
}

/* Função Lista Vazia- Testa de a Lista está vazia  */
int lista_vazia (ListaFuncionario* list){
	return (list == NULL);

}
/*Funcao para inserir ordenado*/
ListaFuncionario* lista_insere_ordenado(ListaFuncionario* list, Funcionario* func){
    ListaFuncionario* novo=(ListaFuncionario*)malloc(sizeof(ListaFuncionario));
    if (novo==NULL)
    {
        printf("Nao foi possivel alocar espaco de memoria para o novo no");
        free(func);
        return list;
    }
    novo->no=func;
    novo->prox=NULL;
    if (list==NULL) return novo;//Lista vazia
    ListaFuncionario* p=list;
    ListaFuncionario* a=NULL;
    while(p!=NULL)
    {
        if (func->matricula<p->no->matricula)
            break;
        a=p;
        p=p->prox;
    }
    if(a==NULL)//Inserido no inicio
        {
            novo->prox=list;
            return novo;
        }
    novo->prox=a->prox;
    a->prox=novo;
    return list;//Inserido no meio da lista
}

/* Função busca- busca um Funcionario na lista */
Funcionario* busca(ListaFuncionario* lst, int v){

	ListaFuncionario* p;
	for (p=lst; p!=NULL; p = p->prox) {
		if (acessa_mat_Func(p->no) == v)  //compara as matrículas
			return p->no;
    }
     printf("Valor nao encontrado na lista!\n");
    return NULL; /* não achou o elemento */
}

/* Função Remove - Remove um Funcionário da Lista */
ListaFuncionario* lista_remove(ListaFuncionario* list, int val){

ListaFuncionario* a = NULL; /* ponteiro para elemento anterior */
ListaFuncionario* p = list; /* ponteiro para percorrer a lista */

/* procura elemento na lista, guardando anterior */
while (p != NULL && acessa_mat_Func(p->no) != val) {
	a = p;
	p = p->prox;
}
/* verifica se achou elemento */
if (p == NULL){

   printf("\nValor nao encontrado na lista!\n");
   return list; /* não achou: retorna lista original */

}
/* retira elemento */
if (a == NULL)
{ /* retira elemento do inicio */
     list = p->prox;
	 printf("\nFuncionario Removido com sucesso!\n");
 }
else { /* retira elemento do meio da lista */

     a->prox = p->prox;
     printf("\nFuncionario Removido com sucesso!\n\n\n");
}
   free(p);
   return list;

}

/* Função Imprime - Imprime uma Lista de Funcionários*/
void lista_imprime (ListaFuncionario* list){

	if(list!=NULL){

	ListaFuncionario* p;
	for (p = list; p != NULL; p = p->prox)
	       imprime_Func(p->no);

	}else printf("A lista está vazia!\n");
}

ListaFuncionario* lista_libera (ListaFuncionario* list){

	ListaFuncionario* p = list;
  while (p != NULL) {
     ListaFuncionario* t = p->prox;   /* guarda referência p/ próx. elemento */
     free(p); /* libera a memória apontada por p */
     p = t; /* faz p apontar para o próximo */
     }
     return NULL;
}
