//Vectors and Matrices



const int rows = 3;
const int columns = 3;

vector<vector<int>> matrix(rows, vector<int>(columns, 0));

void print_matrix(vector<vector<int>> matrix)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void create_matrix(vector<vector<int>>& matrix)
{
	int element;
	vector<int> row;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cin >> element;
			matrix[i][j] = element;
		}
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

void spiralPrint(vector<vector<int>> matrix)
{
	int steps, row, column, layer;
	enum Direction
		{
			left,
			right,
			up,
			down
		};
	Direction direction = right;

	steps = rows * columns;
	row = 0;
	column = 0;
	layer = 0;

	for (int i = 0; i < steps; i++)
	{
		cout << matrix[row][column] << " ";
		switch (direction)
		{
		case right:
			if (column == columns - layer - 1)
			{
				row++;
				direction = down;
				cout << endl;
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
				cout << endl;
			}
			else
			{
				row++;
			}
			break;
		case left:
			if (column == layer)
			{
				row--;
				direction = up;
				cout << endl;
			}
			else
			{
				column--;
			}
			break;
		case up:
			if (row == layer + 1)
			{
				column++;
				direction = right;
				layer++;
			}
			else
			{
				row--;
			}

			break;
		}
	}
}

//Check for duplicates at k distance (manhattan distance) in a matrix.
