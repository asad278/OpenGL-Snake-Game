#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "snake.h"

extern bool gameOver, border;
extern int score, lvl;

int gridX, gridY, foodX, foodY;
bool food=true;
short sDir = RIGHT, wt=10;
int len = 2;
int posX[LEN]={N/2}, posY[LEN]={N/2};

void initGrid(int x, int y){
	gridX = x;
	gridY = y;
}

void unit(int x, int y){
	glBegin(GL_LINE_LOOP);
		glVertex2f(x, y);
		glVertex2f(x+1, y);
		glVertex2f(x+1, y+1);
		glVertex2f(x, y+1);
	glEnd();
}

void drawGrid(){
	if(border){
		glLineWidth(5);
		glColor3f(1, 0, 0);
		for(int x=0; x<gridX; x++) unit(x, 0);
		for(int x=0; x<gridX; x++) unit(x, gridY-1);
		for(int y=0; y<gridY; y++) unit(0, y);
		for(int y=0; y<gridY; y++) unit(gridX-1, y);
	}
	else{
		glLineWidth(1);
		glColor3f(1, 1, 1);
		for(int x=0; x<gridX; x++) unit(x, 0);
		for(int x=0; x<gridX; x++) unit(x, gridY-1);
		for(int y=0; y<gridY; y++) unit(0, y);
		for(int y=0; y<gridY; y++) unit(gridX-1, y);
	}
}

void random(int &x, int &y){
	int mxX = gridX-2*wt, mnX = 2*wt;
	srand(time(NULL));
	x = mnX + rand()%(mxX-mnX);

	int mxY = gridY-2*wt, mnY = 2*wt;
	srand(time(NULL));
	y = mnY + rand()%(mxY-mnY);
}

void drawFood(){
	if(food) random(foodX, foodY);
	food=false;
	glColor3f(0, 0.5, 0.5);
	glRectd(foodX, foodY, foodX+wt, foodY+wt);
}

void drawSnake(){
	for(int i=len-1; i>0; i--)
		posX[i] = posX[i-1], posY[i] = posY[i-1];

	switch(sDir){
		case UP: posY[0]+=lvl; break;
		case DOWN: posY[0]-=lvl; break;
		case LEFT: posX[0]-=lvl; break;
		case RIGHT: posX[0]+=lvl; break;
		default: break;
	}

	for(int i=0; i<len; i++){
		i<wt/5? glColor3f(1, 1, 0) : glColor3f(0, 1, 0);
		glRectd(posX[i], posY[i], posX[i]+wt, posY[i]+wt);
	}

	if(border){
		if(posX[0]<=0 or posX[0]>=gridX-1 or posY[0]<=0 or posY[0]>=gridY-1)
			gameOver=true;
	}
	else{
		if(posX[0]<=0) posX[0]=gridX-1;
		else if(posX[0]>=gridX-1) posX[0]=0;

		if(posY[0]<=0) posY[0]=gridY-1;
		else if(posY[0]>=gridY-1) posY[0]=0;
	}

	for(int i=1; i<len*wt; i++){
		if(posX[i]==posX[0] and posY[i]==posY[0])
			gameOver=true;
	}
	
	if(abs(posX[0]-foodX)<=wt and abs(posY[0]-foodY)<=wt){
		len+=2;
		score++;
		if(len>LEN) len=LEN;
		food=true;
	}
}