#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definici�n de estructuras para libros, usuarios y bibliotecarios
struct SLibro {
	string sTitulo;
	string sAutor;
	string sISBN;
	int nAnoPublicacion;
	string sGenero;
	string sEditorial;
	int nNumPaginas;
};

struct SUsuario {
	int nIdUsuario;
	string sNombre;
	string sApellido;
	string sCorreoElectronico;
	string sDireccion;
};

struct SBibliotecario {
	int nIdEmpleado;
	string sNombre;
	string sApellido;
	string sCorreoElectronico;
	string sDepartamento;
};

// Arrays de datos predefinidos para libros, usuarios y bibliotecarios
string sTitulosLibros[] = {"Canci�n de hielo y fuego", "1984", "El juego de Ender", "Introducci�n a la programaci�n", "Programaci�n avanzada"};
string sAutoresLibros[] = {"George R.R. Martin", "George Orwell", "Orson Scott Card", "Autor 1", "Autor 2"};
int nAnosLibros[] = {1985, 1949, 1956, 2020, 2022};
string sISBNs[] = {"1", "2", "3", "4", "5"};
string sGeneros[] = {"Fantas�a", "Ciencia ficci�n", "Ficci�n", "Tecnolog�a", "Tecnolog�a"};
string sEditoriales[] = {"Editorial A", "Editorial B", "Editorial C", "Editorial D", "Editorial E"};
string sNombresUsuarios[] = {"Juan", "Maria", "Pedro"};
string sApellidosUsuarios[] = {"Gomez", "Lopez", "Martinez"};
string sDirecciones[] = {"CALLE PEREZ", "CALLE ABUNA", "CALLE ITENEZ"};
string sNombresBibliotecarios[] = {"Ana", "Carlos", "Luis"};
string sApellidosBibliotecarios[] = {"Perez", "Rodriguez", "Garcia"};
string sDepartamentosBibliotecarios[] = {"Secci�n de Ficci�n", "Secci�n de No Ficci�n", "Secci�n Infantil"};

// Funci�n para llenar los datos de libros, usuarios y bibliotecarios de manera aleatoria
void LlenarDatos(SLibro libros[], int nNumLibros, SUsuario usuarios[], int nNumUsuarios, SBibliotecario bibliotecarios[], int nNumBibliotecarios, int libroIndex = 0, int usuarioIndex = 0, int bibliotecarioIndex = 0) {
	// Llenar datos para libros
	if (libroIndex < nNumLibros) {
		libros[libroIndex] = {sTitulosLibros[libroIndex], sAutoresLibros[libroIndex], sISBNs[libroIndex], nAnosLibros[libroIndex], sGeneros[libroIndex], sEditoriales[libroIndex], rand() % 401 + 100};
		LlenarDatos(libros, nNumLibros, usuarios, nNumUsuarios, bibliotecarios, nNumBibliotecarios, libroIndex + 1, usuarioIndex, bibliotecarioIndex);
	}
	// Llenar datos para usuarios
	if (usuarioIndex < nNumUsuarios) {
		usuarios[usuarioIndex] = {usuarioIndex + 1, sNombresUsuarios[usuarioIndex], sApellidosUsuarios[usuarioIndex], "", sDirecciones[usuarioIndex]};
		// Generar correo electr�nico para usuario
		usuarios[usuarioIndex].sCorreoElectronico = sNombresUsuarios[usuarioIndex] + sApellidosUsuarios[usuarioIndex] + "@gmail.com";
		LlenarDatos(libros, nNumLibros, usuarios, nNumUsuarios, bibliotecarios, nNumBibliotecarios, libroIndex, usuarioIndex + 1, bibliotecarioIndex);
	}
	// Llenar datos para bibliotecarios
	if (bibliotecarioIndex < nNumBibliotecarios) {
		bibliotecarios[bibliotecarioIndex] = {bibliotecarioIndex + 1, sNombresBibliotecarios[bibliotecarioIndex], sApellidosBibliotecarios[bibliotecarioIndex], "", sDepartamentosBibliotecarios[bibliotecarioIndex]};
		// Generar correo electr�nico para bibliotecario
		bibliotecarios[bibliotecarioIndex].sCorreoElectronico = sNombresBibliotecarios[bibliotecarioIndex] + sApellidosBibliotecarios[bibliotecarioIndex] + "@gmail.com";
		LlenarDatos(libros, nNumLibros, usuarios, nNumUsuarios, bibliotecarios, nNumBibliotecarios, libroIndex, usuarioIndex, bibliotecarioIndex + 1);
	}
}

