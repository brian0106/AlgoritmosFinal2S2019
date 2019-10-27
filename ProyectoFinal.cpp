#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void agregar (string nombreArchivo, string camposAPedir[], string datoIngresado[]) {
	FILE * archivo = fopen(nombreArchivo.c_str(), "a+");
	char valor[40];
	if(archivo != NULL){
		int len = *(&camposAPedir + 1) - camposAPedir;
		for(int i=0; i<len; i++){
			cout<<"Ingrese "<<camposAPedir[i]<<":"<<endl;
//			cin.ignore(0, EOF);-->arreglando
			cin.getline(valor, 40);
			fprintf(archivo, "%s;", valor);
		}
		fprintf(archivo, "\n");
		fclose(archivo);
	}
}

void menuGestion (string control, string nombreArchivo, string camposAPedir[], string datoIngresado[]){
	int menu=0;
	while (menu != 5){
		cout<<"***** MENU DE CONTROL DE "<<control<<" *****"<<endl;
		cout<<"¿Que desea hacer?"<<endl;
		cout<<"1. Agregar\n2. Buscar\n3. Eliminar\n4. Modificar\n5. Regresar al menu principal"<<endl;
		cin>>menu;
		if(menu==1){
			agregar(nombreArchivo, camposAPedir, datoIngresado);
		}
	}
}



int main () {
	int opcion = 0;
	while (opcion != 3){
		cout<<"1. Ingresar al control de alumnos\n2. Ingresar al control biblioteca\n3. Salir"<<endl;
		cin>>opcion;
		if(opcion == 1){
			string camposAlumno[4] = {"Carnet", "Seccion", "Nombre", "Semestre"};
			string datoIngresado[4] = {"","","",""};
			menuGestion("ALUMNOS", "datosAlumnos.txt", camposAlumno, datoIngresado);
		}else if (opcion == 2){
//			menuGestion("Biblioteca", "datosBiblioteca.txt");
		}
	}
	cout<<"eduardo garcia"<<endl;
}
