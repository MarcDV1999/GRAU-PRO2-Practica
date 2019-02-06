//
//  cluster.hpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domènech on 09/11/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//

/** @file cluster.hpp
 @brief Especificación de la clase cluster
 */

#ifndef cluster_hpp
#define cluster_hpp

#include "BinTree.hh"
#include "BinTreeIOint.hh"
#include "procesador.hpp"
#include <vector>
#include <map>

using namespace std;


/** @class cluster
 @brief Representa un cluster
  */

class cluster{
private:
    BinTree<int> arbol_procesadores; // Id_procesador
    vector<procesador> v_procesadores;
    int numero_procesadores;
    int tiempo_ejecucion;
    struct procesador_candidato{
        int nivel;
        bool izquierda;
    };
    map<int,procesador_candidato> procesadores_candidatos;
    map<int,procesador_candidato>::iterator it;
    
    
public:
    
//  Constructoras
    
    cluster();
    /** @brief Constructora por defecto.
        \pre <em>Cierto</em>
        \post Constructora por defecto. Crea un cluster vacio.
     */
    
    cluster(vector<procesador>& v_procesadores);
    /** @brief Constructora.
     \pre <em>Cierto</em>
     \post Crea un cluster con v_procesador
     */
    
    void configurar_cluster(int numero_procesadores);
    /** @brief Configura Cluster.
     \pre <em>Cierto</em>
     \post Los datos siempre comenzaran por una configuracion de cluster. Se leera el numero de procesadores, sus conexiones y la memoria de cada uno de ellos en orden creciente de id. Esta operacion se puede realizar varias veces. Si se vuelve a configurar el cluster mas adelante, los procesos activos se eliminan, pero los procesos pendientes de los usuarios se conservan para el siguiente cluster en el mismo estado que antes.
     */

    
    int poner_proceso_en_procesador(int& id_procesador,proceso& p);
    /** @brief Pone proceso en un Procesador.
     \pre <em>id_procesador debe existir</em>
     \post Se leen el id de un procesador y los datos de un proceso. Si el usuario no existe no se hace nada. Si hay un hueco de memoria libre consecutiva en el que quepa el proceso, pasa a ejecutarse en dicho procesador y la memoria que use pasa a estar ocupada. Si el proceso no cabe, pasa a ser el proceso pendiente mas reciente del usuario.
     */
    void quitar_proceso_de_procesador(int& id_procesador, int& id_proceso);
    /** @brief Quita un proceso de un procesador.
     \pre <em>id_procesador debe existir</em>
     \post Se lee el identificador del proceso y del procesador y si existe dicho proceso en dicho procesador la memoria que usaba pasa a quedar libre y el proceso desaparece. Si no existe el proceso en dicho procesador no se hace nada.
     */
    
    
    int avanzar_tiempo(int tiempo);
    /** @brief Avanza el tiempo.
     \pre <em>Tiempo debe ser positvo</em>
     \post Avanza el tiempo para todos los procesadores del cluster.
     */
    
    
    
    pair<int,int> mejor_procesador(BinTree<int> t, int espacio_necesario);
    
    int enviar_procesos_a_cluster(proceso& p);
    
    /** @brief Envia procesos al cluster.
     \pre <em>n >= 0</em>
     \post Se lee un entero positivo np que indica cuantos procesos pendientes hay que enviar al cluster. Dichos procesos se envıan siguiendo un sistema de turnos. Los turnos se organizan asi: el primer turno le corresponde al proceso pendiente mas antiguo del usuario con menor identificador que tenga mas procesos pendientes; en cada turno posterior se aplica el mismo criterio, pero sin tener en cuenta los procesos que hayan sido devueltos en los turnos anteriores. Los turnos avanzan hasta que se hayan colocado np procesos o cuando no se puedan colocar mas procesos, bien porque no queden procesos pendientes o bien todos los que quedan no se pudieron colocar cuando les toco el turno. Evidentemente si un proceso no cabe cuando le toca el turno, con m ́as razo ́n no cabra despues puesto que ningun procesador libera memoria en esta operacion.Para poner un proceso en el cluster se escoge el procesador, de entre los que pueden aceptar el proceso, que tenga mas memoria libre en ese momento. En caso de empate, se escoge el mas cercano a la raiz, y si persiste el empate el de mas a la izquierda.
     */
    
    
    
    void consultar_procesador(int& id_procesador);
    /** @brief Consulta un procesador.
     \pre <em>El procesador existe</em>
     \post Se lee el identificador del procesador. Se escribe por orden de inicio de memoria dicha posicion y el resto de datos de cada proceso. El tiempo que se escribe es el tiempo que falta para que el proceso acabe, no el tiempo inicial de ejecucion.
     */
    
    
    void escribir_cluster();
    /** @brief Escribe por pantalla el cluster.
     \pre <em>Cierto</em>
     \post Escribe por pantalla el cluster.
     */
    
    int cosultar_mem_libre_procesador(int& id_procesador);
    
};

#endif /* cluster_hpp */






/* static: Ahora vas a coger este metodo y vas a pasar del parametro implicito, y te voy a pasar todo lo que necesitas por los parametros explicitos. Normalmente para funciones recursivas pq necesito pasarle los arboles como parametro, no me sirve tenerlo como parametro implicito
 
 Cuando quiero que un metodo o
 atributo no esté presente en todos
 los objetos, sino que para todos los
 objetos va a ser el mismo.
 
 cluster::lucha(a1,a2);
 */
