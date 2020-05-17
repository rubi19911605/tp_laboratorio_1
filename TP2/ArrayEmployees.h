#define cls 1
#define TAMANIO 51
#define CANTIDAD 1000
#define LIBRE -1

 typedef struct
  {
      int id;
     char nombre   [TAMANIO];
     char apellido [TAMANIO];
    float salario;
      int sector;
      int isEmpty;
  } eEmpleado;
int inicilizarEmpleados (eEmpleado lista[], int tam);
int opcionModificar (eEmpleado miEmpleado);
int MenuMostrarDatos ();
int  inicilizarEmpleados(eEmpleado listaEmpleados[], int tam);
int addEmployee (eEmpleado listaEmpleados[], int tam, int idNext);
int BuscarLibre (eEmpleado listaEmpleados[], int tam);
int confirmar ();
void limpiarPantalla();
eEmpleado CargarEmpleado (int idEmpleado);
int ModificarEmpleados ( eEmpleado listaEmpleados[], int tam );
int findEmployeeById (eEmpleado listaEmpleados[], int tam, int input);
int removeEmployee (eEmpleado listaEmpleados[], int tam);
void OrdenarPorApellidoSector(eEmpleado listaEmpleados[], int tam);
int printEmployees(eEmpleado listaEmpleados[], int tam, int cont);
float sumaSalarios (eEmpleado listaEmpleados[], int tam);
int terminar();
