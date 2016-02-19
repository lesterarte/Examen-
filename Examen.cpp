#include<iostream>
#include<cmath>
#include<iomanip>
using std::cout; 
using std::cin; 
using std::endl; 
using std::abs; 
using std::setw; 

void crearmatriz(char**,int); 
void llenar(char**,int);
void iniciarmatriz(char**,int); 
void eliminarmatriz(char**,int); 
void asigned(char**); 
int contarnumeral(char**,int);
int contarmas(char**,int); 
void imprimirmatriz(char**, int);
void validar(char**, int);   

//---------------------------inicio main--------------------

int main(int argc, char*argv[]){

	char** matriz; 
	int tamanio = 7;
	int op=0; 
	matriz=new char* [tamanio];
	crearmatriz(matriz,tamanio);
	iniciarmatriz(matriz,tamanio);  
	asigned(matriz);


	cout<<"--------------------Bienvenidos--------------"<<endl;
	//while(contarnumeral(matriz,tamanio) ==0 || contarmas(matriz,tamanio)==0){

		imprimirmatriz(matriz,tamanio);
		cout<<"JUGADOR 1 - MUEVE #"<<endl;

		
	//}
					
	eliminarmatriz(matriz,tamanio); 
	return 0; 
	
}



//----------------------------------funciones-----------------------------

void crearmatriz(char** matriz,int size){
	for(int i=0;i<size; i++){
		matriz[i]=new char[size];	
	}
}

void iniciarmatriz(char** matriz, int size){

	for (int i = 0; i <size; i++){
		for (int j = 0; j < size; j++){
			matriz[i][j] ='\0'; 			
		}
	}
}

void eliminarmatriz(char** matriz,int size){

	for(int k=0; k<size; k++){
		delete[] matriz[k]; 
	}

	delete[] matriz; 
}

void asigned(char** matriz){

	matriz[4][0]= '#'; 
	matriz[4][6]= '#';
	matriz[0][4]= '+';
	matriz[6][4]= '+';  

}
int contarnumeral(char** matriz,int size){
	
	int cont=0; 
	for (int i = 0; i <size; i++){
		for (int j = 0; j < size; j++){
			if (matriz[i][j] =='#'){
				cont++; 
			}		

		}
	}
	return cont; 
}

int contarmas(char** matriz,int size){
	int cont=0; 
	for (int i = 0; i <size; i++){
		for (int j = 0; j < size; j++){
			if (matriz[i][j] =='+'){
				cont++; 
			}		

		}
	}
	return cont; 
}

void imprimirmatriz(char** matriz,int size){

	for (int i = 0; i <size; i++){
		for (int j = 0; j < size; j++){
			cout<<endl<<"------------------Coordenadas Juego----------------"<<endl
				<<setw(5)<<matriz[i][j]; 	

		}
		cout<<endl; 
	}

}