#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "snake.h"
using namespace std;

extern short sDir;
bool gameOver=false, border;
int idx=0, score=0, lvl;
vector<int> scores;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();

    if(gameOver){
        score *= lvl;
        cout << "Your score: " << score << endl;
        scores.push_back(score);

        ifstream ip;
        border? ip.open("HighscoreBorder.txt") : ip.open("HighscoreBorderless.txt");
        int scr;
        while(ip >> scr)
            scores.push_back(scr);

        ip.close();

        sort(begin(scores), end(scores), greater<int>());
        
        ofstream op;
        border? op.open("HighscoreBorder.txt") : op.open("HighscoreBorderless.txt");
        for(int i=0; i<min((int)scores.size(), 5); i++)
            op << scores[i] << endl;
        scores.clear();
        exit(0);
    }
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, N, 0, N, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/fps, timer, 0);
}

void init(){
    glClearColor(0.1, 0.1, 0.1, 1);
    initGrid(N, N);
}

void keys(int k, int, int){
    switch (k){
        case GLUT_KEY_UP: if(sDir!=DOWN) sDir=UP; break;
        case GLUT_KEY_DOWN: if(sDir!=UP) sDir=DOWN; break;
        case GLUT_KEY_LEFT: if(sDir!=RIGHT) sDir=LEFT; break;
        case GLUT_KEY_RIGHT: if(sDir!=LEFT) sDir=RIGHT; break;
        case GLUT_KEY_F1: gameOver=true; break;
        default: break;
    }
}

void graphics(){
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(N, N);
    glutCreateWindow("Snake");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(keys);
    init();
    glutMainLoop();
}

int main(int argc, char **argv){
    cout << "Choose level: [1-5 (Recommended)]: ";
    cin >> lvl;
    cout << "0 -> Borderless\n1 -> Border\n";
    cin >> border;

    glutInit(&argc, argv);
    graphics();
}