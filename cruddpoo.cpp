#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include <io.h>
#include <fcntl.h>
#include<cstdlib>
#include<fstream>


using namespace std;
const char *nombre_archivo = "archivo.dat";
	int opc;
struct Estudiante{

	int codigo;
	char nombre[50];
	char apellido[50];
	char direccion[50];
	int telefono;
};
void menu();

void ingresar_estudiante();
void ver_estudiante();
void modificar_estudiante();
void eliminar_estudiante();
main (){

    menu();
   
    opc;
    
      ingresar_estudiante();
     
	ver_estudiante();
	modificar_estudiante();
	eliminar_estudiante();
	return 0;	
	
	
}
void menu(){
		
		do{
	system("cls");
cout<<"----------MENU---------\n";
cout<<"\n 1. Ingresar Estudiante "<<endl;
cout<<"\n 2. Ver Estudiantes"<<endl;
cout<<"\n 3. modificar Estudiante"<<endl;
cout<<"\n 4. eliminar Estudiante"<<endl;
cout<<"\n ----Ingrese una Opcion----"<<endl;
cin>>opc;

switch(opc){
	case 1:
           ingresar_estudiante();
           break;

case 2:
	ver_estudiante();
	
	break;
	
case 3:
	modificar_estudiante();
	
case 4:
	eliminar_estudiante();
	

	
}
	
		system("pause");
		break;
}while(opc<=4);
	
}

void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombre_archivo, "ab"); // ab
	
	
		Estudiante estudiante;
		 string nombre,apellido,direccion;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
			cout<<"Ingrese la direccion: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str());
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		

		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
		
menu();

}


void ver_estudiante(){
system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	
		Estudiante estudiante;
		int id=0;
		fread(&estudiante,sizeof(Estudiante),1, archivo);
		do{
	        
				cout<<id<<"|"<<estudiante.codigo<<" | "<<estudiante.nombre<<" | "<<estudiante.apellido<<" | "<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;
			fread(&estudiante,sizeof(Estudiante),1, archivo);
			id+=1;
		
		}while(feof(archivo)==0);
system("pause");
menu();}


	


void modificar_estudiante (){
	FILE* archivo = fopen(nombre_archivo,"r+b");
			Estudiante estudiante;
			string nombre,apellido,direccion;
			int id=0;
			cout<<"Ingrese el Id que desea Modifica:";
			cin>>id;
			fseek(archivo,id*sizeof(Estudiante),SEEK_SET);
			
			cout<<"Ingrese Codigo:";
			cin>>estudiante.codigo;
			cin.ignore();
			
			
			cout<<"Ingrese Nombres:";
			getline(cin,nombre);
			strcpy(estudiante.nombre,nombre.c_str());
			
			cout<<"Ingrese Apellidos:";
			getline(cin,apellido);
			strcpy(estudiante.apellido,apellido.c_str());
			
				cout<<"Ingrese direccion:";
			getline(cin,direccion);
			strcpy(estudiante.direccion,direccion.c_str());
			
			cout<<"Ingrese Telefono:";
			cin>>estudiante.telefono;
			cin.ignore();
			fwrite(&estudiante,sizeof(Estudiante),1, archivo);
		fclose(archivo);
		menu();
		 }
		
		
void eliminar_estudiante(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	Estudiante estudiante;
	FILE* archivo = fopen(nombre_archivo, "rb");
	FILE* archivo_temp=fopen(nombre_archivo_temp,"w+b");
	int id=0,i=0;
		cout<<"ingrese el id a eliminar:"; 
	cin>>id; 

		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){

			if (i != id){
				fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
			} 

			i++; 
		}

		fclose(archivo_temp); 
		fclose(archivo); 

		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombre_archivo,"wb"); 

		while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
		}

	fclose(archivo_temp); 
	fclose(archivo); 
	menu();
		system("PAUSE");
		
}
	
















