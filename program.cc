//
//  main.cpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domènech on 06/11/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//

/** @file main.cpp
 @brief Programa Principal
 */

#include <iostream>
#include "sistema.hpp"
#include <string>

using namespace std;

string estado;
bool primero = true;
void acabar(){
    exit(12);
}

int main() {
    sistema sys;
    while(cin >> estado){
        
        if(estado == "configurar_cluster") {
            sys.configurar_cluster();
            //sys.escribir_cluster();
            //cout << "Acabo de Crear un sistema";
            //cout << "*********" << endl;
        }
        else if(estado == "poner_usuario") {
            sys.poner_usuario();
            //sys.escribir_usuarios();
            //cout << "Acabo de Poner un Usuario";
            //cout << "*********" << endl;
        }
        else if(estado == "quitar_usuario") {
            sys.quitar_usuario();
            //sys.escribir_usuarios();
            //cout << "Acabo de Quitar un Usuario";
            //cout << "*********" << endl;
        }
        else if(estado == "poner_proceso_en_procesador"){
            sys.poner_proceso_en_procesador();
            //sys.escribir_cluster();
            //cout << "Acabo de Poner un Proceso en Procesador";
            //cout << "*********" << endl;
        }
        else if(estado == "quitar_proceso_de_procesador") {
            sys.quitar_proceso_de_procesador();
            //sys.escribir_cluster();
            //cout << "Acabo de Quitar un proceso de procesador";
            //cout << "*********" << endl;
        }
        else if(estado == "enviar_proceso_a_usuario") {
            sys.enviar_proceso_a_usuario();
            //sys.escribir_usuarios();
            //cout << "Acabo de enviar un Proceso a Usuario";
            //cout << "*********" << endl;
        }
        else if(estado == "consultar_usuario") {
            if(!primero) cout << endl;
            else primero = false;
            //cout << "       Entro en ->>>> consultar_usuario" << endl;
            sys.consultar_usuario();
            //sys.escribir_usuarios();
            //cout << "       Acabo de Consultar un Usuario";
            //cout << "*********" << endl;
        }
        else if(estado == "avanzar_tiempo") {
            //cout << "ME TOCA AVANZAR EL TIEMPO" << endl;
            sys.avanzar_tiempo();
            //cout << "ACABO DE AVANZAR EL TIEMPO" << endl;
        }
        else if(estado == "consultar_procesador") {
            if(!primero)cout << endl;
            else primero = false;
            sys.consultar_procesador();
            //sys.escribir_cluster();
            //cout << "ACABO DE CONSULTAR PROCESADOR" << endl;
        }
        else if(estado == "enviar_procesos_a_cluster") {
            sys.enviar_procesos_a_cluster();
            //sys.escribir_cluster();
            //cout << "enviamos proceso al cluster";
            //cout << "*********" << endl;
        }
        else if(estado == "acabar") {
            acabar();
        }
        
        
    }
    
    
}



