#include<iostream>
#include<string>

using namespace std;

class persona{
	protected:
		string nombre;
		string DNI;
		int edad;
	public:
		persona(string, string, int);
		void mostrarDatos();
};

persona :: persona (string n, string D, int e){
	nombre = n;
	DNI = D;
	edad = e;
}

void persona :: mostrarDatos(){
	cout << nombre << ", su edad es " << edad << " anio, y suDNI es " << DNI << endl;
}

class Docente : public persona{
	private:
		int sueldo;
		string especialidad;
	public:
		Docente(string, string, int, int, string);
		void mostrarDocente();
};

Docente :: Docente(string n, string D, int e, int s, string es) : persona(n,D,e){
	sueldo = s;
	especialidad = es;
}

void Docente :: mostrarDocente(){
	mostrarDatos();
	cout << "el docente mencionado, se especialisa en " << especialidad;
	cout << " , con un sueldo de S/" << sueldo << endl;
}

class estudiante: public persona{
	private:
		int notas[5];
		int nNotas;
		string codigo;
	public:
		estudiante(string, string, int, int [], int, string);
		void mostrarEstudiante();
};

estudiante :: estudiante(string n, string D, int e, int no[], int nN, string c) : persona(n,D,e){
	nNotas = nN;
	for(int i=0; i<nN; i++){
		cout << no[i] << " ";
	}
	cout<<endl;
	codigo = c;
}

void estudiante :: mostrarEstudiante(){
	mostrarDatos();
	cout << " su codigo es: " << codigo << " ,el estudiante mencionado tiene " << nNotas;
	cout << " notas: ";
	for(int i=0; i<nNotas; i++){
		cout << notas[i] << " ";
	}
	cout << endl;
}

int main(){
	string nombre;
	persona p("Pablo Francisco", "342396720", 30);
	p.mostrarDatos();
	cout << endl;
	Docente d("Carlos de la Cruz", "847190389", 35, 2000, "Matematica");
	d.mostrarDocente();
	cout << endl;
	int nota[] = { 15, 14, 9, 15};
	cout << "Ingresar nombre del estudiante: ";
	fflush (stdin);
	getline(cin, nombre);
	estudiante e(nombre, "943618395", 17, nota, 4, "2024-119023");
	e.mostrarEstudiante();
	cout << endl;
	return 0;
}
