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
        cout<<"\n\t\tNo se pudo abrir el archivo"<<endl;
        system("PAUSE");
        system("cls");
    }

    else{
        cout<<"\n\t\tCodigo de la historia: ";
        cin>>codguardado;
        FILE *rv;
        rv = fopen( "historias.txt", "r" );
        fseek( rv, 0, SEEK_END );
        if (ftell( rv ) == 0 )
        {
            cout<<"\n\t\tArchivo vacio"<<endl;
            system("PAUSE");
            system("cls");
        }
        else{
        consulta>>N_Hist;
        while(!consulta.eof()){
            consulta>>codPac>>Estado>>fecha;
            if((codguardado==N_Hist)||(codpacg==codPac)){
                if(codpacg==codPac){
                cout<<"\n\t\tYa existe una historia clinica con ese paciente...";
                system("PAUSE");
                system("cls");
                }
                if(codguardado==N_Hist){
                cout<<"\n\t\tYa existe una historia clinica con ese codigo..."<<endl;
                system("PAUSE");
                system("cls");
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
        cout<<"\n\t\tIngrese el estado del paciente: ";
        cout<<"\n\t\t1.Bien\n\t\t2Moderado\n\t\t3.Grave\n\t\t4.Critico"<<endl;
        cout<<"\n\t\tOpcion: ";
        cin>>opE;
        system("cls");
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
        cout<<"\n\t\tIngrese la fecha de creación: ";
        getline(cin,fecha);
        cout<<"\n\t\tHistoria clinica registrada..."<<endl<<endl;

        entrada<<N_Hist<<" "<<codPac<<" "<<Estado<<" "<<fecha<<endl;
            }


        }
        consulta.close();
        entrada.close();
        system("cls");

}
void Historia_Clinica::Listar_Historia(){
    int A[100],i=0,cant,pos,aux;
    int B[100];
    FILE *rv;
    rv = fopen( "historias.txt", "r" );
    fseek( rv, 0, SEEK_END );
    if (ftell( rv ) == 0 )
    {
        cout<<"\n\t\tArchivo vacio"<<endl;
        system("PAUSE");
        system("cls");
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
        cout<<"\n\t\tNo se ha encontrado el archivo...";
        system("PAUSE");
        system("cls");
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
                cout<<"\n\n\t\tN° de historia: "<<N_Hist<<endl;
                cout<<"\t\tCodigo del paciente: "<<codPac<<endl;
                cout<<"\t\tEstado: "<<Estado<<endl;
                cout<<"\t\tFecha de creación: "<<fecha<<endl;
                }
                        listarH>>N_Hist;

            }
    }
    else{
        cout<<"\n\t\tNo se ha encontrado el archivo...";
        system("PAUSE");
        system("cls");
    }
        i++;

     listarH.close();
     }while(i!=cant);
    }
             system("PAUSE");
             system("cls");

}
void Historia_Clinica::Buscar_Historia(int c){
ifstream encontrar;
    encontrar.open("historias.txt",ios::in);
    if(encontrar.is_open()){
        encontrar>>N_Hist;
        while(!encontrar.eof()){
            encontrar>>codPac>>Estado>>fecha;
            if(N_Hist==c){
                cout<<endl;
                cout<<"\t\t\t     Registro encontrado    "<<endl<<endl;
                cout<<"\t\t\t----------------------------"<<endl;
                cout<<"\n\t\tCodigo de Historia: "<<N_Hist<<endl;
                cout<<"\t\tCodigo del paciente: "<<codPac<<endl;
                cout<<"\t\tEstado: "<<Estado<<endl;
                cout<<"\t\tFecha: "<<fecha<<endl;
            }
            encontrar>>N_Hist;

    }
    }
    else{
        cout<<"\n\t\tNo se ha encontrado el archivo...";
        system("cls");
        system("pause");
    }
     encontrar.close();
     system("cls");
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
        cout<<"\n\t\tIngrese el codigo de la historia a modificar: "<<endl;
		cin>>auxcodh;
		system("cls");
        lectura>>N_Hist;
        while(!lectura.eof()){
        lectura>>codPac>>Estado>>fecha;
            if(auxcodh==N_Hist){
                encontrado=true;
                Buscar_Historia(auxcodh);
                cout<<endl;
                cout<<"\n\t\t\t   MODIFICAR HISTORIA  "<<endl<<endl;
                cout<<"\n\t\t\t-----------------------"<<endl;
                cout<<"\n\t\t1.Estado\n\t\t2.Fecha"<<endl;
                cout<<"\n\t\tElija la opción a modificar: ";
                cin>>op;
                system("cls");
                switch(op){
                case 1:
                    fflush(stdin);
                    cout<<"\n\t\tEstado: "<<endl;
                    cout<<"\n\t\t1.Bien\n\t\t2Moderado\n\t\t3.Grave\n\t\t4.Critico"<<endl;
                    cout<<"\n\t\tOpcion: ";
                    cin>>opE;
                    system("cls");
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
                    cout<<"\n\t\tFecha: ";
                    getline(cin,auxfecha);
                    auxiliar<<N_Hist<<" "<<codPac<<" "<<Estado<<" "<<auxfecha<<endl;
                    break;
                case 3:
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
                auxiliar<<N_Hist<<" "<<codPac<<" "<<Estado<<" "<<fecha<<endl;

            }
                    lectura>>N_Hist;


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
    remove("historias.txt");
    rename("auxiliar.txt","historias.txt");
    system("cls");
}

void Historia_Clinica::Eliminar_Paciente(int c){
    ifstream eliminar;
    ofstream entrada;
    eliminar.open(("historias.txt"),ios::in);
    entrada.open(("temporal.txt"),ios::out);
    if(eliminar.fail()){
        cout<<"\n\t\tExiste un error al abrir el archivo...";
        system("pause");
        system("cls");
    }
    else{
        eliminar>>N_Hist>>codPac;
        while(!eliminar.eof()){
            eliminar>>Estado>>fecha;
            if(codPac==c){
                cout<<"\n\t\tHistoria Clinica Eliminada..."<<endl;
                system("pause");
                system("cls");
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
    system("cls");
}
