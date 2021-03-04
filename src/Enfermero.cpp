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
        cout<<"\n\t\tNo se pudo abrir el archivo"<<endl;
        system("pause");
        system("cls");
    }

    else{
        cout<<"\n\t\tIngrese el codigo del enfermero: ";
        cin>>codguardado;
    FILE *rv;
    rv = fopen( "enfermeros.txt", "r" );
    fseek( rv, 0, SEEK_END );
    if (ftell( rv ) == 0 )
    {
        cout<<"\n\t\tArchivo vacio"<<endl;
        system("pause");
        system("cls");
    }
    else{
        consulta>>cod_Enf;
        while(!consulta.eof()){
                consulta>>cod_Esp>>area;
            if((cod_Enf==codguardado)){
                if(cod_Enf==codguardado){
                    cout<<"\n\t\tYa existe un enfermero con ese codigo...";
                    system("pause");
                    system("cls");
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
                cout<<"\n\t\tIngrese el area de trabajo: ";
                getline(cin,area);
                entrada<<cod_Enf<<" "<<cod_Esp<<" "<<area<<endl;
                cout<<"\n\t\tSe ha registrado la ID del enfermero...";
                cant++;
            }


        }
        entrada.close();
        consulta.close();
        system("pause");
        system("cls");
}
void Enfermero::Buscar_Enfermero(){
ifstream encontrar;
int cod;
    encontrar.open("enfermeros.txt",ios::in);
    cout<<"\n\t\tDigite el codigo del enfermero: ";
    cin>>cod;
    system("cls");
    if(encontrar.is_open()){
        encontrar>>cod_Enf;
        while(!encontrar.eof()){
            encontrar>>cod_Esp>>area;
            if(cod_Enf==cod){
                cout<<"\t\t\t    Registro encontrado   "<<endl;
                cout<<"\t\t\t--------------------------"<<endl;
                cout<<"\n\t\tCodigo de enfermero: "<<cod_Enf<<endl;
                cout<<"\n\t\tCodigo de especialista: "<<cod_Esp<<endl;
                cout<<"\n\t\tArea: "<<area<<endl;
                system("pause");
                system("cls");
                Mostrar_Especialista(cod_Esp);
            }
            encontrar>>cod_Enf;
    }
    }
    else{
        cout<<"\n\t\tNo se ha encontrado el archivo...";
    }
        system("pause");
        system("cls");
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
        cout<<"\n\t\tIngrese el codigo del enfermero a modificar: ";
		cin>>auxcode;
        lectura>>cod_Enf;
        while(!lectura.eof()){
        lectura>>cod_Esp>>area;
            if(auxcode==cod_Enf){
            encontrado=true;
                cout<<"\n\t\t1.Area\n\t\t2.Salir"<<endl;
                cout<<"\n\t\tIngrese una opcion: ";
                cin>>op;
                system("cls");
                  switch(op){
                      case 1:
                      fflush(stdin);
                      cout<<"\n\t\tNueva area: ";
                      getline(cin,auxarea);
                      auxiliar<<cod_Enf<<" "<<cod_Esp<<" "<<auxarea<<endl;
                      break;
                      case 2:
                        cout<<"\n\t\tSe reincorporará al menu de pacientes...";
                        system("pause");
                        system("cls");
                      break;
                      default:
                        cout<<"\n\t\tOpcion incorrecta...";
                        system("pause");
                        system("cls");
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
        cout<<"\n\t\tArchivo no encontrado";
        system("pause");
        system("cls");
    }
    if(encontrado==false){
        cout<<"\n\t\tNo se ha encontrado un registro con ese codigo..."<<endl;
        system("pause");
        system("cls");
    }
    auxiliar.close();
    lectura.close();
    remove("enfermeros.txt");
    rename("auxiliar.txt","enfermeros.txt");
    system("cls");
}

void Enfermero::Listar_Enfermero(){
   FILE *rv;
    rv = fopen( "enfermeros.txt", "r" );
    fseek( rv, 0, SEEK_END );
    if (ftell( rv ) == 0 )
    {
        cout<<"\n\t\tArchivo vacio"<<endl;
        system("pause");
        system("cls");
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
        cout<<"\n\t\tNo se ha encontrado el archivo...";
        system("pause");
        system("cls");
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
                cout<<"\n\t\tCodigo de enfermero: "<<cod_Enf<<endl;
                cout<<"\n\t\tCodigo de especialista: "<<cod_Esp<<endl;
                cout<<"\n\t\tArea: "<<area<<endl;
                }
                        listarE>>cod_Enf;

            }
    }
    else{
        cout<<"\n\t\tNo se ha encontrado el archivo...";
        system("pause");
        system("cls");
    }
        i++;

     listarE.close();
     }while(i!=cant);
    }
            system("PAUSE");
            system("cls");


}
