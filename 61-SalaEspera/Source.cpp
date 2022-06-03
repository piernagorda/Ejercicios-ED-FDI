// Grupo: A
// Usuario del juez: A54
                                              

// En recuperados() se detalla una implementacion alternativa


#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>

//Struct para guardar la gravedad y el iterador
struct tPaciente {
    int gravedad;
    std::list<std::string>::iterator it;
};

class Urgencias {

public:
    //Constructora donde metemos tres listas vacias en el vector
    Urgencias() {
        std::list<std::string> lista1;
        std::list<std::string> lista2;
        std::list<std::string> lista3;
        vectorDeListas.push_back(lista1);
        vectorDeListas.push_back(lista2);
        vectorDeListas.push_back(lista3);
    }

    //Funcion de insertar paciente, coste: O(1)
    void nuevo_paciente(std::string paciente, int gravedad) {
        //Funcion count tiene coste O(1)
        if (pacientesEnSala.count(paciente) == 0) { //El paciente es nuevo
            if (gravedad < 1 || gravedad >3) throw std::domain_error("Gravedad incorrecta");
            else { 
                //Todo esto tiene coste O(1)
                vectorDeListas[gravedad-1].push_back(paciente);
                auto it = vectorDeListas[gravedad-1].end();
                --it;
                pacientesEnSala[paciente].gravedad = gravedad;
                pacientesEnSala[paciente].it = it;
            }
        }
        else throw std::domain_error("Paciente repetido");
    }

    //Funcion de devolver la gravedad del paciente, coste O(1)
    int gravedad_actual(std::string paciente) {
        //De media, la funcion find tiene coste O(1)
        auto it = pacientesEnSala.find(paciente);
        if (it == pacientesEnSala.end()) throw std::domain_error("Paciente inexistente");
        else return it->second.gravedad;
    }

    //Funcion de obtener el paciente mas prioritario, coste O(1)
    std::string siguiente() {
        std::string pacienteTratado;
        //Comprobacion de tamano de la lista y extraccion del nombre del paciente es todo O(1)
        if (vectorDeListas[2].size() != 0) { //Tratamos a pacientes graves
            pacienteTratado = *vectorDeListas[2].begin();
            vectorDeListas[2].erase(vectorDeListas[2].begin()); //Borramos el primero de la cola
            pacientesEnSala.erase(pacienteTratado); //Lo borramos de la lista de pacientes
        }
        else {
            if (vectorDeListas[1].size() != 0) { //Tratamos a pacientes medios
                pacienteTratado = *vectorDeListas[1].begin();
                vectorDeListas[1].erase(vectorDeListas[1].begin()); //Borramos el primero de la cola
                pacientesEnSala.erase(pacienteTratado); //Lo borramos de la lista de pacientes
            }
            else {
                if (vectorDeListas[0].size() != 0) { //Tratamos a pacientes leves
                    pacienteTratado = *vectorDeListas[0].begin();
                    vectorDeListas[0].erase(vectorDeListas[0].begin()); //Borramos el primero de la cola
                    pacientesEnSala.erase(pacienteTratado); //Lo borramos de la lista de pacientes
                }
                else throw std::domain_error("No hay pacientes");
            }
        }
        return pacienteTratado;
    }

    //En el caso peor, todos los pacientes son leves -> cada insercion es O(logn) -> n inserciones sera O(nlogn)
    void mejora(std::string paciente) {
        auto it = pacientesEnSala.find(paciente); //Buscamos al paciente
        if (it == pacientesEnSala.end()) throw std::domain_error("Paciente inexistente");
        else {
            //Si el paciente tiene gravedad 1, al mejorar simplemente hay que meterlo en recuperados y borrarlo de:
            //          -El mapa de pacientes en sala
            //          -La lista de leves
            if (it->second.gravedad == 1) {
                conjunto.insert(paciente); //Lo insertamos en recuperados
                auto itPacienteRecuperado = pacientesEnSala[paciente].it; //Cogemos su iterador
                vectorDeListas[0].erase(itPacienteRecuperado); //Lo borramos de la lista de leves
                pacientesEnSala.erase(paciente); //Lo borramos de la lista de pacientes en sala
            }
            //En este caso donde no hay que insertar, es O(1)
            else {
                --it->second.gravedad; //Le bajamos la gravedad
                int nuevaGravedad = it->second.gravedad;  
                auto itPacienteMejorado = it->second.it; //Accedemos a su iterador     
                //mostrarListas();
                vectorDeListas[(it->second.gravedad)].erase(itPacienteMejorado); //Lo borramos de la lista en la que estaba
                vectorDeListas[(nuevaGravedad) - 1].push_front(paciente); //Metemos en la lista de gravedad -1 el paciente
                pacientesEnSala[paciente].it = vectorDeListas[nuevaGravedad - 1].begin(); //Le asignamos su nuevo iterador
                it->second.gravedad = nuevaGravedad; //Le actualizamos su gravedad
            }
        }
    }
    
    //Copiamos uno a uno los elementos del set. Habra que recorrer los n elementos del set -> O(n)
    //Una implementacion alternativa es tener un vector donde metemos los pacientes sin ordenar y ordenar al final. 
    //Es una opcion mejor en almacenamiento (tal y como esta almacenamos set + vector) ya que almacenariamos solo un
    //vector. Esta ordenacion (atendiendo a la información en internet) implementaria el introsort, cuya complejidad
    //es tambien O(NlogN) en el caso peor. Es una cuestion entonces de memoria.
    std::vector<std::string> recuperados() {
        std::vector<std::string> retorno;
        auto it = conjunto.begin();
        for (it; it != conjunto.end(); ++it) retorno.push_back(*it);
        return retorno;
    }
   
private:
    std::set<std::string> conjunto;
    std::unordered_map<std::string, tPaciente> pacientesEnSala; //Guardamos un diccionario paciente - gravedad
    std::vector<std::list<std::string>> vectorDeListas;
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    Urgencias miSala;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "nuevo_paciente") {
                int gravedad; 
                std::string paciente;
                std::cin >> paciente >> gravedad;
                miSala.nuevo_paciente(paciente, gravedad);
            }
            else if (op == "mejora") {
                std::string paciente;
                std::cin >> paciente;
                miSala.mejora(paciente);
            }
            else if (op == "siguiente") {
                std::string siguiente = miSala.siguiente();
                std::cout << "Siguiente paciente: " << siguiente << "\n";
            }
            else if (op == "gravedad_actual") {
                std::string paciente;
                std::cin >> paciente;
                int gravedad = miSala.gravedad_actual(paciente);
                std::cout << "La gravedad de " + paciente + " es " << gravedad << "\n";
            }
            else if (op == "recuperados") {
                std::vector<std::string> sol = miSala.recuperados();
                std::cout << "Lista de recuperados: ";
                for (auto it = sol.begin(); it != sol.end(); ++it) {
                    std::cout << *it << " ";
                }
                std::cout << "\n";
            }
        }
        catch (std::domain_error const& e) {
            std::cout <<"ERROR: "<< e.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso());//Resolvemos todos los casos
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}