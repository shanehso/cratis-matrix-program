Cratis v0.1.0

Copyright (c) 2024 Shane So
Distributed under the MIT license.
See the file license.txt.


Intro
-----
Cratis is a matrix transformer program that uses file processing
to acquire data for generating matrices. Users may choose one of
four multidimensional action keys, which shift the vector elements
according to the provided input.


Documentation
-------------
Formatting your matrix document file:

  1  Number of Rows
  2  Number of Columns
  3+ Character Matrix
  
The first line should have a positive integer value indicating the
number of rows in the documented matrix.

The second line should have a positive integer value indicating the
number of columns in the documented matrix.

The number of rows should match the number of lines starting from the
line below the initial row and column values of the matrix document file.

The number of columns should match the number of characters in each
row of the matrix provided.

See the included matrix_ex.txt example file for reference.


Setup
-----
Verify that the parent directory containing the main files is
accessible and properly unpacked.

Run cratis.exe to open the program.

The initial user prompt asks for the name of the file containing the
character matrix of your choice.