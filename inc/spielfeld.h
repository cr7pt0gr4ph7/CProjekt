#ifndef __TCP_H__
#define __TCP_H__


class Spielfeld{
private:
	int width;
	int height;
	int sideWidth;
	int sideHeight;
public:
	Spielfeld(int pWidth, int pHeight);
	void setFieldWidth(int pWidth);
	void setFieldHeight(int pHeight);
	int getFieldWidth();
	int getFieldHeight();
	int getSideWidth();
	int getSideHeight();
	void printField(char* pField, int pWidth, int pHeight);
	char* setPoint(int aX, int aY, char* pField, int pHeight);
	char* fillField(int pWidth, int pHeight);
	~Spielfeld();
};

#endif
