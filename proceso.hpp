//
//  proceso.hpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domènech on 15/11/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//

/** @file proceso.hpp
 @brief Especificación de la clase proceso
 */

#ifndef proceso_hpp
#define proceso_hpp
#include <string>
#include <iostream>


using namespace std;

/** @class proceso
 @brief Representa un proceso
 */

class proceso{
    
private:
    int id_proceso;
    string id_usuario;
    int memoria;
    int tiempo;
    int tiempo_restante;
public:
    // Constructoras
    proceso();
    /** @brief Constructora por defecto.
     \pre <em>Cierto</em>
     \post Crea un proceso con todos los campos vacios.
     */
    
    proceso(string usuario,int id_proceso, int memoria, int tiempo);
    /** @brief Constructora.
     \pre <em>id_usuario existe, id_proceso no existe, memoria y tiempo > 0</em>
     \post Crea un proceso con todos los campos de los parametros.
     */
    
    int consultar_id();
    /** @brief consulta el id del proceso.
     \pre <em>Cierto</em>
     \post Retorna el id.
     */
    
    string consultar_id_usuario();
    /** @brief Consulta el id del usuario.
     \pre <em>Cierto</em>
     \post Retorna el id_usuario
     */
    
    int consultar_memoria();
    /** @brief Consulta la memoria del proceso.
     \pre <em>Cierto</em>
     \post Retorna la memoria.
     */
    
    int consultar_tiempo();
    /** @brief Consulta el tiempo del Proceso.
     \pre <em>Cierto</em>
     \post Retorna el tiempo.
     */

    void modificar_tiempo_restante(int t);
    /** @brief Modifica el tiempo restante del Proceso.
     \pre <em>Cierto</em>
     \post Retorna el tiempo restante.
     */
    
    int consultar_tiempo_restante();
    /** @brief Modifica el tiempo restante del Proceso.
     \pre <em>Cierto</em>
     \post Retorna el tiempo restante.
     */
    
    void escribir_proceso();
    /** @brief Escribe el parametro implicito por canal estandar de salida.
     \pre <em>Cierto</em>
     \post Escribe por pantalla el proceso.
     */
};

#endif /* proceso_hpp */
