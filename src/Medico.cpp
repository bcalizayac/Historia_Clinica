#include "Medico.h"
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;
Medico::Medico():Especialista()
{

}

void Medico::Registrar_CodMedico(int idesp){
    char aux;
    bool repetido=false;
    int c=0;
    int codguardado=0;
    int codespe;
    ifstream consulta;
    ofstream entrada;
    consulta.open("medicos.txt",ios::in);
    entrada.open("medicos.txt",ios::app);
    if(entrada.fail()&&consulta.fail()){
        cout<<"\n\n\t\tNo se pudo abrir el archivo"<<endl;
    }
    else{
        cout<<"\n\t\tIngrese el codigo del medico: ";
        cin>>codguardado;
        FILE *rv;
        rv = fopen( "medicos.txt", "r" );
        fseek( rv, 0, SEEK_END );
        if (ftell( rv ) == 0 )
        {
            cout<<"\n\n\t\tArchivo vacio"<<endl;
        }
        else{
            consulta>>cod_Med;
            while(!consulta.eof()){
                consulta>>cod_Esp>>area;
                if((cod_Med==codguardado)){
                    if(cod_Med==codguardado){
                        cout<<"\n\t\tYa existe un medico con ese codigo...";
                    }
                    repetido=true;
                    break;
                }
                consulta>>cod_Med;
            }
        }
        if(repetido==false){
                fflush(stdin);
                cod_Esp=idesp;
                cod_Med=codguardado;
                cout<<"\n\t\tIngrese el area de trabajo: ";
                getline(cin,area);
                entrada<<cod_Med<<" "<<cod_Esp<<" "<<area<<endl;
                cout<<"\n\t\tSe ha registrado la ID del medico...";
                system("pause");
                cant++;
        }
    }
    entrada.close();
    consulta.close();
    system("cls");
}
void Medico::Buscar_Medico(){
    ifstream encontrar;
    int cod;
    encontrar.open("Medicos.txt",ios::in);
    cout<<"\n\t\tDigite el codigo del Medico: ";
    cin>>cod;
    system("cls");
    if(encontrar.is_open()){
        encontrar>>cod_Med;
        while(!encontrar.eof()){
            encontrar>>cod_Esp>>area;
            if(cod_Med==cod){
                cout<<"\n\t\t\tRegistro encontrado"<<endl;
                cout<<"\t\t\t--------------------"<<endl<<endl;
                cout<<"\t\tCodigo de medico: "<<cod_Med<<endl;
                cout<<"\t\tCodigo de especialista: "<<cod_Esp<<endl;
                cout<<"\t\tArea: "<<area<<endl;
            }
            encontrar>>cod_Med;
        }
    }
    else{
        cout<<"\n\n\t\tNo se ha encontrado el archivo...";
    }
    encontrar.close();
    system("cls");
}

void Medico::Modificar_Medico(){
    ofstream auxiliar;
	ifstream lectura;
    char aux;
    bool encontrado=false;
    int auxcode,op;
    string auxarea;
    int opE;
    auxiliar.open("auxiliar.txt",ios::out);
	lectura.open("medicos.txt",ios::in);
    if(auxiliar.is_open() && lectura.is_open()){
        cout<<"\t\tIngrese el codigo del medico a modificar: ";
		cin>>auxcode;
        lectura>>cod_Med;
        while(!lectura.eof()){
            lectura>>cod_Esp>>area;
            if(auxcode==cod_Med){
                encontrado=true;
                cout<<"\n\n\t\t1.Area\t\t2.Salir";
                cout<<"\n\t\tIngrese una opcion: ";
                cin>>op;
                system("cls")
                switch(op){
                    case 1:
                        fflush(stdin);
                        cout<<"\n\t\tNueva area: ";
                        getline(cin,auxarea);
                        auxiliar<<cod_Med<<" "<<cod_Esp<<" "<<auxarea<<endl;
                        break;
                    case 2:
                        cout<<"\n\n\t\tSe reincorporará al menu de pacientes..."<<endl;
                        system("pause");
                        break;
                    default:
                        cout<<"\n\n\t\tOpcion incorrecta..."<<endl;
                        system("pause");
                        break;
                }
            }
            else{
                auxiliar<<cod_Med<<" "<<cod_Esp<<" "<<area<<endl;
            }
            lectura>>cod_Med;
        }
    }
    else{
        cout<<"\n\t\tArchivo no encontrado";
    }
    if(encontrado==false){
        cout<<"\n\t\tNo se ha encontrado un registro con ese codigo..."<<endl;
    }
    auxiliar.close();
    lectura.close();
    remove("medicos.txt");
    rename("auxiliar.txt","medicos.txt");
    system("cls");
}

void Medico::Listar_Medico(){
    FILE *rv;
    rv = fopen( "medicos.txt", "r" );
    fseek( rv, 0, SEEK_END );
    if (ftell( rv ) == 0 )
    {
        cout<<"\n\n\t\tArchivo vacio"<<endl;
    }
    else{
        ifstream listarE;
        int A[100],i=0,cant,pos,aux;
        int B[100];
        listarE.open("medicos.txt",ios::in);
        if(listarE.is_open()){
            listarE>>cod_Med;
            while(!listarE.eof()){
                listarE>>cod_Esp>>area;
                A[i]=cod_Med;
                listarE>>cod_Med;
                i++;
            }
        }
        else{
            cout<<"\n\n\t\tNo se ha encontrado el archivo..."<<endl;
            system("pause");
        }
        cant=i;
        listarE.close();
        //insercion
        for(int i=0;i<cant;i++){
            pos=i;
            aux=A[i];
            while((pos>0)&&(A[pos-1]>aux)){
                A[pos]=A[pos-1];
                pos--;
            }
            A[pos]=aux;
        }
        i=0;
        do{
            listarE.open("medicos.txt",ios::in);
            if(listarE.is_open()){
                listarE>>cod_Med;
                while(!listarE.eof()){
                    listarE>>cod_Esp>>area;
                    if(cod_Med==A[i]){
                        cout<<"\n\t\tCodigo de medico: "<<cod_Med<<endl;
                        cout<<"\t\tCodigo de especialista: "<<cod_Esp<<endl;
                        cout<<"\t\tArea: "<<area<<endl;
                    }
                    listarE>>cod_Med;
                }
            }
            else{
                cout<<"No se ha encontrado el archivo...";
            }
            i++;
            listarE.close();
        }while(i!=cant);
    }
    system("PAUSE");
}

