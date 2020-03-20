#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearscreen(){ 
  system("@cls||clear");
}

void Reservas (){

}

void Disponibilidad (){

}

void Salir (){

}

void menu(){
  int opcion; 
  clearscreen();
printf(" _________________________________________\n");
printf("|___________GUATEMALA AIRLINES____________|\n");
printf("|         1) Reservar Asiento            |\n");
printf("|         2) Ver Disponibilidad          |\n");
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
     Disponibilidad();
     break;  
  case 3:
     Salir(); 
     break;  
   
}
}
int main(){
menu();

return 0;

}
