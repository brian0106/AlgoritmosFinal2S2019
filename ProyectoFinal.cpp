#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

//AGREGA UN ALUMNO AL ARCHIVO ABIERTO
void agregarAlumno (FILE * archivo) {
	char carnet[20]="", nombre[35]="", seccion[20]="";
	string otro = "s";
	while (otro == "s"){
		cout<<"ingrese el carnet"<<endl;
		cin.getline(carnet, 20);
		cout<<"ingrese el nombre"<<endl;
		cin.getline(nombre, 35);
		cout<<"ingrese la seccion"<<endl;
		cin.getline(seccion, 20);
		fprintf(archivo, "%s;%s;%s\n", carnet, nombre, seccion);
		cout<<"desea agregar otro? (s/n)"<<endl;
		cin>>otro;
		cin.ignore();
	}
}

//AGREGA UN LIBRO AL ARCHIVO ABIERTO
void agregarLibro (FILE * archivo) {
	char nombre[35]="", autor[35]="", editorial[35]="";
	string otro = "s";
	while (otro == "s"){
		cout<<"ingrese el nombre"<<endl;
		cin.getline(nombre, 35);
		cout<<"ingrese el autor"<<endl;
		cin.getline(autor, 35);
		cout<<"ingrese la editorial"<<endl;
		cin.getline(editorial, 35);
		fprintf(archivo, "%s;%s;%s\n", nombre, autor, editorial);
		cout<<"desea agregar otro? (s/n)"<<endl;
		cin>>otro;
		cin.ignore();
	}
}

//DEL MENU DE GESTION SI ELIGE AGREGAR PASA A ESTE METODO
//QUE RECIBE EL NOMBRE DEL ARCHIVO FISICO Y CUAL FUE LA
//ELECCION DEL CONTROL AL QUE SE QUERIA ACCEDER.
void agregar (string nombreArchivo, string control) {
	//SE CREA UN ARCHIVO CON EL NOMBRE QUE VENGA EN EL PARAMETRO
	FILE * archivo = fopen(nombreArchivo.c_str(), "a+");
	
	if(archivo != NULL){
		//USANDO EL ARCHIVO CREADO PODEMOS PARTIR A AGREGAR
		//ALUMNOS O LIBROS CON ESTA VALIDACION
		if (control == "ALUMNOS"){
			agregarAlumno(archivo);
		}else{
			agregarLibro(archivo);
		}
		
		//AL FINALIZAR EL CICLO DENTRO DE LOS METODOS ANTERIORES
		//SE CIERRA EL ARCHIVO ABIERTO.
		fclose(archivo);
	}
}

//MENU DE GESTION PARA ALUMNOS O PARA BIBLIOTECA
void menuGestion (string control, string nombreArchivo){
	int menu=0;
	while (menu != 5){
		cout<<"***** MENU DE CONTROL DE "<<control<<" *****"<<endl;
		cout<<"Que desea hacer?"<<endl;
		cout<<"1. Agregar\n2. Buscar\n3. Eliminar\n4. Modificar\n5. Regresar al menu principal"<<endl;
		cin>>menu;
		cin.ignore();
		if(menu==1){
			agregar(nombreArchivo, control);
		}
	}
}

//MENU PRINCIPAL DEL CUAL SE PUEDE ELEGIR SI ACCEDER A ALUMNOS O A BIBLIOTECA
int main () {
	int opcion = 0;
	while (opcion != 3){
		cout<<"1. Ingresar al control de alumnos\n2. Ingresar al control biblioteca\n3. Salir"<<endl;
		cin>>opcion;
		cin.ignore();
		if(opcion == 1){
			menuGestion("ALUMNOS", "datosALUMNOS.txt");
		}else if (opcion == 2){
			menuGestion("BIBLIOTECA", "datosBIBLIOTECA.txt");
		}
	}
	cout<<"eduardo garcia"<<endl;
}
