#include<iostream>

using namespace std;

class vehiculo{ // clase base
	protected:
		string placa;
		string color;
		string marca;
		double veloc;
	public:
		Vehiculo(string, string, string, double);
		void mostrarVeh();
		cambVeloc(double);
};

vehiculo :: Vehiculo(string p, string c, string m, double v){
	placa = p;
	color = c;
	marca = m;
	veloc = v;
}

void vehiculo :: mostarVeh(){
	cout << "La marca del vehiculo color " << color << " es " << marca;
	cout << " , tiene una velocidad de " << veloc << endl;
	cout << "Su numero de placa es: " << placa << endl;
}

void vehiculo :: cambVeloc(double v){
	veloc = v;
}

// clase derivada Automovil
class automovil : public vehiculo{
	private:
		int cantPuert;
		int cantPasaj;
	public:
		Automovil(int, int);
		void mostrarAuto();
		subirPasj(int);
		bajarPasj(int);
};

automovil :: Automovil(string p, string c, string m, double v, int cantPrt, int cantPsj) : vehiculo(p,c,m,v){
	cantPuerta = cantPrt;
	cantPasaj = cantPsj;
}

void automovil :: mostrarAuto(){
	cout << "Este automovil tiene " << cantPuert << " puertas ";
	cout << "y hay " << cantPasaj << " pasajero/s" << endl;
}

void automovil :: subirPasj(int n){
	if(cantPasj >= n){
		cantPasj = cantPasj - n;
	}else{
		cout << "No se puede quitar esa cantidad " << endl;
	}
}

void automovil :: bajarPasj(int n){
	cantPasj = cantPasj + n;
}

int main(){
	
}