#include "Enfermero.h"
#include <fstream>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
Enfermero::Enfermero():Especialista()
{

}

void Enfermero::Registrar_CodEnfermero(int idesp){
    char aux;
    bool repetido=false;
    int c=0;
    int codguardado=0;
    int codespe;
    ifstream consulta;
    ofstream entrada;
    consulta.open("enfermeros.txt",ios::in);
    entrada.open("enfermeros.txt",ios::app);
     if(entrada.fail()&&consulta.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }

    else{
        cout<<"\nIngrese el codigo del enfermero: ";
        cin>>codguardado;
    FILE *rv;
    rv = fopen( "enfermeros.txt", "r" );
    fseek( rv, 0, SEEK_END );
    if (ftell( rv ) == 0 )
    {
        cout<<"Archivo vacio"<<endl;
    }
    else{
        consulta>>cod_Enf;
        while(!consulta.eof()){
                consulta>>cod_Esp>>area;
            if((cod_Enf==codguardado)){
                if(cod_Enf==codguardado){
                cout<<"Ya existe un enfermero con ese codigo...";
                }
                repetido=true;
                break;
            }
            consulta>>cod_Enf;

            }
    }


        if(repetido==false){
                fflush(stdin);
                cod_Esp=idesp;
                cod_Enf=codguardado;
                cout<<"Ingrese el area de trabajo: ";
                getline(cin,area);
                entrada<<cod_Enf<<" "<<cod_Esp<<" "<<area<<endl;
                cout<<"Se ha registrado la ID del enfermero...";
                cant++;
            }


        }
        entrada.close();
        consulta.close();
}
void Enfermero::Buscar_Enfermero(){
ifstream encontrar;
int cod;
    encontrar.open("enfermeros.txt",ios::in);
    cout<<"Digite el codigo del enfermero: ";
    cin>>cod;
    if(encontrar.is_open()){
        encontrar>>cod_Enf;
        while(!encontrar.eof()){
            encontrar>>cod_Esp>>area;
            if(cod_Enf==cod){
                cout<<"Registro encontrado..."<<endl<<endl;
                cout<<"Codigo de enfermero: "<<cod_Enf<<endl;
                cout<<"Codigo de especialista: "<<cod_Esp<<endl;
                cout<<"Area: "<<area<<endl;
            }
            encontrar>>cod_Enf;
    }
    }
    else{
        cout<<"No se ha encontrado el archivo...";
    }
     encontrar.close();
}

void Enfermero::Modificar_Enfermero(){
    ofstream auxiliar;
	ifstream lectura;
    char aux;
    bool encontrado=false;
    int auxcode,op;
    string auxarea;
    int opE;
    auxiliar.open("auxiliar.txt",ios::out);
	lectura.open("enfermeros.txt",ios::in);
    if(auxiliar.is_open() && lectura.is_open()){
        cout<<"Ingrese el codigo del enfermero a modificar: "<<endl;
		cin>>auxcode;
        lectura>>cod_Enf;
        while(!lectura.eof()){
        lectura>>cod_Esp>>area;
            if(auxcode==cod_Enf){
            encontrado=true;
                cout<<"1.Area\n2.Salir"<<endl<<endl;
                cin>>op;
                  switch(op){
                      case 1:
                      fflush(stdin);
                      cout<<"Nueva area: ";
                      getline(cin,auxarea);
                      auxiliar<<cod_Enf<<" "<<cod_Esp<<" "<<auxarea<<endl;
                      break;
                      case 2:
                        cout<<"Se reincorporará al menu de pacientes...";
                      break;
                      default:
                       cout<<"Opcion incorrecta...";
                      break;

                  }

            }
            else{
                      auxiliar<<cod_Enf<<" "<<cod_Esp<<" "<<area<<endl;

            }
                    lectura>>cod_Enf;


        }

    }
    else{
        cout<<"Archivo no encontrado";
    }
    if(encontrado==false){
        cout<<"No se ha encontrado un registro con ese codigo..."<<endl;
    }
    auxiliar.close();
    lectura.close();
    remove("enfermeros.txt");
    rename("auxiliar.txt","enfermeros.txt");
}

void Enfermero::Listar_Enfermero(){
   FILE *rv;
    rv = fopen( "enfermeros.txt", "r" );
    fseek( rv, 0, SEEK_END );
    if (ftell( rv ) == 0 )
    {
        cout<<"Archivo vacio"<<endl;
    }
    else{
    ifstream listarE;
    int A[100],i=0,cant,pos,aux;
    int B[100];
    listarE.open("enfermeros.txt",ios::in);
    if(listarE.is_open()){
        listarE>>cod_Enf;
        while(!listarE.eof()){
            listarE>>cod_Esp>>area;
            A[i]=cod_Enf;
            listarE>>cod_Enf;
            i++;
            }
    }
    else{
        cout<<"No se ha encontrado el archivo...";
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
    listarE.open("enfermeros.txt",ios::in);
    if(listarE.is_open()){
        listarE>>cod_Enf;
         while(!listarE.eof()){
            listarE>>cod_Esp>>area;
            if(cod_Enf==A[i]){
                cout<<"Codigo de enfermero: "<<cod_Enf<<endl;
                cout<<"Codigo de especialista: "<<cod_Esp<<endl;
                cout<<"Area: "<<area<<endl;
                }
                        listarE>>cod_Enf;

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
