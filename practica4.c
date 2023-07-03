#include <stdio.h>

//Conversor de divisas

int main(){
    float euros;
    printf("Itroduzca los euros que quieres convertir \n");
    scanf("%f", &euros);

    printf("%.2f euros equivalen a %.2f pesetas", euros, euros*166.386);
}