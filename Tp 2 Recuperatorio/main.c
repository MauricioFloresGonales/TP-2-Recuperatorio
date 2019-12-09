#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"

#define TE 10

int main()
{
    eEmployee empleado[TE];
    int opcion;

    if(initEmployees(empleado,TE)==0)
    {
        harcodeo(empleado,5);
        printf("Aviso datos ya harcodeados,\n");
    }

    do{
        printf("1- Alta:\n");
        printf("2- Modificar:\n");
        printf("3- Baja:\n");
        printf("4- Informar:\n");
        printf("5- salir:\n");
        while(getInt(&opcion,"elija una opcion: ","Error,solo puede ingresar los numeros del menu\n",1,5)!=0);

        switch(opcion)
        {
        case 1:
            agragarEmpleado(empleado,TE);
            break;
        case 2:
            modificarMenu(empleado,TE);
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
