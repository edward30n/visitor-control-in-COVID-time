#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE  1
#define FALSE 0
#define longitud 80
char contraseniaC[longitud+1];
char contraseniaActual[longitud+1]= {'9','8','7','6'};  /// PROFE, hable con usted para que me permitiera utilizar char en contraseña. Gracias
int entrarAdministrador = 0;
int apartamento[6][5] = {{0,0,1,0,0},{1,0,1,0,0},{1,1,0,1,1},{0,1,1,0,1},{1,0,1,0,1},{0,0,1,0,0}};
int numeroVisitas[6][5];
char nombreUsuario [10][100];
int menu  = 0;
int menu2 = 0;
int menu3 = 0;
int tapabocas = 0;
int contadorVisitantes = 0;
FILE * fArchivo;
void interfazInicio() //Función que imprime el menú inicial
{
 printf("__________________________________________\n");
 printf("| NUMERO |           INTERFAZ            |\n");
 printf("|________|_______________________________|\n");
 printf("|   1    |           Administrador       |\n");
 printf("|--------|-------------------------------|\n");
 printf("|   2    |           Usuario             |\n");
 printf("|--------|-------------------------------|\n");
 printf("|   3    |           Salir               |\n");
 printf("|________|_______________________________|\n\n");
}
void interfazAdminstrador() //Función que imprime el menú para el administrador
{
 printf("__________________________________________________\n");
 printf("| NUMERO |               INTERFAZ                 |\n");
 printf("|________|________________________________________|\n");
 printf("|   1    |  Numero visitantes                     |\n");
 printf("|--------|----------------------------------------|\n");
 printf("|   2    |  Apartamentos covid                    |\n");
 printf("|--------|----------------------------------------|\n");
 printf("|   3    |  Visitantes sin tapabocas              |\n");
 printf("|--------|----------------------------------------|\n");
 printf("|   4    |  Cambio clave                          |\n");
 printf("|--------|----------------------------------------|\n");
}
void interfazUsuario() //Función que imprime el menú inicial
{
 printf("__________________________________________\n");
 printf("| NUMERO |           INTERFAZ            |\n");
 printf("|________|_______________________________|\n");
 printf("|   1    |         Ingreso visitante     |\n");
 printf("|--------|-------------------------------|\n");
 printf("|   2    |         Egreso visitante      |\n");
 printf("|--------|-------------------------------|\n");
 printf("|   3    |         Salir                 |\n");
 printf("|________|_______________________________|\n\n");
}
void contrasenia (char x[longitud]/*vec1[longitud]*/)
{
    /*for(int i=0; i<longitud; i++) //Se recorre el vector  y se va asignando al apuntador cada posición
        {
        contraseniaC[i]=*(vec1+i);
        }*/
    if(strcmp(x,contraseniaActual)==0)
    {
        printf("Bienvenido administrador\n");
        entrarAdministrador = 1;
    }
    else
    {
        printf("\nContre%ca incorrecta\n", 164);
        int entrarAdministrador = 0;
        return(0);
    }
}
void cambioClave(char x[longitud]) //Función para establecer un cambio de la contraseña
{
    char nuevaContrasenia[longitud];
    if(strcmp(x,contraseniaActual)==0)
    {
        printf("Ingrese la nueva contrase%ca:\n",164);
        gets(nuevaContrasenia);
        strcpy(contraseniaActual, nuevaContrasenia);;
        printf("Su nueva contrase%ca es: %s\n" ,164,contraseniaActual);
    }
    else
    {
        printf("\nContrase%ca incorrecta\n",164);
    }
}
void visitantesSinTapabocas()
{
    for(int i=0;i<10;i++)
    {
        puts(nombreUsuario[i]);
    }
}
int numeroVisitantes() // Función que permite contar el numero de visitantes de todos los apartamentos.
{
    int contador = 0;
    for(int x=0; x<6; x++)
    {
        for(int y=0; y<5; y++)
        {
            if(contador == 5 || contador == 10 || contador == 15 || contador == 20 || contador == 25 || contador == 30)
            {
                printf("\n");
            }
            contador += 1;
            printf("|%d|",numeroVisitas[x][y]);
        }
    }
}
void ingresoNuevoVisitante (int *x, int *y) // condigo para el ingreso de un visitante.
{
    if(apartamento[*x][*y]==0)
    {
        if(numeroVisitas[*x][*y] >= 3)
        {
           printf("\nNo se puede ingresar mas visitantes al apartamento\n");
        }
        else
        {
            contadorVisitantes += 1;
            numeroVisitas[*x][*y] += 1;
            if(tapabocas == 1)
            {
                printf("Por favor ingrese su nombre completo: \n");
                fgets(nombreUsuario[contadorVisitantes],sizeof(nombreUsuario),stdin);
                fgets(nombreUsuario[contadorVisitantes],sizeof(nombreUsuario),stdin);
            }
        }
    printf("\nSe ha ingresado un nuevo visitante con exito\n");
    }
    else
    {
        printf("\nLa persona que desea visitar tiene Covid\n");
    }
}
void egresoVisitante (int *x, int *y) // Codigo para la saldia de un visitante.
{
    if(numeroVisitas[*x][*y] > 0)
    {
      numeroVisitas[*x][*y] -= 1;
    }
    else
    {
        printf("\nNo hay invitados en dicho apartamento\n");
    }

}
int apartamentosCovid()  // Codigo que genera la matriz que muestra los apartamentos con covid y limpios. Este codigo adiciona la  parte de impresión de apartamentos con covid.
{
    fArchivo = fopen( "archivo.txt", "a"); //Se abre el archivo y se empieza a escribir la factura
    fprintf(fArchivo,"\n\n       *************************************************\n");
    fprintf(fArchivo,"       *                    Apartamentos                    *\n");
    fprintf(fArchivo,"       *************************************************\n");
    fclose(fArchivo);
    printf("\nA continuacion se muestra una matriz de los apartamentos:\n");
    printf("\nS ---> Apartamento sano\n");
    printf("\nI ---> Apartamento infectado\n");
    int contador = 0;
     for(int x=0; x<6; x++)
    {
        for(int y=0; y<5; y++)
        {
            contador += 1;
            if(apartamento[x][y] == 0)
            {
                printf("|S|");
            }
            else
            {
                fArchivo= fopen("archivo.txt","a");
                fprintf(fArchivo,"%s","Apartamento ");
                fprintf(fArchivo,"%d",contador);
                fprintf(fArchivo,"%s"," con Covid\n");
                fclose(fArchivo);
                printf("|I|");
            }
            if(contador == 5 || contador == 10 || contador == 15 || contador == 20 || contador == 25 || contador == 30)
            {
                printf("\n");
            }
        }
    }
}
int main()
{
    system("color 02");
    while(TRUE)
    {
        menu=0;
        entrarAdministrador =0;
        printf("\nIngrese el n%cmero del men%c al que desea acceder:\n",163,163);
        interfazInicio();
        scanf("%d", &menu);
        switch (menu)
        //Selección menú inicial
        {
            case (1): //Opción administrador
            {
                getchar();
                printf("Por favor ingrese la contrase%ca de administrador:\n",164);
                gets(contraseniaC);
                contrasenia(contraseniaC);
                if(entrarAdministrador == 0)
                    break;
                interfazAdminstrador();
                printf("\nIngrese el al menu de administrador que quiera acceder:\n");
                scanf("%d", &menu2);
                switch (menu2)
                {
                    case(1): // Caso para
                    {
                       numeroVisitantes();
                       break;
                    }
                    case(2):
                    {
                        apartamentosCovid();
                        break;
                    }
                    case(3):
                    {
                        visitantesSinTapabocas();
                        break;
                    }
                    case(4):
                    {
                        getchar();
                        printf("Ingrese la contrase%ca actual\n",164);
                        gets(contraseniaC);
                        cambioClave(contraseniaC); //Se llama a la función que ejecuta la acción de cambiar la contraseña
                        break;
                    }
                }
                break;
            }
            case (2): //Opción Usuario
            {
                interfazUsuario();
                printf("\nIngrese el numero del menu al que desea acceder:\n");
                scanf("%d",&menu3);
                switch (menu3)
                 {
                    case(1):
                    {
                        int posicionX = 0;
                        int posicionY = 0;
                        printf("Ingrese la direccion de apartamento:\n");
                        scanf("%d", &posicionX);
                        scanf("%d", &posicionY);
                        printf("\nEl visitante tiene tapabocas?\n");
                        printf(" Si ----> 0\n");
                        printf(" No ----> 1\n");
                        scanf("%d", &tapabocas);
                        ingresoNuevoVisitante(&posicionX,&posicionY);
                        break;
                    }
                    case(2):
                    {
                        int posicionX = 0;
                        int posicionY = 0;
                        printf("Ingrese la direccion de apartamento:\n");
                        scanf("%d", &posicionX);
                        scanf("%d", &posicionY);
                        egresoVisitante(&posicionX,&posicionY);
                        break;
                    }
                }
                break;
            }
            case (3): //Opción Salir
            {
                return(-1);
            }
        }
    }
}

