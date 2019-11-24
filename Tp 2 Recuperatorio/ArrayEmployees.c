
#include "ArrayEmployees.h"

void harcodeo(eEmployee lista[],int len)
{
    int i;

    int id[]={1,2,3,4,5};

    char name[][51]={"a","c","d","b","e"};//{"ana","juan","pepe","laura","mauricio"};
    char lastName[][51] = {"catunta","grillo","argento","cordoba","gonzales"};
    float salary[] = {100,200,300,400,500};
    int sector[] = {1,2,3,1,2};
    int isEmpty[] = {0,0,0,0,0};

    for(i=0;i<len;i++)
    {
        lista[i].id=id[i];
        strcpy(lista[i].name,name[i]);
        strcpy(lista[i].lastName,lastName[i]);
        lista[i].salary = salary[i];
        lista[i].sector = sector[i];
        lista[i].isEmpty = isEmpty[i];
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

int espacioLibre(eEmployee lista[], int len)
{
    int index;
    int i;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == EMPTY)
        {
            index = i;
            break;

        }else{
            index = -1;
        }//if
    }//for
    return index;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int autoId(eEmployee lista[],int len,int valMenor)
{
    int indexAnterior;
    int idFinal;

    indexAnterior = idMayor(lista,len,valMenor);

    idFinal = indexAnterior +1;

    return idFinal;

}

//----------------------------------------------------------------------------------------------------------------------------------------

int idMayor(eEmployee lista[],int len,int valMenor)
{
    int i;
    int mayor = valMenor-1;

    for(i=0;i<len;i++)
    {
        if(mayor<lista[i].id)
        {
            mayor = lista[i].id;
        }
    }
    return mayor;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int initEmployees(eEmployee list[], int len)
{
    int i;
    int retorno;

    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].id = 0;
            list[i].isEmpty = EMPTY;
        }
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int agragarEmpleado(eEmployee empleados[],int tam)
{
    int retorno;
    int index;
    index=espacioLibre(empleados,tam);
    if(index!=-1)
    {
        retorno=addEmployee(empleados,tam,&empleados[index].id,empleados[index].name,empleados[index].lastName,&empleados[index].salary,&empleados[index].sector);
        empleados[index].isEmpty=NOT_EMPTY;
    }
    else
    {
        retorno=1;
    }
    return retorno;
}



//----------------------------------------------------------------------------------------------------------------------------------------

int addEmployee(eEmployee lista[],int len,int *id,char name[],char lastName[],float *salary,int *sector)
{
    int retorno;

    if(lista!=NULL && (espacioLibre(lista,len))>-1)
    {
            id =(int*) autoId(lista,len,1);
            while(getString(name,"inngrese el Nombre: ","error el nombre se pasa de los limites\n","error,Solo se pueden ingresar letras",1,51)!=0);
            while(getString(lastName,"inngrese el Apellido: ","error el nombre se pasa de los limites\n","error,Solo se pueden ingresar letras",1,51)!=0);
            while(getFloat(salary,"Ingrese el Salario: ","error,Solo puede ingresar numeros entre [0][1.000.000]\n",1,1000000)!=0);
            while(getInt(sector,"ingrese el numero del Sector al que pertenece: ","error,Solo puede ingresar numeros\n",1,999999)!=0);
            retorno = confirmar("confirmar","Cancelar");

         retorno = 0;

    }else{

        printf("No hay mas espacio libre\n");
        retorno = -1;

    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int findEmployeeById(eEmployee list[], int len,int id)
{
    int index;
    int i;

    if(list!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].id == id && list[i].isEmpty == NOT_EMPTY)
            {
                index = i;
                break;

            }else{
                index = -1;
            }//if2
        }//for
    }else{
        index = -1;
    }//if1

    return index;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int removeEmployee(eEmployee list[], int len, int id)
{
    eEmployee aux;
    int retorno;
    int i;

    if(list!=NULL || len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == NOT_EMPTY && list[i].id == id)
            {
                aux.isEmpty = EMPTY;

                if(confirmar("Confirmar ","Cancelar ")==0)
                {
                    list[i].isEmpty = aux.isEmpty;
                    retorno = 0;

                }else{
                    retorno = -1;
                }

            }else{
                retorno = -1;
            }//if2
        }//for

    }else{
        retorno = -1;
    }//if1

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int sortEmployees(eEmployee list[], int len, int order)
{
    int retorno;

    if(list!=NULL || len>0)
    {
        if(order==0)
        {
            ordenarAfabeticamenteUp(list,len);
            mostrarApellidoSector(list,len);
            retorno = 0;
        }else if(order == 1)
        {
            ordenarAfabeticamenteDown(list,len);
            mostrarApellidoSector(list,len);
            retorno = 0;
        }else{
            printf("No eligio ninguna opcion.\n");
        }
    }else{
        retorno = -1;
    }
   return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

void ordenarAfabeticamenteUp(eEmployee list[], int len)
{
    int i;
    int j;
    eEmployee aux;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(list[i].isEmpty==NOT_EMPTY&&list[j].isEmpty==NOT_EMPTY)
            {
                if(stricmp(list[i].lastName,list[j].lastName)<0)
                {
                    strcpy(aux.lastName,list[i].lastName);
                    strcpy(list[i].lastName,list[j].lastName);
                    strcpy(list[j].lastName,aux.lastName);
                }
                else
                {
                     if(stricmp(list[i].lastName,list[j].lastName)== 0)
                     {
                        if(list[i].sector<list[j].sector)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                     }
                }
            }
        }

    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

void ordenarAfabeticamenteDown(eEmployee list[], int len)
{
    int i;
    int j;
    eEmployee aux;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(list[i].isEmpty==NOT_EMPTY&&list[j].isEmpty==NOT_EMPTY)
            {
                if(stricmp(list[i].lastName,list[j].lastName)>0)
                {
                strcpy(aux.lastName,list[i].lastName);
                strcpy(list[i].lastName,list[j].lastName);
                strcpy(list[j].lastName,aux.lastName);

                }else if(stricmp(list[i].lastName,list[j].lastName)== 0)
                {
                    if(list[i].sector>list[j].sector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }

                }
            }

        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

int printEmployees(eEmployee list[], int length)
{
    int retorno;
    int i;

    if(list!=NULL || length>0)
    {
        for(i=0;i<length;i++)
        {
            mostrarUnEmpleado(list,i);
        }
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

void mostrarUnEmpleado(eEmployee list[], int index)
{
    if(list[index].isEmpty == NOT_EMPTY)
    {
        printf("%d\t",list[index].id);
        printf("%10s\t",list[index].name);
        printf("%10s\t",list[index].lastName);
        printf("%10f\t",list[index].salary);
        printf("%10d\n",list[index].sector);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

int  modificarMenu(eEmployee list[], int len)
{

    int opcion;
    int index;
    int id;
    int retorno;
    char auxChar[51];
    float salarioAux;
    int sectorAux;

    if(list!=NULL || len>0)
    {
        retorno = printEmployees(list,len);

        do{
            while(getInt(&id,"ingrese un ID a modificar: ","erro,solo puede ingresar id's\n",1,999999)!=0);
            index = findEmployeeById(list,len,id);
        }while(index > -1);

        mostrarUnEmpleado(list,index);

        do{
            while(getInt(&opcion,"Que desea modificar:\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Salir.\n ","error solo puede ingresar los numeros del menu\n",1,5)!=0);

            switch(opcion)
            {
            case 1:
                while(getString(auxChar,"ingrese nuevo Nombre: ","Error,se paso del limite de caracteres\n","Error,solo puede ingresar letras\n",1,51)!=0);
                strcpy(list[index].name,auxChar);
                retorno=0;
                break;
            case 2:
                while(getString(auxChar,"ingrese nuevo Apellido: ","Error,se paso del limite de caracteres\n","Error,solo puede ingresar letras\n",1,51)!=0);
                if(confirmar("Esta seguro: ","Cancelar: ")== 0)
                {
                    strcpy(list[index].lastName,auxChar);
                }

                retorno=0;
                break;
            case 3:
                while(getFloat(&salarioAux,"Ingrese el nuevo Salario: ","Error,solo puede ingresar numeros\n",1,999999)!=0);
                if(confirmar("Esta seguro: ","Cancelar: ")== 0)
                {
                    list[index].salary = salarioAux;
                }
                retorno=0;

                break;
            case 4:
                while(getInt(&sectorAux,"ingrese nuevo Sector: ","error,Solo puede ingresar numeros\n",1,999999)!=0);
                if(confirmar("Esta seguro: ","Cancelar: ")== 0)
                {
                    list[index].sector = sectorAux;
                }
                retorno=0;
                break;
            default:
                printf("SALIR.\n");
                break;
            }
        }while(opcion != 5);
    }else{
        retorno = -1;
    }
    return retorno;
}



//----------------------------------------------------------------------------------------------------------------------------------------

void mostrarApellidoSector(eEmployee list[], int len)
{
    int i;

    if(list!=NULL || len>0)
    {
        printf("\tApellidos:\tSectores:\n");
        for(i=0;i<len-1;i++)
        {
            if(list[i].isEmpty == NOT_EMPTY)
            {
                printf("\t%10s\t%10d\n",list[i].lastName,list[i].sector);
            }


        }
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------

float totalSalarios(eEmployee list[], int len)
{
    int i;
    float contador =0;
    float retorno;

    if(list!=NULL || len>0)
    {
        for(i=0;i<len-1;i++)
        {
            if(list[i].isEmpty ==NOT_EMPTY)
            {
                contador = contador + list[i].salary;
            }
        }
        retorno = contador;
    }else{
        retorno = -1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

float promedioDeSalarios(eEmployee list[], int len)
{
    int retorno;
    float total;
    float promedio;
    int contador = 0;
    int i;

    if(list!=NULL || len>0)
    {
        for(i=0;i<len-1;i++)
        {
            if(list[i].isEmpty ==NOT_EMPTY)
            {
                contador ++;
            }
        }

        total = totalSalarios(list,len);

        promedio = total / contador;

        retorno = promedio;

    }else{
        retorno = -1;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------------------------

int superanPromedioSalario(eEmployee list[], int len)
{
    int i;
    int contador;
    int retorno;

    if(list!=NULL || len>0)
    {
        for(i=0;i<len-1;i++)
        {
            if(list[i].isEmpty ==NOT_EMPTY)
            {
                if(list[i].salary>promedioDeSalarios(list,len))
                {
                    contador++;
                }
            }
        }
        retorno = contador;
    }else{
        retorno =0;
    }

    return retorno;
}

int informeSalario(eEmployee list[], int len)
{
    float total;
    float promedio;
    int contador;
    int retorno;

    if(list!=NULL || len>0)
    {
        total = totalSalarios(list,len);
        promedio = promedioDeSalarios(list,len);
        contador = superanPromedioSalario(list,len);

        printf("\nSalario total: %f\n",total);
        printf("Salario promedio: %f\n",promedio);
        printf("Num. de empleados que superan el promedio: %d\n\n",contador);
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;

}


//----------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------

int baja(eEmployee lista[],int len)
{
    int id;
    int retorno;

    if(printEmployees(lista,len)==0)
    {
        while(getInt(&id,"ingrese un id: ","Error,ingrese un id existente",1,1000)!=0);
        id =findEmployeeById(lista,len,id);
        retorno = removeEmployee(lista,len,id);
    }else{
        retorno = -1;
    }
    return retorno;
}

int informes(eEmployee lista[],int len)
{
    int opciones;
    int retorno;
    while(getInt(&opciones,"[1] Ordenados alfabeticamente por Apellido y Sector\n[2] -Total\n    -Promedio de los salarios    -Cuantos empleados superan el salario promedio\n^[3] Cancelar\nOpcion: ","Error,Solo puede ingresar numeros que esten en el menu",1,3)!=0);
    switch(opciones)
    {
        case 1:
            retorno = informeOrdenar(lista,len);
            break;
        case 2:
             retorno = informeSalario(lista,len);
            break;
        default:
            printf("Salir\n");
    }

    return retorno;
}

int informeOrdenar(eEmployee lista[],int len)
{
    int opcion;
    int retorno;
    while(getInt(&opcion,"Ordenados alfabeticamente por Apellido y Sector\n[0] Mayor a Menor\[1] Menor a Mayor\nOpcion: ","Error,Solo puede ingresar [0]o[1]",0,1)!=0);
    retorno = sortEmployees(lista,len,opcion);

    return retorno;
}

void mostrarEmpleados(eEmployee lista[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        mostrarUnEmpleado(lista,i);
    }
}


