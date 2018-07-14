#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/alg_grafo_E-S.cpp"
#include "./ej1.cpp"
#include "./ej2.cpp"
#include "./ej3.cpp"
#include "./ej4.cpp"

int main(int argc, const char *argv[])
{
    // Ejercicio 1
    GrafoP<int> g(10);
    g[0] = {0, 50, 2, 60, 9, 20, 5, 2, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    g[1] = {5, 0, 6, 3, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, 20,
                        GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    
    g[7] = {1, 8, 1, 1, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO,
                        GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, GrafoP<int>::INFINITO};
    
    std::cout << g << std::endl;
    
    vector<GrafoP<int>::vertice> dij;
    vector<GrafoP<int>::vertice> dijInv;
    std::cout << Dijkstra<int>(g, 0, dij) << std::endl;
    std::cout << DijkstraInv<int>(g, 0, dijInv) << std::endl;
    
    std::cout << g << std::endl;
    
    // Ejercicio 2
    pseudoCentroGrafo<int>(g);
    
    // Ejercicio 3 -- Aun por terminar
    GrafoP<int> gg(3);
    gg[0] = {0, 1, GrafoP<int>::INFINITO};
    gg[1] = {GrafoP<int>::INFINITO, 0, 2};
    gg[2] = {GrafoP<int>::INFINITO, GrafoP<int>::INFINITO, 0};
    std::cout << "Grafo Aciclico => " << grafoAciclico<int>(gg) << std::endl;
    
    // Ejercicio 4
    vector<bool> tomadas(10, false);
    tomadas[5] = true;
    GrafoP<int> sol = zuelandia<int>(g, tomadas, vector<vector<bool>> (10, vector<bool>(10, false)), 0);
    std::cout << sol << std::endl;
    
    return 0;
}
