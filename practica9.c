#include <stdio.h>

//numero de aprobados y suspensos

int main(){

    int n, contador_aprobados=0, contador_suspensos=0;
    float nota;

    printf("Introduzca el numero de alumnos \n");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        printf("Introduzca la nota del alumno %d \n", i);
        scanf("%f", &nota);
        
        if(nota>=5){
            contador_aprobados++;
        }
        else{
            contador_suspensos++;
        }
    }
    printf("El numero de alumnos aprobados es: %d y el de alumnos suspensos es %d \n", contador_aprobados, contador_suspensos);
}