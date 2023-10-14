#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void leer();
void crear();
void actualizar();
void borrar ();

main () {
	leer();					
	crear();
	 	borrar();
   	actualizar ();
   	
   	
	system("pause");
}
void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		FILE* archivo = fopen(nombre_archivo,"w+b");
	}
	estudiante estudiante;
	int id=0;  // indice o posiscion del registro (fila) dentro del archivo
	fread (&estudiante,sizeof(estudiante),1,archivo);
	cout<<"______"<<endl;
	cout<<"id"<<"|"<<"codigo"<<"|"<<"nombres"<<"|"<<"apellidos"<<"|"<<"telefono"<<endl;
	do{
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
		fread (&estudiante,sizeof(estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
	
	
}
void crear(){
	
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	estudiante estudiante;
	do{ 
	fflush(stdin);
	cout<<"ingrese codigo:";
	cin>>estudiante.codigo;
	cin.ignore();
	
	cout<<"Ingrese Nombres:";
	cin.getline(estudiante.nombres,50);
	
		cout<<"Ingrese Apellidos:";
	cin.getline(estudiante.apellidos,50);
	
		cout<<"Ingrese Telefono:";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(estudiante),1,archivo);
	
	
	
	cout<<"desea ingresar otro estudiante (s/n);";
	cin>>res;
	}while(res=='s' || res=='s');
	fclose(archivo);
	leer();
	
}
void actualizar(){
	
	
	FILE* archivo = fopen(nombre_archivo,"r+b");//crea y borrar
	estudiante estudiante;
	int id=0;
	cout<<"ingrese el id que desea modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(estudiante),SEEK_SET);

	
	cout<<"ingrese codigo:";
	cin>>estudiante.codigo;
	cin.ignore();
	
	cout<<"Ingrese Nombres:";
	cin.getline(estudiante.nombres,50);
	
		cout<<"Ingrese Apellidos:";
	cin.getline(estudiante.apellidos,50);
	
		cout<<"Ingrese Telefono:";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(estudiante),1,archivo);
	

	fclose(archivo);
	leer();
}
void borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
		FILE* archivo = fopen(nombre_archivo,"w+b");
		FILE* archivo_temp = fopen(nombre_archivo_temp,"rb");
		estudiante estudiante;
		int id=0,id_n=0;
		cout<<"ingrese el id a eliminar:";
		cin>>id;
		while(fread (&estudiante,sizeof(estudiante),1,archivo));{
		if (id_n!=id)
				fwrite(&estudiante,sizeof(estudiante),1,archivo_temp);
		}
		id_n++;
		
		
		fclose(archivo);
		fclose(archivo_temp);
	 archivo = fopen(nombre_archivo,"r+b");
	 archivo_temp = fopen(nombre_archivo_temp,"wb");
	while(fread (&estudiante,sizeof(estudiante),1,archivo_temp));{
	fwrite(&estudiante,sizeof(estudiante),1,archivo);
}
		fclose(archivo);
		fclose(archivo_temp);
	leer();
