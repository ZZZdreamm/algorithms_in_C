#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotateSquareOneTime(vector<vector<int>> &matrix, int top, int bottom, int left, int right)
{
    if (top >= bottom || left >= right)
    {
        return;
    }
    int temp = 0;
    int temp2 = matrix[top][left];
    int temp3 = 0;
    for (int i = top; i < bottom; i++)
    {
        temp = matrix[i + 1][left];
        matrix[i + 1][left] = temp2;
        temp2 = temp;
    }

    temp2 = matrix[bottom][left + 1];
    matrix[bottom][left + 1] = temp;
    for (int j = left + 1; j < right; j++)
    {
        temp = matrix[bottom][j + 1];
        matrix[bottom][j + 1] = temp2;
        temp2 = temp;
    }
    temp3 = temp2;
    temp = temp3;

    temp2 = matrix[bottom - 1][right];
    matrix[bottom - 1][right] = temp;
    for (int k = bottom - 1; k > top; k--)
    {
        temp = matrix[k - 1][right];
        matrix[k - 1][right] = temp2;
        temp2 = temp;
    }
    temp3 = temp2;
    temp = temp3;

    temp2 = matrix[top][right - 1];
    matrix[top][right - 1] = temp;
    for (int l = right - 1; l > left; l--)
    {
        temp = matrix[top][l - 1];
        matrix[top][l - 1] = temp2;
        temp2 = temp;
    }

    rotateSquareOneTime(matrix, top + 1, bottom - 1, left + 1, right - 1);
}

void matrixRotation(vector<vector<int>> matrix, int r)
{
    printf("matrixRotation\n");
    printMatrix(matrix);
    for (int rot = 0; rot < r; rot++)
    {
        rotateSquareOneTime(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
    printMatrix(matrix);
}

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24}, {25, 26, 27, 28, 29, 30}, {31, 32, 33, 34, 35, 36}};

    matrixRotation(matrix, 2);

    vector<vector<int>> matrix2 = {{1, 2, 3, 4, 5}, {7, 8, 9, 10, 11}, {13, 14, 15, 16, 17}, {19, 20, 21, 22, 23}, {25, 26, 27, 28, 29}, {31, 32, 33, 34, 35}};

    matrixRotation(matrix2, 1);
    return 0;
}