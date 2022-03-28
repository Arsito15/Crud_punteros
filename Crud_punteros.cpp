#include <iostream>
#include <string.h>

using namespace std;
const char *nombre_archivo = "archivo.dat";
const char *nombre_archivo_temp = "archivo_aux.dat";
int opc = 0;

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
}estudiante,*p_estudiante = &estudiante;

void menu();
void crear();


main(){
menu();
}

void menu(){
	system("cls");
cout<<"1. Ingrese estudiante"<<endl;
cout<<"----------------------"<<endl;
cout<<"2. Salir"<<endl;
cout<<"----------------------"<<endl;
cout<<"Ingrese una opcion: ";
cin>>opc; 
			
	system("cls");
	
	switch(opc)
	{
		case 1: crear();		 		;break;
 		case 2: exit(-1);				;break;  
		default:cout<<"Opcion invalida";  
	}	
}

void crear(Estudiante *p_estudiante){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{
		fflush(stdin);
		cout<<"Ingrese Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese Telefono: ";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (Para si [s] / Para no [n]): ";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
}

}
