// Copyright (c) 2024 Shane So
// Distributed under the MIT license.
// See the file license.txt.

//    ******    *******         **       **********   **    ********
//   **////**  /**////**       ****     /////**///   /**   **////// 
//  **    //   /**   /**      **//**        /**      /**  /**       
// /**         /*******      **  //**       /**      /**  /*********
// /**         /**///**     **********      /**      /**  ////////**
// //**    **  /**  //**   /**//////**      /**      /**         /**
//  //******   /**   //**  /**     /**      /**      /**   ******** 
//   //////    //     //   //      //       //       //   ////////  

// Libraries
// iostream - input and output
// vector - vector collections and methods
// fstream - file input and output
// cctype - character data based functions
#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>

// Reads the matrix and sets
// the row and column parameters
// Input: matrix file name, number of rows, number of columns
// Output: matrix of characters
std::vector<std::vector<char>> gen_matrix(const std::string &filename, int &row, int &col){
	
	// matrix file processing
	std::ifstream f_input;
	f_input.open(filename);
	if (f_input.is_open()) {
		f_input >> row;
		f_input >> col;
	}
	
	// matrix generation
	std::vector<std::vector<char>> m(row, std::vector<char>(col));
	
	// matrix element assignment
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			f_input >> m[i][j];
		}
	}
	
	return m;
}

// Prints and displays the matrix
// Input: matrix composed of nested vectors
// Output: prints out the matrix elements in systemic order
void print(const std::vector<std::vector<char>> &m){
	std::cout << std::endl;
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			std::cout << m[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}

// Checks if char input is an action key: U/D/R/L
// Input: character user input
// Output: boolean flag state informing if the
// character input is an action key or not
bool valid(char input){
	if (isalpha(input) && (tolower(input) == 'u' || tolower(input) == 'd' || tolower(input) == 'r' || tolower(input) == 'l')) {
		return true;
	}
	return false;
}

// Shifts the matrix up
// Input: main matrix, number of rows, number of columns
// Output: shifts the matrix upwards
void move_up(std::vector<std::vector<char>> &m, int &row, int &col) {
	std::vector<char> init_v = m[0];
	for (int i = 1; i < m.size(); i++) {
		m[i-1] = m[i];
	}
	m[row-1] = init_v;
	
	return;
}

// Shifts the matrix down
// Input: main matrix, number of rows, number of columns
// Output: shifts the matrix downwards
void move_down(std::vector<std::vector<char>> &m, int &row, int &col) {
	std::vector<char> fin_v = m[row-1];
	for (int i = m.size() - 1; i > 0; i--) {
		m[i] = m[i-1];
	}
	m[0] = fin_v;
	
	return;
}

// Shifts the matrix right
// Input: main matrix, number of rows, number of columns
// Output: shifts the matrix to the right
void move_right(std::vector<std::vector<char>> &m, int &row, int &col) {
	std::vector<char> end_v;
	for (int a = 0; a < m.size(); a++) {
		end_v.push_back(m[a][col-1]);
	}
	
	for (int i = 0; i < m.size(); i++) {
		for (int j = m[i].size() - 1; j > 0; j--) {
			m[i][j] = m[i][j-1];
		}
	}
	for (int v = 0; v < m.size(); v++) {
		m[v][0] = end_v[v];
	}
	
	return;
}

// Shifts the matrix left
// Input: main matrix, number of rows, number of columns
// Output: shifts the matrix to the left
void move_left(std::vector<std::vector<char>> &m, int &row, int &col) {
	std::vector<char> start_v;
	for (int a = 0; a < m.size(); a++) {
		start_v.push_back(m[a][0]);
	}
	
	for (int i = 0; i < m.size(); i++) {
		for (int j = 1; j < m[i].size(); j++) {
			m[i][j-1] = m[i][j];
		}
	}
	for (int v = 0; v < m.size(); v++) {
		m[v][col-1] = start_v[v];
	}
	
	return;
}

// Shifts the matrix and acquires user input (extension of initial move function)
// Input: main matrix, character key, number of rows, number of columns
// Output: changes reference of matrix and altering its value positions
void move(std::vector<std::vector<char>> &m, char key, int &row, int &col) {
	
	std::vector<char> v;
	
	switch (tolower(key)) {
		case 'u':
			move_up(m, row, col);
			break;
		case 'd':
			move_down(m, row, col);
			break;
		case 'r':
			move_right(m, row, col);
			break;
		case 'l':
			move_left(m, row, col);
			break;
	}
	
	return;
}

// Shifts the matrix and acquires user input
// Input: main matrix, number of rows, number of columns
// Output: changes reference of matrix and altering its value positions
void move(std::vector<std::vector<char>> &m, int row, int col){
	
	// collect user input
	char key;
	do {
		std::cout << "Choose an action key (U/D/R/L) or any other key to quit: ";
		std::cin >> key;
		move(m, key, row, col);
		print(m);
	} while (valid(key));
	exit(0);
	
	return;
}

//
// Main Method
//
int main(){
	
	int row = 0, col = 0;
	
	std::string filename;
	std::cout << "Enter matrix file name: ";
	getline(std::cin, filename);
	
	std::vector<std::vector<char>> matrix = gen_matrix(filename, row, col);
	print(matrix);
	move(matrix, row, col);
	
    return 0;
}