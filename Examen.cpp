#include<iostream>
using std::cout; 
using std::cin; 
using std::endl; 

void crearmatriz(char**,int); 
void llenar(char**,int);
void iniciarmatriz(char**,int); 
void eliminarmatriz(char**,int); 
void asigned(char**); 

int main(int argc, char*argv[]){

	char** matriz; 
	int tamanio = 7; 
	matriz=new char* [tamanio];
	crearmatriz(matriz,tamanio);
	iniciarmatriz(matriz,tamanio);  
	asigned(matriz);
	eliminarmatriz(matriz,tamanio); 
	
}


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
