//
//  Conjunto_Usuarios.hpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domènech on 16/11/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//

/** @file Conjunto_Usuarios.hpp
 @brief Especificación de la clase clusterConjunto_Usuarios
 */

#ifndef Conjunto_Usuarios_hpp
#define Conjunto_Usuarios_hpp


#include "usuario.hpp"
#include <map>


class Conjunto_Usuarios{
    
private:
    map<string,usuario> m_usuarios;
    map<string,usuario>::iterator iterador;
    
    int numero_usuarios;
    
public:
    
    Conjunto_Usuarios();
    /** @brief Constructora por defecto.
     \pre <em>Cierto</em>
     \post Constructora por defecto. Crea un Conjunto Usuarios vacio.
     */
    
    Conjunto_Usuarios(map<string,usuario>& m_usuarios);
    /** @brief Constructora.
     \pre <em>Cierto</em>
     \post Crea un Conjunto_Usuarios con un conjunto de usuarios.
     */
    
    void enviar_proceso_a_usuario(string id_usuario, int id_proceso, int memoria, int tiempo);
    /** @brief Envia un proceso a un usuario.
     \pre <em>Cierto</em>
     \post Se leen los datos de un proceso y pasa a ser un proceso pendiente del usuario, el mas reciente de todos.
     */
    
    void poner_usuario(string& id_usuario,usuario& u);
    /** @brief Añade usuario.
     \pre <em>Cierto</em>
     \post Añade un usuario al Conjunto. Si ya existia no se añade.
     */
    
    void quitar_usuario(string& id_usuario);
    /** @brief Quita usuario.
     \pre <em>Cierto</em>
     \post Quita un usuario si existe, en caso contrario no hace nada.
     */
    
    bool existe_usuario(string& id_usuario, usuario& u);
    /** @brief Comprueba si existe un usuario.
     \pre <em>Cierto</em>
     \post Retorna True si existe el usuario y guarda en en los parametros implicitos su informacion, en caso contrario retorna False.
     */
    
    //proceso mejor_candidato();
    
    void escribir_usuarios();
    /** @brief Escribe la informacion de los usuarios del conjunto.
     \pre <em>Cierto</em>
     \post Imprime por pantalla la informacion de los usuarios del conjunto.
     */
    
    void quitar_proceso_pendiente(string& id);
    /** @brief Retorna un usuario.
     \pre <em>El usuario debe existir</em>
     \post Retorna el usuario.
     */
    
    void poner_proceso_activo(string id_usuario, proceso& p);
    
    proceso usuario_con_mas_procesos_pendientes();
    /** @brief Analiza que usuario tiene mas procesos pendientes.
     \pre <em>Cierto</em>
     \post Retorna el proceso mas antiguo del usuario con menor identificador con mas procesos pendientes
     */
};

#endif /* Conjunto_Usuarios_hpp */
