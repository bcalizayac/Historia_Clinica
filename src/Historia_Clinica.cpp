#include "Historia_Clinica.h"
#include <fstream>
#include "Paciente.h"
#include<string>
#include<string.h>
#include<iostream>

Historia_Clinica::Historia_Clinica()
{

}
int Historia_Clinica::getcodPac(){
    return codPac;
}
void Historia_Clinica::setcodPac(int cod){
    codPac=cod;
}


void Historia_Clinica::Registrar_Historia(){
    char aux;
    bool repetido=false;
    int codguardado,codpacg=codPac;
    ifstream consulta;
    int opE=0;
    ofstream entrada;
    consulta.open("historias.txt",ios::in);
    entrada.open("historias.txt",ios::app);
     if(entrada.fail()&&consulta.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }

    else{
        cout<<"Codigo de la historia: ";
        cin>>codguardado;
        FILE *rv;
        rv = fopen( "historias.txt", "r" );
        fseek( rv, 0, SEEK_END );
        if (ftell( rv ) == 0 )
        {
            cout<<"Archivo vacio"<<endl;
        }
        else{
        consulta>>N_Hist;
        while(!consulta.eof()){
            consulta>>codPac>>Estado>>fecha;
            if((codguardado==N_Hist)||(codpacg==codPac)){
                if(codpacg==codPac){
                cout<<"Ya existe una historia clinica con ese paciente...";
                }
                if(codguardado==N_Hist){
                cout<<"Ya existe una historia clinica con ese codigo..."<<endl;

                }
                repetido=true;
                break;
            }
            consulta>>N_Hist;
            }
        }
        if(repetido==false){
        fflush(stdin);
        N_Hist=codguardado;
        codpacg=codPac;
        cout<<"Ingrese el estado del paciente: ";
        cout<<"\n1.Bien\n2Moderado\n3.Grave\n4.Critico"<<endl;
        cout<< "Opcion: ";
        cin>>opE;
        switch(opE){
                case 1:
                    Estado="Bien";

                    break;
                case 2:
                    Estado="Moderado";

                    break;
                case 3:
                    Estado="Grave";

                    break;
                case 4:
                    Estado="Critico";
                    break;


                    }
        fflush(stdin);
        cout<<"Ingrese la fecha de creación: ";
        getline(cin,fecha);
        cout<<"Historia clinica registrada..."<<endl<<endl;

        entrada<<N_Hist<<" "<<codPac<<" "<<Estado<<" "<<fecha<<endl;
            }


        }
        consulta.close();
        entrada.close();

}
void Historia_Clinica::Listar_Historia(){
    int A[100],i=0,cant,pos,aux;
    int B[100];
    FILE *rv;
    rv = fopen( "historias.txt", "r" );
    fseek( rv, 0, SEEK_END );
    if (ftell( rv ) == 0 )
    {
        cout<<"Archivo vacio"<<endl;
    }
    else{
    ifstream listarH;
    listarH.open("historias.txt",ios::in);
    if(listarH.is_open()){
        listarH>>N_Hist;
        while(!listarH.eof()){
            listarH>>codPac>>Estado>>fecha;
            A[i]=N_Hist;
            listarH>>N_Hist;
            i++;
            }
    }
    else{
        cout<<"No se ha encontrado el archivo...";
    }
        cant=i;
    listarH.close();
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
    listarH.open("historias.txt",ios::in);
    if(listarH.is_open()){
        listarH>>N_Hist;
         while(!listarH.eof()){
            listarH>>codPac>>Estado>>fecha;
            if(N_Hist==A[i]){
                cout<<"\n\nN° de historia: "<<N_Hist<<endl;
                cout<<"Codigo del paciente: "<<codPac<<endl;
                cout<<"Estado: "<<Estado<<endl;
                cout<<"Fecha de creación: "<<fecha<<endl;
                }
                        listarH>>N_Hist;

            }
    }
    else{
        cout<<"No se ha encontrado el archivo...";
    }
        i++;

     listarH.close();
     }while(i!=cant);
    }
             system("PAUSE");



}
void Historia_Clinica::Buscar_Historia(int c){
ifstream encontrar;
    encontrar.open("historias.txt",ios::in);
    if(encontrar.is_open()){
        encontrar>>N_Hist;
        while(!encontrar.eof()){
            encontrar>>codPac>>Estado>>fecha;
            if(N_Hist==c){
                cout<<"Registro encontrado..."<<endl<<endl;
                cout<<"Codigo de Historia: "<<N_Hist<<endl;
                cout<<"Codigo del paciente: "<<codPac<<endl;
                cout<<"Estado: "<<Estado<<endl;
                cout<<"Fecha: "<<fecha<<endl;
            }
            encontrar>>N_Hist;

    }
    }
    else{
        cout<<"No se ha encontrado el archivo...";
    }
     encontrar.close();
}
void Historia_Clinica::Modificar_Historia(){
    ofstream auxiliar;
	ifstream lectura;
    char aux;
    bool encontrado=false;
    int auxcodh,auxcodp,op;
    string auxfecha;
    int opE;
    string auxesta;
    auxiliar.open("auxiliar.txt",ios::out);
	lectura.open("historias.txt",ios::in);
    if(auxiliar.is_open() && lectura.is_open()){
        cout<<"Ingrese el codigo de la historia a modificar: "<<endl;
		cin>>auxcodh;
        lectura>>N_Hist;
        while(!lectura.eof()){
        lectura>>codPac>>Estado>>fecha;
            if(auxcodh==N_Hist){
            encontrado=true;
            Buscar_Historia(auxcodh);
                cout<<"\n\nElija la opción a modificar: "<<endl<<endl;
                cout<<"1.Estado\n2.Fecha"<<endl<<endl;
                cin>>op;
                switch(op){
                case 1:
                    fflush(stdin);
                    cout<<"Estado: "<<endl;
                    cout<<"1.Bien\n2Moderado\n3.Grave\n4.Critico"<<endl;
                    cout<<"Opcion: ";
                    cin>>opE;
                    switch(opE){
                         case 1:
                        auxesta="Bien";

                    break;
                case 2:
                    auxesta="Moderado";

                    break;
                case 3:
                    auxesta="Grave";

                    break;
                case 4:
                    auxesta="Critico";
                    break;
                    }



                    auxiliar<<N_Hist<<" "<<codPac<<" "<<auxesta<<" "<<fecha<<endl;
                    break;
                case 2:
                    fflush(stdin);
                    cout<<"Fecha: ";
                    getline(cin,auxfecha);
                    auxiliar<<N_Hist<<" "<<codPac<<" "<<Estado<<" "<<auxfecha<<endl;
                    break;
                case 3:
                    cout<<"Se reincorporará al menu de pacientes...";
                    break;
                default:
                    cout<<"Opcion incorrecta...";
                    break;
                }



            }
            else{
                auxiliar<<N_Hist<<" "<<codPac<<" "<<Estado<<" "<<fecha<<endl;

            }
                    lectura>>N_Hist;


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
    remove("historias.txt");
    rename("auxiliar.txt","historias.txt");
}

void Historia_Clinica::Eliminar_Paciente(int c){
    ifstream eliminar;
    ofstream entrada;
    eliminar.open(("historias.txt"),ios::in);
    entrada.open(("temporal.txt"),ios::out);
    if(eliminar.fail()){
        cout<<"Existe un error al abrir el archivo...";
    }
    else{
        eliminar>>N_Hist>>codPac;
        while(!eliminar.eof()){
            eliminar>>Estado>>fecha;
            if(codPac==c){
            cout<<"Historia Clinica Eliminada..."<<endl;
            }
            else{
            entrada<<N_Hist<<" "<<codPac<<" "<<Estado<<" "<<fecha<<endl;
             }
        eliminar>>N_Hist>>codPac;

        }

        }
    entrada.close();
    eliminar.close();
    remove("historias.txt");
    rename("temporal.txt","historias.txt");

}
