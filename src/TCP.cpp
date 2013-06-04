//============================================================================
// Name        : TCP.cpp
// Author      : Denis Gauss
// Version     : 1.0.0
// Copyright   : Your copyright notice
// Description : Spielbrett in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printField(int* pField,int pWidth,int pHeight)
{
	int x,y;
	for(x=0;x<pWidth;x++){			//Spielfeldausgeben
					for(y=0;y<pHeight;y++) {cout<< pField[x*pHeight+y];}
					cout<<endl;
					}
}
int* setPoint(int aX,int aY,int* pField,int pHeight)
{
	pField[aX*pHeight+aY]=1;
	return pField;
}
int* fillField(int pWidth,int pHeight)
{
	int x,y;
	int* temp=new int[pWidth*pHeight];
	for(x=0;x<pWidth;x++){			//Spielfeld+Rand füllen

			for(y=0;y<pHeight;y++){

				if((x==0||x==pWidth-1)&&(y!=0||y!=pHeight-1)){
					temp[x*pHeight+y]=7;

					}
				else if(y==0||y==pHeight-1){
					temp[x*pHeight+y]=7;
				}
				else{
					temp[x*pHeight+y]=0;
				}
			}
		}
	return temp;

}
int myMain() {

	int width,height;
	width=17;
	height=32;
	int* spielfeld=new int[width*height];

	spielfeld=fillField(width,height);
	printField(spielfeld,width,height);
	spielfeld= setPoint(5,5,spielfeld,height);
	printField(spielfeld,width,height);


	return 0;
}
