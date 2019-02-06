//
//  proceso.cpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domènech on 15/11/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//
/** @file proceso.cpp
 @brief Implementación de la clase proceso.
 */
#include "proceso.hpp"

proceso::proceso(){
    id_usuario = "";
    id_proceso = -1;
    memoria = 0;
    tiempo = 0;
    tiempo_restante = tiempo;
}

proceso::proceso(string id_usuario,int id_proceso, int memoria, int tiempo){
    this -> id_usuario = id_usuario;
    this -> id_proceso = id_proceso;
    this -> memoria = memoria;
    this -> tiempo = tiempo;
    tiempo_restante = tiempo;
    
}

int proceso::consultar_id(){
    return id_proceso;
}

string proceso::consultar_id_usuario(){
    return id_usuario;
}

int proceso::consultar_memoria(){
    return memoria;
}

int proceso::consultar_tiempo(){
    return tiempo;
}

void proceso::modificar_tiempo_restante(int t){
    
    tiempo_restante = t;
}
int proceso::consultar_tiempo_restante(){
    return tiempo_restante;
}

void proceso::escribir_proceso(){
    cout << "   " << id_proceso << "  " << id_usuario;
    cout << "  " << memoria << "  " << tiempo_restante << endl;
}
