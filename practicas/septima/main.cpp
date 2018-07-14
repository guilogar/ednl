#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/alg_grafo_E-S.cpp"
#include "./ej1.cpp"
#include "./ej2.cpp"
#include "./ej3.cpp"
#include "./ej6.cpp"
#include "./ej8.cpp"
#include "./ej9.cpp"
#include "./ej11.cpp"
#include "../grafos/pilaenla.h"

#include <map>

int main(int argc, const char *argv[])
{
    // Ejercicio 1 -- Para resolver este ejercicio, aplicar o DijkstraOpuesto pasandole el origen
    // o bien, el destino.
    GrafoP<int> g(10);
    g[0] = {0, 50, 2, 60, 9, 20, 5, 2, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    g[1] = {5, 0, 6, 3, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, 20,
                        GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    
    g[7] = {1, 8, 1, 1, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO,
                        GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    
    //std::cout << g << std::endl;
    
    vector<GrafoP<int>::vertice> dij;
    vector<GrafoP<int>::vertice> dijInv;
    /*
     *std::cout << DijkstraOpuesto<int>(g, 0, dij) << std::endl;
     *std::cout << DijkstraInvOpuesto<int>(g, 0, dijInv) << std::endl;
     */
    
    //std::cout << g << std::endl;
    
    // Ejercicio 2
    typedef typename GrafoP<int>::vertice vertice;
    typedef typename GrafoP<int>::arista arista;
    typedef typename GrafoP<int>::tCamino camino;
    Pila<arista> paredes;
    paredes.push(arista(15, 16));
    camino c;
    /*
     *std::cout << "El coste para salir es => " << laberinto<int>(5, paredes, 0, 21, c) << std::endl;
     *std::cout << c << std::endl;
     */
    
    // Ejercicio 3
    /*
     *vector<int> cantidadAlmacenadaCiudad(10, 0);
     *almacen<int>(g, {5, 80, 0, 0, 0, 0, 60, 95, 1, 8},
     *             {0, 5, 2, 3, 4, 5, 8, 9, 6, 7},
     *             0, 20, cantidadAlmacenadaCiudad);
     */
    
    // Ejercicio 6
    GrafoP<int> tren(3), autobus(3);
    
    tren[0] = {0, 2, GrafoP<int>::INFINITO};
    tren[1] = {5, 0, 30};
    tren[2] = {1, 7, 0};
    
    autobus[0] = {0, 3, 50};
    autobus[1] = {3, 0, 14};
    autobus[2] = {1, 5, 0};
    //std::cout << agenciaTransportes<int>(tren, autobus, 1) << std::endl;
    
    // Ejercicio 8
    //std::cout << soloUnTransbordo<int>(tren, autobus, 0, 2) << std::endl;
    
    // Ejercicio 9
    camino cc;
    std::cout << "El coste para ir de 0 a 2 es => " << taxi(tren, autobus, 0, 2, cc, 5) << std::endl;
    
    // Ejercicio 11
    GrafoP<int> isla1(3), isla2(2), isla3(3);
    
    isla1[0] = {0, 2, 3};
    isla1[1] = {1, 0, 3};
    isla1[2] = {1, 2, 0};
    
    isla2[0] = {0, 2};
    isla2[1] = {1, 0};
    
    isla3[0] = {0, 2, 3};
    isla3[1] = {1, 0, 4};
    isla3[2] = {1, 2, 0};
    
    std::map<vertice, int> mapa;
    mapa.insert(std::make_pair(7, 5));
    mapa.insert(std::make_pair(0, 6));
    
    vector<std::map<vertice, int>> puentes(8, std::map<vertice, int> ());
    puentes[4] = mapa;
    
    std::cout << huries(isla1, isla2, isla3, puentes) << std::endl;
    
    return 0;
}
