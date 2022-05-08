// IMPORTANTE
// Nombre del alumno: Javier Piernagorda
// Usuario del juez: A54


// Elecciones presidenciales

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

struct tInfo{
    int maximoVotos=0;
    std::string partido;
    std::unordered_map<std::string, int> votosPorPartido;
};

class ConteoVotos {
    
public:
    ConteoVotos(){
        
    }
    
    /*
      Registra un nuevo estado en el sistema, con el nombre y número de compromisarios pasados como parámetro. Si ya existía un estado registrado con el mismo nombre, se lanzará una ex- cepción de tipo std::domain_error con el mensaje Estado ya existente. Puedes suponer que num_compromisarios > 0.
     */
    void nuevo_estado(const std::string &nombre, int num_compromisarios){
        if (registroEstadosCompromisarios.count(nombre)>0) throw std::domain_error("Estado ya existente");
        else registroEstadosCompromisarios.insert({nombre, num_compromisarios});
    }
    
    /*
     Suma num_votos a la cantidad de votos recibida por el partido dentro del estado indicado como parámetro. Si el estado no estaba registrado previamente en el sistema, se lanzará una excepción std::domain_error con el mensaje Estado no encontrado. Puedes suponer que num_votos > 0.
     */
    void sumar_votos(const std::string &estado, const std::string &partido, int num_votos){
        if (registroEstadosCompromisarios.count(estado)==0) throw std::domain_error("Estado no encontrado");
        else{
            /*
             std::unordered_map<std::string, tInfo> registroVotosPorEstado;
             std::map<std::string, int> compromisariosPorPartido;
             */
            auto it = registroVotosPorEstado[estado].votosPorPartido.find(partido);
            //El partido no existia en ese estado -> se mete con sus votos
            if (it == registroVotosPorEstado[estado].votosPorPartido.end()){
                registroVotosPorEstado[estado].votosPorPartido[partido] = num_votos;
            }
            else registroVotosPorEstado[estado].votosPorPartido[partido] += num_votos;
            
            if (registroVotosPorEstado[estado].votosPorPartido[partido] > registroVotosPorEstado[estado].maximoVotos){
                registroVotosPorEstado[estado].maximoVotos = registroVotosPorEstado[estado].votosPorPartido[partido];
                std::string partidoQueIbaLiderando = registroVotosPorEstado[estado].partido;
                registroVotosPorEstado[estado].partido = partido; //Actualizamos el que va ganando
                //Pasamos a registrar los compromisarios: hay que quitarle al anterior ganador y sumarle al nuevo
                compromisariosPorPartido[partidoQueIbaLiderando]-=registroEstadosCompromisarios[estado];
                if (compromisariosPorPartido.find(partido)==compromisariosPorPartido.end()){
                    //El partido es nuevo -> lo insertamos
                    compromisariosPorPartido[partido]=registroEstadosCompromisarios[estado];
                }
                else compromisariosPorPartido[partido]+=registroEstadosCompromisarios[estado];
            }
            
        }
    }
    /*
     Devuelve el nombre del partido que más votos ha obtenido en el estado indicado. Puedes suponer (sin necesidad de comprobarlo en tu código) que el estado ha recibido previamente al menos un voto para algún partido político, y que el partido mayoritario tiene un número de votos estricta- mente mayor que los partidos restantes; es decir, no hay empates. Si el estado indicado no estaba registrado previamente en el sistema, se lanzará una excepción std::domain_error con el mensaje Estado no encontrado.
     */
    std::string ganador_en(const std::string &estado) const{
        if (registroEstadosCompromisarios.count(estado)==0) throw std::domain_error("Estado no encontrado");
        else return registroVotosPorEstado.at(estado).partido;
    }
    /*
     Devuelve una lista de los partidos que han obtenido al menos un compromisario en alguno de los estados. Cada elemento de la lista es un par (nombre, num_total), donde nombre es el nombre del partido, y num_total es la suma total de compromisarios que ha obtenido en todo el país. La lista debe estar ordenada alfabéticamente según el nombre del partido. Puedes suponer (sin necesidad de comprobarlo en el código) que todos los estados registrados en el sistema tienen un partido ganador, es decir, que no hay empate en ninguno de ellos.
     */
    std::vector<std::pair<std::string,int>> resultados() const{
        std::vector<std::pair<std::string,int>> vectorRet;
        std::string partido;
        int compromisarios;
        for ( auto it = compromisariosPorPartido.begin(); it!=compromisariosPorPartido.end(); ++it){
            partido = (*it).first;
            compromisarios = (*it).second;
            if (compromisarios>0){
                std::pair<std::string, int> pareja(partido, compromisarios);
                vectorRet.push_back(pareja);
            }
        }
        return vectorRet;
    }
private:
    std::unordered_map<std::string, int> registroEstadosCompromisarios;
    std::unordered_map<std::string, tInfo> registroVotosPorEstado;
    std::map<std::string, int> compromisariosPorPartido;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    ConteoVotos cv;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "nuevo_estado") {
                std::string nombre; int num_compromisarios;
                std::cin >> nombre >> num_compromisarios;
                cv.nuevo_estado(nombre,num_compromisarios);
            }
            else if (op == "sumar_votos") {
                std::string estado, partido;
                int num_votos;
                std::cin >> estado >> partido >> num_votos;
                cv.sumar_votos(estado, partido, num_votos);
            }
            else if (op == "ganador_en") {
                std::string estado;
                std::cin >> estado;
                std::string sol = cv.ganador_en(estado);
                std::cout << "Ganador en " << estado << ": " << sol << '\n';
            }
            else if (op == "resultados") {
                std::vector<std::pair<std::string, int>> sol = cv.resultados();
                for (std::pair<std::string, int> const& s : sol)
                    std::cout << s.first << ' ' << s.second << '\n';
            }
        }
        catch (std::domain_error const& e) {
            std::cout << e.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---\n";
    return true;
    
}

int main() {
    
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    while (resuelveCaso()) ;//Resolvemos todos los casos
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}


