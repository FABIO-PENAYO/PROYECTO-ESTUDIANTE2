#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct students{
	int id;
	string nombre;
	float nota;
};



void menu ();
bool agregar_estudiantes(students est);
void mostrar_estudiantes();

bool actualizar_estudiantes(int id_estudiante);
bool eliminar_estudiante(int id_estudiante);


int main(){
	menu();
	
}


bool agregar_estudiantes(students est){
	
	ofstream archivo;
	archivo.open("lista.txt",ios::app);
	
	cout<<"eligio la opcion agregar estudiantes: "<<endl;
	cout<<"ingrese el nombre del estudiante: ";
	cin>>est.nombre;
	cout<<"ingrese la nota del estudiante: ";
	cin>>est.nota;

	est.id = 1 + rand() % 100;
	if(archivo.fail()){
		cout<<"error\n";
		return false;
	}	
	archivo << est.id << " " << est.nombre << " " << est.nota << "\n";
    archivo.close();
    return true;

}



void mostrar_estudiantes(){
	cout<<"LISTA DE ESTUDIANTES:"<<endl;
	
	ifstream archivo;
	string linea;
	archivo.open("lista.txt");
	
	if(archivo.fail()){
		cout<<"Error al abrir el archivo. intente de nuevo \n";
	}
	while(!archivo.eof()){
		getline(archivo,linea);
		cout << linea <<endl;
	}
}

// Función para actualizar un estudiante en el archivo de texto
/*bool actualizarEstudiante(int id) {
    ifstream archivo("estudiantes.txt");
    ofstream archivoTemporal("temp.txt");
    if (!archivo || !archivoTemporal) {
        cout << "Error al abrir los archivos." << endl;
        return false;
    }

    Estudiante estudiante;
    bool encontrado = false;

    while (archivo >> estudiante.id >> estudiante.nombre >> estudiante.nota) {
        if (estudiante.id == id) {
            cout << "Ingrese el nuevo nombre: ";
            cin.ignore();
            getline(cin, estudiante.nombre);
            cout << "Ingrese la nueva nota: ";
            cin >> estudiante.nota;
            encontrado = true;
        }
        archivoTemporal << estudiante.id << " " << estudiante.nombre << " " << estudiante.nota << endl;
    }

    archivo.close();
    archivoTemporal.close();

    if (encontrado) {
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");
        cout << "Estudiante actualizado correctamente." << endl;
    } else {
        remove("temp.txt");
        cout << "Estudiante con ID " << id << " no encontrado." << endl;
    }
    return encontrado;
}
*/

bool actualizar_estudiantes(int id_estudiante){


	students est;
	ofstream archivo1;
	ifstream archivo;
	
	
	archivo.open("lista.txt", ios::in);
	archivo1.open("temp.txt");
	bool encontrado = false;
	
	
	cout<<"INGRESE EL NUMERO DE IDENTIFICACION DEL ESTUDIANTE QUE DESEA ACTUALIZAR:";
	cin>> id_estudiante;
	
	
	if(archivo.fail() || archivo1.fail()){
		cout<<"error al abrir el archivo"<<endl;
		return false;
	}
	
	
	
	while ( archivo >> est.id >> est.nombre >> est.nota){
		if(est.id == id_estudiante){
			cout<<"ESTUDIANTE ENCONTRADO"<<endl;
			cout << "INGRESE EL NUEVO NOMBRE: ";
			cin.ignore();
			getline(cin , est.nombre);
			cout <<" INGRESE LA NUEVA NOTA: ";
			cin >> est.nota;
			encontrado = true;
		}
		archivo1 << est.id << " " << est.nombre << " " << est.nota << "\n";
	}
	
	
	archivo1.close();
	archivo.close();


	
	
	
	if(encontrado){
		remove("lista.txt");
		rename("temp.txt","lista.txt");
		cout << "Estudiante actualizado correctamente." << endl;
	}
	else{
		remove("temp.txt");
		cout<<"EL USUARIO NO FUE ENCONTRADO DENTRO DEL SISTEMA"<<endl;
	}

	return true;
	
}


