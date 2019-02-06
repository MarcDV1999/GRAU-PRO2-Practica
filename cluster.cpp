//
//  cluster.cpp
//  Practica Pro 2 Quatri 2
//
//  Created by Marc Domènech on 09/11/2018.
//  Copyright © 2018 Marc Domenech. All rights reserved.
//
/** @file cluster.cpp
 @brief Implementación de la clase cluster
 */
#include "cluster.hpp"
#include <iostream>
using namespace std;

cluster::cluster(){
    arbol_procesadores = BinTree<int>();
    v_procesadores = vector<procesador>();
    //int tiempo_ejecucion = 0;
    procesadores_candidatos = map<int,procesador_candidato>();
    it = procesadores_candidatos.begin();
    tiempo_ejecucion = 0;
}

cluster::cluster(vector<procesador>& v_procesadores){
    //Definir el arbol para entonces
    this -> v_procesadores = v_procesadores;
    tiempo_ejecucion = 0;
}

void cluster::configurar_cluster(int numero_procesadores){
    
    read_bintree_int(arbol_procesadores, 0);
    this -> numero_procesadores = numero_procesadores;
    //v_procesadores.resize(numero_procesadores);
    
    int memoria;
    if(v_procesadores.size() > 0) v_procesadores.clear(); // Creo que con esto se soluciona
    for (int i = 0; i < numero_procesadores; i++) {
        cin >> memoria;
        procesador p(i,memoria);
        v_procesadores.push_back(p);
    }
    /* Creo que ya esta solucionado
        Ahora tocaria limpiar todos los procesadores, quitando todos sus procesos
        (volver crear el vector de procesadores vacios)
        Por otro lado tenemos que mantener las colas de procesos pendientes, que
        no se hasta que punto no hay que hacer nada pq si no lo modifico... se
        deberia mantener.
     */
}


int cluster::poner_proceso_en_procesador(int& id_procesador, proceso& p){
    if(id_procesador <= v_procesadores.size()){
        if(v_procesadores[id_procesador-1].poner_proceso(p) == -1) return -1;
        else return 1;
        
        
    }
    return -1;
    
}

void cluster::quitar_proceso_de_procesador(int& id_procesador, int& id_proceso){
    if(id_procesador <= v_procesadores.size()) v_procesadores[id_procesador-1].quitar_proceso(id_proceso);
}

int cluster::avanzar_tiempo(int tiempo){
    
    int procesos_acabados = 0, aux;
    // Recorremos el vector de procesadores avanzando el tiempo a cada uno de ellos.
    // aux almacena cuantos procesos se eliminan en un procesador.
    for (int i = 0; i < v_procesadores.size(); i++) {
        aux = v_procesadores[i].avanzar_tiempo(tiempo);
        procesos_acabados += aux;
    }
    tiempo_ejecucion += tiempo;
    return procesos_acabados;
    
}

pair<int, int> cluster::mejor_procesador(BinTree<int> t, int espacio_necesario){
    // Buscar el que tenga mas espacio, que este mas cerca de la raiz y mas a laizquierda posible.
    // First = ID del procesador  Second = profundidad
    
    if(t.empty()) return make_pair(-1,-1);
    else{
        pair<int, int> p_izquierda = mejor_procesador(t.left(), espacio_necesario);
        pair<int, int> p_derecha = mejor_procesador(t.right(), espacio_necesario);
        pair<int, int> p_raiz = make_pair(t.value(), 0);
        
        ++p_izquierda.second; // Sumamos una a la profundidad
        ++p_derecha.second;
        int mem_libre_izq,mem_libre_der,mem_libre_raiz;
        
        // Guardamos el espacio libre de los tres procesadores.
        if(p_izquierda.first >= 0) mem_libre_izq = v_procesadores[p_izquierda.first-1].consultar_memoria_libre();
        else mem_libre_izq = -1;
        
        if(p_derecha.first >= 0) mem_libre_der = v_procesadores[p_derecha.first-1].consultar_memoria_libre();
        else mem_libre_der = -1;
        
        if(p_raiz.first >= 0) mem_libre_raiz = v_procesadores[p_raiz.first-1].consultar_memoria_libre();
        else mem_libre_raiz = -1;
        
        // Comparo los tres pairs para ver cual es el mejor
        if(mem_libre_der >= espacio_necesario or mem_libre_izq >= espacio_necesario or mem_libre_raiz >= espacio_necesario){
            
            if(mem_libre_raiz >= mem_libre_izq and mem_libre_raiz >= mem_libre_der) return p_raiz; // si la raiz es el mas grande.
            else if(mem_libre_raiz < mem_libre_izq and mem_libre_der < mem_libre_izq) return p_izquierda; // Si izquierda es el mas grande
            else if(mem_libre_raiz < mem_libre_der and mem_libre_izq < mem_libre_der) return p_derecha; // Si derecha es el mas grande
            else if(p_derecha.second < p_izquierda.second) return p_derecha; // SI izquierda es mas profundo
            else if(p_izquierda.second < p_derecha.second) return p_izquierda; // Si derecha es mas profundo
            else return p_izquierda; // Si empatan en todo, el de la izquierda

        }
        else return make_pair(-1,-1);
    }
}


int cluster::enviar_procesos_a_cluster(proceso& p){
    // Teniendo el mejor proceso, buscamos el mejor procesador y lo enviamos.
    //p.escribir_proceso();
    pair<int,int> proc = mejor_procesador(arbol_procesadores,p.consultar_memoria());
    //cout << "Memoria procesador " << proc.first << ": ";
    if(proc.first != -1)v_procesadores[proc.first-1].poner_proceso(p);
    else return 0;
    return 1;
    //v_procesadores[proc.first].escribir_procesador();
    
}

void cluster::consultar_procesador(int& id_procesador){
    v_procesadores[id_procesador-1].consultar_procesador();
}


void cluster::escribir_cluster(){
    for (int i = 0; i < numero_procesadores; i++) {
        cout << "-------------------------" << endl;
        v_procesadores[i].escribir_procesador();
        cout << "-------------------------" << endl;
    }
}
