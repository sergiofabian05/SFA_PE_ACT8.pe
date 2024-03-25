
//Sergio Fabian Aguiar   Matricula: 374317
//DESCRIP: Realiza programa en C el programa deberá tener menu.
//SFA_PE_ACT8
//// Fecha 20/03/2024     Ultima modificacion:24/03/2024
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define C 4
#define M 4

int msges();
void menu();
void LlenarVector(int vect[], int m, int ri, int rf);
void LlenarVectorAleatorio(int vect[], int m, int ri, int rf);
void SumaDeVectores(int vec1[], int vec2[], int vec3[], int m);
void ImprimirVector(int vect[], int m, const char *nombre);
void LlenarMatriz(int matri[][M], int m, int n, int vect[]);
void ImprimirMatriz(int matri[][M], int m, int n);

int main()
{
    menu();
    return 0;
}
int msges()
{
    int op;
    system("CLS");
    printf("\tMENU\n");
    printf("1. LLENAR VECTOR 1 (MANUALMENTE) \n");
    printf("2. LLENAR VECTOR 2 (ALEATORIAMENTE) \n");
    printf("3. LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2) \n");
    printf("4. IMPRIMIR VECTORES \n");
    printf("5. LLENA MATRIZ 4 X 4 \n");
    printf("6. IMPRIMIR MATRIZ \n");
    printf("0. SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
void menu()
{
    int vect1[N], vect2[N], vect3[N], matriz[N][M];
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            LlenarVector(vect1, N, 30, 70);
            break;
        case 2:
            LlenarVectorAleatorio(vect2, N, 10, 20);
            break;
        case 3:
            SumaDeVectores(vect1, vect2, vect3, N * 2);
            break;
        case 4:
            ImprimirVector(vect1, N, "Vector1");
            ImprimirVector(vect2, N, "Vector2");
            ImprimirVector(vect3, N * 2, "Vector3");
            break;
        case 5:
            LlenarMatriz(matriz, C, M, vect3);
            break;
        case 6:
            ImprimirMatriz(matriz, C, M);
            break;
        }

    } while (op != 0);
}
void LlenarVector(int vect[], int m, int ri, int rf)
{
    system("cls");
    int i;
    printf("Llenar vector ingresa numero enteros positivos\n");
    printf("En el rango del %d al %d \n", ri, rf);
    for (i = 0; i < m; i++)
    {
        do
        {
            printf("%d ---> ", i + 1);
            scanf("%d", &vect[i]);
        } while (vect[i] < ri or vect[i] > rf);
    }
    system("pause");
}
void LlenarVectorAleatorio(int vect[], int m, int ri, int rf)
{
    system("cls");
    int i, j, rango, valor, encontrado;
    rango = (rf - ri) + 1;

    srand(time(NULL));

    for (i = 0; i < m; i++)
    {
        do
        {
            valor = (rand() % rango) + ri;
            encontrado = false; 
            for (j = 0; j < i && !encontrado; j++)
            {
                if (vect[j] == valor)
                {
                    encontrado = true;
                }
            }
        } while (encontrado);
        vect[i] = valor;
    }
    system("pause");
}
void SumaDeVectores(int vec1[], int vec2[], int vec3[], int m)
{
    system("cls");
    int i, j, k;

    for (i = 0; i < m / 2; i++)
    {
        vec3[i] = vec1[i];
    }
    k = 0;
    for (j = m / 2; j < m; j++)
    {
        vec3[j] = vec2[k];
        k += 1;
    }
    system("pause");
}
void ImprimirVector(int vect[], int m, const char *nombre)
{
    system("cls");
    int i;
    printf("%s \n", nombre);
    for (i = 0; i < m; i++)
    {
        printf("%d ---> [%d]\n", i + 1, vect[i]);
    }
    system("pause");
}
void LlenarMatriz(int matri[][M], int m, int n, int vect[])
{
    system("cls");
    int i, j, k;
    k = 0;
    for (i = 0; i < m; i++)
    {
        j = 0;
        while (j < n)
        {
            matri[i][j] = vect[k];
            j += 1;
            k += 1;
        }
    }
    system("pause");
}
void ImprimirMatriz(int matri[][M], int m, int n)
{
    system("cls");
    int i, j;
    printf("Matriz: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" [%d] ", matri[i][j]);
        }
        printf("\n");
    }
    system("pause");
}