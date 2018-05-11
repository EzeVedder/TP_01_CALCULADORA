


typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;

}ePersona;

int esNumerico(char str[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int esSoloLetras(char str[]);
int verificarDni(ePersona persona[],int T,int dni);

int cargar(ePersona persona[],int T);
void mostrarPersona(ePersona persona);
void borrarPersona (ePersona persona[],int T);
void ordenarPersonas(ePersona persona[],int T);
void mostrarPersonas(ePersona persona[], int T);

void estadisticas(ePersona persona[],int T,int cont18,int cont19, int cont35);

int indexLibre(ePersona persona[],int T);

int menu(char mensaje[]);

/** \brief Muestra un mensaje y pide al usuario ingresar un string
 * \param  Pide el mensaje a ser mostrado
 * \param  Pide la cadena en la que el usuario va a escribir
 */

 void inicializarPersonas(ePersona persona[],int T);
