#include <iostream>
#include <cmath>

using namespace std;

//clase base
class figura{
	protected:
		string color;
	public:
		figura(string);
};

figura :: figura(string c){
	color = c;
}

//clase derivada
class circulo : public figura{
	private:
		double radio;
	public:
		circulo(string, double);
		void calcularAreaCir();
		void calcularPerimetro();
};

circulo :: circulo(string c, double r) : figura(c){
	radio = r;
}

void circulo :: calcularAreaCir(){
	double Area = (M_PI * pow(radio,2));
	cout << " El area del circulo " << color << " es " << Area << endl;
}

void circulo :: calcularPerimetro(){
	double Perimetro = (2 * M_PI * radio);
	cout << " El perimetro del circulo " << color <<" es " << Perimetro << endl;
}

// clase derivada 
class rectangulo : public figura{
	private:
		double base;
		double altura;
	public:
		rectangulo(string, double, double);
		void calcularAreaRec();
};

rectangulo :: rectangulo(string c, double b, double h) : figura(c){
	base = b;
	altura = h;
}

void rectangulo :: calcularAreaRec(){
	double area = base * altura;
	cout << " Su area del rectangulo " << color << " es: " << area << endl;
}

// clase derivada
class triangulo : public figura{
	private:
		double base;
		double altura;
		string tipo;
	public:
		triangulo(string, double, double, string);
		void calcularAreaTrian();
};

triangulo :: triangulo(string c, double b, double h, string t) : figura(c){
	base = b;
	altura = h;
	tipo = t;
}

void triangulo :: calcularAreaTrian(){
	double area = (base * altura)/2;
	cout << " El area del triangulo " << color << " del tipo " << tipo << "es: " << area;
}

int main(){
	string color1, color2, color3, tipo;
	double radio, base1, altura1, base2, altura2;
	cout<<" Complete los datos para un circulo: " << endl;
	cout << " Color: "; cin>>color1;
	cout << " Radio: "; cin >> radio;
	circulo c(color1, radio);
	c.calcularAreaCir();
	c.calcularPerimetro();
	cout << endl;
	
	cout << " Complete los datos para un rectangulo: " << endl;
	cout << " Color: "; cin >> color2;
	cout << " Base: "; cin >> base1;
	cout << " Altura: "; cin >> altura1;
	rectangulo r(color2, base1, altura1);
	r.calcularAreaRec();
	cout << endl;
	
	cout << " Complete los datos para un triangulo: " << endl;
	cout << " Color: "; cin >> color3;
	cout << " Base: "; cin >> base2;
	cout << " Altura: "; cin >> altura2;
	cout << " Escriba el tipo de triangulo: "; cin >> tipo;
	triangulo t(color3, base2, altura2, tipo);
	t.calcularAreaTrian();
	cout << endl;
	return 0;
}