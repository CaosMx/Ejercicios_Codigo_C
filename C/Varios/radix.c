/*
* RadixSort para Análisis de Algoritmos
* CaosMx
* 27 Dic 2017
 */

#include <stdio.h>
#include <math.h>
#define NUMELTS 20 //NOmbre estructura y capacidad máxima de ints

void radixsort(int x[], int n){ 
/*Estructura radix*/
  struct {
    int info;
    int next;
  } node[NUMELTS];


  int exp, first, i, j, k, p, q, y;

  /* Inicializar una lista viculada */
  for (i = 0; i < n-1; i++) {
    node[i].info = x[i];
    node[i].next = i+1;
  } 

  node[n-1].info = x[n-1];
  node[n-1].next = -1;
  first = 0; /*first es la cabeza de la lista vinculada */

  for (k = 1; k < 5; k++) {
    /* Suponer que tenemos números de cuatro dígitos */
    for (i = 0; i < 10; i++) {
      /*Inicializar colas */
      rear[i] = -1;
      front[i] = -1;
    }
    /* Procesar cada elemento en la lista */
    while (first != -1) {
      p = first;
      first = node[first].next;
      y = node[p].info;

      /* Extraer el késimo dígito */
      exp = pow(10, k-1);	/* elevar 10 a la (k-1)ésima potencia */
      j = (y/exp) % 10;

      /* Insertar y en encolar[j] */
      q = rear[j];
      if (q == -1)
	front[j] = p;
      else
	node[q].next = p;
      rear[j] = p;
    }//while first !=-1

    /* En este punto, cada registro está  en su cola basándose en el digito k
       Ahora formar una lista única de todos los elementos de la cola. Encontrar
       el primer elemento. */
    for (j = 0; j < 10 && front[j] == -1; j++);
      ;
    first = front[j];

    /* Vincular las colas restantes */
    while (j <= 9) { 	/*Verificar si se ha terminado */
      /*Encontrar el elemento siguiente */
      for (i = j+1; i < 10 && front[i] == -1; i++);
	;
      if (i <= 9) {
	p = i;
	node[rear[j]].next = front[i];
      } /* fin del if */
      j = i;
    } //while j<9
    node[rear[p]].next = -1;
  } //for k<5


  /* Copianndo de regreso al archivo original */
  for (i = 0; i < n; i++) {
    x[i] = node[first].info;
    first = node[first].next;
  } 

} //radixsort


int main(void){
  int x[50] = {NULL}, i;
  static int n;

  printf("\nCadena de numeros enteros a ordenar: \n");

  for (n = 0;; n++)
    if (!scanf("%d", &x[n])) break;
  if (n)
    radixsort (x, n);
  for (i = 0; i < n; i++)
    printf("%d ", x[i]);
  return 0;
}//main
