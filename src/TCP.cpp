//============================================================================
// Name        : TCP.cpp
// Author      : Denis Gauss
// Version     : 1.0.0
// Copyright   : Your copyright notice
// Description : Spielbrett in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../inc/tcp.h"
using namespace std;

Spielfeld::Spielfeld(){
}

Spielfeld::~Spielfeld(){
}

int Spielfeld::setFieldWidth(int pWidth)
{
	width = pWidth;
}
int Spielfeld::setFieldHeight(int pHeight)
{
	height = pHeight;
}

int Spielfeld::tcp_main() {

	int width,height,pX,pY;
	pX=15;
	pY=10;
	height=17;
	width=32;

	char* spielfeld=new char[width*height];

	cout<< "Feld 1:"<<endl;

	spielfeld = fillField(height,width);	//Leeres Spielfeld intiieren
	printField(spielfeld,height,width);	//Leeres Spielfeld ausgeben

	cout<< "Feld 2 mit Testpunkt P(" << pX << "|" << pY << "):"<<endl;

	spielfeld = setPoint(15,10,spielfeld,width);
	printField(spielfeld,height,width);

	return 0;
}
void Spielfeld::printField(char* pField,int pWidth,int pHeight)
{
	int x,y;
	for(x=0;x<pWidth;x++){			//Spielfeld ausgeben
		for(y=0 ; y<pHeight ; y++) {
			cout<< pField[x*pHeight+y];
		}
		cout<<endl;
	}
}
char* Spielfeld::setPoint(int aX,int aY,char* pField,int pHeight)
{
	pField[aX*pHeight+aY]='1';
	return pField;
}
char* Spielfeld::fillField(int pWidth,int pHeight)
{
	int x,y;
	char* temp=new char[pWidth*pHeight];
	for(x=0 ; x<pWidth ; x++){			//Spielfeld+Rand füllen
		for(y=0 ; y<pHeight ; y++){
			if((x==0 || x==pWidth-1) && (y!=0 || y!=pHeight-1)){
				temp[x*pHeight+y]='#';
			}
			else if(y==0 || y==pHeight-1){
				temp[x*pHeight+y]='#';
			}
			else{
				temp[x*pHeight+y]=' ';
			}
		}
	}
	return temp;
}
