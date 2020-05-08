#include "funcionesCalcu.h"

int getInt(char text[])
{
    int validacion;
    float num;
    do{
        fflush(stdin);
        printf("%s",text);
        scanf("%f", &num);
        printf("\n");
        validacion = validarInt(num);
        if(validacion == 0){
            printf("Error: debe ingresar un numero entero\n");
        }
    }while(!validacion);
    return (int)num;
}

int validarInt(float num)
{
    int aux = (int)num;
    num -= aux;
    if(num == 0)
    {
        return 1;
    }
    return 0;
}

void menuPrint(int a, int b,int aFlag,int bFlag)
{
    printf("\n");
    if(aFlag == 1)
    {
        printf("1. Ingresar 1er operando (A=%d)\n",a);
    }else
    {
        printf("1. Ingresar 1er operando (A=x)\n");
    }
    if(bFlag == 1)
    {
        printf("2. Ingresar 2do operando (B=%d)\n",b);
    }else
    {
        printf("2. Ingresar 2do operando (B=x)\n");
    }
        printf("3. Calcular todas las operaciones\n");
        printf("\t a) Calcular la suma (A+B)\n");
        printf("\t b) Calcular la resta (A-B)\n");
        printf("\t c) Calcular la division (A/B)\n");
        printf("\t d) Calcular la multiplicacion (A*B)\n");
        printf("\t e) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");
}

int sumar(int a,int b)
{
    return (a+b);
}

int restar(int a,int b)
{
    return (a-b);
}

float dividir(int a,int b)
{
    float result = 0;
    if(b!=0)
    {
        result = a/(float)b;
    }
     return result;
}

int multiplicar(int a,int b)
{
    return (a*b);
}

int factorial(int a)
{
    int i,factorial = 1;

    for(i=a;i>0;i--)
    {
        factorial = i*factorial;
    }
    return factorial;
}

void printResult(int a,int b,int suma,int resta,float div,int multi,int facA,int facB)
{
    printf("a) El resultado de %d+%d es: %d\n",a,b,suma);
    printf("b) El resultado de %d-%d es: %d\n",a,b,resta);
    if(b == 0)
    {
        printf("c) No es posible dividir por 0\n");
    }else
    {
        printf("c) El resultado de %d/%d es: %.2f\n",a,b,div);
    }
    printf("d) El resultado de %d*%d es: %d\n",a,b,multi);
    printf("e) El factorial de %d es: %d y el de %d es: %d\n\n",a,facA,b,facB);

}

