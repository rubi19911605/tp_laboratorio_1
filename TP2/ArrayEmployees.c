#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"

char MenuArranque (int contador)
 {
	 char opcion;

	 limpiarPantalla();

		 printf("\n   Sistema para administracion de nomina \n");
		 printf("\n   Indique la funcion que desea ejecutar \n");
		 printf("\n opcion 1.............. Alta Empleado");
		 printf("\n opcion 2...............Edita Empleado");
		 printf("\n opcion 3...............Elimina Empleado");
		 printf("\n opcion 4...............Mostrar Lista Empleados");

		 printf("\n\n Presione Esc para Salir...  ");

     fflush(stdin);
     opcion = getche();


     if (contador == 0 && opcion !='1'&& opcion)
	   {
		printf("\n%c No existen empleados \n\n\t\t\t",10);
        return 0;
	   }

 return opcion;
 }

  int opcionModificar (eEmpleado miEmpleado)
 {
	char opcion;

	limpiarPantalla();

		 printf("\n Editando informacion del empleado con ID: %d\n",miEmpleado.id);

		 printf("\n\n opcion 1.............. Editar Nombre:     %-15s",  miEmpleado.nombre);
		 printf("\n\n opcion 2.............. Editar Apellido:   %-25s", miEmpleado.apellido);
		 printf("\n\n opcion 3.............. Editar Salario:    %-11.2f",miEmpleado.salario);
		 printf("\n\n opcion 4.............. Editar Sector:     %-6d",  miEmpleado.sector);
		 printf("\n\n [Esc] para Finalizar");

		 printf("\n\n\n Ingrese la opcion que desea Modificar: ");

     fflush(stdin);
     opcion = getche();
 return opcion;
 }


  int MenuMostrarDatos ()
 {
	char opcion;

	limpiarPantalla();

		 printf("\n LISTAR REPORTES PARA EMPLEADOS");

		 printf("\n\n opcion 1.............. REPORTE ORDENADO POR APELLIDO Y SECTOR DE LA EMPRESA.");
		 printf("\n\n opcion 2.............. REPORTE DE SALARIOS --- EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO.");

		 printf("\n\n pulse [Esc] para Finalizar");

		 printf("\n\n\n Por favor indique la opcion del reporte a listar: ");

     fflush(stdin);
     opcion = getche();
 return opcion;
 }

 int  inicilizarEmpleados(eEmpleado listaEmpleados[], int tam)
 {
	  {
		for (int i=0 ;i < tam ; i++)
		 {
			listaEmpleados[i].id  = LIBRE;
			listaEmpleados[i].isEmpty  = LIBRE;
		 }
		return 0;
	  }
 }


int addEmployee (eEmpleado listaEmpleados[], int tam, int idNext)
 {
 	if(listaEmpleados != NULL && tam > 0)
	 {
		int indice = BuscarLibre (listaEmpleados, tam);
			 if (indice == -1) return -2;

		 listaEmpleados[indice] = CargarEmpleado(idNext);
		 return listaEmpleados[indice].isEmpty;
	 }
  return 0;
 }


  int BuscarLibre (eEmpleado listaEmpleados[], int tam)
 {
    if(listaEmpleados != NULL && tam > 0)

		for( int i=0; i< tam; i++)
  		 {
			if(listaEmpleados[i].isEmpty == LIBRE)
			{
				return i;
				break;
			}
         }
 return -1;
 }
