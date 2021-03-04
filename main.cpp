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
    int opP,opH,opE,codP,canP,opc,jr=0,ocup,auxcode, is=0, im=0, v, cmed=0, vm=0, ww;
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
                cout<<"\t-------------------------------------------------------"<<endl;
                cout<<"\t-                MENU DE ESPECIALISTAS                -"<<endl;
                cout<<"\t-------------------------------------------------------"<<endl;
                cout<<"\t1.Registrar Especialista"<<endl;
                cout<<"\t2.Listar Especialista"<<endl;
                cout<<"\t3.Mostrar Especialista"<<endl;
                cout<<"\t4.Modificar Datos del Especialista"<<endl;
                cout<<"\t5.Buscar Especialista"<<endl;
                cout<<"\t6.Medico"<<endl;
                cout<<"\t7.Enfermero"<<endl;
                cout<<"\t8.Salir"<<endl;
                cout<<"\tIngrese una opcion: ";
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
                                ObjEsp.Registrar_Especialista(ocup,auxcode, cmed);
                                if((ObjEsp.getValidado())==true){
                                    ObjMed.Registrar_CodMedico(auxcode);
                                }

                                break;
                            case 2:
                                cout<<"Escriba el codigo del especialista: ";
                                cin>>auxcode;
                                ObjEsp.Registrar_Especialista(ocup,auxcode,cmed);
                                if((ObjEsp.getValidado())==true){
                                    ObjEnf.Registrar_CodEnfermero(auxcode);
                                }
                                break;
                            default:
                                break;
                        }
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
                        break;
                    case 7:
                        do{
                            cout<<"MENU DE ENFERMEROS"<<endl<<endl;
                            cout<<"\n1.Listar\n2.Buscar\n3.Modificar\n4.Pacientes\n5.Salir"<<endl;
                            cin>>opE;
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
                                    do{
                                        cout<<"MENÚ DE PACIENTES"<<endl<<endl;
                                        cout<<"1.Registrar\n2.Listar\n3.Buscar\n4.Modificar\n5.Eliminar\n6.Historia Clinica\n7.Salir"<<endl;
                                        cin>>opP;
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
                                                    cout<<"MENU DE HISTORIAS CLINICAS"<<endl<<endl;
                                                    cout<<"1.Registrar Historia\n2.Listar Historias\n3.Buscar Historia\n4.Modificar Historia\n6.Salir"<<endl;
                                                    cin>>opH;
                                                    ObjPac.Historia_Clin(opH);
                                                }while(opH!=6);
                                                break;
                                            case 7:
                                                cout<<"Ha salido del programa...";
                                                break;
                                            default:
                                                break;
                                        }
                                    }while(opP!=7);
                                    break;
                            }
                        }while(opE!=5);
                        break;
                    case 8:
                        jr=1;
                        break;
                    default:
                        cout<<"DATO ERRONEO";
                }
                system("cls");
                break;
            case 2:

                do{
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
                            do{
                            cout<<"MENU DE MEDICOS"<<endl<<endl;
                            cout<<"\n1.Listar\n2.Buscar\n3.Modificar\n4.Pacientes\n5.Salir"<<endl;
                            cin>>opE;
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
                                    do{
                                        cout<<"MENÚ DE PACIENTES"<<endl<<endl;
                                        cout<<"1.Listar\n2.Buscar\n3.Modificar\n4.Eliminar\n5.Historia Clinica\n6.Salir"<<endl;
                                        cin>>opP;
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
                                                    cout<<"MENU DE HISTORIAS CLINICAS"<<endl<<endl;
                                                    cout<<"\n1.Listar Historias\n2.Buscar Historia\n3.Modificar Historia\n4.Salir"<<endl;
                                                    cin>>opH;
                                                    ObjPac.Historia_Clin(opH+1);
                                                }while(opH!=6);
                                                break;
                                            case 7:
                                                cout<<"Ha salido del programa...";
                                                break;
                                            default:
                                                break;
                                        }
                                    }while(opP!=7);
                                    break;
                                }
                            }while(opE!=5);
                            break;
                        case 2:
                            do{
                                im=objIS.LogearMedico(im, ww);
                            }while(im==0);
                            break;
                        default:
                            cout<<"Dato Incorrecto"<<endl;
                            break;
                    }
                }while(vm==0);
                break;
            default:
                cout<<"\n\t\tDATO INCORRECTO";
                break;
        }
    }while(jr==0);
    return 0;
}
