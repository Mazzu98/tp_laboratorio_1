#include "funcionesCalcu.h"
#include "entradaValidada.h"

int main()
{
    int a,b,selected=0;
    int aFlag=0,bFlag=0,calculoFlag=0;
    int suma,resta,multiplicacion,factorialA,factorialB;
    float division;

    do
    {
        menuPrint(a,b,aFlag,bFlag);

        do
        {
            selected = getInt("Ingrese una opcion: ");

        }while (selected < 1 || selected >5 );

        system("cls");

        switch (selected)
        {
            case 1:
                    a = getInt("Ingresar numero:");
                    aFlag = 1;                                      // flag para saber si ya se ingreso a
                    break;
            case 2:
                    b = getInt("Ingresar numero:");
                    bFlag = 1;                                      // flag para saber si ya se ingreso b
                    break;
            case 3:
                    if(aFlag == 1 && bFlag == 1)
                    {
                        calculoFlag =1;
                        suma = sumar(a,b);
                        resta = restar(a,b);
                        division = dividir(a,b);
                        multiplicacion = multiplicar(a,b);
                        factorialA = factorial(a);
                        factorialB = factorial(b);
                    }else
                    {
                        printf("\nDebe ingresar los dos numeros antes de realizar operaciones\n\n");
                    }
                    break;
            case 4:
                    if(aFlag == 1 && bFlag == 1)
                    {
                        if(calculoFlag == 1)
                        {
                            printResult(a,b,suma,resta,division,multiplicacion,factorialA,factorialB);
                        }else
                        {
                            printf("\nDebe realizar los calculos primero\n\n");
                        }
                    }else
                    {
                        printf("\nDebe ingresar los dos numeros antes de realizar operaciones\n\n");
                    }

                    break;
            case 5:
                    break;
            default:
                    printf("Debe ingresar una opcion valida\n");
                    break;
        }


    }while(selected != 5);
    return 0;
}
