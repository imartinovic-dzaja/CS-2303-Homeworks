#ifndef ADJMAT_H_INCLUDED
#define ADJMAT_H_INCLUDED

class AdjMat
{
private:
	int m_n;
	int *m_edgesP;

public:
    AdjMat();
    AdjMat(int);
    AdjMat(int , int*);
    ~AdjMat();

    void setEdge(int row, int col);
    int getEdge(int row, int col);
    void createMainDiagonalSymmetry();
    void printMatrix();

};




#endif // ADJMAT_H_INCLUDED

