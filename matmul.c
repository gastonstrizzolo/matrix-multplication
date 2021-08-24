/*
A very simple matrix multiplicator
Usage: ./foo n m p
where n is the number of rows of the first matrix
where m is the nunmber of columns of the first matrix and the number of rows of the second
where p is the number of columns of the second matrix
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int rows;       //n
        int columns;    //m
        int** mat;
} matrix;

matrix* createMatrix(int n, int m){
        matrix *matx = calloc(1,sizeof(matrix));
        matx->rows = n;
        matx->columns = m;
        matx->mat = malloc(n * sizeof(int *));
	for(int i = 0; i < n; i++)
		matx->mat[i] = malloc(m * sizeof(int));
        return matx;
}

matrix* enterMatrix(int n, int m){
        matrix *matx = createMatrix(n,m);
        for(int i=0; i < n; i++){
                for(int j=0; j < m; j++){
                        printf("\t enter the element in [%d,%d] position ", i+1, j+1);
                        scanf("%d", &matx->mat[i][j]);
                }
        }
        return matx;
}

void displayMatrix(matrix *matx){
        for(int i=0; i < matx->rows; i++){
                for(int j=0; j < matx->columns; j++){
                        printf("\t   %d", matx->mat[i][j]);
                }
                printf("\n");
        }
}

matrix* product(matrix *m1, matrix *m2){
        matrix *matx = createMatrix(m1->rows, m2->columns);
        for(int i=0; i < m1->rows; i++){
                for(int j=0; j < m2->columns; j++){
                        for(int k=0; k < m2->columns; k++){
                                matx->mat[i][j] += m1->mat[i][k] * m2->mat[k][j];  
                        }
                }
        }
        return matx;
}

int main(int argc, char** argv){
        matrix * m1 ;
        matrix * m2  ;
        matrix * prod ;

        if(argc != 4){
                printf("error, usage: ->/ n m p \n");
                exit(1);
        }
        int n = atoi(argv[1]);
        int m = atoi(argv[2]);
        int p = atoi(argv[3]);
        
        printf("Enter matrix 1 \n");
        m1 = enterMatrix(n,m);
        displayMatrix(m1);
        printf("Enter matrix 2 \n");
        m2 = enterMatrix(m,p);
        displayMatrix(m2);
        printf("Processing \n");
        prod = product(m1,m2);
        displayMatrix(prod);

        return 0;
}
