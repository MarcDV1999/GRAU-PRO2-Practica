//
//  usuario.cpp
//  
//
//  Created by Marc Domenech on 06/11/2018.
//
/** @file usuario.cpp
 @brief Implementacion de la clase usuario.
 */
#include "usuario.hpp"
#include "proceso.hpp"
#include <string>
#include <iostream>
#include <map>


using namespace std;

usuario::usuario(string id){
    id_usuario = id;
    numero_procesos = 0;
    numero_procesos_pendientes = 0;
    cola_procesos_pendientes = queue<proceso>();
    procesos_usuario = map<int,proceso>();
}

int usuario::consultar_usuario(proceso& p){
    // retorna el numero de procesos pendientes y guarda el proceso mas antiguo
    if(numero_procesos_pendientes <= 0) return 0;
    else p = (cola_procesos_pendientes.front());
    return numero_procesos_pendientes;
    
}


void usuario::ponerProcesoPendiente(proceso& p){
    cola_procesos_pendientes.push(p);
    numero_procesos_pendientes++;
}

void usuario::quitarProcesoPendiente(){
    procesos_usuario.insert(make_pair(cola_procesos_pendientes.front().consultar_id(), cola_procesos_pendientes.front()));
    cola_procesos_pendientes.pop();
    numero_procesos_pendientes--;
    numero_procesos++;
    
}

void usuario::poner_proceso_activo(proceso& p){
    //cout << "He entrado" << endl;
    procesos_usuario.insert(make_pair(p.consultar_id(),p));
    numero_procesos++;
}

void usuario::escribir_usuario(){
    cout << id_usuario << endl;
    cout << "NUMERO DE PROCESOS: " << numero_procesos << endl;
    cout << "NUMERO DE PROCESOS PENDIENTES: " << numero_procesos_pendientes << endl;
    cout << "ULTIMO PROCESO PENDIENTE: ";
    proceso p;
    consultar_usuario(p);
    p.escribir_proceso();
    
    
}
