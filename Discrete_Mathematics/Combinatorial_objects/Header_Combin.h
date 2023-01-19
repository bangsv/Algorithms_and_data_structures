#pragma once
#include <iostream>
#include <vector>

typedef std::vector<int> vec_int;

//Implementation of algorithms for geneating subsets.
void binary_subset(int k, int n, vec_int subset);

void number_subset(int k, int n, vec_int subset);

// Generating combinations
bool Combinations(vec_int& a, int n, int m);

void Print(vec_int& a, int n); // Suitable for displaying Combinations and Permutations

// Generating permutations

bool Permutations(vec_int& a, int n);

void swap(vec_int& a, int i, int j);

bool Generating_placements_Array(int* a, int n, int m);
void Print_Array(int* a, int n);

