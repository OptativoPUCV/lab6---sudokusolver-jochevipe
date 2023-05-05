#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

  
  for(int i=0 ; i<9 ; i++){
    
    int filas[10] = {0};
    int columnas[10] = {0};
    int submatriz[10] = {0};
    
    for(int j=0 ; j<9 ; j++){

      if(n->sudo[i][j] != 0){
        if(filas[n->sudo[i][j]] == 1){
          return 0;
        }else{
          filas[n->sudo[i][j]] = 1;
        }
      }
      
      if(n->sudo[j][i] != 0){
        if(columnas[n->sudo[j][i]] == 1){
          return 0;
        }else{
          columnas[n->sudo[j][i]] = 1;
        }
      }

      int subI=3*(i/3) + (j/3) ;
      int subJ=3*(i%3) + (j%3) ;

      
      if(n->sudo[subI][subJ] != 0){
        if(submatriz[n->sudo[subI][subJ]] == 1){
          return 0;
        }else{
          submatriz[n->sudo[subI][subJ]] = 1;
        }
      }

    }
  }
  
  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();

  if(n->sudo[0][2] == 0){
    for(int i = 1 ; i<=9 ; i++){
  
      Node* aux = copy(n);
      aux->sudo[0][2] = i;
      
      pushBack(list,aux);
      
    }
  }
   return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/