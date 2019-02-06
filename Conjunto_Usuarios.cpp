//
//  Conjunto_Usuarios.cpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domènech on 16/11/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//

#include "Conjunto_Usuarios.hpp"
#include "proceso.hpp"
#include "usuario.hpp"
#include <iostream>
using namespace std;

Conjunto_Usuarios::Conjunto_Usuarios(){
    m_usuarios = map<string,usuario>();
    iterador = m_usuarios.begin();
}

Conjunto_Usuarios::Conjunto_Usuarios(map<string,usuario>& m_usuarios){
    numero_usuarios += m_usuarios.size();
    this -> m_usuarios = m_usuarios;
    iterador = m_usuarios.begin();
}

void Conjunto_Usuarios::enviar_proceso_a_usuario(string id_usuario, int id_proceso, int memoria, int tiempo){
    proceso p(id_usuario, id_proceso, memoria, tiempo);
    
    iterador = m_usuarios.find(id_usuario);
    if(iterador != m_usuarios.end()) {
        iterador -> second.ponerProcesoPendiente(p);
        }
    
}

void Conjunto_Usuarios::poner_usuario(string& id_usuario,usuario& u){
    
    iterador = m_usuarios.find(id_usuario);
    if(iterador == m_usuarios.end()){
        numero_usuarios++;
        m_usuarios.insert(make_pair(id_usuario,u));
    }
    
}

void Conjunto_Usuarios::quitar_usuario(string& id_usuario){
    proceso p;
    iterador = m_usuarios.find(id_usuario);
    
    if(numero_usuarios > 0 and iterador != m_usuarios.end() and (iterador -> second.consultar_usuario(p)) == 0){
        m_usuarios.erase(iterador);
        numero_usuarios--;
    }
    iterador = m_usuarios.begin();
}

bool Conjunto_Usuarios::existe_usuario(string& id_usuario, usuario& u){
    // Retorna false si no encuentra el usuario y true si lo encuentra
    iterador = m_usuarios.find(id_usuario);
    if(iterador != m_usuarios.end()) {
        u =  iterador -> second;
        return true;
    }
    else return false;
}
/*
proceso Conjunto_Usuarios::mejor_candidato(){
    map<string,usuario>::iterator it_mejor = m_usuarios.begin();
    int id_proximo_proceso;
    for (iterador = m_usuarios.begin(); iterador != m_usuarios.end(); iterador++) {
        if(it_mejor -> second.consultar_usuario(id_proximo_proceso) < iterador -> second.consultar_usuario(id_proximo_proceso)) it_mejor = iterador; // quien tiene mas
    }
    return it_mejor -> second.consultar_proximo_proceso_pendiente(id_proximo_proceso);
}
*/

void Conjunto_Usuarios::escribir_usuarios(){
    for (iterador = m_usuarios.begin(); iterador != m_usuarios.end(); iterador++) {
        iterador -> second.escribir_usuario();
    }
}

void Conjunto_Usuarios::quitar_proceso_pendiente(string& id){
    iterador = m_usuarios.find(id);
    iterador -> second.quitarProcesoPendiente();
}

void Conjunto_Usuarios::poner_proceso_activo(string id_usuario, proceso& p){
    iterador = m_usuarios.find(id_usuario);
    if(iterador != m_usuarios.end()) iterador -> second.poner_proceso_activo(p);
}
proceso Conjunto_Usuarios::usuario_con_mas_procesos_pendientes(){
    
    map<string,usuario>::iterator mejor_usuario = m_usuarios.begin();
    proceso p;
    if(m_usuarios.size() > 0){
        for (iterador = m_usuarios.begin(); iterador != m_usuarios.end(); iterador++) {
            //cout << "       Este es el primero:";
            //iterador -> second.escribir_usuario();
            //cout << "       EL MEJOR: ";
            //mejor_usuario -> second.escribir_usuario();
            if(iterador -> second.consultar_usuario(p) > mejor_usuario -> second.consultar_usuario(p)) mejor_usuario = iterador;
            
            //cout << "       Me quedo con: ";
            //smejor_usuario -> second.escribir_usuario();
        }
    }
    else return p;
    return p;
}
