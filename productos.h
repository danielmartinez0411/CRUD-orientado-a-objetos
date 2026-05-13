#pragma once
#include <string>


class Producto {
private:
    double precio;
    std::string nombre;
public:

    Producto(std::string n, double p);

    void setPrecio(double p);

    void setNombre(std::string& n);

    std::string getNombre() const;

    double getPrecio() const;

};