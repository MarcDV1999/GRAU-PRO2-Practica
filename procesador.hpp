//
//  procesador.hpp
//  
//
//  Created by Marc Domènech on 06/11/2018.
//

/** @file procesador.hpp
 @brief Especificación de la clase procesador
 */

#ifndef procesador_hpp
#define procesador_hpp

#include "usuario.hpp"
#include "proceso.hpp"
#include <map>
#include <string>

/** @class procesador
 @brief Representa un procesador
 */

class procesador{
private:
    int id_procesador;
    int memoria_total;
    int numero_procesos;
    int memoria_libre;
    
    class hueco{
    private:
        int pos_inicial;
        int total;
    public:
        hueco(int pos_inicial, int total);
        /** @brief Constructora.
         \pre <em> pos_inicial y total deben estar dentro de los limites de la memoria del procesador </em>
         \post Crea un hueco vacio, con pos_inicial y total.
         */
        
        int consultar_tamaño();
        /** @brief Consulta el tamaño de un hueco.
         \pre <em>Cierto </em>
         \post retorna el tamaño del hueco.
         */
    };
    
    map<int,proceso> m_procesos;
    map<int,hueco> m_huecos;
    map<int,proceso>::iterator it_procesos;
    map<int,hueco>::iterator it_huecos;
    
public:
    
    // Constructoras
    
    procesador(int id_procesador, int memoria_total);
    /** @brief Constructora.
     \pre <em>El id de procesador y la memoria deben ser > 0 </em>
     \post Crea un procesador vacio, con id_procesador y memoria_total.
     */
    
    int poner_proceso(proceso& p);
    /** @brief Pone un proceso en el procesaddor.
     \pre <em>Cierto</em>
     \post Añade el proceso en el parametro implicito si se puede, sino retorna -1 y pasa a estar pendiente
     */
    
    int quitar_proceso(int id_proceso);
    /** @brief Quita un proceso de un procesador.
     \pre <em>id_proceso debe existir</em>
     \post Quita el proceso del parametro implicito. Retorna 1 si se ha podido quitar y -1 en caso contrario
     */
    
    pair<int,hueco> mejor_hueco(proceso& x);
    /** @brief Analiza cual es el mejor hueco para el proceso p.
     \pre <em>Cierto</em>
     \post Retorna una pareja con la primera posicion de memoria donde se enuentra el hueco y el hueco. En caso de que no hayan huecos retorna -1 en FIRST.
     */
    
    int usar_hueco(proceso& x,pair<int,hueco>& mas_justo);
    /** @brief Pone un proceso en un hueco en especial.
     \pre <em>Cierto</em>
     \post Retorna 1 si se ha podido colocar el proceso y -1 si no se ha podido.
     */
    
    
    
    void consultar_procesador();
    /** @brief Consulta un Procesador.
     \pre <em>Cierto</em>
     \post Retorna el conjunto de los procesos del procesador.
     */
    
    
    int avanzar_tiempo(int& tiempo);
    /** @brief Avanza el tiempo.
     \pre <em> Cierto </em>
     \post Avanza el tiempo a todos los procesos del procesador i Retorna el numero de procesos que se han eliminado.
     */
    
    int consultar_memoria_libre();
    /** @brief Consulta la memoria libre del procesador.
     \pre <em> Cierto </em>
     \post Retorna la memoria libre del procesador
     */
    
    void escribir_procesador();
    /** @brief Escribe por el canal estandar de salida la informacion del procesador.
     \pre <em> Cierto </em>
     \post Escribe por el canal estandar de salida la informacion del procesador.
     */
    void modificar_numero_procesos();
    
    void escribir_procesos();
};
#endif /* procesador_hpp */
