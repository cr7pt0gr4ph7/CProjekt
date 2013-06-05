//============================================================================
// Name        : TCP.cpp
// Author      : Denis Gauss, Maurice Angermann
// Version     : 1.0.0
// Copyright   : 2013, DHBW Karlsruhe
// Description : Spielbrett in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../inc/tcp.h"
using namespace std;

void Spielfeld::setFieldWidth(int pWidth)
{
	width = pWidth;
}
void Spielfeld::setFieldHeight(int pHeight)
{
	height = pHeight;
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

Spielfeld::Spielfeld(int pWidth, int pHeight){
	setFieldHeight(pHeight);
	setFieldWidth(pWidth);

	//char* spielfeld=new char[width*height];

	cout<< "leeres Spielfeld:"<<endl;

	//spielfeld = fillField(height,width);	//Leeres Spielfeld intiieren
}

Spielfeld::~Spielfeld(){
}
