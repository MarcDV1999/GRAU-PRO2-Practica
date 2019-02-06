//
//  usuario.hpp
//  
//
//  Created by Marc Domenech on 06/11/2018.
//

/** @file usuario.hpp
 @brief Especificacion de la clase usuario
 */

#ifndef usuario_hpp
#define usuario_hpp


#include <queue>
#include <list>
#include <string>
#include "proceso.hpp"
#include <string>
#include <map>



/** @class usuario
 @brief Representa un usuario
 */

class usuario{
private:
    string id_usuario;
    int numero_procesos;
    int numero_procesos_pendientes;
    queue<proceso> cola_procesos_pendientes;
    map<int,proceso> procesos_usuario;

public:
    
    // Constructoras
    
    usuario(string id);
    /** @brief Constructora.
     \pre <em>El id no puede estar ya registrado en el cluster</em>
     \post Crea un usuario con id_usuario.
     */

    int consultar_usuario(proceso& p);
    /** @brief Consulta un Usuario.
     \pre <em>Cierto</em>
     \post Retorna cuantos procesos pendientes tiene y guarda el proceso mas antiguo. Si no tiene procesos pendientes solo retorna 0 y no toca p.
     */
    void ponerProcesoPendiente(proceso& p);
    /** @brief Añade un proceso pendiente.
     \pre <em>Cierto</em>
     \post Se añade a la cola de procesos pendientes del usuario el proceso p.
     */
    
    void quitarProcesoPendiente();
    /** @brief Quita el proceso pendiente mas antiguo.
     \pre <em>p existe</em>
     \post Quita el proceso pendiente mas antiguo.
     */
    
    void poner_proceso_activo(proceso& p);
    /** @brief Quita el proceso pendiente mas antiguo.
     \pre <em>p existe</em>
     \post Quita el proceso pendiente mas antiguo.
     */
    
    void escribir_usuario();
};
#endif /* usuario_hpp */
