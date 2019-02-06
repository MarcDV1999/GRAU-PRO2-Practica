//
//  procesador.cpp
//  
//
//  Created by Marc Domènech on 06/11/2018.
//
/** @file procesador.cpp
 @brief Implementación de la clase cluster
 */

#include "procesador.hpp"
#include <iostream>
using namespace std;


procesador::procesador(int id_procesador, int memoria_total){
    this -> id_procesador = id_procesador;
    this -> memoria_total = memoria_total;
    numero_procesos = 0;
    memoria_libre = memoria_total;
    m_procesos = map<int,proceso>();
    
    hueco h(0,memoria_total-1);
    m_huecos = map<int,hueco>();
    it_huecos = m_huecos.begin();
    //cout << m_huecos.size() << endl;
    m_huecos.insert(it_huecos, make_pair(0,h));
    
}

int procesador::poner_proceso(proceso& p){
    pair<int, hueco> aux = mejor_hueco(p);
    if(usar_hueco(p, aux) != -1){
        //cout << "ENTRO_----------------_______----____---___-"<< endl;
        memoria_libre -= p.consultar_memoria();
        numero_procesos++;
        //cout << "ID: " << id_procesador+1 << " numero: " << numero_procesos << endl;
        if(m_huecos.size() == 0){
            hueco h(p.consultar_memoria()+(memoria_total-memoria_libre - p.consultar_memoria()),memoria_libre);
            m_huecos.insert(make_pair(p.consultar_memoria()+(memoria_total-memoria_libre - p.consultar_memoria()),h));
            return 1;
        
        }
    }
    return -1;
}

int procesador::quitar_proceso(int id_proceso){
    
    for (it_procesos = m_procesos.begin(); it_procesos != m_procesos.end(); it_procesos++) {
        if(id_proceso == it_procesos -> second.consultar_id()){
            hueco h(it_procesos -> first,it_procesos -> second.consultar_memoria()-1);
            m_huecos.insert(make_pair(it_procesos -> first, h));
            int inicio_nuevo_hueco = it_procesos -> first;
            int tamaño_nuevo_hueco = it_procesos -> second.consultar_memoria();
            it_procesos = m_procesos.erase(it_procesos);
            memoria_libre += it_procesos -> second.consultar_memoria();
            numero_procesos--;
            
            // Hasta aqui creamos otro hueco y lo introducimos en m_huecos. Problema, quiero que en m_huecos no haya dos huecos consecutivos, sino juntarlos los dos para formar un hueco mas grande.
            
            it_huecos = m_huecos.find(inicio_nuevo_hueco);
            map<int,hueco>::iterator it_izquierda = it_huecos,it_derecha = it_huecos; // Lo usaremos para apuntar a el hueco de delante y detras para ver si hay que juntar los huecos o no.
            
            if(it_izquierda != m_huecos.begin())it_izquierda--;
            if(it_derecha != m_huecos.end())it_derecha++;
            
            if((it_derecha -> first == inicio_nuevo_hueco + tamaño_nuevo_hueco) and (it_izquierda -> second.consultar_tamaño()+it_izquierda->first)+1 == inicio_nuevo_hueco){
                // Caso donde tengo huecos por la izquierda y por la derecha
                //cout <<  "Tengo que tocar por todos lados " << endl;
                hueco h(it_izquierda->first,tamaño_nuevo_hueco + it_derecha ->second.consultar_tamaño() +it_izquierda ->second.consultar_tamaño()+1);
                it_izquierda = m_huecos.erase(it_izquierda);
                it_derecha = m_huecos.erase(it_derecha);
                it_huecos = m_huecos.erase(it_huecos);
                m_huecos.insert(make_pair(it_izquierda->first,h));
                
            }
            else if((it_izquierda -> second.consultar_tamaño()+it_izquierda->first)+1 == inicio_nuevo_hueco){
                // Caso donde solo tengo hueco a la izquierda
                //cout << "Tengo que juntarme con el de la izquierda" << endl;
                
                hueco h(it_izquierda->first,tamaño_nuevo_hueco + it_derecha ->second.consultar_tamaño());
                it_izquierda = m_huecos.erase(it_izquierda);
                it_huecos = m_huecos.erase(it_huecos);
                m_huecos.insert(make_pair(it_izquierda->first,h));
            }
            else if(it_derecha -> first == inicio_nuevo_hueco + tamaño_nuevo_hueco){
                // Caso donde solo tengo hueco a la derecha
                //cout << "Tengo que juntarme con el de la derecha" << endl;
                hueco h(inicio_nuevo_hueco,tamaño_nuevo_hueco + it_derecha ->second.consultar_tamaño());
                it_derecha = m_huecos.erase(it_derecha);
                it_huecos = m_huecos.erase(it_huecos);
                m_huecos.insert(make_pair(inicio_nuevo_hueco,h));
                
            }
            return 1;
            
        }
    }
    
    return -1;
    
}

