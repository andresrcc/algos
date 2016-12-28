//Vectors and Matrices



const rows vector = 4;
int const columns = 4;
//                                             value of each cell
vector<vector<int>> matrix(rows, vector<int>(columns, 0));
        //type         number of rows    number of columns

void print_matrix(vector<vector<int>> matrix){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

}

void create_matrix(){
  int element;
  vector<vector<int>> matrix;

  for(int i = 0; i < rows; ++i){
    vector<int> row;
    for(int j = 0; j < columns; ++j){
      cin >> element;
      row.push_back(element);
    }
    matrix.push_back(row);
  }
}

//Rotate array
vector<int> rotateArray(vector<int> &A, int B) {
    vector<int> ret; 
    for (int i = 0; i < A.size(); i++) {
        ret.push_back(A[(i + B) % A.size()]);
    }
    return ret; 
}

//spiral matrix print
#include "stdafx.h"
#include <vector>
#include <fstream>

using namespace std;
int main()
{
	ifstream rf("input.txt");
	ofstream wf("output.txt");
	int rows, columns, steps, row, column, layer;
	enum Direction {left, right, up, down};
	Direction direction = right;

	rf >> rows >> columns;

	vector<vector<int>>matrix(rows,vector<int>(columns,0));

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			rf >> matrix[i][j];
			
		}
	}

	steps = rows*columns;
	row = 0;
	column = 0;
	layer = 0;

	for(int i = 0; i < steps; i++)
	{
		switch(direction)
		{
		case right:
			if(column == columns - layer - 1)
			{
				row++;
				direction = down;
				wf << endl;
			}
			else
			{
				column++;	
			}
			break;
		case down:
			if (row == rows - layer - 1)
			{
				column--;
				direction = left;
				wf << endl;
			}else
			{
				row++;
			}
			break;
		case left:
			if(column == layer)
			{
				row--;
				direction = up;
				wf << endl;
			}else
			{
				column--;
			}
			break;
		case up:
			if(row == layer + 1)
			{
				column++;
				direction = right;
				layer++;
			}else
			{
				row--;
			}

			break;
		}
		wf << matrix[row][column] << " ";
	}


	return 0;
}

//Check for duplicates at k distance (manhattan distance) in a matrix.