// Funci�n para imprimir los datos de los libros
void ImprimirLibros(const SLibro libros[], int nNumLibros, int nIndex = 0) {
	if (nIndex == nNumLibros) return;
	cout << "Libro " << nIndex + 1 << ": ";
	cout << "T�tulo: " << libros[nIndex].sTitulo << ", ";
	cout << "Autor: " << libros[nIndex].sAutor << ", ";
	cout << "ISBN: " << libros[nIndex].sISBN << ", ";
	cout << "A�o de Publicaci�n: " << libros[nIndex].nAnoPublicacion << ", ";
	cout << "G�nero: " << libros[nIndex].sGenero << ", ";
	cout << "Editorial: " << libros[nIndex].sEditorial << ", ";
	cout << "N�mero de P�ginas: " << libros[nIndex].nNumPaginas << endl;
	ImprimirLibros(libros, nNumLibros, ++nIndex);
}

// Funci�n para imprimir los datos de un usuario
void ImprimirUsuario(const SUsuario &usuario) {
	cout << "Usuario " << usuario.nIdUsuario << ": "
		<< "Nombre: " << usuario.sNombre << " "
		<< "Apellido: " << usuario.sApellido << " "
		<< "Correo Electr�nico: " << usuario.sCorreoElectronico << " "
		<< "Direcci�n: " << usuario.sDireccion << endl;
}

// Funci�n para imprimir los datos de un bibliotecario
void ImprimirBibliotecario(const SBibliotecario &bibliotecario) {
	cout << "Bibliotecario " << bibliotecario.nIdEmpleado << ": "
		<< "Nombre: " << bibliotecario.sNombre << " "
		<< "Apellido: " << bibliotecario.sApellido << " "
		<< "Correo Electr�nico: " << bibliotecario.sCorreoElectronico << " "
		<< "Departamento: " << bibliotecario.sDepartamento << endl;
}

// Funci�n para buscar un usuario por nombre y apellido
void BuscarUsuario(const string& sNombre, const string& sApellido, const SUsuario usuarios[], int nNumUsuarios) {
	int contadorNombre = 0; // Contador para coincidencias en el nombre
	int contadorApellido = 0; // Contador para coincidencias en el apellido
	
	// Iterar sobre el arreglo de usuarios
	for (int i = 0; i < nNumUsuarios; ++i) {
		// Buscar coincidencias en el nombre
		if (usuarios[i].sNombre.find(sNombre) != string::npos) {
			contadorNombre++; // Incrementar el contador de coincidencias en nombre
		}
		// Buscar coincidencias en el apellido
		if (usuarios[i].sApellido.find(sApellido) != string::npos) {
			contadorApellido++; // Incrementar el contador de coincidencias en apellido
			cout << "Usuario encontrado:" << endl;
			ImprimirUsuario(usuarios[i]); // Imprimir el usuario encontrado
		}
	}
	
	// Imprimir el total de coincidencias encontradas
	cout << "Coincidencias en nombre: " << contadorNombre << endl;
	cout << "Coincidencias en apellido: " << contadorApellido << endl;
}

// Funci�n para buscar un bibliotecario por nombre y apellido
void BuscarBibliotecario(const string& sNombre, const string& sApellido, const SBibliotecario bibliotecarios[], int nNumBibliotecarios) {
	int contadorNombre = 0; // Contador para coincidencias en el nombre
	int contadorApellido = 0; // Contador para coincidencias en el apellido
	
	// Iterar sobre el arreglo de bibliotecarios
	for (int i = 0; i < nNumBibliotecarios; ++i) {
		// Buscar coincidencias en el nombre
		if (bibliotecarios[i].sNombre.find(sNombre) != string::npos) {
			contadorNombre++; // Incrementar el contador de coincidencias en nombre
		}
		// Buscar coincidencias en el apellido
		if (bibliotecarios[i].sApellido.find(sApellido) != string::npos) {
			contadorApellido++; // Incrementar el contador de coincidencias en apellido
			cout << "Bibliotecario encontrado:" << endl;
			ImprimirBibliotecario(bibliotecarios[i]); // Imprimir el bibliotecario encontrado
		}
	}
	
	// Imprimir el total de coincidencias encontradas
	cout << "Coincidencias en nombre: " << contadorNombre << endl;
	cout << "Coincidencias en apellido: " << contadorApellido << endl;
}

// Funci�n para buscar un libro por t�tulo
void BuscarLibro(const string& sBusqueda, const SLibro libros[], int nNumLibros) {
	int contador = 0; // Contador para el total de libros encontrados
	
	// Imprimir el resultado de la b�squeda
	cout << "Resultado de la b�squeda para \"" << sBusqueda << "\": ";
	
	// Iterar sobre el arreglo de libros
	for (int i = 0; i < nNumLibros; ++i) {
		// Buscar coincidencias en el t�tulo del libro
		if (libros[i].sTitulo.find(sBusqueda) != string::npos) {
			contador++; // Incrementar el contador de libros encontrados
			cout << endl << "-" << libros[i].sTitulo; // Imprimir el t�tulo del libro encontrado
		}
	}
	
	// Imprimir el total de libros encontrados
	cout << endl;
	cout << "Total de libros encontrados: " << contador << endl;
}

