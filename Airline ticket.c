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
void Asientos_disponibles();
void regresar_menu();
void disponiblidad();

void clearscreen(){ 
  system("@cls||clear");
}

int get_index(){
    for(int f = 0; f <= num_vuelos; f++){
        int compare = strncmp(arr_boletos[f].id, "", 9);
        
        if(compare == 0){
            return f;
        }
    }
    
    return 0;
}
int Buscar_boleto_reserva(char bordingpass[9]){
 for(int i = 0; i <= num_vuelos; i++){
        int compare = strncmp(arr_boletos[i].id, bordingpass, 9);
        
        if(compare == 0){
            return 1;
        }
    }
    
    return 0;
}
void Reservas (){
Asientos_disponibles();
char asiento_deseado[3];
int indice = get_index(); 
char boardingpass[9]; 
int opcion;
printf("\n");
printf ("Ingrese el asiento que desea reservar:");
scanf("%s", asiento_deseado); 
sprintf(boardingpass, "%s-%s", numero_vuelo, asiento_deseado);
int search = Buscar_boleto_reserva(boardingpass);
if (search == 0){
 strcpy(arr_boletos[indice].id, boardingpass);
clearscreen();
printf("Asiento %s reservado EXITOSAMENTE!\n", asiento_deseado);
printf("Ingrese 0 si desea regresar al menu.\n");
scanf("%d", &opcion);
switch (opcion)
case 0:
menu();

}else{
clearscreen();
printf("Este aciento ya ha sido RESERVADO\n");
printf("Ingrese 0 si desea regresar al menu.\n");
scanf("%d", &opcion);
switch (opcion)
case 0:
menu();
}
}

int Buscar_boleto(char columna[1], int fila){
 for(int i = 0; i <= num_vuelos; i++){
        char buffer[32];
        
        sprintf(buffer,"%s-%s%d", numero_vuelo, columna, fila);
        int compare = strncmp(arr_boletos[i].id, buffer, 9);
        
        if(compare == 0){
            return 1;
        }
    }
    
    return 0;
}


void Asientos_disponibles(){
  int opcion;
  char enter;
 char  Matriz_asientos[COLS][ROWS];
 printf("|    | A | B | C | D | E | F |\n");
 printf("------------------------------\n");
for (int r = 1; r <= ROWS; r++){
   char fila[32];
for (int c = 0; c <= COLS; c++){
  if(c == 0){
  if(r < 10){
    sprintf(fila, "| %s%d%s|", " ",r, " ");
    } else{ 
    sprintf(fila, "|%s%d%s|", " ", r, " ");
    }
  }else{
    int buscado = Buscar_boleto(letras[c - 1], r);
  if(buscado == 1) {
    sprintf(fila, "%s X |", fila);
  }else{
    sprintf(fila, "%s 0 |", fila);
         }
        }
      }    
    sprintf(fila, "%s\n", fila);
    printf("%s", fila);
  }
}

void disponibilidad(){
  int opcion; 
  Asientos_disponibles();
  printf("Ingrese 0 si desea regresar al menu.\n");
scanf("%d", &opcion);
switch (opcion)
case 0:
menu();
}


void Resumen(){
int opcion;
  clearscreen();
int reservados = get_index();
int libres =(192- get_index());
float porcentaje_ocupado=(reservados/192)*100;
float porcentaje_libres = (libres/192)*100;
printf ("##RESUMEN\n");
printf("Reservados:%f", porcentaje_ocupado);
printf(" \n");
printf("Libres:%f", porcentaje_libres);
printf(" \n");
printf("Si desea regresar al menu principal, presione 0. \n");
scanf("%d",&opcion);
  switch (opcion)
case 0:
menu();
}


void Salir (){
int opcion;
  clearscreen();
printf("Si desea regresar al menu principal, presione 0. \n");
scanf("%d",&opcion);
  switch (opcion)
case 0:
menu();
}
  
void menu2 (){
  char pais_salida[8];
  char pais_destino[8];

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
  
}


void menu(){
  int opcion; 
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
  clearscreen();
     Reservas();
     break;
  case 2:
  clearscreen();
     disponibilidad();
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
menu2();
menu();

return 0;

}