int confirmar ()
 {
 	char opcion;
	do{
		fflush(stdin);
		opcion = getche();
 	} while (opcion !='s' && opcion !='n');

	if (opcion =='s') return 1;
 return -1;
 }

 void limpiarPantalla()
 {
	 if (cls)
	 system("cls || clear");
 }


 eEmpleado CargarEmpleado (int idEmpleado)
 {
    eEmpleado miEmpleado;
 	limpiarPantalla();

    printf("\n REGISTRO DE NUEVO EMPLEADO \n\n",idEmpleado);
    printf("\n  El numero de ID para el registro es: %.4d\n",idEmpleado);
    miEmpleado.id = idEmpleado;

    printf("\n  Ingresar Nombre: ");
    fflush(stdin);
    fgets(miEmpleado.nombre,TAMANIO,stdin);
    miEmpleado.nombre[strlen(miEmpleado.nombre)-1]='\0';

    printf("\n  Ingresar el Apellido: ");
    fflush(stdin);
    fgets(miEmpleado.apellido,TAMANIO,stdin);
    miEmpleado.apellido[strlen(miEmpleado.apellido)-1]='\0';

    printf("\n  Asignar el Salario: ");
    scanf(" %f", &miEmpleado.salario);

    printf("\n  Asignar el Sector: ");
    printf("\n\n opcion 1.............. Administracion ");
    printf("\n\n opcion 2.............. Sistemas");
    printf("\n\n opcion 3.............. Operaciones");
    printf("\n\n opcion 4.............. Call Center\n\n");
    scanf(" %d", &miEmpleado.sector);

	limpiarPantalla();

	printf("\n VERIFIQUE LOS DATOS DE REGISTRO DE NUEVO EMPLEADO \n\n");
	printf(" ID: %18d \n\n Nombre: %17s \n\n Apellido: %16s \n\n Salario: $ %17.2f \n\n Sector: %14d ",
	miEmpleado.id,  miEmpleado.nombre, miEmpleado.apellido, miEmpleado.salario, miEmpleado.sector);

	printf("\n\n Los datos son correctos? (s/n) ");
	miEmpleado.isEmpty = confirmar();

  return miEmpleado;
 }

 int ModificarEmpleados ( eEmpleado listaEmpleados[], int tam )
 {
    int indice;
    int entrada;

    if(listaEmpleados != NULL && tam > 0)
      {
        printf("%c Ingrese el ID del empleado que desea modificar: ",10);
        scanf(" %d", &entrada);
        indice = findEmployeeById (listaEmpleados, tam, entrada);
            if (indice == -1)
              {
                printf("\n El ID ingresado no existe: %d\n",entrada);
                return -1;
              }

		eEmpleado miEmpleado =  listaEmpleados[indice];

            do
              {
                switch ( opcionModificar(miEmpleado))
                    {
                    case '1' :
                        printf(" Ingresar el Nombre: ");
                        fflush(stdin);
                        fgets(miEmpleado.nombre,TAMANIO,stdin);
                        miEmpleado.nombre[strlen(miEmpleado.nombre)-1]='\0';
                        break;

                    case '2' :
                        printf(" Ingresar el Apellido: ");
                        fflush(stdin);
                        fgets(miEmpleado.apellido,TAMANIO,stdin);
                        miEmpleado.apellido[strlen(miEmpleado.apellido)-1]='\0';
                        break;

                    case '3' :
                        printf(" Asignar el Salario: ");
                        scanf(" %f", &miEmpleado.salario);
                        break;

                    case '4' :
                        printf(" Ingrese el Sector: ");
                        printf("\n\n opcion 1.............. Administracion ");
                        printf("\n\n opcion 2.............. Sistemas");
                        printf("\n\n opcion 3.............. Operaciones");
                        printf("\n\n opcion 4.............. Call Center\n\n");
                        scanf(" %d", &miEmpleado.sector);
                        break;

                    case 27:
                            limpiarPantalla();

                            printf("\n\n ****DATOS ANTERIORES****\n");
                            printf("%.4s   %-10s %-15s $ %10s %10s \n", "ID","NOMBRE", "APELLIDO","SALARIO","SECTOR");
                            printf("%.4d   %-10s %-15s $ %10.2f %5d",listaEmpleados[indice].id, listaEmpleados[indice].nombre, listaEmpleados[indice].apellido, listaEmpleados[indice].salario, listaEmpleados[indice].sector);

                            printf("\n\n ******NUEVOS DATOS****** \n");
                            printf("%.4s   %-10s %-15s $ %10s %10s \n", "ID","NOMBRE", "APELLIDO","SALARIO","SECTOR");
                            printf("%.4d   %-10s %-15s $ %10.2f %5d",miEmpleado.id, miEmpleado.nombre, miEmpleado.apellido, miEmpleado.salario, miEmpleado.sector);

                            printf("\n\n  Confirma la modificacion ? (s/n) ");

                                if ( confirmar()==-1 ) return -1;

                            listaEmpleados[indice] = miEmpleado;
                            return 1;
                        break;

                    default:
                        printf("\n\n Opcion erronea ");
                        break;
                    }
              } while (indice != -2 );
      }
  return 0;
 }
 int findEmployeeById (eEmpleado listaEmpleados[], int tam, int input)
 {
     for( int i=0; i< tam; i++)
  		{
			if(listaEmpleados[i].id == input && listaEmpleados[i].isEmpty == 1)
			{
				return i;
				break;
			}
        }
  return -1;
 }

 int removeEmployee (eEmpleado listaEmpleados[], int tam)
 {
    int id;
    int input;

        if(listaEmpleados != NULL && tam > 0)
         {
            printf("%c Ingrese el ID del empleado que desea eliminar: ",13);
            scanf(" %d", &input);
            id = findEmployeeById (listaEmpleados, tam, input);

                if (id == -1)
                  {
                    printf("\n El ID ingresado no existe %d\n",input);
                    return -1;
                  }
                      else
                        {
                        limpiarPantalla();

                        printf("\n ATENCION se esta eliminando el ID del empleado: %.4d \n",input);
                        printf("\n\n   Nombre: %s \n\n Apellido: %s \n\n  Salario: $ %.2f \n\n   Sector: %d ",
                        listaEmpleados[id].nombre, listaEmpleados[id].apellido, listaEmpleados[id].salario,  listaEmpleados[id].sector);

                        printf("\n\n\n ¡Confirma la accion? (s/n) ");
                        if ( confirmar() == 1 ) listaEmpleados[id].isEmpty = -1;


                        return listaEmpleados[id].isEmpty;
                        }
         }
  return 0;
 }

 void OrdenarPorApellidoSector(eEmpleado listaEmpleados[], int tam)
 {
    int i;
    int j;

    eEmpleado auxEmpleado;

    for(i=0; i<tam-1; i++)
      {
        for(j=i+1; j<tam; j++)
          {
            if(strcmp(listaEmpleados[i].apellido, listaEmpleados[j].apellido)>0 || strcmp(listaEmpleados[i].apellido, listaEmpleados[j].apellido) ==0 && listaEmpleados[i].sector > listaEmpleados[j].sector)
              {
                auxEmpleado  = listaEmpleados[i];
                    listaEmpleados[i] = listaEmpleados[j];
                    listaEmpleados[j] = auxEmpleado;
              }
           }
      }
 }


 int printEmployees(eEmpleado listaEmpleados[], int tam, int cont)
 {
    if(listaEmpleados != NULL && tam > 0)

    limpiarPantalla();
    float total;

     do
      {
        switch (MenuMostrarDatos() )
            {
            case '1':
                    OrdenarPorApellidoSector(listaEmpleados,tam);
                    printf("%c Listado de Empleados ordenado por Apellido y Sector\n",13);
                         for(int i=0; i<tam; i++)
                           {
                             if(listaEmpleados[i].isEmpty == 1) printf("\n ID: %.4d  %2d  %-12s  %-10s  $ %10.2f ",
                                listaEmpleados[i].id, listaEmpleados[i].sector, listaEmpleados[i].apellido, listaEmpleados[i].nombre, listaEmpleados[i].salario);
                           }
                    printf("\n\n");
                    while (terminar() !=27);
                break;

            case '2':
                    total = sumaSalarios(listaEmpleados, tam);

                    printf("%c Listado de Empleados con Salarios por encima del Promedio \n",13);
                    printf("\n Total de Salarios $ %.2f \t Promedio $ %.2f \n",total ,total/cont);
                        for(int i=0; i<tam; i++)
                           {
                             if(listaEmpleados[i].isEmpty == 1 && listaEmpleados[i].salario > total/cont ) printf("\n ID: %.4d  %2d  %-12s  %-10s  $ %10.2f ",
                                listaEmpleados[i].id, listaEmpleados[i].sector, listaEmpleados[i].apellido, listaEmpleados[i].nombre, listaEmpleados[i].salario);
                           }
                    printf("\n\n");
                    while (terminar() !=13);
                break;

            case 27 :
                    return -1;
                break;

            default :
                    printf("\n\n Opcion invalida ");
                    while (terminar() !=13);
                break;
            }
       } while (tam>0);
  return 0;
 }

 float sumaSalarios (eEmpleado listaEmpleados[], int tam)
 {
     float suma = 0;
     for(int i=0; i<tam-1; i++)
       {
           if (listaEmpleados[i].isEmpty ==1)
         suma += listaEmpleados[i].salario;
       }
  return suma;
 }


 int terminar()
 {
    char salir;
    printf("%c pulse [Esc] para Finalizar  %c",13,13);
    fflush(stdin);
    salir = getche();
  return salir;
 }




