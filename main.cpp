#include <iostream>
#include "Paciente.h"
#include "Enfermero.h"
#include "Especialista.h"
#include "Medico.h"
#include "Inicio_Sesion.h"

#include<string>
#include<string.h>
#include <fstream>
#include "Historia_Clinica.h"

using namespace std;

int main()
{
    Inicio_Sesion objIS;
    Paciente ObjPac;
    Especialista ObjEsp;
    Enfermero ObjEnf;
    Medico ObjMed;
    int opP,opH,opE,codP,canP,opc,jr=0,ocup,auxcode, is=0, v, cmed=0, vm=0, ww;
    do{
        is=objIS.Verificar_Usuario(is);
    }while(is==0);
    do{
        cout<<"\t\t\t------------------------------"<<endl;
        cout<<"\t\t\t-       MENU PRINCIPAL       -"<<endl;
        cout<<"\t\t\t------------------------------"<<endl;
        cout<<"\n\t\t1.Menu de Especialistas"<<endl;
        cout<<"\t\t2.Inicio de Sesion"<<endl;
        cout<<"\t\tElija una opcion: ";
        cin>>v;
        system("cls");
        switch (v){
            case 1:
                cout<<"\t\t\t-------------------------------------------------------"<<endl;
                cout<<"\t\t\t-                MENU DE ESPECIALISTAS                -"<<endl;
                cout<<"\t\t\t-------------------------------------------------------"<<endl;
                cout<<"\n\t\t1.Registrar Especialista"<<endl;
                cout<<"\t\t2.Listar Especialista"<<endl;
                cout<<"\t\t3.Mostrar Especialista"<<endl;
                cout<<"\t\t4.Modificar Datos del Especialista"<<endl;
                cout<<"\t\t5.Buscar Especialista"<<endl;
                cout<<"\t\t6.Medico"<<endl;
                cout<<"\t\t7.Enfermero"<<endl;
                cout<<"\t\t8.Salir"<<endl;
                cout<<"\t\tIngrese una opcion: ";
                cin>>opc;
                system("cls");
                switch( opc ){
                    case 1:
                        cout<<"\t\t\t     Registro     "<<endl;
                        cout<<"\t\t\t------------------"<<endl;
                        cout<<"\n\t\t1.Medico"<<endl;
                        cout<<"\n\t\t2.Enfermero"<<endl;
                        cout<<"\n\t\tElija una opcion: ";
                        cin>>ocup;
                        system("cls");
                        switch(ocup){
                            case 1:
                                cout<<"\n\n\t\tEscriba el codigo del especialista: ";
                                cin>>auxcode;
                                system("cls");
                                ObjEsp.Registrar_Especialista(ocup,auxcode);
                                if((ObjEsp.getValidado())==true){
                                    ObjMed.Registrar_CodMedico(auxcode);
                                }
                                system("cls");
                                break;
                            case 2:
                                cout<<"\n\n\t\tEscriba el codigo del especialista: ";
                                cin>>auxcode;
                                ObjEsp.Registrar_Especialista(ocup,auxcode);
                                if((ObjEsp.getValidado())==true){
                                    ObjEnf.Registrar_CodEnfermero(auxcode);
                                }
                                system("cls");
                                break;
                            default:
                                cout<<"\n\t\tDato Incorrecto"<<endl;
                                system("pause");
                                system("cls");
                                break;
                        }
                        break;
                    case 2:
                        ObjEsp.Listar_Especialista();
                        break;
                    case 3:
                        int ide;
                        cout<<"\n\n\t\tIngrese la Identificaion de Especalista: ";
                        cin>>ide;
                        ObjEsp.Mostrar_Especialista(ide);
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        do{
                            cout<<endl;
                            cout<<"\t\t\t----------------------------"<<endl;
                            cout<<"\t\t\t-      MENU DE MEDICOS     -"<<endl;
                            cout<<"\t\t\t----------------------------"<<endl;
                            cout<<"\n\t\t1.Listar\n\t\t2.Buscar\n\t\t3.Modificar\n\t\t4.Pacientes\n\t\t5.Salir"<<endl;
                            cout<<"\n\t\tIngrese una opcion: ";
                            cin>>opE;
                            switch(opE){
                                case 1:
                                    ObjMed.Listar_Medico();
                                    break;
                                case 2:
                                    ObjMed.Buscar_Medico();
                                    break;
                                case 3:
                                    ObjMed.Modificar_Medico();
                                    break;
                                case 4:
                                    do{
                                        cout<<"\t\t\t-----------------------------------"<<endl;
                                        cout<<"\t\t\t-        MENU DE PACIENTES        -"<<endl;
                                        cout<<"\t\t\t-----------------------------------"<<endl;
                                        cout<<"\n\t\t1.Listar\n\t\t2.Buscar\n\t\t3.Modificar\n\t\t4.Eliminar\n\t\t5.Historia Clinica\n\t\t6.Salir"<<endl;
                                        cout<<"\n\t\tIngrese una opcion: ";
                                        cin>>opP;
                                        system("cls");
                                        switch(opP+1){
                                            case 1:
                                                break;
                                            case 2:
                                                ObjPac.Listar_Paciente();
                                                system("PAUSE");
                                                break;
                                            case 3:
                                                cout<<"Ingrese el codigo del paciente que desea mostrar...";
                                                cin>>codP;
                                                ObjPac.Encontrar_Paciente(codP);
                                                system("PAUSE");
                                                break;
                                            case 4:
                                                ObjPac.Modificar_Paciente();
                                                system("PAUSE");
                                                break;
                                            case 5:
                                                ObjPac.Eliminar_Paciente();
                                                system("PAUSE");
                                                break;
                                            case 6:
                                                do{
                                                    cout<<"\t\t\t------------------------------------"<<endl;
                                                    cout<<"\t\t\t-    MENU DE HISTORIAS CLINICAS    -"<<endl;
                                                    cout<<"\t\t\t------------------------------------"<<endl;
                                                    cout<<"\n\t\t1.Listar Historias\n\t\t2.Buscar Historia\n\t\t3.Modificar Historia\n\t\t4.Salir"<<endl;
                                                    cout<<"\n\t\tIngrese una opcion: ";
                                                    cin>>opH;
                                                    ObjPac.Historia_Clin(opH+1);
                                                    system("cls");
                                                }while(opH!=6);
                                                break;
                                            case 7:
                                                cout<<"Ha salido del programa...";
                                                system("pause");
                                                system("cls");
                                                break;
                                            default:
                                                break;
                                        }
                                    }while(opP!=7);
                                    break;
                                    system("cls");
                                }
                            }while(opE!=5);
                            system("cls");
                        break;
                    case 7:
                        do{
                            cout<<endl;
                            cout<<"\t\t\t---------------------------"<<endl;
                            cout<<"\t\t\t-    MENU DE ENFERMEROS   -"<<endl;
                            cout<<"\t\t\t---------------------------"<<endl;
                            cout<<"\n\t\t1.Listar\n\t\t2.Buscar\n\t\t3.Modificar\n\t\t4.Pacientes\n\t\t5.Salir"<<endl;
                            cout<<"\n\t\tIngrese una opcion: ";
                            cin>>opE;
                            system("cls");
                            switch(opE){
                                case 1:
                                    ObjEnf.Listar_Enfermero();
                                    break;
                                case 2:
                                    ObjEnf.Buscar_Enfermero();
                                    break;
                                case 3:
                                    ObjEnf.Modificar_Enfermero();
                                    break;
                                case 4:
                                    break;
                            }
                        }while(opE!=5);
                        break;
                    case 8:
                        jr=1;
                        break;
                    default:
                        cout<<"DATO ERRONEO";
                        system("pause");
                        system("cls");
                }
                system("cls");
                break;
            case 2:

                do{
                    int im=0;
                    cout<<"\t\t\t------------------------------------------------"<<endl;
                    cout<<"\t\t\t-           Menu de Inicio de Sesion           -"<<endl;
                    cout<<"\t\t\t------------------------------------------------"<<endl;
                    cout<<"\n\t\t1.Inicio de Sesion Medico"<<endl;
                    cout<<"\t\t2.Inicio de Sesion Enfermero/a"<<endl;
                    cout<<"\t\t3.Volver al Menu Principal"<<endl;
                    cout<<"\t\tElija una opcion: ";
                    cin>>ww;
                    system("cls");
                    switch(ww){
                        case 1:
                            do{
                                im=objIS.LogearMedico(im, ww);
                            }while(im==0);
                            cout<<endl;
                            system("cls");
                            do{
                            cout<<endl;
                            cout<<"\t\t\t----------------------------"<<endl;
                            cout<<"\t\t\t-      MENU DE MEDICOS     -"<<endl;
                            cout<<"\t\t\t----------------------------"<<endl;
                            cout<<"\n\t\t1.Listar\n\t\t2.Buscar\n\t\t3.Modificar\n\t\t4.Pacientes\n\t\t5.Salir"<<endl;
                            cout<<"\n\t\tIngrese una opcion: ";
                            cin>>opE;
                            switch(opE){
                                case 1:
                                    ObjMed.Listar_Medico();
                                    break;
                                case 2:
                                    ObjMed.Buscar_Medico();
                                    break;
                                case 3:
                                    ObjMed.Modificar_Medico();
                                    break;
                                case 4:
                                    do{
                                        cout<<"\t\t\t-----------------------------------"<<endl;
                                        cout<<"\t\t\t-        MENU DE PACIENTES        -"<<endl;
                                        cout<<"\t\t\t-----------------------------------"<<endl;
                                        cout<<"\n\t\t1.Listar\n\t\t2.Buscar\n\t\t3.Modificar\n\t\t4.Eliminar\n\t\t5.Historia Clinica\n\t\t6.Salir"<<endl;
                                        cout<<"\n\t\tIngrese una opcion: ";
                                        cin>>opP;
                                        system("cls");
                                        switch(opP+1){
                                            case 1:
                                                break;
                                            case 2:
                                                ObjPac.Listar_Paciente();
                                                system("PAUSE");
                                                break;
                                            case 3:
                                                cout<<"Ingrese el codigo del paciente que desea mostrar...";
                                                cin>>codP;
                                                ObjPac.Encontrar_Paciente(codP);
                                                system("PAUSE");
                                                break;
                                            case 4:
                                                ObjPac.Modificar_Paciente();
                                                system("PAUSE");
                                                break;
                                            case 5:
                                                ObjPac.Eliminar_Paciente();
                                                system("PAUSE");
                                                break;
                                            case 6:
                                                do{
                                                    cout<<"\t\t\t------------------------------------"<<endl;
                                                    cout<<"\t\t\t-    MENU DE HISTORIAS CLINICAS    -"<<endl;
                                                    cout<<"\t\t\t------------------------------------"<<endl;
                                                    cout<<"\n\t\t1.Listar Historias\n\t\t2.Buscar Historia\n\t\t3.Modificar Historia\n\t\t4.Salir"<<endl;
                                                    cout<<"\n\t\tIngresa una opcion: ";
                                                    cin>>opH;
                                                    system("cls");
                                                    ObjPac.Historia_Clin(opH+1);
                                                    system("cls");
                                                }while(opH!=6);
                                                break;
                                            case 7:
                                                cout<<"Ha salido del programa...";
                                                system("pause");
                                                system("cls");
                                                break;
                                            default:
                                                break;
                                        }
                                    }while(opP!=7);
                                    break;
                                    system("cls");
                                }
                            }while(opE!=5);
                            system("cls");
                            break;
                        case 2:
                            do{
                                im=objIS.LogearMedico(im, ww);
                            }while(im==0);
                            cout<<endl;
                            system("cls");
                            do{
                                cout<<"\t\t\t--------------------------"<<endl;
                                cout<<"\t\t\t-   MENU DE PACIENTES    -"<<endl;
                                cout<<"\t\t\t--------------------------"<<endl;
                                cout<<"\n\t\t1.Registrar\n\t\t2.Listar\n\t\t3.Buscar\n\t\t4.Modificar\n\t\t5.Eliminar\n\t\t6.Historia Clinica\n\t\t7.Salir"<<endl;
                                cout<<"\n\t\tIngrese una opcion: ";
                                cin>>opP;
                                system("cls");
                                switch(opP){
                                    case 1:
                                        ObjPac.Registrar_Paciente();
                                        system("PAUSE");
                                        break;
                                    case 2:
                                        ObjPac.Listar_Paciente();
                                        system("PAUSE");
                                        break;
                                    case 3:
                                        cout<<"Ingrese el codigo del paciente que desea mostrar...";
                                        cin>>codP;
                                        ObjPac.Encontrar_Paciente(codP);
                                        system("PAUSE");
                                        break;
                                    case 4:
                                        ObjPac.Modificar_Paciente();
                                        system("PAUSE");
                                        break;
                                    case 5:
                                        ObjPac.Eliminar_Paciente();
                                        system("PAUSE");
                                        break;
                                    case 6:
                                        do{
                                            cout<<"\t\t\t------------------------------------"<<endl;
                                            cout<<"\t\t\t-    MENU DE HISTORIAS CLINICAS    -"<<endl;
                                            cout<<"\t\t\t------------------------------------"<<endl;
                                            cout<<"\n\t\t1.Registrar Historia\n\t\t2.Listar Historias\n\t\t3.Buscar Historia\n\t\t4.Modificar Historia\n\t\t6.Salir"<<endl;
                                            cout<<"\n\t\tIngrese una opcion: ";
                                            cin>>opH;
                                            ObjPac.Historia_Clin(opH);
                                            system("cls");
                                        }while(opH!=6);
                                        break;
                                    case 7:
                                        cout<<"\n\t\tHa salido del programa...";
                                        system("cls");
                                        break;
                                    default:
                                        break;
                                    }
                                }while(opP!=7);
                                break;
                        case 3:
                            vm=1;
                            break;
                        default:
                                cout<<"\n\t\tDato Incorrecto"<<endl;
                                system("pause");
                                system("cls");
                                break;
                    }
                    system("cls");
                }while(vm==0);
                break;
            default:
                cout<<"\n\t\tDATO INCORRECTO";
                break;
        }
    }while(jr==0);
    return 0;
}