// Funci�n principal
int main() {
	// Definici�n de constantes para el n�mero de libros, usuarios y bibliotecarios
	const int NUM_LIBROS = 5; // N�mero de libros predefinidos
	const int NUM_USUARIOS = 3; // N�mero de usuarios predefinidos
	const int NUM_BIBLIOTECARIOS = 3; // N�mero de bibliotecarios predefinidos
	
	// Inicializaci�n de la semilla para la generaci�n de n�meros aleatorios
	srand(time(nullptr));
	
	// Declaraci�n de arreglos para almacenar libros, usuarios y bibliotecarios
	SLibro libros[NUM_LIBROS]; // Arreglo para almacenar los datos de los libros
	SUsuario usuarios[NUM_USUARIOS]; // Arreglo para almacenar los datos de los usuarios
	SBibliotecario bibliotecarios[NUM_BIBLIOTECARIOS]; // Arreglo para almacenar los datos de los bibliotecarios
	
	// Variable para almacenar la opci�n seleccionada en el men� principal
	int opcion;
	do {
		// Men� principal
		cout << "MENU" << endl;
		cout << "1) Llenar Datos" << endl;
		cout << "2) Listados" << endl;
		cout << "3) B�squeda" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opci�n: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: {
			// Llenar datos de libros, usuarios y bibliotecarios
			LlenarDatos(libros, NUM_LIBROS, usuarios, NUM_USUARIOS, bibliotecarios, NUM_BIBLIOTECARIOS);
			cout << "Datos llenados exitosamente." << endl;
			cout << "Presione Enter para continuar..." << endl;
			cin.ignore(); // Para esperar a que el usuario presione Enter
			cin.get();    // Para esperar a que el usuario presione Enter
			break;
		}
		case 2: {
			char subopcion;
			do {
				// Men� de listados
				cout << "SUBMENU DE LISTADOS" << endl;
				cout << "A) Lista de Usuarios" << endl;
				cout << "B) Lista de Bibliotecarios" << endl;
				cout << "C) Lista de Libros" << endl;
				cout << "X) Salir" << endl;
				cout << "Ingrese una opci�n: ";
				cin >> subopcion;
				
				switch (subopcion) {
				case 'A':
				case 'a':
					// Imprimir lista de usuarios
					for (int i = 0; i < NUM_USUARIOS; ++i) {
						ImprimirUsuario(usuarios[i]);
					}
					break;
				case 'B':
				case 'b':
					// Imprimir lista de bibliotecarios
					for (int i = 0; i < NUM_BIBLIOTECARIOS; ++i) {
						ImprimirBibliotecario(bibliotecarios[i]);
					}
					break;
				case 'C':
				case 'c':
					// Imprimir lista de libros
					ImprimirLibros(libros, NUM_LIBROS);
					break;
				case 'X':
				case 'x':
					break;
				default:
					cout << "Opci�n no v�lida." << endl;
				}
			} while (subopcion != 'X' && subopcion != 'x');
			break;
		}
		case 3: {
			char subopcion;
			do {
				// Men� de b�squeda
				cout << "SUBMENU DE BUSQUEDA" << endl;
				cout << "A) B�squeda de Libro (T�tulo)" << endl;
				cout << "B) B�squeda de Usuario (Nombre y Apellido)" << endl;
				cout << "C) B�squeda de Bibliotecario (Nombre y Apellido)" << endl;
				cout << "X) Salir" << endl;
				cout << "Ingrese una opci�n: ";
				cin >> subopcion;
				
				switch (subopcion) {
				case 'A':
				case 'a': {
					// B�squeda de libro por t�tulo
					string sTitulo;
					cout << "Ingrese el t�tulo del libro a buscar: ";
					cin.ignore();
					getline(cin, sTitulo);
					BuscarLibro(sTitulo, libros, NUM_LIBROS);
					break;
				}
				case 'B':
				case 'b': {
					// B�squeda de usuario por nombre y apellido
					string sNombre, sApellido;
					cout << "Ingrese el nombre del usuario: ";
					cin >> sNombre;
					cout << "Ingrese el apellido del usuario: ";
					cin >> sApellido;
					BuscarUsuario(sNombre, sApellido, usuarios, NUM_USUARIOS);
					break;
				}
				case 'C':
				case 'c': {
					// B�squeda de bibliotecario por nombre y apellido
					string sNombre, sApellido;
					cout << "Ingrese el nombre del bibliotecario: ";
					cin >> sNombre;
					cout << "Ingrese el apellido del bibliotecario: ";
					cin >> sApellido;
					BuscarBibliotecario(sNombre, sApellido, bibliotecarios, NUM_BIBLIOTECARIOS);
					break;
				}
				case 'X':
				case 'x':
					break;
				default:
					cout << "Opci�n no v�lida." << endl;
				}
			} while (subopcion != 'X' && subopcion != 'x');
			break;
		}
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opci�n no v�lida." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}
