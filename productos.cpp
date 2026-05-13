#include "productos.h"
#include <string>


Producto::Producto(std::string n, double p) {
	setPrecio(p);
	setNombre(n);
}

void Producto::setPrecio(double p) {
    if (p < 0) {
        precio = 0;
    }
    else {
        precio = p;
    }
}

void Producto::setNombre(std::string& n) {
    if (!n.empty()) {
        nombre = n;
    }
}

std::string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}