#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define maxi 64

// definicion de un proceso

typedef struct{
	char *prioridad;
	char *rafaga;
	char *Tllegada;
	char *bloqueado;//tiempo en que se bloquea
	char *tbloqueado;
	char nombre;
	
		
	}Proc;
	
int Nproc;
int Quantum;
int contador;
char *token;
char *tempo;
char *temp;
Proc llegada[100];
Proc proceso[100];
int i=0;



// este metodo le pide al usuario
// los datos necesarios para ejecutar el algoritmo





int llenar_Procesos(){
	token= (char *) malloc(20);
    tempo= (char *) malloc(20);
     
printf ("Ingrese el numero de procesos a realizar \n");
scanf("%i",&Nproc);
printf ("Ingrese el Quantum \n");
scanf ("%i",&Quantum);
printf("El numero de procesos es:%d", Nproc);
printf("\n");

for ( i = 0; i< Nproc ; i++){

printf("Ingrese datos del proceso [prioridad],[rafaga],[tiempo llegada],[tiempo en que se bloquea],[tiempo bloqueado]\n");
scanf("%s",tempo);
token= strtok(tempo,",");
contador=0;

while (token != NULL){
	proceso[i].prioridad= (char *) malloc(20);
	proceso[i].rafaga= (char *) malloc(20);
	proceso[i].Tllegada= (char *) malloc(20);
	proceso[i].bloqueado= (char *) malloc(20);
	proceso[i].Tllegada= (char *) malloc(20);
	
        	
	if( contador == 0 )
             {
              proceso[i].prioridad=token;
             // printf(" prioridad: %s ",proceso[i].prioridad); 
                              
             }    
             else if ( contador == 1 )
             {
               proceso[i].rafaga=token;
              //printf("  rafaga:  %s",proceso[i].rafaga); 
                              

             }
             else if( contador == 2 )
             {
               proceso[i].Tllegada=token;
              //printf("  tiempo de llegada: %s",proceso[i].Tllegada); 
                             

             } 
              else if( contador == 3 )
             {
               proceso[i].bloqueado=token;
              //printf("  tiempo de llegada: %s",proceso[i].bloqueado); 
                             

             }
              else if( contador == 4 )
             {
               proceso[i].tbloqueado=token;
              //printf("  tiempo de llegada: %s",proceso[i].tbloqueado); 
                             

             }                
                     
            
              token= strtok(NULL,",");
              
             contador++;
	
	
	}


	}
	//imprimamos los procesos para probar
	int i=0;
	for ( i = 0; i< Nproc ; i++){
		printf(" prioridad: %s ",proceso[i].prioridad); 
		printf("  rafaga:  %s",proceso[i].rafaga); 
		printf("  tiempo de llegada: %s",proceso[i].Tllegada); 
		printf("  tiempo de bloqueado: %s",proceso[i].bloqueado); 
		printf("  tiempo de duracion  bloqueado: %s\n",proceso[i].tbloqueado); 
		printf("  Termina el proceso %d \n",i);
	}
	
	
		
	//empiezan las colas
	  temp= (char *) malloc(20);
	  i=0;
	//llenamos la cola de llegada
	for ( i = 0; i< Nproc ; i++){
		temp= proceso[i].Tllegada ;
		printf("\n temporal %s \n", proceso[i].Tllegada);
		
		if(temp<proceso[i+1].Tllegada){
			llegada[i]=proceso[i];
			
			}
			else{
				llegada[i]=proceso[i+1];
				
				}
				printf(" prioridad: %s /n",llegada[i].prioridad); 
		
						}
	
		
	return 0;
	}
	
	int main(){
		llenar_Procesos();
		
		return 0;
		}

