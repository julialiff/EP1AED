#include "FilaDePrioridade.c"

int main() {
  PFILA f = criarFila(10);
  exibirLog(f);

  printf("-------inserir id: 1, prioridade: 1-------\n");
  if(inserirElemento(f, 1, 1)) printf("ok\n");
  else printf("nok (1)\n");

  printf("\nTAMANHO: %i\n", tamanho(f));

  printf("-------inserir id: 3, prioridade: 3-------\n");
  if(inserirElemento(f, 3, 3)) printf("ok\n");
  else printf("nok (2)\n");
  exibirLog(f);

  printf("\nTAMANHO: %i\n", tamanho(f));
  if(inserirElemento(f, 2, 2)) printf("ok\n");
  else printf("nok (3)\n");
  exibirLog(f);


  // if(inserirElemento(f, 0, 0)) printf("ok\n");
  // else printf("nok (4)\n");
  // exibirLog(f);

  // printf("INSERIR ELEMENTO 5,5\n");

  if(inserirElemento(f, 5, 5)) printf("ok\n");
  else printf("nok (5)\n");
  exibirLog(f);

  if(inserirElemento(f, 8, 8)) printf("ok\n");
  else printf("nok (7)\n");
  exibirLog(f);

  if(inserirElemento(f, 6, 6)) printf("ok\n");
  else printf("nok (6)\n");
  exibirLog(f);

  PONT percorre = f->fila;
  printf("primeiro elem: %p, id %i prioridade %f\n\n", f->fila, f->fila->id, f->fila->prioridade);
  while(percorre){
    printf("end: %p\n", percorre);
    printf("id: %i\n", percorre->id);
    printf("prioridade: %f\n", percorre->prioridade);
    printf("ant: %p\n", percorre->ant);
    printf("prox: %p\n\n\n", percorre->prox);
    percorre = percorre->prox;
  }
  // int tam = tamanho(f);
  // printf("TAMANHO: %i\n",tam);
  // float resposta;
  // if (consultarPrioridade(f, 0, &resposta)) printf("ok\n");
  // else printf("notok\n");

  // printf("\n\n\n\n");
  // printf("RESPOSTA CONSULTA DE PRIORIDADE AO ELEMENTO: %f\n", resposta);
  // printf("\n\n\n\n");
  //   while(percorre){
  //   printf("end: %p\n", percorre);
  //   printf("id: %i\n", percorre->id);
  //   printf("prioridade: %f\n", percorre->prioridade);
  //   printf("ant: %p\n", percorre->ant);
  //   printf("prox: %p\n\n\n", percorre->prox);
  //   percorre = percorre->ant;
  // }

  // printf("------AUMENTAR PRIORIDADE elemento 5 prioridade 10----------\n");
  // if(aumentarPrioridade(f, 5, 10)) printf("ok\n");
  // else printf("nok (6)\n");
  // exibirLog(f);
  // printf("------AUMENTAR PRIORIDADE elemento 0 prioridade 15----------\n");
  // if(aumentarPrioridade(f, 0, 15)) printf("ok\n");
  // else printf("nok (7)\n");
  // exibirLog(f);
  // printf("------AUMENTAR PRIORIDADE elemento 3 prioridade 4----------\n");
  // if(aumentarPrioridade(f, 3, 4)) printf("ok\n");
  // else printf("nok (8)\n");
  // exibirLog(f);
  // printf("------AUMENTAR PRIORIDADE elemento 3 prioridade 4----------\n");
  // if(aumentarPrioridade(f, 3, 4)) printf("ok\n");
  // else printf("nok (9) - esperado, pois a nova prioridade nao eh maior\n");
  // exibirLog(f);
  // printf("------AUMENTAR PRIORIDADE elemento 4 prioridade 4----------\n");
  // if(aumentarPrioridade(f, 4, 4)) printf("ok\n");
  // else printf("nok (10) - esperado, elemento com id=4 nao existe\n");
  // exibirLog(f);


  // PONT prioritario;
  // prioritario = removerElemento(f);
  // if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  // else printf("Fila vazia (1)\n");
  // exibirLog(f);
  // prioritario = removerElemento(f);
  // if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  // else printf("Fila vazia (2)\n");
  // exibirLog(f);
  // prioritario = removerElemento(f);
  // if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  // else printf("Fila vazia (3)\n");
  // exibirLog(f);
  // prioritario = removerElemento(f);
  // if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  // else printf("Fila vazia (4)\n");
  // exibirLog(f);
  // prioritario = removerElemento(f);
  // if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  // else printf("Fila vazia (5)\n");
  // exibirLog(f);
  // prioritario = removerElemento(f);
  // if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  // else printf("Fila vazia (6)\n");
  // exibirLog(f);
  // prioritario = removerElemento(f);
  // if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  // else printf("Fila vazia (7)\n");
  // exibirLog(f);

  // if(inserirElemento(f, 1, 1)) printf("ok\n");
  // else printf("nok (10)\n");
  // exibirLog(f);
  // if(inserirElemento(f, 3, 3)) printf("ok\n");
  // else printf("nok (11)\n");
  // exibirLog(f);
  // if(inserirElemento(f, 2, 2)) printf("ok\n");
  // else printf("nok (12)\n");
  // exibirLog(f);
  // if(inserirElemento(f, 0, 0.5)) printf("ok\n");
  // else printf("nok (13)\n");
  // exibirLog(f);
  // if(inserirElemento(f, 5, 5)) printf("ok\n");
  // else printf("nok (14)\n");
  // exibirLog(f);

  // printf("\n\nReduzindo prioridade\n");


  printf("----diminuir prioridade id: 8 prioridade 4-----\n");
  if(reduzirPrioridade(f, 8, 0)) printf("ok\n");
  else printf("nok (15)\n");
  exibirLog(f);

  printf("----diminuir prioridade id: 0 prioridade 1-----\n");
  if(reduzirPrioridade(f, 0, 1)) printf("ok\n");
  else printf("nok (16) - esperado, nova prioridade eh maior\n");
  exibirLog(f);
  printf("----diminuir prioridade id: 3 prioridade 2-----\n");
  if(reduzirPrioridade(f, 3, 2)) printf("ok\n");
  else printf("nok (17)\n");
  exibirLog(f);
  printf("----diminuir prioridade id: 3 prioridade 2-----\n");
  if(reduzirPrioridade(f, 3, 2)) printf("ok\n");
  else printf("nok (18) - esperado, nova prioridade eh igual\n");
  exibirLog(f);
  printf("----diminuir prioridade id: 4 prioridade 1-----\n");
  if(reduzirPrioridade(f, 4, 1)) printf("ok\n");
  else printf("nok (19) - esperado, elemento com id=4 nao existe\n");
  exibirLog(f);

  printf("\n\n\n");
  percorre = f->fila;
  while(percorre){
    printf("end: %p\n", percorre);
    printf("id: %i\n", percorre->id);
    printf("prioridade: %f\n", percorre->prioridade);
    printf("ant: %p\n", percorre->ant);
    printf("prox: %p\n\n\n", percorre->prox);
    percorre = percorre->prox;
  }


  return 0;
}
