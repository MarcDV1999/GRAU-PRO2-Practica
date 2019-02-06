//
//  sistema.cpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domenech on 16/11/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//

#include "sistema.hpp"

sistema::sistema(){
    U = Conjunto_Usuarios();
    c = cluster();
}
sistema::sistema(int n){
    vector<procesador> v;
    for (int i = 0; i < n; i++) {
        if(i <= 5) {
            procesador p(i,i*10 + 10);
            v.push_back(p);
        }
        else {
            procesador p(i,i*10 - 40);
            v.push_back(p);
        }
    }
    c = cluster(v);
}

void sistema::configurar_cluster(){
    int num_procesadores;
    cin >> num_procesadores;
    c.configurar_cluster(num_procesadores);
    //c.escribir_cluster();
    
}

void sistema::poner_usuario(){
    string id_usuario;
    cin >> id_usuario;
    usuario u(id_usuario);
    U.poner_usuario(id_usuario, u);
    
}

void sistema::quitar_usuario(){
    string id_usuario;
    cin >> id_usuario;
    U.quitar_usuario(id_usuario);
    
}

void sistema::poner_proceso_en_procesador(){
    int procesador,id_proceso,espacio,tiempo;
    string id_usuario;
    cin >> procesador >> id_usuario >> id_proceso >> espacio >> tiempo;
    proceso p(id_usuario,id_proceso,espacio,tiempo);
    if(c.poner_proceso_en_procesador(procesador, p) == -1)U.enviar_proceso_a_usuario(id_usuario, id_proceso, espacio, tiempo);
    else U.poner_proceso_activo(id_usuario, p);
    
}

void sistema::quitar_proceso_de_procesador(){
    int id_proceso, procesador;
    cin >> procesador >> id_proceso;
    c.quitar_proceso_de_procesador(procesador, id_proceso);
    
}

void sistema::enviar_proceso_a_usuario(){
    string id_usuario;
    int id_proceso, memoria, tiempo;
    cin >> id_usuario >> id_proceso >> memoria >> tiempo;
    U.enviar_proceso_a_usuario(id_usuario, id_proceso, memoria, tiempo);
    
}


void sistema::consultar_usuario(){
    usuario u("");
    proceso p;
    string id_usuario;
    int p_pendientes;
    cin >> id_usuario;
    cout << "Usuario " << id_usuario;
    if(U.existe_usuario(id_usuario, u)){
        p_pendientes = u.consultar_usuario(p);
        //cout << "el proceso pendiente es: " << id_proceso << endl;
        if(p_pendientes == 0) cout <<endl<<"  " << p_pendientes;
        else cout << endl << "  " << p_pendientes << " " << p.consultar_id();
    }
    
}


void sistema::avanzar_tiempo(){
    
    int tiempo;
    cin >> tiempo;
    //escribir_usuarios();
    c.avanzar_tiempo(tiempo);
}


void sistema::consultar_procesador(){
    int num_procesador;
    cin >> num_procesador;
    cout << "Procesador " << num_procesador;
    c.consultar_procesador(num_procesador);
}


void sistema::enviar_procesos_a_cluster(){
    
    queue<proceso> procesos_fallidos;
    int n;
    cin >> n; // numero procesos a enviar.
    proceso p;
    bool acabado = false; // si no quedan mas pendientes o si no hay ninguno que se pueda poner
    //cout << n << "-----> " << acabado << endl;
    while(n > 0 and !acabado){
        
        proceso p= U.usuario_con_mas_procesos_pendientes(); // Ya tenemos el proceso a poner, si no quedan el procesos tendra como id -1.
        //cout << "Vamos a poner el proceso en el cluster: ";
        //p.escribir_proceso();
        if(p.consultar_id() > 0) {
            //cout << "Pues vamos a tener que ponerlo" << endl;
            if(c.enviar_procesos_a_cluster(p) == 0) {
                //cout << "Pues este NO PODEMOS METERLO" << endl;
                procesos_fallidos.push(p);
            }
            else n--;
            string id_usuario = p.consultar_id_usuario();
            U.quitar_proceso_pendiente(id_usuario);
        }
        else acabado = true;
    }
    for (int i = 0; i < procesos_fallidos.size(); i++) {
        U.enviar_proceso_a_usuario(procesos_fallidos.front().consultar_id_usuario(), procesos_fallidos.front().consultar_id(), procesos_fallidos.front().consultar_memoria(), procesos_fallidos.front().consultar_tiempo());
        procesos_fallidos.pop();
    }
}


void sistema::escribir_cluster(){
    cout << "----------- CLUSTER --------------" << endl << endl;
    c.escribir_cluster();
    cout << "----------- FIN --------------" << endl << endl;
}

void sistema::escribir_usuarios(){
    cout << "----------- USUARIOS --------------" << endl << endl;
    U.escribir_usuarios();
    cout << "----------- FIN --------------" << endl << endl;
}

