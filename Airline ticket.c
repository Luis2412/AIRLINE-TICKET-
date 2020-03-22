#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//macros
#define ROWS 32
#define COLS 6
#define num_vuelos 191

struct boleto {
  char id[9];
};
struct boleto
  arr_boletos[num_vuelos];

char *letras[] = {"A","B","C","D","E","F"};
char numero_vuelo[5];

void menu();

void clearscreen(){ 
  system("@cls||clear");
}

void Reservas (){

}

int Buscar_boleto(char columna[1], int fila){
 for(int i = 0; i <= num_vuelos; i++){
        char buffer[9];
        
        sprintf(buffer,"%s-%s%d", numero_vuelo, columna, fila);
        int compare = strncmp(arr_boletos[i].id, buffer, 9);
        
        if(compare == 0){
            return 1;
        }
    }
    
    return 0;
}

void Asientos_disponibles(){
  clearscreen();
 char  Matriz_asientos[COLS][ROWS];
 printf("|    | A | B | C | D | E | F |");
 printf("-----------------------------");
 for (int c = 0; c <= COLS; c++){
   for (int r = 1; r <= ROWS; r++){
     if(c>0){
      if (Buscar_boleto(letras[c], r)==1){
     printf(" X ");
        } else {
          printf(" 0 ");
        }
     }
     else{ 
       char con[4];
       if(r < 10){
         sprintf(con,"  %d ",r);
       } else{ 
          sprintf(con," %d ",r);
       }
         printf(con);
     }
   }
 }
 
}

  



void Resumen(){

}

void Salir (){
int opcion;
  clearscreen();
printf("Presione 0 para salir y 1 para regresar a la pantalla de inicio.\n");
scanf("%d",&opcion);

switch(opcion){
  case 0:
     exit (0);
     break;
  case 1:
     menu();
     break;   
}
}

//arreglar disponibilidad (matriz)
//arreglar la opcion de numero de vuelo
//agregar la funcion a la matriz y a la funcion de reserva de asientos
  


void menu(){
  int opcion; 
  char pais_salida[10];
  char pais_destino[10];
  

  clearscreen();
  printf("Complete los siguientes espacios en blanco \n");
  printf("\n");
  printf("Pais de salida: ");
  scanf("%s", pais_salida);
  printf("Pais de destino: ");
  scanf("%s", pais_destino);
  printf("Numero de vuelo: ");
  scanf("%s",numero_vuelo);
  printf(" \n");

  clearscreen();
  printf(" \n");
printf("NUMERO DE VUELO: %s",numero_vuelo);
printf(" \n");
printf(" _________________________________________\n");
printf("|___________GUATEMALA AIRLINES___________|\n");
printf("|         1) Reservar Asiento            |\n");
printf("|         2) Ver Disponibilidad          |\n");
printf("|         3) Ver Resumen                 |\n");
printf("|         4) Salir                       |\n");    
printf("|________________________________________|\n");
printf("\n\n");
printf("Ingrese la opcion que desea. \n");
scanf("%d",&opcion);
switch(opcion){
  case 1:
     Reservas();
     break;
  case 2:
     Asientos_disponibles();
     break;  
  case 3:
     Resumen(); 
     break; 
  case 4:
     Salir(); 
     break;   
}
}
int main(){
menu();

return 0;

}














