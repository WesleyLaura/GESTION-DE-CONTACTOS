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
#include <windows.h>
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

void MostrarContactos(const ContactoEmail Contactos[], int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        cout << "Nombres completos: " << Contactos[i].nombre << endl
             << "Sexo: " << Contactos[i].sexo << endl
             << "Edad: " << Contactos[i].edad << endl
             << "Teléfono: " << Contactos[i].telefono << endl
             << "Email: " << Contactos[i].email << endl
             << "Nacionalidad: " << Contactos[i].nacionalidad << endl
             << "---------------------------------------------------\n";
    }
}

void EliminarContacto(ContactoEmail Contactos[], int& cantidad) {
    string nombre1;
    cout << "Ingrese los nombres completos del contacto a eliminar: ";
    cin.ignore();
    getline(cin, nombre1);
    bool encontrado = false;
    for (int i = 0; i < cantidad; ++i) {
        if (Contactos[i].nombre == nombre1) {
            for (int j = i; j < cantidad - 1; ++j) {
                Contactos[j] = Contactos[j + 1];
            }
            --cantidad;
            encontrado = true;
            cout << "Contacto eliminado.\n";
            break;
        }
    }
    if (encontrado==false) {
        cout << "Contacto no encontrado.\n";
    }
}

void mostrarContactosPorServidor(ContactoEmail Contactos[], int cantidad) {
    ContactoEmail gmail[MaxContactos], outlook[MaxContactos], yahoo[MaxContactos], otros[MaxContactos];
    int gmailCount = 0, outlookCount = 0, yahooCount = 0, otrosCount = 0;

    for (int i = 0; i < cantidad; ++i) {
        if (Contactos[i].email.find("gmail.com") != string::npos) {
            gmail[gmailCount++] = Contactos[i];
        } else if (Contactos[i].email.find("outlook.com") != string::npos) {
            outlook[outlookCount++] = Contactos[i];
        } else if (Contactos[i].email.find("yahoo.com") != string::npos) {
            yahoo[yahooCount++] = Contactos[i];
        } else {
            otros[otrosCount++] = Contactos[i];
        }
    }

    auto printContacts = [](const ContactoEmail Contactos[], int count) {
        for (int i = 0; i < count; ++i) {
            cout << Contactos[i].email << " - " << Contactos[i].nombre<< '\n';
        }
    };

    cout << "Contactos con gmail.com:\n";
    printContacts(gmail, gmailCount);
    cout << "Contactos con outlook.com:\n";
    printContacts(outlook, outlookCount);
    cout << "Contactos con yahoo.com:\n";
    printContacts(yahoo, yahooCount);
    cout << "Contactos con otros servidores:\n";
    printContacts(otros, otrosCount);
}

int main(){
	SetConsoleOutputCP(CP_UTF8);
	ContactoEmail Contactos[MaxContactos];
	int cantidad=0;
	int op;

	do {
        cout << "---------------MENU GESTION DE CONTACTOS---------------\n";
        cout << "1. Agregar un contacto\n";
        cout<<  "2. Mostrar contactos\n";
        cout<<  "3. Eliminar contacto\n";
        cout<<  "4. Mostrar listado de contactos existentes por TIPO DE SERVIDOR DE CORREO\n";
        cout << "5. Salir\n";
        cout << "\n\nIngrese una opción:";
        cin >> op;

        switch (op) {
            case 1:
                AgregarContacto(Contactos, cantidad);
                break;
            case 2:
				MostrarContactos(Contactos, cantidad);  
           		break;
           	case 3:
			    EliminarContacto(Contactos,cantidad);	
			 	break;
			case 4:
				 mostrarContactosPorServidor(Contactos,cantidad);
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