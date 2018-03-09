#include "listaD.h"


void limpar_Memoria(Nodo_Lista *_nodo){
    /*if((_nodo->valor)!=NULL){
        free(_nodo->valor);
        _nodo->valor=NULL;
    }*/
    if((_nodo)!=NULL){
        free(_nodo);
        _nodo=NULL;
    }
}

Lista *cria_Lista(void)
{
    Lista *aux=(Lista*)malloc(sizeof(Lista));
    if(aux==NULL) return NULL;
    aux->primeiro=NULL;
    aux->ultimo=NULL;
    return aux;
}

long int tamanho_Lista(Lista *_lista)
{
    long int cont=0;
    Nodo_Lista *aux=_lista->primeiro;
    while(aux!=NULL){
        cont++;
        aux=aux->proximo;
    }
    return cont;
}

Nodo_Lista *posicao_Lista(Lista *_lista, long int _posicao)
{
    Nodo_Lista *aux=_lista->primeiro;
    long int cont=0;
    while ((aux!=NULL)&&(cont<_posicao)){
        cont ++;
        aux=aux->proximo;
    }
    if (cont!=_posicao) return NULL;
        else return aux;
}

int permutar_Lista(Lista *_lista, long int _origem, long int _destino)
{
    Nodo_Lista *o=posicao_Lista(_lista,_origem);
    Nodo_Lista *d=posicao_Lista(_lista,_destino);
    if ((o==NULL)||(d==NULL)) return 0;
    Valores *aux=o->valor;
    o->valor=d->valor;
    d->valor=aux;
    return 1;
}

void insere_Lista(Lista *_lista, Valores *_valor, long int _posicao)
{
    if(_lista==NULL)return;//Lista inválida
    Nodo_Lista *p=_lista->primeiro;
    Nodo_Lista *aux=(Nodo_Lista*)malloc(sizeof(Nodo_Lista));
    if (aux==NULL)return;//Não foi possível reservar a memoria
    aux->anterior=NULL;
    aux->proximo=NULL;
    aux->valor=_valor;
    if(p==NULL){
        _lista->primeiro=aux;
        return;//Lista vazia
    }
    Nodo_Lista *a=NULL;
    long int cont=0;
    while((p!=NULL)&&(cont<_posicao)){
        a=p;
        cont++;
        p=p->proximo;
    }
    if (a==NULL){
        aux->proximo=p;
        p->anterior=aux;
        _lista->primeiro=aux;
        return;//Início;
    }
    a->proximo=aux;
    aux->anterior=a;
    if(p==NULL)
        _lista->ultimo=aux;
    else{
        aux->proximo=p;
        p->anterior=aux;
    }
    return;//Inserido no meio
}

void exclui_Lista(Lista *_lista, long int _posicao)
{
    if(_lista==NULL)return;//Lista inválida
    Nodo_Lista *p=_lista->primeiro;
    Nodo_Lista *a=NULL;
    long int cont=0;
    while((p!=NULL)&&(cont<_posicao)){
        a=p;
        p=p->proximo;
        cont++;
    }
    if(p==NULL)return;//Lista vazia ou nodo não existe
    if (cont!=_posicao)return;//Posição não localizada
    Nodo_Lista *aux=p->proximo;
    if(a==NULL) _lista->primeiro=aux;
        else a->proximo=aux;
    if (aux!=NULL) aux->anterior=a;
        else _lista->ultimo=a;
    limpar_Memoria(p);
}

void esvazia_Lista(Lista *_lista)
{
    Nodo_Lista *aux=_lista->ultimo;
    Nodo_Lista *p;
    while(aux!=NULL){
        p=aux;
        aux=aux->anterior;
        limpar_Memoria(p);
    }
}

Valores *valor_Lista(Lista *_lista, long int _posicao)
{
    Nodo_Lista *aux=posicao_Lista(_lista,_posicao);
    if(aux==NULL) return NULL;
    return aux->valor;
}
