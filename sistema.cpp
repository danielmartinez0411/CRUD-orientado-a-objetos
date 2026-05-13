#include "sistema.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


void Sistema::guardar(double p, std::string n) {


    if (buscar(n) == 1) {

        std::cout << "el producto ya existe" << std::endl;

    }
    else {

        Producto nuevo(n, p);
        productos.push_back(nuevo);
        n = " ";
        p = 0;
    }



}

bool Sistema::buscar(const std::string& nom) {


    bool estado = 0;

    auto it = std::find_if(productos.begin(), productos.end(), [nom, &estado](const Producto& n) {
        if (n.getNombre() == nom) {
            std::cout << n.getNombre() << " $" << n.getPrecio() << '\n';
            estado = 1;
            return 1;
        }
        else {
            return 0;
        }
        });

    return estado;
}

void Sistema::mostrar() {

    if (!productos.empty()) {

        int cont = 1;
        for (const auto& n : productos) {
            std::cout << cont << ". " << n.getNombre() << " $" << n.getPrecio() << std::endl;
            cont++;
        }

    }
    else {
        std::cout << "Aun no se han agregado productos" << std::endl;
    }
}

void Sistema::eliminar(const std::string& nom) {

    if (!productos.empty()) {

        int i = 0;
        for (const auto& n : productos) {
            if (n.getNombre() == nom) {
                productos.erase(productos.begin() + i);
                std::cout << "Producto eliminado correctamente \n";
                return;
            }
            i++;
        }

        std::cout << "Producto no encontrado" << std::endl;

    }
    else {
        std::cout << "Aun no se han agregado productos" << std::endl;
    }

}

void Sistema::actualizar(const std::string& nom) {


    if (productos.empty()) {

        std::cout << "Aun no se han agregado productos \n";



    }
    else {
        int op = 0;
        std::string nam = "";
        double pr = 0;

        std::cout << "Ingrese la operacion que desea hacer: \n";
        std::cout << "\n1. Cambiar nombre:";
        std::cout << "\n2. Cambiar precio:";
        std::cout << "\nOpcion: ";

        validarOpcion(op);

        switch (op) {
        case 1:
            validarNombreActualizar(nam);
            for (auto& n : productos) {
                if (n.getNombre() == nom) {
                    n.setNombre(nam);
                    return;
                }
            }
            break;
        case 2:

            validarPrecioActualizar(pr);

            for (auto& n : productos) {
                if (n.getNombre() == nom) {
                    n.setPrecio(pr);
                    return;
                }
            }
            break;




        default: std::cout << "Opcion invalida"; break;
        }

    }




}


void Sistema::validarNombreActualizar(std::string& nam) {

    std::cout << "Ingrese el nuevo nombre del producto: \n";
    std::cin.ignore(1000, '\n');



    while (nam.empty()) {

        std::getline(std::cin, nam);


    }


}

void Sistema::validarPrecioActualizar(double& precio) {

    std::cout << "Ingrese el nuevo precio del producto \n";
    std::cin >> precio;


    while (true) {

        if (std::cin.fail() || precio < 0) {
            std::cout << "Precio invalido, ingrese nuevamente\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        else {
            break;
        }
    }

}

std::string Sistema::pedirNombre() {

    std::string nom = "";
    std::cout << "Ingrese el nombre del producto: \n";
    std::cin.ignore(1000, '\n');



    while (nom.empty()) {
        std::getline(std::cin, nom);


    }

    return nom;

}

double Sistema::pedirPrecio() {

    double precio = 0;
    std::cout << "Ingrese el precio del producto \n";
    std::cin >> precio;


    while (true) {

        if (std::cin.fail() || precio < 0) {
            std::cout << "Precio invalido, ingrese nuevamente\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        else {
            break;
        }
    }

    return precio;

}

void Sistema::validarOpcion(int& op) {

    while (true) {

        std::cin >> op;


        if (std::cin.fail()) {

            std::cout << "Entrada invalida, introduzca nuevamente \n";

            std::cin.clear();
            std::cin.ignore(1000, '\n');

        }
        else {
            break;
        }



    }


}

void Sistema::ejecutar() {

    int op = 0;
    std::string nom = "";
    double precio = 0;

    while (true) {



        std::cout << "\tBienvenido al sistema, elija la opcion que prefiera";
        std::cout << "\n1. Agregar";
        std::cout << "\n2. Mostrar";
        std::cout << "\n3. Buscar";
        std::cout << "\n4. Actualizar";
        std::cout << "\n5. Eliminar";
        std::cout << "\n6.Salir";
        std::cout << "\nOpcion: ";

        validarOpcion(op);

        switch (op) {
        case 1:
            guardar(pedirPrecio(), pedirNombre()); break;

        case 2:

            mostrar(); break;

        case 3:
            buscar(pedirNombre()); break;

        case 4:
            actualizar(pedirNombre()); break;

        case 5: eliminar(pedirNombre()); break;

        case 6:
            std::cout << "Gracias por usar nuestros servicios" << std::endl;
            return;

        default: std::cout << "Opcion incorrecta \n";break;

        }


    }



}