// Función para eliminar un estudiante en el archivo de texto
/*bool eliminarEstudiante(int id) {
    ifstream archivo("estudiantes.txt");
    ofstream archivoTemporal("temp.txt");
    if (!archivo || !archivoTemporal) {
        cout << "Error al abrir los archivos." << endl;
        return false;
    }

    Estudiante estudiante;
    bool encontrado = false;

    while (archivo >> estudiante.id >> estudiante.nombre >> estudiante.nota) {
        if (estudiante.id != id) {
            archivoTemporal << estudiante.id << " " << estudiante.nombre << " " << estudiante.nota << endl;
        } else {
            encontrado = true;
        }
    }

    archivo.close();
    archivoTemporal.close();

    if (encontrado) {
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");
        cout << "Estudiante eliminado correctamente." << endl;
    } else {
        remove("temp.txt");
        cout << "Estudiante con ID " << id << " no encontrado." << endl;
    }
    return encontrado;
}*/





bool eliminar_estudiante( int id_estudiante){
	
	students est;
	
	ifstream archivo("lista.txt",ios::in);//
	ofstream archivo1("temp.txt");//para abrir el archivo y que lo nuevo se agregue al final de la linea
	
	string linea;
	
	bool encontrado = false;
	
	if(archivo.fail() || archivo1.fail()){//si el archivo tiene problemas de lectura devuelve true si no los tiene devuelve false
		cout<<"error al abrir el archivo"<<"\n";
		return false;
	}
	
	
	
	while(archivo >> est.id >> est.nombre >> est.nota){//el contenido del archivo se guarda en las variables est.id etc.
		if(est.id != id_estudiante){
			archivo1 << est.id << "," << est.nombre << "," << est.nota <<endl;
		}
		else{
			encontrado = true;
		}	
	}
	
	if(encontrado == true){
		remove("lista.txt");//si el 
		rename("temporal.txt","lista.txt");
		cout<<"ESTUDIANTE ELIMINADO"<<endl;
	}
	else{
		remove("temporal.txt");
		cout<<"EL USUARIO NO FUE ENCONTRADO EN EL SISTEMA"<<endl;
	}
	return encontrado;
	
}








void menu(){
	int opcion;
	int id_estudiante;
	students est;
	cout<<"BIENVENIDOS A COMPAÑIAS FERDOR"<<endl;
	cout<<"ingrese la opcion que desea ingresar"<<endl;
	cout<<"---------MENU---------"<<endl;
	cout<<" 1	agregar estudiante"<<endl;
	cout<<" 2	mostrar todos los estudiantes"<<endl;
	cout<<" 3	actualizar estudiante"<<endl;
	cout<<" 4	eliminar estudiante"<<endl;
	cout<<" 0	salir"<<endl;
	cout<<"OPCION: ";
	cin>>opcion ;
	do{
		if(opcion ==1){
			if(agregar_estudiantes(est)){
				cout << "Estudiante agregado correctamente." << endl;
			}
			else{
				cout<<" ERROR AL AGREGAR NUEVO ESTUDIANTE" <<endl;
			}
			menu();
			break;
		}
		if(opcion ==2){
			mostrar_estudiantes();
			menu();
			break;
		}
		if(opcion ==3){
			if(actualizar_estudiantes(id_estudiante) == true){
				cout<<"ESTUDIANTE ACTUALIZADO CORRECTAMENTE"<<endl;
			}
			else{
				cout<<"ERROR AL ACTUALIZAR AL ESTUDIANTE"<<endl;
			}
			menu();
			break;
		}
		if(opcion ==4){
			cout<<"INGRESE EL ID DEL ALUMNO A ELIMINAR: ";
			cin >> id_estudiante;
			if(eliminar_estudiante(id_estudiante)){
				cout<<"Estudiante Eliminado Correctamente"<<endl;
			}
			else{
				cout<<"ERROR AL ELIMINAR ESTUDIANTE"<<endl;
			}
			menu();
			break;
		}
		if(opcion ==0){
			break;
		}
		else{
			cout<<"ERROR, OPCION NO VALIDA INTENTE DE NUEVO."<<endl;
			menu();
		}
		
	}while(opcion != 0);
}
