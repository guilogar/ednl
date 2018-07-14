#include <iostream>
#include "../grafos/alg_grafo_E-S.cpp"
#include "../grafos/grafoMA.h"
#include "../grafos/alg_grafoMA.h"
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/particion.h"
#include "../grafos/particion.cpp"
#include "./ej1.cpp"
#include "./ej2.cpp"
#include "./ej3.cpp"

int main(int argc, const char *argv[])
{
    // Ejercicio 1
    typedef int tCoste;
    vector<ciudad<tCoste>> ciudades(5);
    ciudades[0] = ciudad<tCoste>(5, 3);
    ciudades[1] = ciudad<tCoste>(8, 23);
    ciudades[2] = ciudad<tCoste>(96, 1);
    ciudades[3] = ciudad<tCoste>(5, 200);
    ciudades[4] = ciudad<tCoste>(6, 15);
    
    Grafo G(5);
    G[0][2] = true;
    //G[0][4] = true;
    
    Particion P(5);
    
    //std::cout << tombuctu<tCoste>(ciudades, G, P) << std::endl;
    
    // Ejercicio 2
    
    /*
     *std::set<LineaAerea<tCoste>> lineas = tombuctu2<tCoste>(ciudades, G);
     *for (auto l : lineas) {
     *    std::cout << "Origen: " << l.origen_ << std::endl;
     *    std::cout << "Destino: " << l.destino_ << std::endl;
     *    std::cout << "Representante Isla Origen: " << l.r_origen_ << std::endl;
     *    std::cout << "Representante Isla Destino: " << l.r_destino_ << std::endl;
     *    std::cout << "Coste => " << l.coste_ << std::endl;
     *    std::cout << "===============================" << std::endl;
     *}
     */
    
    // Ejercicio 3
    
    //std::cout << Kruskall(GrafoP<tCoste>(5)) << std::endl;
    std::cout << KruskallMaximo(GrafoP<tCoste>(5)) << std::endl;
    
    // Ejercicio 4
    
    // Ejercicio 5
    
    // Ejercicio 6
    
    
    return 0;
}
