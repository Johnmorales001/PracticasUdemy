#include <stdio.h>

//area de un rectangulo

int main(){
    float base, altura;
    printf("Introduzca la base del rectangulo \n");
    scanf("%f", &base);
    printf("Introduzca la altura del rectangulo \n");
    scanf("%f",&altura);
    float area = base * altura;

    printf("El area del rectangulo de base %.2f y altura %.2f es: %.2f", base, altura, area);
}