/******************************************************************************
*******************************************************************************
Una empresa requiere un sistema para administrar su nómina de empleados.
Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
*******************************************************************************
----------El sistema deberá tener el siguiente menú de opciones:---------------
*******************************************************************************
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente
   el número de Id. El resto de los campos se le pedirá al usuario.
*******************************************************************************
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar:
   o Nombre
   o Apellido
   o Salario
   o Sector
*******************************************************************************
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
*******************************************************************************
4. INFORMAR:
    1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
    2. Total y promedio de los salarios, y cuántos empleados superan el salario
    promedio.
*******************************************************************************
NOTA: Se deberá realizar el menú de opciones y las validaciones a través de
funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber
realizado la carga de algún empleado.
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





