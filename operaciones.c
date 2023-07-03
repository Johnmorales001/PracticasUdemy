#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"

int comprobarId(struct empleado empleados[100], int num_emp, int id);

void mostrarMenu(){
    printf("\nIntroduzca la opcion que desea realizar:\n");
    printf("1-Alta empleado\n");
    printf("2-Baja empleado\n");
    printf("3-Listar empleados\n");
    printf("4-Consultar datos empleado\n");
    printf("5-Modificar sueldo\n");
    printf("6-Modificar horas\n");
    printf("7-salir\n");
}             

void listarEmpleados(struct empleado empleados[100], int num_emp){
    printf("Listando los datos del empleado:\n");
    for(int i=0; i<num_emp; i++){
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Id del empleado: %d\n", empleados[i].id);
        printf("Sueldo: %.2f\n", empleados[i].sueldo);
        printf("Horas semanales: %d\n", empleados[i].horas);
        printf("\n");
    }
}

int alta(struct empleado empleados[100], int num_emp){
    int creado = 0;
    struct empleado emp;

    fflush(stdin);
    printf("Intruduzca nombres y apellidos\n");
    gets(emp.nombre);

    printf("Introduzca el Id del empleado\n");
    scanf("%d", &emp.id);

    printf("Introduzca el sueldo\n");
    scanf("%f", &emp.sueldo);

    printf("Intoduzca horas semanales trabajadas\n");
    scanf("%d", &emp.horas);

    int existe = comprobarId(empleados, num_emp, emp.id);
    if(num_emp < 100){
        if(existe == 0){
            empleados[num_emp] = emp;
            creado = 1;
        }
        else{
            printf("No se puede crear empleado. ID duplicado\n");
        }
    }
    else{
        printf("No se puede dar de alta al empleado. Cupo alcanzado\n");
    }
    return creado;
}

int baja(struct empleado empleados[100], int num_emp){
    int eliminado = 0;
    int id, indice;

    printf("Intruzca el Id del empleado a dar de baja\n");
    scanf("%d", &id);

    int existe = comprobarId(empleados, num_emp, id);

    if (existe == 1){
        for(int i=0; i<num_emp; i++){
            if (empleados[i].id == id){
                indice = i;
            }
        }
        for(int j = indice; j<num_emp-1; j++){
            empleados[j] = empleados[j+1];
        struct empleado aux;
        empleados[j+1] = aux;
        }
        eliminado = 1;
    }
    else{
        printf("No se puede dar de baja al empleado. ID no existe\n");
    }
    return eliminado;
}

void consultarDatosEmpleado(struct empleado empleados[100], int num_emp){
    int id;
    printf("Introduzca el Id del empleado cuyos datos quieras consultar\n");
    scanf("%d", &id);

    int existe = comprobarId(empleados, num_emp, id);
    if(existe ==1){
        for(int i=0; i<num_emp; i++){
            if(empleados[i].id == id){
                printf("Listando datos del empleado con id: %d\n", empleados[i].id);
                printf("Nombre: %s\n", empleados[i].nombre);
                printf("Sueldo: %.2f\n", empleados[i].sueldo);
                printf("Horas semanales: %d\n", empleados[i].horas);
            }
        }
    }
    else{
        printf("No se puede consultar los datos del empleado. Id no existe\n");
    }
}

void modificarSueldo(struct empleado empleados[100], int num_emp){
    int id;

    printf("Intruduzca el Id del empleado cuyo sueldo quieres modificar\n");
    scanf("%d", &id);

    int existe = comprobarId(empleados, num_emp, id);

    if(existe == 1){
        float nuevo_sueldo;
        printf("Introduzca el nuevo sueldo del empleado\n");
        scanf("%f", &nuevo_sueldo);
        for (int i=0; i<num_emp; i++){
            if(empleados[i].id == id){
                empleados[i].sueldo = nuevo_sueldo;
                printf("Sueldo actualizado\n");
            }
        }
    }
    else{
        printf("No se puede modificar el sueldo del empleado. Id no existe\n");
    }
}

void modificarHoras(struct empleado empleados[100], int num_emp){
    int id;

    printf("Intruduzca el Id del empleado cuyas horas quieres modificar\n");
    scanf("%d", &id);

    int existe = comprobarId(empleados, num_emp, id);

    if(existe == 1){
        int nuevas_horas;
        printf("Introduzca las nuevas horas semanales del empleado\n");
        scanf("%d", &nuevas_horas);
        for (int i=0; i<num_emp; i++){
            if(empleados[i].id == id){
                empleados[i].horas = nuevas_horas;
                printf("Sueldo actualizado\n");
            }
        }
    }
    else{
        printf("No se puede modificar las horas del empleado. Id no existe\n");
    }
}

int comprobarId(struct empleado empleados[100], int num_emp, int id){
    int resultado = 0;

    for (int i=0; i<num_emp; i++){
        if(empleados[i].id == id){
            resultado = 1;
        }
    }
    return resultado;
}