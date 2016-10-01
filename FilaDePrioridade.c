#include "FilaDePrioridade.h"

PFILA criarFila(int max){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxRegistros = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) res->arranjo[i] = NULL;
  res->fila = NULL;
  return res;
}

bool exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", tamanho(f));
  PONT atual = f->fila;
  while (atual){
    printf("%p[%i;%f;%p]%p ", atual->ant, atual->id, atual->prioridade, atual, atual->prox);
    atual = atual->prox;
  }
  printf("\n\n");
}

int tamanho(PFILA f){
  int i = 0;
  if(f->fila==NULL){
    return i;
  }
  PONT fila = f->fila;
  while(fila){
    i++;
    fila = fila->prox;
  }
  return i;
}

bool inserirElemento(PFILA f, int id, float prioridade){
  if(id<0 || id>=f->maxRegistros) return false; //se id é invalido, return false
  PONT elem = (PONT) malloc(sizeof(PONT)); // cria um elemento do tipo PONT
  elem->id = id;
  elem->prioridade = prioridade;
  elem->ant = NULL;
  elem->prox = NULL;
  if(f->fila == NULL){ //Se eh o primeiro elemento
    f->arranjo[id] = elem;
    f->fila = f->arranjo[id];
    return true;
  }
  PONT percorreFila = f->fila;

  while(percorreFila){ //verifica se o id já existe na fila
    if(f->fila->id==id){
      return false;
    }
    percorreFila = percorreFila->prox;
  }

  f->arranjo[id] = elem; //se id nao existe na fila ainda, ele eh adicionado ao arranjo
  if(prioridade > f->fila->prioridade){ //se a prioridade do elemento sendo inserido agora eh maior que a prioridade do primeiro elemento da fila, ele vira o começo da fila
    f->arranjo[id]->prox = f->fila;
    f->fila->ant = f->arranjo[id];
    f->fila = f->arranjo[id];
    return true;
  }

  percorreFila = f->fila;
  PONT ultimo = NULL;


  while(percorreFila){ //inserir entre elementos
    if(prioridade > percorreFila->prioridade){//se a prioridade do elemento sendo inserido agora eh maior que alguma prioridade, sera inserido antes dela
      f->arranjo[id]->prox = percorreFila;
      f->arranjo[id]->ant = percorreFila->ant;
      percorreFila->ant->prox = f->arranjo[id];
      percorreFila->ant = f->arranjo[id];

      percorreFila->ant = f->arranjo[id];
      return true;
    }
    if(!percorreFila->prox){
      ultimo = percorreFila;
    }
    percorreFila = percorreFila->prox;
  }
  if(ultimo){
    ultimo->prox = f->arranjo[id];
    f->arranjo[id]->ant = ultimo;
    printf("%f\n",ultimo->prioridade); //inserir no fim
  }
  return false;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  if (id < 0 || id >= f->maxRegistros) return false;
  if(f->arranjo[id]==NULL) return false;
  if(f->arranjo[id]->prioridade >= novaPrioridade) return false;

  PONT elem = f->arranjo[id];
  elem->prioridade = novaPrioridade;

  if(elem->prox && elem->ant){
    elem->prox->ant = elem->ant;
    elem->ant->prox = elem->prox;
  }
  if(elem->prox && !elem->ant){
    return true;
  }
  if(elem->ant && !elem->prox){
    elem->ant->prox = NULL;
  }

  if(elem->prioridade > f->fila->prioridade){ //se eh o novo inicio de fila
    elem->ant = NULL;
    elem->prox = f->fila;
    f->fila = elem;
    return true;
  }

  PONT percorreFila = f->fila;
  PONT aux = NULL;
  while(percorreFila){
    if(percorreFila->prioridade < novaPrioridade){
      aux = percorreFila;
      break;
    }
    percorreFila = percorreFila->prox;
  }
  aux->ant->prox = elem;
  elem->prox = aux;
  elem->ant = aux->ant;
  aux->ant = elem;
  return true;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  if (id < 0 || id >= f->maxRegistros) return false;
  if(f->arranjo[id] == NULL) return false;
  if(f->arranjo[id]->prioridade <= novaPrioridade) return false;

  PONT elem = f->arranjo[id];
  elem->prioridade = novaPrioridade;
  if(elem->prox && elem->ant){ //se ele esta entre dois elementos
    elem->prox->ant = elem->ant;
    elem->ant->prox = elem->prox;
  }
  if(elem->prox && !elem->ant){ //se ele eh o primeiro
    if(elem->prox->prioridade < elem->prioridade){ //se a prioridade dele ainda é a maior, mesmo com redução, nao mexemos em quem eh o primeiro da fila
      return true;
    }
    f->fila = f->fila->prox;
    f->fila->ant = NULL;
  }
  if(elem->ant && !elem->prox){ //se ele eh o ultimo
    return true;
  }

  PONT percorreFila = f->fila;
  PONT aux = NULL;
  while(percorreFila){
    if(percorreFila->prioridade < novaPrioridade){
      aux = percorreFila;
      break;
    }
    if(percorreFila->prox == NULL){
      percorreFila->prox = elem;
      elem->ant = percorreFila;
      elem->prox = NULL;
      return true;
    }
    percorreFila = percorreFila->prox;
  }


  aux->ant->prox = elem;
  elem->prox = aux;
  elem->ant = aux->ant;
  aux->ant = elem;
  return true;
}

PONT removerElemento(PFILA f){
  if(f->fila==NULL) return NULL;
  PONT elem = f->fila;
  if(f->fila->prox){
    f->fila = f->fila->prox;
    f->fila->ant = NULL;
  }
  else{
    f->fila = NULL;
  }
  elem->prox = NULL;
  f->arranjo[elem->id] = NULL;
  return elem;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  if(id < 0 || id >= f->maxRegistros) return false;
  if(f->arranjo[id]){
    printf("%p\n",&f->arranjo[id]->prioridade);
    *resposta = f->arranjo[id]->prioridade;
    printf("%p\n", &resposta);
    return true;
  }
  else{
    return false;
  }
}
