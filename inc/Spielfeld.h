#ifndef __SPIELFELD_H__
#define __SPIELFELD_H__


class Spielfeld{
private:
	int width;
	int height;
	int spielstand;
	int infoWidth;
	char *spielfeld; //als Block fuer Uebergabe an Output
	char *info;
	char *spielfeldinfo; //spielfeld + info
public:
	Spielfeld(int pWidth, int pHeight);
	int getWidth();
	int getHeight();
	void clearSpielfeld(); //Spielfeld leeren
	void printSpielfeld(); //Spielfeld ausgeben
	void clearInfo(); //Info leeren
	void initInfo(); //Info initialisieren
	void addTextToInfo(const char* pStr, int pX, int pY); //Text an Punkt [X|Y] einfuegen
	void addInfoToSpielfeld(); //Info an Spielfeldhaengen
	void printSpielfeldInfo(); //Spielfeld mit Info ausgeben
	void drawPoint(int pX, int pY); //Punkt im Spielfeld einfuegen
	~Spielfeld();
};

#endif
