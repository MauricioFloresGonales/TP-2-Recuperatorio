#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include <ctype.h>
#include <conio.h>


int getInt(int* valor, char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno;
    char numeroAux[hiLimit+1];
    int validador;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", numeroAux);

    validador = validarNumero(numeroAux);

    *valor=atoi(numeroAux);

    if(validador==0)
    {
        if(*valor<lowLimit || *valor>hiLimit)
        {
            printf("%s\n", eMessage);
            retorno = -1;

        }else{
              retorno = 0;
        }
    }else{
        printf("%s\n", eMessage);
        retorno = -1;
    }



    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int getFloat(float* valor,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int retorno;
    char numeroAux[(int)hiLimit+1];
    int validador;


    printf("%s", message);
    fflush(stdin);
    scanf("%s", numeroAux);

    validador = validarNumero(numeroAux);

    *valor=atof(numeroAux);

    if(validador==0)
    {
        if(*valor<lowLimit || *valor>hiLimit)
        {
            printf("%s\n", eMessage);
            retorno = -1;

        }else{
              retorno = 0;
        }
    }else{
        printf("%s\n", eMessage);
        retorno = -1;
    }
    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int validarNumero(char* numeroChar)
{
    int digitoAux;
    int retorno;

    digitoAux = isdigit(*numeroChar);

    if(digitoAux == 1)
    {
        retorno = 0;
    }else{
        retorno = -1;
    }

    return retorno;

}

//------------------------------------------------------------------------------------------------------------------------------------------

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
 {
    int retorno;
    char charAux;

    printf("%s",message);
    fflush(stdin);
    scanf("%c",&charAux);

    charAux = tolower(charAux);
    lowLimit = tolower(lowLimit);
    hiLimit = tolower(hiLimit);

    if(charAux < lowLimit  || charAux> hiLimit)
    {
        printf("%s\n",eMessage);
        retorno = -1;
    }else{
        *input = charAux;
        retorno = 0;
    }//if

    return retorno;
 }

//------------------------------------------------------------------------------------------------------------------------------------------

int getOneChar(char* input,char message[],char eMessage[],char oneLimit, char twoLimit)
{
    int retorno;

    printf("%s",message);
    fflush(stdin);
    scanf("%s",input);

    if(*input == oneLimit || *input == twoLimit)
    {
        retorno = 0;

    }else{
        printf("%s",eMessage);
        retorno= -1;
    }//if

    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int confirmar(char message[],char eMenssage[])
{
    int retorno;
    char letra;

    do{
        printf("%s 'S' -- %s 'N'\n\n",message,eMenssage);
        fflush(stdin);
        letra = getch();
        //letra = getch();//------ En windows la funcion se escribe: int getch(void);
        //letra = getchar();//------ En Linux int getchar(void);
        letra = tolower(letra);

        if(letra == 's')
        {
            retorno = 0;
        }else if(letra == 'n')
            {
                retorno = 1;

            }else{

                retorno = -1;

                }
    }while(retorno == -1);

    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int getString(char* input,char message[],char eMessage[],char eNumMessage[], int lowLimit, int hiLimit)
{
    int retorno = 0;
    char arrAux[hiLimit+1];
    int largo;

    printf("%s",message);
    fflush(stdin);
    gets(arrAux);
    //scanf("%s",arrAux);

    largo = strlen(arrAux);

    if((validarLetrasEnString(arrAux,hiLimit+1)) == -1)
    {
        printf("%s\n",eNumMessage);
        retorno = -1;

    }else if(largo < lowLimit || largo > hiLimit)
        {
            printf("%s\n",eMessage);
            retorno = -1;

        }else{
            strcpy(input,arrAux);
            retorno = 0;
        }


    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int validarLetrasEnString(char palabra[],int tam)
{
    int i;
    int validador;
    int retorno = 0;

    for(i=0;i<tam;i++)
    {
        validador = isdigit(palabra[i]);

        if(validador == 1)
        {
            retorno = -1;
        }
    }
    return retorno;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int getStringWithNums(char* input,char message[],char eMessage[],int lowLimit, int hiLimit)
{
    int retorno = 0;
    char arrAux[hiLimit+1];
    int largo;

    printf("%s",message);
    fflush(stdin);
    scanf("%s",arrAux);

    largo = strlen(arrAux);

    if(largo < lowLimit || largo > hiLimit)
    {
        printf("%s\n",eMessage);
        retorno = -1;

    }else{
        strcpy(input,arrAux);
        retorno = 0;
    }


    return retorno;
}






