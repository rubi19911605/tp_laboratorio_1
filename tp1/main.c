#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"   // llamo las funciones de las operaciones

int main ()
{
// declaro las variables locales
  int num1;
  int num2;
  char operacion;
  char respuesta;
  respuesta = 's';

do {

//pido num1
  printf ("\nIngrese un numero: ");
  scanf ("%d", &num1);

//pido num2
  printf ("\nIngrese un numero: ");
  fflush( stdin );
  scanf ("%d", &num2);

  //pido el tipo de operacion
  printf ("\nIngrese el tipo de operacion que desea realizar:\n (a)suma \n (b)resta \n (c)multiplicacion \n (d)division \n (e)factorial n! \n");
  fflush( stdin );
  scanf ("%c",&operacion);

// imprimo los resultados de acuerdo a la operacion seleccionada por el usuario:

switch (operacion)
	{
	case 'a':
	  printf (" \n la Suma es: %d \n", suma2num (num1, num2));
	  break;
	case 'b':
	  printf (" \n la resta es: %d \n", resta2num (num1, num2));
	  break;
	case 'c':
	  printf (" \n la multiplicacion es: %d \n", multiplica2num (num1, num2));
	  break;
	case 'd':
	  printf (" \n la division es: %.2f \n", divide2num (num1, num2));
	  break;
    case 'e':
	  printf (" \n el factorial del primer numero es: %f", factorial (num1));
      printf (" \n el factorial del segundo numero es: %f \n", factorial (num2));
	  break;

	}
// le pregunto al usuario si desa realizar otra operacion.
printf ("\n Desea realizar otra operacion: 's': ");
  fflush( stdin );
  scanf ("%c", &respuesta);
}while (respuesta == 's');

  return 0;
}
