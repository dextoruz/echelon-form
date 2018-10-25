#include<iostream>
#include<fstream>
using namespace std;

bool is_reducedEche_form(int **matrix, int row, int col) {
	// your code here

	int p = 0;
	for(int i = 0; i < col ; i++){
		if(p == row || p == col) break;
		if(matrix[p][i] == 0){
			int colsum = 0,restMsum = 0,rowsum = 0;
			for(int j = p; j < row; j++){
				for(int k = p; k < col; k++ )
					restMsum += matrix[j][k];
			}
			for(int i = p; i < col; i++) { colsum += matrix[p][i]; }
			for(int i = p; i < row; i++) { rowsum += matrix[i][p]; }
			if(restMsum == 0 && colsum == 0) { return true; }
			if(restMsum != 0 && colsum == 0) { return false; }
			if(rowsum != 0) { return false; }
			continue;
		}
		if(matrix[p][i] == 1){
			///// downwords check zeros from pivot point
			for(int j = p+1; j < row; j++)
				if(matrix[j][i] != 0)
					return false;

			//// upwards check zeros from pivot point
			for(int j = 0; j < p; j++)
			 	if(matrix[j][i] != 0)
					return false;

			p++;
		}
		else  return false;
	}
	// access **matrix like this matrix[i][j]
	return 1;
}

//Don't touch this function
void alloca_memory(int **matrix, int row, int col) {
	for (int i = 0; i < row; i++)
		matrix[i] = new int[col];
}

//Don't touch this function
void free_memory(int **matrix, int row) {
	for (int i = 0; i > row; i++)
		delete[] matrix[i];
	delete[] matrix;
}

int main() {

	int row = 0, col = 0, tmatrix = 0;
	int **matrix = 0;
	ifstream in("in.txt");
	ofstream out("out.txt"); // will automatically created if not present

	if (!in.is_open()) {
		cout << "Error in opening file" << endl;
		return 0;
	}

	in >> tmatrix;

	for (int i = 0; i < tmatrix; i++) {
		in >> row >> col;
		matrix = new int*[row];
		alloca_memory(matrix, row, col);

		for (int k = 0; k < row; k++)
			for (int j = 0; j < col; j++)
				in >> matrix[k][j];

		if (is_reducedEche_form(matrix, row, col)) // your desired function to which you passes 2d array(matrix)
			out << 1<<endl;
		else out << 0 << endl;

		free_memory(matrix, row); // to free the memory allocated

	}

}
