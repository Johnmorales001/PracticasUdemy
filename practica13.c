#include <stdio.h>

//habitaciones de un hotel

int main(){
    int informacion[3][4] = {{1,120,150,220}, {2,130,160,230},{3,100,120,200}};
    int suma_tem_baja = 0, suma_tem_media = 0, suma_tem_alta = 0;

    for (int i=0; i<3; i++){
        for (int j=1; j<4; j++){
            if (j == 1){
                suma_tem_baja = suma_tem_baja + informacion[i][j];
            }
            if (j == 2){
                suma_tem_media = suma_tem_media + informacion[i][j];
            }
             if (j == 3){
                suma_tem_alta = suma_tem_alta + informacion[i][j];
            }   
        }
    }
    float promedio_temp_baja = suma_tem_baja/3;
    float promedio_temp_media = suma_tem_media/3;
    float promedio_temp_alta = suma_tem_alta/3;

    printf("Promedio temperatura baja: %.2f\nPromedio temperatura media: %.2f\nPromedio temperatura media: %.2f\n", promedio_temp_baja, promedio_temp_media, promedio_temp_alta);
}