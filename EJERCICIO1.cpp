/* 1. Gestión de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes características: nombres completos,
sexo, edad, teléfono, email, nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com,
outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del
mismo.
*/
#include <iostream>

#include <string>
using namespace std;
const int MaxContactos=100;
struct ContactoEmail{
	string nombre;
	string sexo;
	string email;
	string nacionalidad;
	int edad;
	string telefono;
};
 void AgregarContacto(ContactoEmail Contactos[], int& cantidad){
 	if(cantidad<MaxContactos){
 		ContactoEmail NuevoContacto;
 		 cin.ignore();
 		cout << "Ingrese nombres completos del usuario: ";
        getline(cin,NuevoContacto.nombre);
        cout << "Ingrese sexo: ";
        getline(cin, NuevoContacto.sexo);
		cout << "Ingrese edad: ";
        cin >> NuevoContacto.edad;
        cout << "Ingrese teléfono: ";
        cin >> NuevoContacto.telefono;
        cout << "Ingrese email: ";
        cin >> NuevoContacto.email;
        cout << "Ingrese nacionalidad: ";
        cin >> NuevoContacto.nacionalidad;
	Contactos[cantidad++]=NuevoContacto;
	 }else{
	 	cout<<"NO SE PUEDEN AGREGAR MAS CONTACTOS";
	 }
 	
 }

int main(){
	ContactoEmail Contactos[MaxContactos];
int cantidad=0;
int op;

	do {
        cout << "MENU GESTION DE CONTACTOS\n";
        cout << "1. Agregar un contacto\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> op;

        switch (op) {
            case 1:
                AgregarContacto(Contactos, cantidad);
                break;
           
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }

    } while (op!= 5);
    
	return 0;
}