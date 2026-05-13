#pragma once
#include "productos.h"
#include <vector>


class Sistema {
private:

    std::vector <Producto> productos;

public:

    void guardar(double p, std::string n);

    bool buscar(const std::string& nom);

    void mostrar();

    void eliminar(const std::string& nom);

    void actualizar(const std::string& nom);

    void validarNombreActualizar(std::string& nam);

    void validarPrecioActualizar(double& precio);

    std::string pedirNombre();

    double pedirPrecio();

    void validarOpcion(int& op);

    void ejecutar();


};