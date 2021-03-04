#include <iostream>
#include "Inicio_Sesion.h"
#include "Especialista.h"
#include "Medico.h"
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;

int main(){
    int opc, jr=0, regesp=0, n=0, is=0;
    Inicio_Sesion objIS;
    Especialista objEsp;
    Medico objMed;
    do{
        is=objIS.Verificar_Usuario(is);
    }while(is==0);

    do{
        cout<<"\t-------------------------------------------------------"<<endl;
        cout<<"\t-                MENU DE ESPECIALISTAS                -"<<endl;
        cout<<"\t-------------------------------------------------------"<<endl;
        cout<<"\t1.Registrar Especialista"<<endl;
        cout<<"\t2.Listar Especialista"<<endl;
        cout<<"\t3.Mostrar Especialista"<<endl;
        cout<<"\t4.Modificar Datos del Especialista"<<endl;
        cout<<"\t5.Buscar Especialista"<<endl;
        cout<<"\t6.Salir"<<endl;
        cout<<"\tIngrese una opcion: ";
        cin>>opc;
        system("cls");
        switch( opc ){
            case 1:
                int opreg;
                do{
                    cout<<"\t\tRegistro de Especialista"<<endl;
                    cout<<"\t\t------------------------"<<endl;
                    cout<<"\t!.Medicos"<<endl;
                    cout<<"\t2.Enfermeros"<<endl;
                    cout<<"\t3.Regresar al Menu de Especialistas"<<endl;
                    cout<<"\tElija una opcion: ";
                    cin>>opreg;
                    system("cls");
                    switch(opreg){
                    case 1:
                        objMed.Registrar_Especialista();
                        n++;
                        break;
                    case 2:

                        break;
                    case 3:
                        regesp=1;
                        system("cls");
                        break;
                    default:
                        cout<<"DATO ERRONEO";
                        system("cls");
                    }
                }while(regesp==0);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                jr=1;
                break;
            default:
                cout<<"DATO ERRONEO";
        }
    }while(jr==0);
    return 0;
}
