#include <iostream>
#include <string>

using namespace std;

// Clase base Vehiculo
class vehiculo {
protected:
    string placa;
    string color;
    string marca;
    double veloc;
public:
    vehiculo(string, string, string, double);
    void mostrarVeh();
    void cambVeloc();
};

vehiculo::vehiculo(string p, string c, string m, double v) {
    placa = p;
    color = c;
    marca = m;
    veloc = v;
}

void vehiculo::mostrarVeh() {
    cout << " La marca del vehiculo color " << color << " es de la marca " << marca;
    cout << ", tiene una velocidad maxima de " << veloc << " Km/h" << endl;
    cout << " Su numero de placa es: " << placa << endl;
}

void vehiculo::cambVeloc() {
    int opc1;
    double vel;
    do {
        cout << "\t Desea cambiar la velocidad: " << endl;
        cout << "\t 1) Si " << endl << "\t 2) No" << endl;
        cout << "\t Escriba el numero de la opcion que va elegir: ";
        cin >> opc1;
        if (opc1 == 1) {
            cout << "\t Escriba la velocidad maxima en km/h: ";
            cin >> vel;
            veloc = vel;
        }
    } while (opc1 == 1);
}

// Clase derivada Automovil
class automovil : public vehiculo {
private:
    int cantPuert;
    int cantPasaj;
public:
    automovil(string, string, string, double, int, int);
    void mostrarAuto();
    void subirPasj();
    void bajarPasj();
};

automovil::automovil(string p, string c, string m, double v, int cantPrt, int cantPsj) : vehiculo(p, c, m, v) {
    cantPuert = cantPrt;
    cantPasaj = cantPsj;
}

void automovil::mostrarAuto() {
	mostrarVeh();
    cout << " Este automovil tiene " << cantPuert << " puertas ";
    cout << "y hay " << cantPasaj << " pasajero/s." << endl;
}

void automovil::bajarPasj() {
    int opc2, n;
    do {
        cout << "\t Desea bajar la cantidad de pasajeros: " << endl;
        cout << "\t 1) Si " << endl << "\t 2) No" << endl;
        cout << "\t Escriba el numero de la opcion que va elegir: ";
        cin >> opc2;
        if (opc2 == 1) {
            cout << "\t Escriba la cantidad: ";
            cin >> n;
            if (cantPasaj >= n) {
                cantPasaj -= n;
            } else {
                cout << "\t No se puede quitar esa cantidad." << endl;
            }
        }
    } while (opc2 == 1);
}

void automovil::subirPasj() {
    int opc3, n;
    do {
        cout << "\t Desea subir la cantidad de pasajeros: " << endl;
        cout << "\t 1) Si " << endl << "\t 2) No" << endl;
        cout << "\t Escriba el numero de la opcion que va elegir: ";
        cin >> opc3;
        if (opc3 == 1) {
            cout << "\t Escriba la cantidad: ";
            cin >> n;
            cantPasaj += n;
        }
    } while (opc3 == 1);
}

// Clase derivada Camion
class camion : public vehiculo {
private:
    double carga;
public:
    camion(string, string, string, double, double);
    void mostrarCamion();
    void cambiarCarga();
};

camion::camion(string p, string c, string m, double v, double crg) : vehiculo(p, c, m, v) {
    carga = crg;
}

void camion::mostrarCamion() {
	mostrarVeh();
    cout << " Este camion tiene como carga maxima " << carga << " kg." << endl;
}

void camion::cambiarCarga() {
    int opc4;
    double n;
    do {
        cout << "\t Desea cambiar su carga en kg: " << endl;
        cout << "\t 1) Si " << endl << "\t 2) No" << endl;
        cout << "\t Escriba el numero de la opcion que va elegir: ";
        cin >> opc4;
        if (opc4 == 1) {
            cout << "\t Escriba la nueva carga en kg: ";
            cin >> n;
            if (n >= 0) {
                carga = n;
            } else {
                cout << "\t Carga no valida." << endl;
            }
        }
    } while (opc4 == 1);
}

int main() {
    vehiculo v("ABC-1234", "Gris", "Toyota", 180);
    v.mostrarVeh();
    cout << endl;

    automovil a("XYZ-5678", "Azul marino", "Honda", 200, 4, 5);
    a.mostrarAuto();
    a.cambVeloc();
    a.subirPasj();
    a.bajarPasj();
    cout << "Datos actuales del auto: " << endl;
    a.mostrarAuto();
    cout << endl;

    camion c("TRK-9012", "Blanco", "Freightliner", 120, 10000);
    c.mostrarCamion();
    c.cambVeloc();
    c.cambiarCarga();
    cout << "Datos actuales del camion: " << endl;
    c.mostrarCamion();
    cout << endl;

    return 0;
}