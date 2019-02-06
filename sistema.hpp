//
//  sistema.hpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domènech on 04/12/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//

#ifndef sistema_hpp
#define sistema_hpp

//#include "BinTree.hh"
//#include "BinTreeIOint.hh"
#include "cluster.hpp"
#include "Conjunto_Usuarios.hpp"
#include "procesador.hpp"
#include "proceso.hpp"
#include "usuario.hpp"


/** @class cluster
 @brief Representa un cluster
 */

class sistema{
private:
    Conjunto_Usuarios U;
    cluster c;
    
    
public:
    
    //  Constructoras
    
    sistema();
    /** @brief Constructora por defecto.
     \pre <em>Cierto</em>
     \post Constructora por defecto. Crea un cluster vacio.
     */
    
    sistema(int n);
    
    void configurar_cluster();
    /** @brief Configura Cluster.
     \pre <em>Cierto</em>
     \post Los datos siempre comenzaran por una configuracion de cluster. Se leera el numero de procesadores, sus conexiones y la memoria de cada uno de ellos en orden creciente de id. Esta operacion se puede realizar varias veces. Si se vuelve a configurar el cluster mas adelante, los procesos activos se eliminan, pero los procesos pendientes de los usuarios se conservan para el siguiente cluster en el mismo estado que antes.
     */
    
    
    void poner_usuario();
    /** @brief Pone proceso en un Procesador.
     \pre <em>id_procesador debe existir</em>
     \post Se leen el id de un procesador y los datos de un proceso. Si el usuario no existe no se hace nada. Si hay un hueco de memoria libre consecutiva en el que quepa el proceso, pasa a ejecutarse en dicho procesador y la memoria que use pasa a estar ocupada. Si el proceso no cabe, pasa a ser el proceso pendiente mas reciente del usuario.
     */
    void quitar_usuario();
    /** @brief Quita un proceso de un procesador.
     \pre <em>id_procesador debe existir</em>
     \post Se lee el identificador del proceso y del procesador y si existe dicho proceso en dicho procesador la memoria que usaba pasa a quedar libre y el proceso desaparece. Si no existe el proceso en dicho procesador no se hace nada.
     */
    
    
    void poner_proceso_en_procesador();
    /** @brief Avanza el tiempo.
     \pre <em>Tiempo debe ser positvo</em>
     \post Se lee un entero positivo que indica las unidades de tiempo que han transcurrido desde el momento inicial (al configurar el cluster) o desde la ultima vez que se avanzo el tiempo. Se eliminan todos los procesos activos que hayan acabado en ese intervalo de tiempo.
     */
    
    void quitar_proceso_de_procesador();
    /** @brief Consulta un procesador.
     \pre <em>El procesador existe</em>
     \post Se lee el identificador del procesador. Se escribe por orden de inicio de memoria dicha posicion y el resto de datos de cada proceso. El tiempo que se escribe es el tiempo que falta para que el proceso acabe, no el tiempo inicial de ejecucion.
     */
    
    void enviar_proceso_a_usuario();
    /** @brief Envia procesos al cluster.
     \pre <em>n >= 0</em>
     \post Se lee un entero positivo np que indica cuantos procesos pendientes hay que enviar al cluster. Dichos procesos se envıan siguiendo un sistema de turnos. Los turnos se organizan asi: el primer turno le corresponde al proceso pendiente mas antiguo del usuario con menor identificador que tenga mas procesos pendientes; en cada turno posterior se aplica el mismo criterio, pero sin tener en cuenta los procesos que hayan sido devueltos en los turnos anteriores. Los turnos avanzan hasta que se hayan colocado np procesos o cuando no se puedan colocar mas procesos, bien porque no queden procesos pendientes o bien todos los que quedan no se pudieron colocar cuando les toco el turno. Evidentemente si un proceso no cabe cuando le toca el turno, con m ́as razo ́n no cabra despues puesto que ningun procesador libera memoria en esta operacion.Para poner un proceso en el cluster se escoge el procesador, de entre los que pueden aceptar el proceso, que tenga mas memoria libre en ese momento. En caso de empate, se escoge el mas cercano a la raiz, y si persiste el empate el de mas a la izquierda.
     */
    
    void consultar_usuario();
    /** @brief Consulta el Usuario.
     \pre <em>Cierto</em>
     \post Consulta el Cluster.
     */
    
    void avanzar_tiempo();
    /** @brief Avanza el tiempo en el cluster.
     \pre <em>Cierto</em>
     \post Avanza el tiempo en el cluster.
     */
    
    
    void consultar_procesador();
    /** @brief Consulta el Procesador.
     \pre <em>Cierto</em>
     \post Consulta el procesador.
     */
    
    void escribir_proceso(proceso& p);
    /** @brief Escribe la informacion de un proceso.
     \pre <em>Cierto</em>
     \post Escribe la informacion de un proceso.
     */
    
    void enviar_procesos_a_cluster();
    /** @brief Envia procesos al cluster
     \pre <em>Cierto</em>
     \post Imprime por pantalla la informacion de los usuarios del conjunto.
     */
    
    void escribir_cluster();
    /** @brief Escribe la informacion de los usuarios del conjunto.
     \pre <em>Cierto</em>
     \post Imprime por pantalla la informacion de los usuarios del conjunto.
     */
    
    void escribir_usuarios();
    /** @brief Escribe la informacion de los usuarios del conjunto.
     \pre <em>Cierto</em>
     \post Imprime por pantalla la informacion de los usuarios del conjunto.
     */
    
    
    
    
};

#endif /* sistema_hpp */









/* static: Ahora vas a coger este metodo y vas a pasar del parametro implicito, y te voy a pasar todo lo que necesitas por los parametros explicitos. Normalmente para funciones recursivas pq necesito pasarle los arboles como parametro, no me sirve tenerlo como parametro implicito
 
 Cuando quiero que un metodo o
 atributo no esté presente en todos
 los objetos, sino que para todos los
 objetos va a ser el mismo.
 
 cluster::lucha(a1,a2);
 */
