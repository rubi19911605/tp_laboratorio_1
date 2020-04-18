#include <stdio.h>
// la funcion resta dos numeros
int resta2num (int lol1, int lol2)
{
  int resultado;

  resultado = lol1 - lol2;
  return resultado;
}

// la funcion suma dos numeros
int suma2num (int lol1, int lol2)
{
  int resultado;

  resultado = lol1 + lol2;
  return resultado;
}

// la funcion multiplica dos numeros
int multiplica2num (int lol1, int lol2)
{
  int resultado;

  resultado = lol1 * lol2;
  return resultado;
}

// la funcion divide dos numeros
float divide2num (int lol1, int lol2)
{
  int resultado;

  if (lol1 == 0 || lol2 == 0)
    {
    printf ("\n no se puede dividir por 0");

    }
  else

    resultado = (float) lol1 / lol2;

  return resultado;
}
// la funcion factorial
double factorial (int lol1)

{
double factorial;
factorial =1;


for (int i=1; i<=lol1;i++)
{
factorial = factorial * i;
}
return factorial;


}
