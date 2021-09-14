#ifndef ITEM_H
#define ITEM_H

typedef struct item Item;

/*
*  Ira verificar qual item tem o maior peso
*  inputs: Dois ponteiros para itens
*  output: O maior peso entre eles
*  pre-condicao: Itens devem existir
*  pos-condicao: Os itens não são alterados
*/
int moreItem(Item* A, Item* B);

/*
*  Ira inicializar a estrutura item
*  inputs: Um inteiro que representa o tamanho do vetor de itens
*  output: Um ponteiro duplo para a estrutura item
*  pre-condicao: -
*  pos-condicao: O vetor de item deve estar criado
*/
Item** initItem(int t);

/*
*  Ira criar um item
*  inputs: Um double representando o peso e um inteiro representando o id
*  output: Um ponteiro para item
*  pre-condicao: -
*  pos-condicao: O item será criado
*/
Item* createItem(double peso, int id);

/*
*  Retorna o peso do item
*  inputs: Um ponteiro para item
*  output: O peso do item
*  pre-condicao: Item deve existir
*  pos-condicao: O Item não é alterado
*/
double getWeightItem(Item* i);

/*
*  Retorna o id do item
*  inputs: Um ponteiro para item
*  output: O id do item
*  pre-condicao: Item deve existir
*  pos-condicao: O Item não é alterado
*/
int getIdItem(Item* i);

/*
*  Imprime um item
*  inputs: Um ponteiro para item
*  output: -
*  pre-condicao: Item deve existir
*  pos-condicao: O Item não é alterado
*/
void printItem(Item* i);

/*
*  Altera o peso do item
*  inputs: Um ponteiro para item e o novo valor do peso
*  output: -
*  pre-condicao: Item deve existir
*  pos-condicao: O peso do item estará alterado
*/
void setWeightItem(Item* i, double peso);

/*
*  Libera a memória do vetor de itens
*  inputs: Um ponteiro para vetor de itens e o tamanho do vetor
*  output: -
*  pre-condicao: O vetor de itens deve existir
*  pos-condicao: O vetor será apagado
*/
void destroyItem(Item** item, int t);

#endif
