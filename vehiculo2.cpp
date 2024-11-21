#include <iostream>
using namespace std;

class vehiculo {
protected:
    string color;
    int cantPsj;
public:
    vehiculo(string, int);
};

vehiculo::vehiculo(string c, int Psj) {
    color = c;
    cantPsj = Psj;
}

class terrestre : public vehiculo {
protected:
    int cantPuert;
    double velocidad;
public:
    terrestre(string, int, int, double);
};

terrestre::terrestre(string c, int Psj, int Prt, double v) : vehiculo(c, Psj) {
    cantPuert = Prt;
    velocidad = v;
}

class carro : public terrestre {
private:
    int cant;
public:
    carro(string, int, int, double, int);
    void usarCar();
    void devolverCar();
    void mostrarDatos();
};

carro::carro(string c, int Psj, int Prt, double v, int ct) : terrestre(c, Psj, Prt, v) {
    cant = ct;
}
void carro::usarCar() {
    if (cant > 0) {
        cant--;
        cout << "\t Se ha usado un carro, ahora hay " << cant << " disponibles." << endl;
    } else {
        cout << "\t No hay mas autos disponibles" << endl;
    }
}
void carro::devolverCar() {
    if (cant < 10) {
        cant++;
        cout << "\t Un carro ha sido devuelto, ahora hay " << cant << " disponibles." << endl;
    } else {
        cout << "\t La cantidad de carros esta completa, no se puede agregar mas." << endl;
    }
}
void carro::mostrarDatos() {
    cout << "\t Carro: Color: " << color << ", Pasajeros: " << cantPsj << ", Puertas: " << cantPuert << ", Velocidad: " << velocidad << " km/h, Disponibles: " << cant << endl;
}

class aereo : public vehiculo {
private:
    double alturaMax;
public:
    aereo(string, int, double);
    void mostrarAlturaMax();
    void mostrarDatos();
};

aereo::aereo(string c, int Psj, double h) : vehiculo(c, Psj) {
    alturaMax = h;
}
void aereo::mostrarAlturaMax() {
    cout << " \t La altura maxima es: " << alturaMax << " metros." << endl;
}
void aereo::mostrarDatos() {
    cout << "\t Aereo: Color: " << color << ", Pasajeros: " << cantPsj << ", Altura Maxima: " << alturaMax << " metros" << endl;
}

class helicoptero : public aereo {
private:
    int cant;
public:
    helicoptero(string, int, int, double);
    void usarHelic();
    void devolverHelic();
    void mostrarDatos();
};

helicoptero::helicoptero(string c, int Psj, int ct, double h) : aereo(c, Psj, h) {
    cant = ct;
}
void helicoptero::usarHelic() {
    if (cant > 0) {
        cant--;
        cout << "\t Se ha usado un helicoptero, ahora hay " << cant << " disponibles." << endl;
    } else {
        cout << "\t No hay mas helicopteros disponibles" << endl;
    }
}
void helicoptero::devolverHelic() {
    if (cant < 1) {
        cant++;
        cout << "\t Un helicoptero ha sido devuelto, ahora hay " << cant << " disponibles." << endl;
    } else {
        cout << "\t La cantidad de helicopteros esta completa, no se puede agregar mas." << endl;
    }
}
void helicoptero::mostrarDatos() {
    cout << "\t Helicoptero: ";
    aereo::mostrarDatos();
    cout << "\t Disponibles: " << cant << endl;
}

class maritimo : public vehiculo {
private:
    double capacidadCarga;
public:
    maritimo(string, int, double);
    void mostrarCapacidadCarga();
    void mostrarDatos();
};

maritimo::maritimo(string c, int Psj, double carga) : vehiculo(c, Psj) {
    capacidadCarga = carga;
}
void maritimo::mostrarCapacidadCarga() {
    cout << "\t La capacidad de carga es: " << capacidadCarga << " toneladas." << endl;
}
void maritimo::mostrarDatos() {
    cout << "\t Maritimo: Color: " << color << ", Pasajeros: " << cantPsj << ", Capacidad de Carga: " << capacidadCarga << " toneladas" << endl;
}

class lancha : public maritimo {
private:
    int cant;
public:
    lancha(string, int, int, double);
    void usarLancha();
    void devolverLancha();
    void mostrarDatos();
};

lancha::lancha(string c, int Psj, int ct, double carga) : maritimo(c, Psj, carga) {
    cant = ct;
}
void lancha::usarLancha() {
    if (cant > 0) {
        cant--;
        cout << "\t Se ha usado una lancha, ahora hay " << cant << " disponibles." << endl;
    } else {
        cout << "\t No hay mas lanchas disponibles" << endl;
    }
}
void lancha::devolverLancha() {
    if (cant < 3) {
        cant++;
        cout << "\t Una lancha ha sido devuelta, ahora hay " << cant << " disponibles." << endl;
    } else {
        cout << "\t La cantidad de lanchas esta completa, no se puede agregar mas." << endl;
    }
}
void lancha::mostrarDatos() {
    cout << "\t Lancha: ";
    maritimo::mostrarDatos();
    cout << "\t Disponibles: " << cant << endl;
}

int main() {
    carro c("rojo", 6, 4, 200, 10);
    helicoptero h("blanco", 4, 1, 3000);
    lancha l("azul", 4, 2, 5);

    int opc;
    do {
        cout << "Seleccione una opcion:" << endl;
        cout << "1) Usar carro" << endl;
        cout << "2) Devolver carro" << endl;
        cout << "3) Usar helicoptero" << endl;
        cout << "4) Devolver helicoptero" << endl;
        cout << "5) Usar lancha" << endl;
        cout << "6) Devolver lancha" << endl;
        cout << "7) Mostrar altura maxima del helicoptero" << endl;
        cout << "8) Mostrar capacidad de carga de la lancha" << endl;
        cout << "9) Mostrar datos" << endl;
        cout << "10) Salir" << endl;
        cout << "Escriba el numero de la opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                c.usarCar();
                break;
            case 2:
                c.devolverCar();
                break;
            case 3:
                h.usarHelic();
                break;
            case 4:
                h.devolverHelic();
                break;
            case 5:
                l.usarLancha();
                break;
            case 6:
                l.devolverLancha();
                break;
            case 7:
                h.mostrarAlturaMax();
                break;
            case 8:
                l.mostrarCapacidadCarga();
                break;
            case 9:
                c.mostrarDatos();
                h.mostrarDatos();
                l.mostrarDatos();
                break;
            case 10:
                cout << "Cerrando programa" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opc != 10);

    return 0;
}