pair<int,procesador::hueco> procesador::mejor_hueco(proceso& x){
    
    it_huecos = m_huecos.begin();
    bool cabe = false;
    int memoria_proceso = x.consultar_memoria();
    hueco h(memoria_proceso,memoria_libre-1);
    pair<int,hueco> mas_justo = make_pair(memoria_proceso,h);
    
    for (it_huecos = m_huecos.begin(); it_huecos != m_huecos.end(); it_huecos++) {
        
        //cout << endl << "MEM: " << memoria_proceso << "  ---  " << it_huecos -> second.consultar_tamaño() << "(/&%$·%%$&/()=(/&%&$%$··&/()=(/&%$%%$&/()" << endl;
        if(memoria_proceso == (it_huecos -> second.consultar_tamaño())) {
            //aqui
            
            //cout << endl << "/(/(/(/(/(/(/(/(/(Entras aqui no?  puto cabron de merda" << endl;
            return make_pair(it_huecos -> first, it_huecos -> second);
        }
        
        else if (((it_huecos -> second.consultar_tamaño()) - memoria_proceso -1 > 0) and (it_huecos -> second.consultar_tamaño() - memoria_proceso - 1 < mas_justo.second.consultar_tamaño())){
            mas_justo.first = it_huecos -> first;
            mas_justo.second = it_huecos -> second;
            cabe = true;
        }
        
    }
    
    if(cabe) {
        //cout << "CABEEEEE--------______---____--__--_-_--_-_" <<endl;
        return mas_justo;
    }
    else return make_pair(-1,it_huecos -> second);
}

int procesador::usar_hueco(proceso& x,pair<int,hueco>& mas_justo){
    if(mas_justo.first != -1){
        if(mas_justo.second.consultar_tamaño() == x.consultar_memoria()){
            // El espacio que ocupa es igual de grande que el hueco
            m_procesos.insert(make_pair(mas_justo.first,x));
            m_huecos.erase(mas_justo.first);
        }
        else{
            // El espacio que ocupa es mas pequeño que el hueco
            hueco h(mas_justo.first+x.consultar_memoria(),(mas_justo.second.consultar_tamaño()-x.consultar_memoria()));
            m_procesos.insert(make_pair(mas_justo.first,x));
            m_huecos.erase(mas_justo.first);
            m_huecos.insert(make_pair(mas_justo.first+x.consultar_memoria(), h));
            }
        return 1;
    }
    else return -1;
}



void procesador::consultar_procesador(){
    for (it_procesos = m_procesos.begin(); it_procesos != m_procesos.end(); it_procesos++) {
        cout << endl<< "  " << it_procesos -> first << " " << it_procesos -> second.consultar_id_usuario() << " " << it_procesos -> second.consultar_id() << " " << it_procesos -> second.consultar_memoria() << " " << it_procesos -> second.consultar_tiempo_restante();
        //it_procesos -> second.escribir_proceso();
    }
}

int procesador::avanzar_tiempo(int& tiempo){
    //int total = m_procesos.size();
    if(tiempo >= 0 and  m_procesos.size() > 0){
        int procesos_eliminados = 0;
        map<int,proceso>::iterator it_aux;
        //cout << "////////////////////////////" << endl << endl;
        //cout << "Nos toca avanzar el tiempo" << endl;
        it_procesos = m_procesos.begin();
        while(it_procesos != m_procesos.end()){
            //cout << "tenemos el proceso: ";
            //it_procesos -> second.escribir_proceso();
            
            int t = it_procesos -> second.consultar_tiempo_restante();
            it_procesos -> second.modificar_tiempo_restante(t - tiempo);
            //it_procesos -> second.escribir_proceso();
            //cout << "El tiempo es negativo???  ";
            
            if(it_procesos -> second.consultar_tiempo_restante() < 1) {
                //cout << "Si" << endl;
                // Se ha avanzado el tiempo del proceso y el proceso ha acabado.
                int n = it_procesos -> second.consultar_id(); // id del proceso
                if(quitar_proceso(n) == 1) procesos_eliminados++;
                //it_procesos -> second.escribir_proceso();
                //cout << "Creo que ya lo he quitado" << endl << endl;
                
            }
            else {
               // cout << "NO" << endl << endl;
                it_procesos++;
            }
        }
        //cout << "hemos eliminado " << procesos_eliminados << " de " << total << endl;
        return procesos_eliminados;
        
    }
    
    return 0;
}


int procesador::consultar_memoria_libre(){
    return memoria_libre;
}

void procesador::escribir_procesador(){
    cout << "Procesador: " << id_procesador+1 << endl;
    cout << "Memoria Total: " << memoria_total << endl;
    cout << "Memoria Libre: " << memoria_libre << endl;
    cout << "Numero Procesos: " << numero_procesos << endl;
    
}

void procesador::escribir_procesos(){
    for (it_procesos = m_procesos.begin(); it_procesos != m_procesos.end(); it_procesos++) {
        it_procesos -> second.escribir_proceso();
    }
}


void procesador::modificar_numero_procesos(){
    numero_procesos++;
}




procesador::hueco::hueco(int pos_inicial,int total){
    this -> pos_inicial = pos_inicial;
    this -> total = total+1;
}





int procesador::hueco::consultar_tamaño(){
    return total;
}





