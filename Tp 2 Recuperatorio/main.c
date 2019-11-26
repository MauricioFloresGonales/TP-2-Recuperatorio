#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"

#define TE 10

int main()
{
    eEmployee empleado[TE];
    int opcion;
    int pasoUno;

    do{
        printf("1- Alta:\n");
        printf("2- Modificar:\n");
        printf("3- Baja:\n");
        printf("4- Informar:\n");
        printf("5- salir:\n");
        while(getInt(&opcion,"elija una opcion: ","Error,solo puede ingresar los numeros del menu\n",1,5)!=0);

        if(initEmployees(empleado,TE)==0)
        {
            harcodeo(empleado,5);
        }

        switch(opcion)
        {
        case 1:

            pasoUno = agragarEmpleado(empleado,TE);

            break;
        case 2:
            if(pasoUno==0)
            {
                modificarMenu(empleado,TE);
            }else{
                printf("todavia no ingreso ningun empleado");
            }


            break;
        case 3:
            baja(empleado,TE);

            break;
        case 4:
            mostrarEmpleados(empleado,TE);
            informes(empleado,TE);
            break;
        default:
            printf("SALIR");
        }

    system("pause");
    system("cls");

    }while(opcion != 7);

}
