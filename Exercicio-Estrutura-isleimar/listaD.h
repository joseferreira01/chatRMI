/*Arquivo lista.h
**cabeçalho de funções de lista encadeada
*/
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*Bibliotecas necessárias para o
**funcionamento
*/
#include <stdio.h>
#include <stdlib.h>

/*Declaração do tipo do nodo*/
typedef struct nodo_Lista{
    struct nodo_Lista *anterior;
    struct valores *valor;
    struct nodo_Lista *proximo;
}Nodo_Lista;

/*Declaração da estrutura de lista*/
typedef struct lista{
    struct nodo_Lista *primeiro;
    struct nodo_Lista *ultimo;
} Lista;

/*tipo de variavel de valores*/
typedef struct valores Valores;

/*Cria uma lista vazia */
Lista *cria_Lista(void);

/*Tamanho da lista*/
long int tamanho_Lista(Lista *_lista);

/*Posição da lista*/
Nodo_Lista *posicao_Lista(Lista *_lista, long int _posicao);

/*Permuta a posição entre dois valores na lista
Retorna 1 para sucesso e 0 para fracasso*/
int permutar_Lista(Lista *_lista, long int _origem, long int _destino);

/*Insere um novo valor na lista e
**Retorna o início da lista*/
void insere_Lista(Lista *_lista, Valores *_valor, long int _posicao);


/*Excluir dados na lista*/
void exclui_Lista(Lista *_lista, long int _posicao);

/*Esvazia todos os dados da lista*/
void esvazia_Lista(Lista *_lista);

/*Retorna dados da posição específica*/
Valores *valor_Lista(Lista *_lista, long int _posicao);

#endif // LISTA_H_INCLUDED
