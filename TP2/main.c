/******************************************************************************
*******************************************************************************
Una empresa requiere un sistema para administrar su n�mina de empleados.
Se sabe que dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
*******************************************************************************
----------El sistema deber� tener el siguiente men� de opciones:---------------
*******************************************************************************
1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente
   el n�mero de Id. El resto de los campos se le pedir� al usuario.
*******************************************************************************
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar:
   o Nombre
   o Apellido
   o Salario
   o Sector
*******************************************************************************
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
*******************************************************************************
4. INFORMAR:
    1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
    2. Total y promedio de los salarios, y cu�ntos empleados superan el salario
    promedio.
*******************************************************************************
NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de
funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber
realizado la carga de alg�n empleado.
********************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 1000


#include "ArrayEmployees.h"

 int main()
 {
    eEmpleado listarEmpleados [ CANTIDAD ];

    int estado = (inicilizarEmpleados (listarEmpleados, CANTIDAD));
    if (estado == -1)
      {
        printf("\n\n No se ha inicializado la lista\n\n");
        return -1;
      }
    int carga = estado;
    estado ++;

    char salir;
    int flag;

    do
      {
        switch ( MenuArranque (carga) )
          {

        case '1':
                flag = addEmployee (listarEmpleados, CANTIDAD, estado);

                    if (flag == 0)
                      {
                        printf("%c No hay espacio \n\n",10);
                        break;
                      }

                    if (flag == -1)
                      {
                        printf("%c Cambios descartados \n\n",10);
                        system("pause");
                      }
                    if (flag == 1)
                      {
                        printf("%c DATOS CARGADOS CON EXITO \n\n",10);
                        estado++;
                        carga++;
                      }
                    system("pause");

                        break;

            case '2':
                    if (ModificarEmpleados (listarEmpleados, CANTIDAD) == -1)

                    {
                        printf("\n\n CAMBIOS DESCARTADOS \n\n");
                    }
                       else printf("\n\n DATOS MODIFICADOS CON EXITO \n\n");
                    system("pause");


            case '3':
                    if (removeEmployee (listarEmpleados, CANTIDAD) == -1)
                      {
                        printf("%c Empleado dado de Baja \n\n",10);
                        carga--;
                      }
                           else printf("%c No se dio de Baja ningun Empleado \n\n",10);
                    system("pause");

            case '4':
                    printEmployees (listarEmpleados, CANTIDAD, carga);
                break;


            default :
                    printf("%c Elija otra opcion \n\n",10);
                    while (terminar() !=27);
                        break;
           }
      }while ( salir != 's');
  return 0;
 }





