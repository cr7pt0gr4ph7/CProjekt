#ifndef __TCP_H__
#define __TCP_H__


class Spielfeld{
private:
	int width;
	int height;
	int spielstand;
	char *spielfeld; //als Block fuer Uebergabe an Output
	char *info;
public:
	Spielfeld(int pWidth, int pHeight);
	void setWidth(int pWidth);
	int getWidth();
	void setHeight(int pHeight);
	int getHeight();
	void clearSpielfeld(); //Spielfeld leeren
	void printSpielfeld(); //Spielfeld ausgeben
	void drawPoint(int pX, int pY); //Punkt im Spielfeld einfuegen
	~Spielfeld();
};

#endif
