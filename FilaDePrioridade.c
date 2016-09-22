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
  if(tamanho(f)>=2){
    PONT segundo = f->fila->prox;
    if(segundo->prox==NULL){
      printf("\nVERDADE PORRA\n");
    }
    printf("%p \n", segundo->prox);
  }
  PONT percorreFila = f->fila;

  while(percorreFila!=NULL){ //verifica se o id já existe na fila
    printf("id: %i\n", id);
    printf("PERCORRE FILA %p \n", f->fila->prox);
    if(f->fila->id==id){
      return false;
    }
    percorreFila = percorreFila->prox;
  }

  f->arranjo[id] = elem; //se id nao existe na fila ainda, ele eh adicionado ao arranjo
  printf("prioridade atual: %f\n" ,prioridade);
  printf("prioridade do 1: %f\n" , f->fila->prioridade);
  if(prioridade > f->fila->prioridade){ //se a prioridade do elemento sendo inserido agora eh maior que a prioridade do primeiro elemento da fila, ele vira o começo da fila
    f->arranjo[id]->prox = f->fila;
    f->fila->ant = f->arranjo[id];
    f->fila = f->arranjo[id];
    return true;
  }

  percorreFila = f->fila;
  PONT ultimo = NULL;

  printf("--------------------------------\n");
  printf("\nPRIORIDADE 1 fila %f\n",f->fila->prioridade);
  printf("\nPRIORIDADE atual %f\n",prioridade);
  //inserir entre elementos
  while(percorreFila){
    printf("%f\n",percorreFila->prioridade);
    if(prioridade > percorreFila->prioridade){//se a prioridade do elemento sendo inserido agora eh maior que alguma prioridade, sera inserido antes dela
      printf("entrou no if\n");
      f->arranjo[id]->prox = percorreFila;
      printf("arranjo: %i percorre fila: %i\n",f->arranjo[id]->id, percorreFila->id);

      f->arranjo[id]->ant = percorreFila->ant;
      percorreFila->ant->prox = f->arranjo[id];
      percorreFila->ant = f->arranjo[id];

      printf("\n #%i#\nok", f->arranjo[id]->id);
      printf("\n #%i#\n", percorreFila->ant->id);
      percorreFila->ant = f->arranjo[id];
      return true;
    }
    printf("PERCORRE FILA PROX: %p\n",percorreFila->prox); //inserir no fim
    if(!percorreFila->prox){
      printf("ULTIMO: %p\n",percorreFila); //inserir no fim
      ultimo = percorreFila;
    }
    percorreFila = percorreFila->prox;
  }
  printf("\n----------------INSERIR NO FIM------------------\n"); //inserir no fim
  if(ultimo){
    ultimo->prox = f->arranjo[id];
    f->arranjo[id]->ant = ultimo;
    printf("%f\n",ultimo->prioridade); //inserir no fim
  }
  // printf("%f\n",percorreFila->ant->prioridade); //inserir no fim
  //   if(percorreFila->ant!=NULL){
  //     f->arranjo[id]->ant = percorreFila->ant;
  //     percorreFila->ant->prox = f->arranjo[id];
  //   }
  //   percorreFila->ant = f->arranjo[id];
  // return true;

  printf("--------------------------------\n");
  return false;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  if (id < 0 || id >= f->maxRegistros) return false;
  if(f->arranjo[id]==NULL) return false;
  if(f->arranjo[id]->prioridade >= novaPrioridade) return false;

  PONT elem = f->arranjo[id];
  elem->prioridade = novaPrioridade;

  if(elem->prox && elem->ant){
    printf("tem prox e ant\n");
    elem->prox->ant = elem->ant;
    elem->ant->prox = elem->prox;
  }
  if(elem->prox && !elem->ant){
    printf("tem prox e não ant\n");
    return true;
  }
  if(elem->ant && !elem->prox){
    printf("tem ant e não prox\n");
    elem->ant->prox = NULL;
  }

  // PONT proximo = NULL;
  // PONT anterior = NULL;
  // if(elem->prox) proximo = elem->prox;
  // if(elem->ant) anterior = elem->ant;
  // anterior->prox = proximo;
  // proximo->ant = anterior;

  // printf("elem id: %i prioridade %f\n", elem->id, elem->prioridade);
  // printf("prox id: %i prioridade %f\n", proximo->id, proximo->prioridade);
  // printf("ant  id: %i prioridade %f\n", anterior->id, anterior->prioridade);

  printf("elem->prioridade: %f f->fila->prioridade%f\n", elem->prioridade, f->fila->prioridade);
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
      printf("o item %i tem prioridade %f\n", percorreFila->id, percorreFila->prioridade);
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
  if(f->arranjo[id]==NULL) return false;
  if(f->arranjo[id]->prioridade <= novaPrioridade) return false;
  return false;
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
  if(id<0 || id >= f->maxRegistros) return false;
  if(f->arranjo[id]){
    printf("%p\n",&f->arranjo[id]->prioridade);
    resposta = &f->arranjo[id]->prioridade;
    printf("%p\n", &resposta);
    return true;
  }
  else{
    return false;
  }
}
