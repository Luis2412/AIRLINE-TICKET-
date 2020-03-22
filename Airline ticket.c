#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 32
#define COLS 6
char matriz_boletos[192];
char *letras[] = {"A","B","C","D","E","F"};
char numero_vuelo[5];

void menu();

void clearscreen(){ 
  system("@cls||clear");
}

void Reservas (){
int Buscar_boleto(char columna[1], int fila){
  int encontrado = 0;
  for (int asientos = 0 ; asientos < 192; asientos++){
    char buffer[8];
    sprintf(buffer,"%s-%s%d", numero_vuelo, columna, fila);
    char boleto[8] = matriz_boletos[asientos];
    if (boleto == buffer){
      encontrado = 1;
    }
  }
  return encontrado;
}  
  
}

void Asientos_disponibles(){
  clearscreen();
 char  Matriz_asientos[COLS][ROWS];
 printf("|    | A | B | C | D | E | F |");
 printf("-----------------------------");
 for (int c = 0; c <= COLS; c++){
   for (int r = 1; r <= ROWS; r++){
     if(c>0){
      if (Buscar_boleto(*letras[c], r)){
     printf(" X ");
        } else {
          printf(" 0 " );
        }
     }
     else{ 
       if(r < 10){
         printf("  "+ r + " " );
       } else{ 
         printf(" " + r + " " );
       }
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

void menu(){
  int opcion;
  char pais_salida[10];
  char pais_destino[10];
  char numero_vuelo[10];

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
printf("|___________GUATEMALA AIRLINES____________|\n");
printf("|         1) Reservar Asiento            |\n");
printf("|         2) Ver Disponibilidad          |\n");
printf("|         3) Ver Resumen                 |\n");  
printf("|         3) Salir                       |\n");     
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
