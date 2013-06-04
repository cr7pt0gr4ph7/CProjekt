#ifndef __TCP_H__
#define __TCP_H__


class Spielfeld{
private:
	int width;
	int height;
public:
	Spielfeld();
	void setFieldWidth(int pWidth);
	void setFieldHeight(int pHeight);
	void printField(char* pField, int pWidth, int pHeight);
	char* setPoint(int aX, int aY, char* pField, int pHeight);
	char* fillField(int pWidth, int pHeight);
	int tcp_main();
	~Spielfeld();
};

#endif
