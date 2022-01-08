#pragma once
#include "Includes.h"
#include "Termcolor.h"

#pragma region Identifiers
void generate();

void makeBoard(int row, vector<vector<int>>& board, int resetCounter, int& rstCounter);

void printBoard(int row, vector<vector<int>> board, int rstCounter);
void printBoardToFile(int row, vector<vector<int>> board, int rstCounter);

void sudoku_Easy(int row, vector<vector<int>> board, int rangeEasy, int rstCounter);
void sudoku_Normal(int row, vector<vector<int>> board, int rangeNormal, int rstCounter);
void sudoku_Hard(int row, vector<vector<int>> board, int rangeHard, int rstCounter);
void sudoku_Expert(int row, vector<vector<int>> board, int rangeExpert, int rstCounter);
void sudoku_Impossible(int row, vector<vector<int>> board, int rangeImpossible, int rstCounter);
#pragma endregion

//-------------------------------------------------------------------------------------------------------------------------

void generate() {

	int rowAndColumn{9};
	int row{rowAndColumn};
	int column{rowAndColumn};

	int resetCounter{500000};
	int rstCounter{};

	//How many numbers to remove
	int rangeEasy{40};
	int rangeNormal{55};
	int rangeHard{65};
	int rangeExpert{70};
	int rangeImpossible{75};

	vector<vector<int>> board(column, vector<int>(row));

	while (true)
	{
		makeBoard(row, board, resetCounter, rstCounter);

		printBoard(row, board, rstCounter);
		printBoardToFile(row, board, rstCounter);

		//Print playable Sudoku Boards
		for (size_t i = 0; i < 2; i++)
		{
			sudoku_Easy(row, board, rangeEasy, rstCounter);
			sudoku_Normal(row, board, rangeNormal, rstCounter);
			sudoku_Hard(row, board, rangeHard, rstCounter);
			sudoku_Expert(row, board, rangeExpert, rstCounter);
			sudoku_Impossible(row, board, rangeImpossible, rstCounter);
		}
		
		Sleep(500);
		rstCounter = 0;
	}
}

void makeBoard(int row, vector<vector<int>>& board, int resetCounter, int& rstCounter) {

	vector<int> boxNumbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<vector<int>> boxes{};
	vector<vector<int>> boxesTemp(row, vector<int>(row));

	int counterRounds{};
	
	//Reset Board
	for (size_t y = 0; y < row; y++)
	{
		for (size_t x = 0; x < row; x++)
			board[x][y] = 0;
	}

	//Shuffle vector with a time seed, and place them in a vector
	for (size_t i = 0; i < row;)
	{
		counterRounds++;

		//Resets the board if the borad gets stuck
		if (counterRounds > resetCounter)
		{
			for (size_t y = 0; y < row; y++)
			{
				for (size_t x = 0; x < row; x++)
					board[x][y] = 0;
			}

			i = 0;
			counterRounds = 0;
			rstCounter++;
			boxes.clear();
		}

		//Make a random sorted vector
		unsigned seeds = std::chrono::system_clock::now().time_since_epoch().count();
		shuffle(boxNumbers.begin(), boxNumbers.end(), std::default_random_engine(seeds));
		boxes.push_back(boxNumbers);

		//checking that any number is different
		if (i == 0)
		{
			system("cls");

			//Fill in the first box automaticly
			board[0][0] = boxes[0][0];
			board[0][1] = boxes[0][1];
			board[0][2] = boxes[0][2];
			board[1][0] = boxes[0][3];
			board[1][1] = boxes[0][4];
			board[1][2] = boxes[0][5];
			board[2][0] = boxes[0][6];
			board[2][1] = boxes[0][7];
			board[2][2] = boxes[0][8];

			printBoard(row, board, rstCounter);
			i++;
		}
		else if (i == 1)
		{
			if (boxNumbers[0] != boxes[0][0] && boxNumbers[0] != boxes[0][1] && boxNumbers[0] != boxes[0][2])
			{
				if (boxNumbers[1] != boxes[0][0] && boxNumbers[1] != boxes[0][1] && boxNumbers[1] != boxes[0][2])
				{
					if (boxNumbers[2] != boxes[0][0] && boxNumbers[2] != boxes[0][1] && boxNumbers[2] != boxes[0][2])
					{
						if (boxNumbers[3] != boxes[0][3] && boxNumbers[3] != boxes[0][4] && boxNumbers[3] != boxes[0][5])
						{
							if (boxNumbers[4] != boxes[0][3] && boxNumbers[4] != boxes[0][4] && boxNumbers[4] != boxes[0][5])
							{
								if (boxNumbers[5] != boxes[0][3] && boxNumbers[5] != boxes[0][4] && boxNumbers[5] != boxes[0][5])
								{
									if (boxNumbers[6] != boxes[0][6] && boxNumbers[6] != boxes[0][7] && boxNumbers[6] != boxes[0][8])
									{
										if (boxNumbers[7] != boxes[0][6] && boxNumbers[7] != boxes[0][7] && boxNumbers[7] != boxes[0][8])
										{
											if (boxNumbers[8] != boxes[0][6] && boxNumbers[8] != boxes[0][7] && boxNumbers[8] != boxes[0][8])
											{
												system("cls");

												board[0][3] = boxes[1][0];
												board[0][4] = boxes[1][1];
												board[0][5] = boxes[1][2];
												board[1][3] = boxes[1][3];
												board[1][4] = boxes[1][4];
												board[1][5] = boxes[1][5];
												board[2][3] = boxes[1][6];
												board[2][4] = boxes[1][7];
												board[2][5] = boxes[1][8];

												printBoard(row, board, rstCounter);
												counterRounds = 0;
												i++;
											}
											else
												boxes.pop_back();
										}
										else
											boxes.pop_back();
									}
									else
										boxes.pop_back();
								}
								else
									boxes.pop_back();
							}
							else
								boxes.pop_back();
						}
						else
							boxes.pop_back();
					}
					else
						boxes.pop_back();
				}
				else
					boxes.pop_back();
			}
			else
				boxes.pop_back();
		}
		else if (i == 2)
		{
			if (boxNumbers[0] != boxes[0][0] && boxNumbers[0] != boxes[0][1] && boxNumbers[0] != boxes[0][2] && boxNumbers[0] != boxes[1][0] && boxNumbers[0] != boxes[1][1] && boxNumbers[0] != boxes[1][2])
			{
				if (boxNumbers[1] != boxes[0][0] && boxNumbers[1] != boxes[0][1] && boxNumbers[1] != boxes[0][2] && boxNumbers[1] != boxes[1][0] && boxNumbers[1] != boxes[1][1] && boxNumbers[1] != boxes[1][2])
				{
					if (boxNumbers[2] != boxes[0][0] && boxNumbers[2] != boxes[0][1] && boxNumbers[2] != boxes[0][2] && boxNumbers[2] != boxes[1][0] && boxNumbers[2] != boxes[1][1] && boxNumbers[2] != boxes[1][2])
					{
						if (boxNumbers[3] != boxes[0][3] && boxNumbers[3] != boxes[0][4] && boxNumbers[3] != boxes[0][5] && boxNumbers[3] != boxes[1][3] && boxNumbers[3] != boxes[1][4] && boxNumbers[3] != boxes[1][5])
						{
							if (boxNumbers[4] != boxes[0][3] && boxNumbers[4] != boxes[0][4] && boxNumbers[4] != boxes[0][5] && boxNumbers[4] != boxes[1][3] && boxNumbers[4] != boxes[1][4] && boxNumbers[4] != boxes[1][5])
							{
								if (boxNumbers[5] != boxes[0][3] && boxNumbers[5] != boxes[0][4] && boxNumbers[5] != boxes[0][5] && boxNumbers[5] != boxes[1][3] && boxNumbers[5] != boxes[1][4] && boxNumbers[5] != boxes[1][5])
								{
									if (boxNumbers[6] != boxes[0][6] && boxNumbers[6] != boxes[0][7] && boxNumbers[6] != boxes[0][8] && boxNumbers[6] != boxes[1][6] && boxNumbers[6] != boxes[1][7] && boxNumbers[6] != boxes[1][8])
									{
										if (boxNumbers[7] != boxes[0][6] && boxNumbers[7] != boxes[0][7] && boxNumbers[7] != boxes[0][8] && boxNumbers[7] != boxes[1][6] && boxNumbers[7] != boxes[1][7] && boxNumbers[7] != boxes[1][8])
										{
											if (boxNumbers[8] != boxes[0][6] && boxNumbers[8] != boxes[0][7] && boxNumbers[8] != boxes[0][8] && boxNumbers[8] != boxes[1][6] && boxNumbers[8] != boxes[1][7] && boxNumbers[8] != boxes[1][8])
											{
												system("cls");

												board[0][6] = boxes[2][0];
												board[0][7] = boxes[2][1];
												board[0][8] = boxes[2][2];
												board[1][6] = boxes[2][3];
												board[1][7] = boxes[2][4];
												board[1][8] = boxes[2][5];
												board[2][6] = boxes[2][6];
												board[2][7] = boxes[2][7];
												board[2][8] = boxes[2][8];

												printBoard(row, board, rstCounter);
												counterRounds = 0;
												i++;
											}
											else
												boxes.pop_back();
										}
										else
											boxes.pop_back();
									}
									else
										boxes.pop_back();
								}
								else
									boxes.pop_back();
							}
							else
								boxes.pop_back();
						}
						else
							boxes.pop_back();
					}
					else
						boxes.pop_back();
				}
				else
					boxes.pop_back();
			}
			else
				boxes.pop_back();
		}
		else if (i == 3)
		{
			if (boxNumbers[0] != boxes[0][0] && boxNumbers[0] != boxes[0][3] && boxNumbers[0] != boxes[0][6])
			{
				if (boxNumbers[1] != boxes[0][1] && boxNumbers[1] != boxes[0][4] && boxNumbers[1] != boxes[0][7])
				{
					if (boxNumbers[2] != boxes[0][2] && boxNumbers[2] != boxes[0][5] && boxNumbers[2] != boxes[0][8])
					{
						if (boxNumbers[3] != boxes[0][0] && boxNumbers[3] != boxes[0][3] && boxNumbers[3] != boxes[0][6])
						{
							if (boxNumbers[4] != boxes[0][1] && boxNumbers[4] != boxes[0][4] && boxNumbers[4] != boxes[0][7])
							{
								if (boxNumbers[5] != boxes[0][2] && boxNumbers[5] != boxes[0][5] && boxNumbers[5] != boxes[0][8])
								{
									if (boxNumbers[6] != boxes[0][0] && boxNumbers[6] != boxes[0][3] && boxNumbers[6] != boxes[0][6])
									{
										if (boxNumbers[7] != boxes[0][1] && boxNumbers[7] != boxes[0][4] && boxNumbers[7] != boxes[0][7])
										{
											if (boxNumbers[8] != boxes[0][2] && boxNumbers[8] != boxes[0][5] && boxNumbers[8] != boxes[0][8])
											{
												system("cls");

												board[3][0] = boxes[3][0];
												board[3][1] = boxes[3][1];
												board[3][2] = boxes[3][2];
												board[4][0] = boxes[3][3];
												board[4][1] = boxes[3][4];
												board[4][2] = boxes[3][5];
												board[5][0] = boxes[3][6];
												board[5][1] = boxes[3][7];
												board[5][2] = boxes[3][8];

												printBoard(row, board, rstCounter);
												counterRounds = 0;
												i++;
											}
											else
												boxes.pop_back();
										}
										else
											boxes.pop_back();
									}
									else
										boxes.pop_back();
								}
								else
									boxes.pop_back();
							}
							else
								boxes.pop_back();
						}
						else
							boxes.pop_back();
					}
					else
						boxes.pop_back();
				}
				else
					boxes.pop_back();
			}
			else
				boxes.pop_back();
		}
		else if (i == 4)
		{
		if (boxNumbers[0] != boxes[3][0] && boxNumbers[0] != boxes[3][1] && boxNumbers[0] != boxes[3][2] && boxNumbers[0] != boxes[1][0] && boxNumbers[0] != boxes[1][3] && boxNumbers[0] != boxes[1][6])
		{
			if (boxNumbers[1] != boxes[3][0] && boxNumbers[1] != boxes[3][1] && boxNumbers[1] != boxes[3][2] && boxNumbers[1] != boxes[1][1] && boxNumbers[1] != boxes[1][4] && boxNumbers[1] != boxes[1][7])
			{
				if (boxNumbers[2] != boxes[3][0] && boxNumbers[2] != boxes[3][1] && boxNumbers[2] != boxes[3][2] && boxNumbers[2] != boxes[1][2] && boxNumbers[2] != boxes[1][5] && boxNumbers[2] != boxes[1][8])
				{
					if (boxNumbers[3] != boxes[3][3] && boxNumbers[3] != boxes[3][4] && boxNumbers[3] != boxes[3][5] && boxNumbers[3] != boxes[1][0] && boxNumbers[3] != boxes[1][3] && boxNumbers[3] != boxes[1][6])
					{
						if (boxNumbers[4] != boxes[3][3] && boxNumbers[4] != boxes[3][4] && boxNumbers[4] != boxes[3][5] && boxNumbers[4] != boxes[1][1] && boxNumbers[4] != boxes[1][4] && boxNumbers[4] != boxes[1][7])
						{
							if (boxNumbers[5] != boxes[3][3] && boxNumbers[5] != boxes[3][4] && boxNumbers[5] != boxes[3][5] && boxNumbers[5] != boxes[1][2] && boxNumbers[5] != boxes[1][5] && boxNumbers[5] != boxes[1][8])
							{
								if (boxNumbers[6] != boxes[3][6] && boxNumbers[6] != boxes[3][7] && boxNumbers[6] != boxes[3][8] && boxNumbers[6] != boxes[1][0] && boxNumbers[6] != boxes[1][3] && boxNumbers[6] != boxes[1][6])
								{
									if (boxNumbers[7] != boxes[3][6] && boxNumbers[7] != boxes[3][7] && boxNumbers[7] != boxes[3][8] && boxNumbers[7] != boxes[1][1] && boxNumbers[7] != boxes[1][4] && boxNumbers[7] != boxes[1][7])
									{
										if (boxNumbers[8] != boxes[3][6] && boxNumbers[8] != boxes[3][7] && boxNumbers[8] != boxes[3][8] && boxNumbers[8] != boxes[1][2] && boxNumbers[8] != boxes[1][5] && boxNumbers[8] != boxes[1][8])
										{
											system("cls");

											board[3][3] = boxes[4][0];
											board[3][4] = boxes[4][1];
											board[3][5] = boxes[4][2];
											board[4][3] = boxes[4][3];
											board[4][4] = boxes[4][4];
											board[4][5] = boxes[4][5];
											board[5][3] = boxes[4][6];
											board[5][4] = boxes[4][7];
											board[5][5] = boxes[4][8];

											printBoard(row, board, rstCounter);
											counterRounds = 0;
											i++;
										}
										else
											boxes.pop_back();
									}
									else
										boxes.pop_back();
								}
								else
									boxes.pop_back();
							}
							else
								boxes.pop_back();
						}
						else
							boxes.pop_back();
					}
					else
						boxes.pop_back();
				}
				else
					boxes.pop_back();
			}
			else
				boxes.pop_back();
		}
		else
			boxes.pop_back();
		}
		else if (i == 5)
		{
		if (boxNumbers[0] != boxes[3][0] && boxNumbers[0] != boxes[3][1] && boxNumbers[0] != boxes[3][2] && boxNumbers[0] != boxes[4][0] && boxNumbers[0] != boxes[4][1] && boxNumbers[0] != boxes[4][2] && boxNumbers[0] != boxes[2][0] && boxNumbers[0] != boxes[2][3] && boxNumbers[0] != boxes[2][6])
		{
			if (boxNumbers[1] != boxes[3][0] && boxNumbers[1] != boxes[3][1] && boxNumbers[1] != boxes[3][2] && boxNumbers[1] != boxes[4][0] && boxNumbers[1] != boxes[4][1] && boxNumbers[1] != boxes[4][2] && boxNumbers[1] != boxes[2][1] && boxNumbers[1] != boxes[2][4] && boxNumbers[1] != boxes[2][7])
			{
				if (boxNumbers[2] != boxes[3][0] && boxNumbers[2] != boxes[3][1] && boxNumbers[2] != boxes[3][2] && boxNumbers[2] != boxes[4][0] && boxNumbers[2] != boxes[4][1] && boxNumbers[2] != boxes[4][2] && boxNumbers[2] != boxes[2][2] && boxNumbers[2] != boxes[2][5] && boxNumbers[2] != boxes[2][8])
				{
					if (boxNumbers[3] != boxes[3][3] && boxNumbers[3] != boxes[3][4] && boxNumbers[3] != boxes[3][5] && boxNumbers[3] != boxes[4][3] && boxNumbers[3] != boxes[4][4] && boxNumbers[3] != boxes[4][5] && boxNumbers[3] != boxes[2][0] && boxNumbers[3] != boxes[2][3] && boxNumbers[3] != boxes[2][6])
					{
						if (boxNumbers[4] != boxes[3][3] && boxNumbers[4] != boxes[3][4] && boxNumbers[4] != boxes[3][5] && boxNumbers[4] != boxes[4][3] && boxNumbers[4] != boxes[4][4] && boxNumbers[4] != boxes[4][5] && boxNumbers[4] != boxes[2][1] && boxNumbers[4] != boxes[2][4] && boxNumbers[4] != boxes[2][7])
						{
							if (boxNumbers[5] != boxes[3][3] && boxNumbers[5] != boxes[3][4] && boxNumbers[5] != boxes[3][5] && boxNumbers[5] != boxes[4][3] && boxNumbers[5] != boxes[4][4] && boxNumbers[5] != boxes[4][5] && boxNumbers[5] != boxes[2][2] && boxNumbers[5] != boxes[2][5] && boxNumbers[5] != boxes[2][8])
							{
								if (boxNumbers[6] != boxes[3][6] && boxNumbers[6] != boxes[3][7] && boxNumbers[6] != boxes[3][8] && boxNumbers[6] != boxes[4][6] && boxNumbers[6] != boxes[4][7] && boxNumbers[6] != boxes[4][8] && boxNumbers[6] != boxes[2][0] && boxNumbers[6] != boxes[2][3] && boxNumbers[6] != boxes[2][6])
								{
									if (boxNumbers[7] != boxes[3][6] && boxNumbers[7] != boxes[3][7] && boxNumbers[7] != boxes[3][8] && boxNumbers[7] != boxes[4][6] && boxNumbers[7] != boxes[4][7] && boxNumbers[7] != boxes[4][8] && boxNumbers[7] != boxes[2][1] && boxNumbers[7] != boxes[2][4] && boxNumbers[7] != boxes[2][7])
									{
										if (boxNumbers[8] != boxes[3][6] && boxNumbers[8] != boxes[3][7] && boxNumbers[8] != boxes[3][8] && boxNumbers[8] != boxes[4][6] && boxNumbers[8] != boxes[4][7] && boxNumbers[8] != boxes[4][8] && boxNumbers[8] != boxes[2][2] && boxNumbers[8] != boxes[2][5] && boxNumbers[8] != boxes[2][8])
										{
											system("cls");

											board[3][6] = boxes[5][0];
											board[3][7] = boxes[5][1];
											board[3][8] = boxes[5][2];
											board[4][6] = boxes[5][3];
											board[4][7] = boxes[5][4];
											board[4][8] = boxes[5][5];
											board[5][6] = boxes[5][6];
											board[5][7] = boxes[5][7];
											board[5][8] = boxes[5][8];

											printBoard(row, board, rstCounter);
											counterRounds = 0;
											i++;
										}
										else
											boxes.pop_back();
									}
									else
										boxes.pop_back();
								}
								else
									boxes.pop_back();
							}
							else
								boxes.pop_back();
						}
						else
							boxes.pop_back();
					}
					else
						boxes.pop_back();
				}
				else
					boxes.pop_back();
			}
			else
				boxes.pop_back();
		}
		else
			boxes.pop_back();
		}
		else if (i == 6)
		{
		if (boxNumbers[0] != boxes[0][0] && boxNumbers[0] != boxes[0][3] && boxNumbers[0] != boxes[0][6] && boxNumbers[0] != boxes[3][0] && boxNumbers[0] != boxes[3][3] && boxNumbers[0] != boxes[3][6])
		{
			if (boxNumbers[1] != boxes[0][1] && boxNumbers[1] != boxes[0][4] && boxNumbers[1] != boxes[0][7] && boxNumbers[1] != boxes[3][1] && boxNumbers[1] != boxes[3][4] && boxNumbers[1] != boxes[3][7])
			{
				if (boxNumbers[2] != boxes[0][2] && boxNumbers[2] != boxes[0][5] && boxNumbers[2] != boxes[0][8] && boxNumbers[2] != boxes[3][2] && boxNumbers[2] != boxes[3][5] && boxNumbers[2] != boxes[3][8])
				{
					if (boxNumbers[3] != boxes[0][0] && boxNumbers[3] != boxes[0][3] && boxNumbers[3] != boxes[0][6] && boxNumbers[3] != boxes[3][0] && boxNumbers[3] != boxes[3][3] && boxNumbers[3] != boxes[3][6])
					{
						if (boxNumbers[4] != boxes[0][1] && boxNumbers[4] != boxes[0][4] && boxNumbers[4] != boxes[0][7] && boxNumbers[4] != boxes[3][1] && boxNumbers[4] != boxes[3][4] && boxNumbers[4] != boxes[3][7])
						{
							if (boxNumbers[5] != boxes[0][2] && boxNumbers[5] != boxes[0][5] && boxNumbers[5] != boxes[0][8] && boxNumbers[5] != boxes[3][2] && boxNumbers[5] != boxes[3][5] && boxNumbers[5] != boxes[3][8])
							{
								if (boxNumbers[6] != boxes[0][0] && boxNumbers[6] != boxes[0][3] && boxNumbers[6] != boxes[0][6] && boxNumbers[6] != boxes[3][0] && boxNumbers[6] != boxes[3][3] && boxNumbers[6] != boxes[3][6])
								{
									if (boxNumbers[7] != boxes[0][1] && boxNumbers[7] != boxes[0][4] && boxNumbers[7] != boxes[0][7] && boxNumbers[7] != boxes[3][1] && boxNumbers[7] != boxes[3][4] && boxNumbers[7] != boxes[3][7])
									{
										if (boxNumbers[8] != boxes[0][2] && boxNumbers[8] != boxes[0][5] && boxNumbers[8] != boxes[0][8] && boxNumbers[8] != boxes[3][2] && boxNumbers[8] != boxes[3][5] && boxNumbers[8] != boxes[3][8])
										{
											system("cls");

											board[6][0] = boxes[6][0];
											board[6][1] = boxes[6][1];
											board[6][2] = boxes[6][2];
											board[7][0] = boxes[6][3];
											board[7][1] = boxes[6][4];
											board[7][2] = boxes[6][5];
											board[8][0] = boxes[6][6];
											board[8][1] = boxes[6][7];
											board[8][2] = boxes[6][8];

											printBoard(row, board, rstCounter);
											counterRounds = 0;
											i++;
										}
										else
											boxes.pop_back();
									}
									else
										boxes.pop_back();
								}
								else
									boxes.pop_back();
							}
							else
								boxes.pop_back();
						}
						else
							boxes.pop_back();
					}
					else
						boxes.pop_back();
				}
				else
					boxes.pop_back();
			}
			else
				boxes.pop_back();
		}
		else
			boxes.pop_back();
		}
		else if (i == 7)
		{
		if (boxNumbers[0] != boxes[6][0] && boxNumbers[0] != boxes[6][1] && boxNumbers[0] != boxes[6][2] && boxNumbers[0] != boxes[1][0] && boxNumbers[0] != boxes[1][3] && boxNumbers[0] != boxes[1][6] && boxNumbers[0] != boxes[4][0] && boxNumbers[0] != boxes[4][3] && boxNumbers[0] != boxes[4][6])
		{
			if (boxNumbers[1] != boxes[6][0] && boxNumbers[1] != boxes[6][1] && boxNumbers[1] != boxes[6][2] && boxNumbers[1] != boxes[1][1] && boxNumbers[1] != boxes[1][4] && boxNumbers[1] != boxes[1][7] && boxNumbers[1] != boxes[4][1] && boxNumbers[1] != boxes[4][4] && boxNumbers[1] != boxes[4][7])
			{
				if (boxNumbers[2] != boxes[6][0] && boxNumbers[2] != boxes[6][1] && boxNumbers[2] != boxes[6][2] && boxNumbers[2] != boxes[1][2] && boxNumbers[2] != boxes[1][5] && boxNumbers[2] != boxes[1][8] && boxNumbers[2] != boxes[4][2] && boxNumbers[2] != boxes[4][5] && boxNumbers[2] != boxes[4][8])
				{
					if (boxNumbers[3] != boxes[6][3] && boxNumbers[3] != boxes[6][4] && boxNumbers[3] != boxes[6][5] && boxNumbers[3] != boxes[1][0] && boxNumbers[3] != boxes[1][3] && boxNumbers[3] != boxes[1][6] && boxNumbers[3] != boxes[4][0] && boxNumbers[3] != boxes[4][3] && boxNumbers[3] != boxes[4][6])
					{
						if (boxNumbers[4] != boxes[6][3] && boxNumbers[4] != boxes[6][4] && boxNumbers[4] != boxes[6][5] && boxNumbers[4] != boxes[1][1] && boxNumbers[4] != boxes[1][4] && boxNumbers[4] != boxes[1][7] && boxNumbers[4] != boxes[4][1] && boxNumbers[4] != boxes[4][4] && boxNumbers[4] != boxes[4][7])
						{
							if (boxNumbers[5] != boxes[6][3] && boxNumbers[5] != boxes[6][4] && boxNumbers[5] != boxes[6][5] && boxNumbers[5] != boxes[1][2] && boxNumbers[5] != boxes[1][5] && boxNumbers[5] != boxes[1][8] && boxNumbers[5] != boxes[4][2] && boxNumbers[5] != boxes[4][5] && boxNumbers[5] != boxes[4][8])
							{
								if (boxNumbers[6] != boxes[6][6] && boxNumbers[6] != boxes[6][7] && boxNumbers[6] != boxes[6][8] && boxNumbers[6] != boxes[1][0] && boxNumbers[6] != boxes[1][3] && boxNumbers[6] != boxes[1][6] && boxNumbers[6] != boxes[4][0] && boxNumbers[6] != boxes[4][3] && boxNumbers[6] != boxes[4][6])
								{
									if (boxNumbers[7] != boxes[6][6] && boxNumbers[7] != boxes[6][7] && boxNumbers[7] != boxes[6][8] && boxNumbers[7] != boxes[1][1] && boxNumbers[7] != boxes[1][4] && boxNumbers[7] != boxes[1][7] && boxNumbers[7] != boxes[4][1] && boxNumbers[7] != boxes[4][4] && boxNumbers[7] != boxes[4][7])
									{
										if (boxNumbers[8] != boxes[6][6] && boxNumbers[8] != boxes[6][7] && boxNumbers[8] != boxes[6][8] && boxNumbers[8] != boxes[1][2] && boxNumbers[8] != boxes[1][5] && boxNumbers[8] != boxes[1][8] && boxNumbers[8] != boxes[4][2] && boxNumbers[8] != boxes[4][5] && boxNumbers[8] != boxes[4][8])
										{
											system("cls");

											board[6][3] = boxes[7][0];
											board[6][4] = boxes[7][1];
											board[6][5] = boxes[7][2];
											board[7][3] = boxes[7][3];
											board[7][4] = boxes[7][4];
											board[7][5] = boxes[7][5];
											board[8][3] = boxes[7][6];
											board[8][4] = boxes[7][7];
											board[8][5] = boxes[7][8];

											printBoard(row, board, rstCounter);
											counterRounds = 0;
											i++;
										}
										else
											boxes.pop_back();
									}
									else
										boxes.pop_back();
								}
								else
									boxes.pop_back();
							}
							else
								boxes.pop_back();
						}
						else
							boxes.pop_back();
					}
					else
						boxes.pop_back();
				}
				else
					boxes.pop_back();
			}
			else
				boxes.pop_back();
		}
		else
			boxes.pop_back();
		}
		else if (i == 8)
		{
		if (boxNumbers[0] != boxes[6][0] && boxNumbers[0] != boxes[6][1] && boxNumbers[0] != boxes[6][2] && boxNumbers[0] != boxes[7][0] && boxNumbers[0] != boxes[7][1] && boxNumbers[0] != boxes[7][2] && boxNumbers[0] != boxes[2][0] && boxNumbers[0] != boxes[2][3] && boxNumbers[0] != boxes[2][6] && boxNumbers[0] != boxes[5][0] && boxNumbers[0] != boxes[5][3] && boxNumbers[0] != boxes[5][6])
		{
			if (boxNumbers[1] != boxes[6][0] && boxNumbers[1] != boxes[6][1] && boxNumbers[1] != boxes[6][2] && boxNumbers[1] != boxes[7][0] && boxNumbers[1] != boxes[7][1] && boxNumbers[1] != boxes[7][2] && boxNumbers[1] != boxes[2][1] && boxNumbers[1] != boxes[2][4] && boxNumbers[1] != boxes[2][7] && boxNumbers[1] != boxes[5][1] && boxNumbers[1] != boxes[5][4] && boxNumbers[1] != boxes[5][7])
			{
				if (boxNumbers[2] != boxes[6][0] && boxNumbers[2] != boxes[6][1] && boxNumbers[2] != boxes[6][2] && boxNumbers[2] != boxes[7][0] && boxNumbers[2] != boxes[7][1] && boxNumbers[2] != boxes[7][2] && boxNumbers[2] != boxes[2][2] && boxNumbers[2] != boxes[2][5] && boxNumbers[2] != boxes[2][8] && boxNumbers[2] != boxes[5][2] && boxNumbers[2] != boxes[5][5] && boxNumbers[2] != boxes[5][8])
				{
					if (boxNumbers[3] != boxes[6][3] && boxNumbers[3] != boxes[6][4] && boxNumbers[3] != boxes[6][5] && boxNumbers[3] != boxes[7][3] && boxNumbers[3] != boxes[7][4] && boxNumbers[3] != boxes[7][5] && boxNumbers[3] != boxes[2][0] && boxNumbers[3] != boxes[2][3] && boxNumbers[3] != boxes[2][6] && boxNumbers[3] != boxes[5][0] && boxNumbers[3] != boxes[5][3] && boxNumbers[3] != boxes[5][6])
					{
						if (boxNumbers[4] != boxes[6][3] && boxNumbers[4] != boxes[6][4] && boxNumbers[4] != boxes[6][5] && boxNumbers[4] != boxes[7][3] && boxNumbers[4] != boxes[7][4] && boxNumbers[4] != boxes[7][5] && boxNumbers[4] != boxes[2][1] && boxNumbers[4] != boxes[2][4] && boxNumbers[4] != boxes[2][7] && boxNumbers[4] != boxes[5][1] && boxNumbers[4] != boxes[5][4] && boxNumbers[4] != boxes[5][7])
						{
							if (boxNumbers[5] != boxes[6][3] && boxNumbers[5] != boxes[6][4] && boxNumbers[5] != boxes[6][5] && boxNumbers[5] != boxes[7][3] && boxNumbers[5] != boxes[7][4] && boxNumbers[5] != boxes[7][5] && boxNumbers[5] != boxes[2][2] && boxNumbers[5] != boxes[2][5] && boxNumbers[5] != boxes[2][8] && boxNumbers[5] != boxes[5][2] && boxNumbers[5] != boxes[5][5] && boxNumbers[5] != boxes[5][8])
							{
								if (boxNumbers[6] != boxes[6][6] && boxNumbers[6] != boxes[6][7] && boxNumbers[6] != boxes[6][8] && boxNumbers[6] != boxes[7][6] && boxNumbers[6] != boxes[7][7] && boxNumbers[6] != boxes[7][8] && boxNumbers[6] != boxes[2][0] && boxNumbers[6] != boxes[2][3] && boxNumbers[6] != boxes[2][6] && boxNumbers[6] != boxes[5][0] && boxNumbers[6] != boxes[5][3] && boxNumbers[6] != boxes[5][6])
								{
									if (boxNumbers[7] != boxes[6][6] && boxNumbers[7] != boxes[6][7] && boxNumbers[7] != boxes[6][8] && boxNumbers[7] != boxes[7][6] && boxNumbers[7] != boxes[7][7] && boxNumbers[7] != boxes[7][8] && boxNumbers[7] != boxes[2][1] && boxNumbers[7] != boxes[2][4] && boxNumbers[7] != boxes[2][7] && boxNumbers[7] != boxes[5][1] && boxNumbers[7] != boxes[5][4] && boxNumbers[7] != boxes[5][7])
									{
										if (boxNumbers[8] != boxes[6][6] && boxNumbers[8] != boxes[6][7] && boxNumbers[8] != boxes[6][8] && boxNumbers[8] != boxes[7][6] && boxNumbers[8] != boxes[7][7] && boxNumbers[8] != boxes[7][8] && boxNumbers[8] != boxes[2][2] && boxNumbers[8] != boxes[2][5] && boxNumbers[8] != boxes[2][8] && boxNumbers[8] != boxes[5][2] && boxNumbers[8] != boxes[5][5] && boxNumbers[8] != boxes[5][8])
										{
											system("cls");

											board[6][6] = boxes[8][0];
											board[6][7] = boxes[8][1];
											board[6][8] = boxes[8][2];
											board[7][6] = boxes[8][3];
											board[7][7] = boxes[8][4];
											board[7][8] = boxes[8][5];
											board[8][6] = boxes[8][6];
											board[8][7] = boxes[8][7];
											board[8][8] = boxes[8][8];

											printBoard(row, board, rstCounter);
											counterRounds = 0;
											i++;
										}
										else
											boxes.pop_back();
									}
									else
										boxes.pop_back();
								}
								else
									boxes.pop_back();
							}
							else
								boxes.pop_back();
						}
						else
							boxes.pop_back();
					}
					else
						boxes.pop_back();
				}
				else
					boxes.pop_back();
			}
			else
				boxes.pop_back();
		}
		else
			boxes.pop_back();
		}
	}

	system("cls");
}

void printBoard(int row, vector<vector<int>> board, int rstCounter) {

	//Line 0
	cout << "Resets: " << rstCounter << endl;
	cout << "------------" << endl << endl;

	//Line 1
	for (size_t i = 0; i < row; i++)
	{
		if (i < 1)
			cout << "  | ";
		char letter = i + 65;
		if (i == 3 || i == 6)
		{
			cout << "  ";
			cout << termcolor::cyan << letter << termcolor::reset << " ";
		}
		else
			cout << termcolor::cyan << letter << termcolor::reset << " ";
	}
	cout << endl;

	//Line 2
	for (size_t i = 0; i < 25; i++)
	{
		if (i == 2)
			cout << "|";
		else
			cout << "-";
	}
	cout << endl;

	//Rest of the lines
	for (size_t i = 0; i < row; i++)
	{
		char letter = i + 65;
		if (i == 3 || i == 6)
		{
			cout << "  | ";
			for (size_t i = 0; i < 21; i++)
				cout << "-";
			cout << endl;
			cout << termcolor::cyan << letter << termcolor::reset << " | ";
		}
		else
			cout << termcolor::cyan << letter << termcolor::reset << " | ";
		
		for (size_t j = 0; j < row; j++)
		{
			if (j == 3 || j == 6)
			{
				cout << "| ";
				cout << board[i][j] << " ";
			}
			else
				cout << board[i][j] << " ";
		}
			
		cout << endl;
	}
}
void printBoardToFile(int row, vector<vector<int>> board, int rstCounter) {

	ofstream result("Result.txt", ios::in | ios::app | ios::out);

	//Line 0
	result << "Resets: " << rstCounter << endl;
	result << "----------" << endl;

	//Board
	for (size_t i = 0; i < row; i++)
	{
		if (i == 3 || i == 6)
		{
			for (size_t i = 0; i < 21; i++)
				result << "-";
			result << endl;
		}

		for (size_t j = 0; j < row; j++)
		{
			if (j == 3 || j == 6)
			{
				result << "| ";
				result << board[i][j] << " ";
			}
			else
				result << board[i][j] << " ";
		}

		result << endl;
	}

	result << endl << endl;

	result.close();
}

void sudoku_Easy(int row, vector<vector<int>> board, int rangeEasy, int rstCounter)
{
	vector<vector<int>> easy(row, vector<int>(row));
	vector<int> sortEasy{};
	vector<vector<char>> sortEasyChar(9, vector<char>(9));

	int rnd{};
	int countEasy{};

	//Bulding the easy-vector
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
			easy[i][j] = board[i][j];
	}

	//Building the sort-vector
	for (size_t i = 0; i < rangeEasy; i++)
	{
		sortEasy.push_back(0);
	}

	//---------------------------------------------------------------

	//Delegate available numbers to the vector
	for (size_t i = 0; i < sortEasy.size();)
	{
		random_device rd;
		mt19937_64 gen(rd());
		uniform_int_distribution<int> RNG(1, 81);
		rnd = RNG(gen);

		for (size_t j = 0; j < sortEasy.size(); j++)
		{
			if (sortEasy[j] == rnd)
				j = sortEasy.size();
			else
				countEasy++;
		}

		if (countEasy >= sortEasy.size() - 1)
		{
			sortEasy[i] = rnd;

			countEasy = 0;
			i++;
		}
	}

	//Applying empty space to the "vector<vector<int>> easy"
	for (size_t i = 0; i < sortEasy.size(); i++)
	{
		if (sortEasy[i] == 1)
			easy[0][0] = 0;
		else if (sortEasy[i] == 2)
			easy[0][1] = 0;
		else if (sortEasy[i] == 3)
			easy[0][2] = 0;
		else if (sortEasy[i] == 4)
			easy[0][3] = 0;
		else if (sortEasy[i] == 5)
			easy[0][4] = 0;
		else if (sortEasy[i] == 6)
			easy[0][5] = 0;
		else if (sortEasy[i] == 7)
			easy[0][6] = 0;
		else if (sortEasy[i] == 8)
			easy[0][7] = 0;
		else if (sortEasy[i] == 9)
			easy[0][8] = 0;

		else if (sortEasy[i] == 10)
			easy[1][0] = 0;
		else if (sortEasy[i] == 11)
			easy[1][1] = 0;
		else if (sortEasy[i] == 12)
			easy[1][2] = 0;
		else if (sortEasy[i] == 13)
			easy[1][3] = 0;
		else if (sortEasy[i] == 14)
			easy[1][4] = 0;
		else if (sortEasy[i] == 15)
			easy[1][5] = 0;
		else if (sortEasy[i] == 16)
			easy[1][6] = 0;
		else if (sortEasy[i] == 17)
			easy[1][7] = 0;
		else if (sortEasy[i] == 18)
			easy[1][8] = 0;

		else if (sortEasy[i] == 19)
			easy[2][0] = 0;
		else if (sortEasy[i] == 20)
			easy[2][1] = 0;
		else if (sortEasy[i] == 21)
			easy[2][2] = 0;
		else if (sortEasy[i] == 22)
			easy[2][3] = 0;
		else if (sortEasy[i] == 23)
			easy[2][4] = 0;
		else if (sortEasy[i] == 24)
			easy[2][5] = 0;
		else if (sortEasy[i] == 25)
			easy[2][6] = 0;
		else if (sortEasy[i] == 26)
			easy[2][7] = 0;
		else if (sortEasy[i] == 27)
			easy[2][8] = 0;

		else if (sortEasy[i] == 28)
			easy[3][0] = 0;
		else if (sortEasy[i] == 29)
			easy[3][1] = 0;
		else if (sortEasy[i] == 30)
			easy[3][2] = 0;
		else if (sortEasy[i] == 31)
			easy[3][3] = 0;
		else if (sortEasy[i] == 32)
			easy[3][4] = 0;
		else if (sortEasy[i] == 33)
			easy[3][5] = 0;
		else if (sortEasy[i] == 34)
			easy[3][6] = 0;
		else if (sortEasy[i] == 35)
			easy[3][7] = 0;
		else if (sortEasy[i] == 36)
			easy[3][8] = 0;

		else if (sortEasy[i] == 37)
			easy[4][0] = 0;
		else if (sortEasy[i] == 38)
			easy[4][1] = 0;
		else if (sortEasy[i] == 39)
			easy[4][2] = 0;
		else if (sortEasy[i] == 40)
			easy[4][3] = 0;
		else if (sortEasy[i] == 41)
			easy[4][4] = 0;
		else if (sortEasy[i] == 42)
			easy[4][5] = 0;
		else if (sortEasy[i] == 43)
			easy[4][6] = 0;
		else if (sortEasy[i] == 44)
			easy[4][7] = 0;
		else if (sortEasy[i] == 45)
			easy[4][8] = 0;

		else if (sortEasy[i] == 46)
			easy[5][0] = 0;
		else if (sortEasy[i] == 47)
			easy[5][1] = 0;
		else if (sortEasy[i] == 48)
			easy[5][2] = 0;
		else if (sortEasy[i] == 49)
			easy[5][3] = 0;
		else if (sortEasy[i] == 50)
			easy[5][4] = 0;
		else if (sortEasy[i] == 51)
			easy[5][5] = 0;
		else if (sortEasy[i] == 52)
			easy[5][6] = 0;
		else if (sortEasy[i] == 53)
			easy[5][7] = 0;
		else if (sortEasy[i] == 54)
			easy[5][8] = 0;

		else if (sortEasy[i] == 55)
			easy[6][0] = 0;
		else if (sortEasy[i] == 56)
			easy[6][1] = 0;
		else if (sortEasy[i] == 57)
			easy[6][2] = 0;
		else if (sortEasy[i] == 58)
			easy[6][3] = 0;
		else if (sortEasy[i] == 59)
			easy[6][4] = 0;
		else if (sortEasy[i] == 60)
			easy[6][5] = 0;
		else if (sortEasy[i] == 61)
			easy[6][6] = 0;
		else if (sortEasy[i] == 62)
			easy[6][7] = 0;
		else if (sortEasy[i] == 63)
			easy[6][8] = 0;

		else if (sortEasy[i] == 64)
			easy[7][0] = 0;
		else if (sortEasy[i] == 65)
			easy[7][1] = 0;
		else if (sortEasy[i] == 66)
			easy[7][2] = 0;
		else if (sortEasy[i] == 67)
			easy[7][3] = 0;
		else if (sortEasy[i] == 68)
			easy[7][4] = 0;
		else if (sortEasy[i] == 69)
			easy[7][5] = 0;
		else if (sortEasy[i] == 70)
			easy[7][6] = 0;
		else if (sortEasy[i] == 71)
			easy[7][7] = 0;
		else if (sortEasy[i] == 72)
			easy[7][8] = 0;

		else if (sortEasy[i] == 73)
			easy[8][0] = 0;
		else if (sortEasy[i] == 74)
			easy[8][1] = 0;
		else if (sortEasy[i] == 75)
			easy[8][2] = 0;
		else if (sortEasy[i] == 76)
			easy[8][3] = 0;
		else if (sortEasy[i] == 77)
			easy[8][4] = 0;
		else if (sortEasy[i] == 78)
			easy[8][5] = 0;
		else if (sortEasy[i] == 79)
			easy[8][6] = 0;
		else if (sortEasy[i] == 80)
			easy[8][7] = 0;
		else if (sortEasy[i] == 81)
			easy[8][8] = 0;
	}

	//Converting to char
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			string tmp = std::to_string(easy[i][j]);

			sortEasyChar[i][j] = tmp[0];
		}	
	}

	//Removing all 0 to ' '
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			if (easy[i][j] == 0)
				sortEasyChar[i][j] = ' ';
		}
	}

	//---------------------------------------------------------------------------------------------------------------------

	//Printing the Board into a txt.-file
	ofstream sudoku_Easy("Sudoku_Easy.txt", ios::in | ios::app | ios::out);
	sudoku_Easy << "Resets: " << rstCounter << endl;
	sudoku_Easy << "----------" << endl;
	for (size_t i = 0; i < row; i++)
	{
		if (i == 3 || i == 6)
		{
			for (size_t i = 0; i < 21; i++)
				sudoku_Easy << "-";
			sudoku_Easy << endl;
		}

		for (size_t j = 0; j < row; j++)
		{
			if (j == 3 || j == 6)
			{
				sudoku_Easy << "| ";
				sudoku_Easy << sortEasyChar[i][j] << " ";
			}
			else
				sudoku_Easy << sortEasyChar[i][j] << " ";
		}

		sudoku_Easy << endl;
	}
	sudoku_Easy << endl << endl;
	sudoku_Easy.close();

	sortEasy.clear();
}
void sudoku_Normal(int row, vector<vector<int>> board, int rangeNormal, int rstCounter)
{
	vector<vector<int>> normal(row, vector<int>(row));
	vector<int> sortNormal{};
	vector<vector<char>> sortNormalChar(9, vector<char>(9));

	int rnd{};
	int countNormal{};

	//Bulding the easy-vector
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
			normal[i][j] = board[i][j];
	}

	//Building the sort-vector
	for (size_t i = 0; i < rangeNormal; i++)
	{
		sortNormal.push_back(0);
	}

	//---------------------------------------------------------------

	//Delegate available numbers to the vector
	for (size_t i = 0; i < sortNormal.size();)
	{
		random_device rd;
		mt19937_64 gen(rd());
		uniform_int_distribution<int> RNG(1, 81);
		rnd = RNG(gen);

		for (size_t j = 0; j < sortNormal.size(); j++)
		{
			if (sortNormal[j] == rnd)
				j = sortNormal.size();
			else
				countNormal++;
		}

		if (countNormal >= sortNormal.size() - 1)
		{
			sortNormal[i] = rnd;

			countNormal = 0;
			i++;
		}
	}

	//Applying empty space to the "vector<vector<int>> easy"
	for (size_t i = 0; i < sortNormal.size(); i++)
	{
		if (sortNormal[i] == 1)
			normal[0][0] = 0;
		else if (sortNormal[i] == 2)
			normal[0][1] = 0;
		else if (sortNormal[i] == 3)
			normal[0][2] = 0;
		else if (sortNormal[i] == 4)
			normal[0][3] = 0;
		else if (sortNormal[i] == 5)
			normal[0][4] = 0;
		else if (sortNormal[i] == 6)
			normal[0][5] = 0;
		else if (sortNormal[i] == 7)
			normal[0][6] = 0;
		else if (sortNormal[i] == 8)
			normal[0][7] = 0;
		else if (sortNormal[i] == 9)
			normal[0][8] = 0;

		else if (sortNormal[i] == 10)
			normal[1][0] = 0;
		else if (sortNormal[i] == 11)
			normal[1][1] = 0;
		else if (sortNormal[i] == 12)
			normal[1][2] = 0;
		else if (sortNormal[i] == 13)
			normal[1][3] = 0;
		else if (sortNormal[i] == 14)
			normal[1][4] = 0;
		else if (sortNormal[i] == 15)
			normal[1][5] = 0;
		else if (sortNormal[i] == 16)
			normal[1][6] = 0;
		else if (sortNormal[i] == 17)
			normal[1][7] = 0;
		else if (sortNormal[i] == 18)
			normal[1][8] = 0;

		else if (sortNormal[i] == 19)
			normal[2][0] = 0;
		else if (sortNormal[i] == 20)
			normal[2][1] = 0;
		else if (sortNormal[i] == 21)
			normal[2][2] = 0;
		else if (sortNormal[i] == 22)
			normal[2][3] = 0;
		else if (sortNormal[i] == 23)
			normal[2][4] = 0;
		else if (sortNormal[i] == 24)
			normal[2][5] = 0;
		else if (sortNormal[i] == 25)
			normal[2][6] = 0;
		else if (sortNormal[i] == 26)
			normal[2][7] = 0;
		else if (sortNormal[i] == 27)
			normal[2][8] = 0;

		else if (sortNormal[i] == 28)
			normal[3][0] = 0;
		else if (sortNormal[i] == 29)
			normal[3][1] = 0;
		else if (sortNormal[i] == 30)
			normal[3][2] = 0;
		else if (sortNormal[i] == 31)
			normal[3][3] = 0;
		else if (sortNormal[i] == 32)
			normal[3][4] = 0;
		else if (sortNormal[i] == 33)
			normal[3][5] = 0;
		else if (sortNormal[i] == 34)
			normal[3][6] = 0;
		else if (sortNormal[i] == 35)
			normal[3][7] = 0;
		else if (sortNormal[i] == 36)
			normal[3][8] = 0;

		else if (sortNormal[i] == 37)
			normal[4][0] = 0;
		else if (sortNormal[i] == 38)
			normal[4][1] = 0;
		else if (sortNormal[i] == 39)
			normal[4][2] = 0;
		else if (sortNormal[i] == 40)
			normal[4][3] = 0;
		else if (sortNormal[i] == 41)
			normal[4][4] = 0;
		else if (sortNormal[i] == 42)
			normal[4][5] = 0;
		else if (sortNormal[i] == 43)
			normal[4][6] = 0;
		else if (sortNormal[i] == 44)
			normal[4][7] = 0;
		else if (sortNormal[i] == 45)
			normal[4][8] = 0;

		else if (sortNormal[i] == 46)
			normal[5][0] = 0;
		else if (sortNormal[i] == 47)
			normal[5][1] = 0;
		else if (sortNormal[i] == 48)
			normal[5][2] = 0;
		else if (sortNormal[i] == 49)
			normal[5][3] = 0;
		else if (sortNormal[i] == 50)
			normal[5][4] = 0;
		else if (sortNormal[i] == 51)
			normal[5][5] = 0;
		else if (sortNormal[i] == 52)
			normal[5][6] = 0;
		else if (sortNormal[i] == 53)
			normal[5][7] = 0;
		else if (sortNormal[i] == 54)
			normal[5][8] = 0;

		else if (sortNormal[i] == 55)
			normal[6][0] = 0;
		else if (sortNormal[i] == 56)
			normal[6][1] = 0;
		else if (sortNormal[i] == 57)
			normal[6][2] = 0;
		else if (sortNormal[i] == 58)
			normal[6][3] = 0;
		else if (sortNormal[i] == 59)
			normal[6][4] = 0;
		else if (sortNormal[i] == 60)
			normal[6][5] = 0;
		else if (sortNormal[i] == 61)
			normal[6][6] = 0;
		else if (sortNormal[i] == 62)
			normal[6][7] = 0;
		else if (sortNormal[i] == 63)
			normal[6][8] = 0;

		else if (sortNormal[i] == 64)
			normal[7][0] = 0;
		else if (sortNormal[i] == 65)
			normal[7][1] = 0;
		else if (sortNormal[i] == 66)
			normal[7][2] = 0;
		else if (sortNormal[i] == 67)
			normal[7][3] = 0;
		else if (sortNormal[i] == 68)
			normal[7][4] = 0;
		else if (sortNormal[i] == 69)
			normal[7][5] = 0;
		else if (sortNormal[i] == 70)
			normal[7][6] = 0;
		else if (sortNormal[i] == 71)
			normal[7][7] = 0;
		else if (sortNormal[i] == 72)
			normal[7][8] = 0;

		else if (sortNormal[i] == 73)
			normal[8][0] = 0;
		else if (sortNormal[i] == 74)
			normal[8][1] = 0;
		else if (sortNormal[i] == 75)
			normal[8][2] = 0;
		else if (sortNormal[i] == 76)
			normal[8][3] = 0;
		else if (sortNormal[i] == 77)
			normal[8][4] = 0;
		else if (sortNormal[i] == 78)
			normal[8][5] = 0;
		else if (sortNormal[i] == 79)
			normal[8][6] = 0;
		else if (sortNormal[i] == 80)
			normal[8][7] = 0;
		else if (sortNormal[i] == 81)
			normal[8][8] = 0;
	}

	//Converting to char
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			string tmp = std::to_string(normal[i][j]);

			sortNormalChar[i][j] = tmp[0];
		}
	}

	//Removing all 0 to ' '
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			if (normal[i][j] == 0)
				sortNormalChar[i][j] = ' ';
		}
	}

	//---------------------------------------------------------------------------------------------------------------------

	//Printing the Board into a txt.-file
	ofstream sudoku_Normal("Sudoku_Normal.txt", ios::in | ios::app | ios::out);
	sudoku_Normal << "Resets: " << rstCounter << endl;
	sudoku_Normal << "----------" << endl;
	for (size_t i = 0; i < row; i++)
	{
		if (i == 3 || i == 6)
		{
			for (size_t i = 0; i < 21; i++)
				sudoku_Normal << "-";
			sudoku_Normal << endl;
		}

		for (size_t j = 0; j < row; j++)
		{
			if (j == 3 || j == 6)
			{
				sudoku_Normal << "| ";
				sudoku_Normal << sortNormalChar[i][j] << " ";
			}
			else
				sudoku_Normal << sortNormalChar[i][j] << " ";
		}

		sudoku_Normal << endl;
	}
	sudoku_Normal << endl << endl;
	sudoku_Normal.close();

	sortNormal.clear();
}
void sudoku_Hard(int row, vector<vector<int>> board, int rangeHard, int rstCounter)
{
	vector<vector<int>> hard(row, vector<int>(row));
	vector<int> sortHard{};
	vector<vector<char>> sortHardChar(9, vector<char>(9));

	int rnd{};
	int countHard{};

	//Bulding the easy-vector
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
			hard[i][j] = board[i][j];
	}

	//Building the sort-vector
	for (size_t i = 0; i < rangeHard; i++)
	{
		sortHard.push_back(0);
	}

	//---------------------------------------------------------------

	//Delegate available numbers to the vector
	for (size_t i = 0; i < sortHard.size();)
	{
		random_device rd;
		mt19937_64 gen(rd());
		uniform_int_distribution<int> RNG(1, 81);
		rnd = RNG(gen);

		for (size_t j = 0; j < sortHard.size(); j++)
		{
			if (sortHard[j] == rnd)
				j = sortHard.size();
			else
				countHard++;
		}

		if (countHard >= sortHard.size() - 1)
		{
			sortHard[i] = rnd;

			countHard = 0;
			i++;
		}
	}

	//Applying empty space to the "vector<vector<int>> easy"
	for (size_t i = 0; i < sortHard.size(); i++)
	{
		if (sortHard[i] == 1)
			hard[0][0] = 0;
		else if (sortHard[i] == 2)
			hard[0][1] = 0;
		else if (sortHard[i] == 3)
			hard[0][2] = 0;
		else if (sortHard[i] == 4)
			hard[0][3] = 0;
		else if (sortHard[i] == 5)
			hard[0][4] = 0;
		else if (sortHard[i] == 6)
			hard[0][5] = 0;
		else if (sortHard[i] == 7)
			hard[0][6] = 0;
		else if (sortHard[i] == 8)
			hard[0][7] = 0;
		else if (sortHard[i] == 9)
			hard[0][8] = 0;

		else if (sortHard[i] == 10)
			hard[1][0] = 0;
		else if (sortHard[i] == 11)
			hard[1][1] = 0;
		else if (sortHard[i] == 12)
			hard[1][2] = 0;
		else if (sortHard[i] == 13)
			hard[1][3] = 0;
		else if (sortHard[i] == 14)
			hard[1][4] = 0;
		else if (sortHard[i] == 15)
			hard[1][5] = 0;
		else if (sortHard[i] == 16)
			hard[1][6] = 0;
		else if (sortHard[i] == 17)
			hard[1][7] = 0;
		else if (sortHard[i] == 18)
			hard[1][8] = 0;

		else if (sortHard[i] == 19)
			hard[2][0] = 0;
		else if (sortHard[i] == 20)
			hard[2][1] = 0;
		else if (sortHard[i] == 21)
			hard[2][2] = 0;
		else if (sortHard[i] == 22)
			hard[2][3] = 0;
		else if (sortHard[i] == 23)
			hard[2][4] = 0;
		else if (sortHard[i] == 24)
			hard[2][5] = 0;
		else if (sortHard[i] == 25)
			hard[2][6] = 0;
		else if (sortHard[i] == 26)
			hard[2][7] = 0;
		else if (sortHard[i] == 27)
			hard[2][8] = 0;

		else if (sortHard[i] == 28)
			hard[3][0] = 0;
		else if (sortHard[i] == 29)
			hard[3][1] = 0;
		else if (sortHard[i] == 30)
			hard[3][2] = 0;
		else if (sortHard[i] == 31)
			hard[3][3] = 0;
		else if (sortHard[i] == 32)
			hard[3][4] = 0;
		else if (sortHard[i] == 33)
			hard[3][5] = 0;
		else if (sortHard[i] == 34)
			hard[3][6] = 0;
		else if (sortHard[i] == 35)
			hard[3][7] = 0;
		else if (sortHard[i] == 36)
			hard[3][8] = 0;

		else if (sortHard[i] == 37)
			hard[4][0] = 0;
		else if (sortHard[i] == 38)
			hard[4][1] = 0;
		else if (sortHard[i] == 39)
			hard[4][2] = 0;
		else if (sortHard[i] == 40)
			hard[4][3] = 0;
		else if (sortHard[i] == 41)
			hard[4][4] = 0;
		else if (sortHard[i] == 42)
			hard[4][5] = 0;
		else if (sortHard[i] == 43)
			hard[4][6] = 0;
		else if (sortHard[i] == 44)
			hard[4][7] = 0;
		else if (sortHard[i] == 45)
			hard[4][8] = 0;

		else if (sortHard[i] == 46)
			hard[5][0] = 0;
		else if (sortHard[i] == 47)
			hard[5][1] = 0;
		else if (sortHard[i] == 48)
			hard[5][2] = 0;
		else if (sortHard[i] == 49)
			hard[5][3] = 0;
		else if (sortHard[i] == 50)
			hard[5][4] = 0;
		else if (sortHard[i] == 51)
			hard[5][5] = 0;
		else if (sortHard[i] == 52)
			hard[5][6] = 0;
		else if (sortHard[i] == 53)
			hard[5][7] = 0;
		else if (sortHard[i] == 54)
			hard[5][8] = 0;

		else if (sortHard[i] == 55)
			hard[6][0] = 0;
		else if (sortHard[i] == 56)
			hard[6][1] = 0;
		else if (sortHard[i] == 57)
			hard[6][2] = 0;
		else if (sortHard[i] == 58)
			hard[6][3] = 0;
		else if (sortHard[i] == 59)
			hard[6][4] = 0;
		else if (sortHard[i] == 60)
			hard[6][5] = 0;
		else if (sortHard[i] == 61)
			hard[6][6] = 0;
		else if (sortHard[i] == 62)
			hard[6][7] = 0;
		else if (sortHard[i] == 63)
			hard[6][8] = 0;

		else if (sortHard[i] == 64)
			hard[7][0] = 0;
		else if (sortHard[i] == 65)
			hard[7][1] = 0;
		else if (sortHard[i] == 66)
			hard[7][2] = 0;
		else if (sortHard[i] == 67)
			hard[7][3] = 0;
		else if (sortHard[i] == 68)
			hard[7][4] = 0;
		else if (sortHard[i] == 69)
			hard[7][5] = 0;
		else if (sortHard[i] == 70)
			hard[7][6] = 0;
		else if (sortHard[i] == 71)
			hard[7][7] = 0;
		else if (sortHard[i] == 72)
			hard[7][8] = 0;

		else if (sortHard[i] == 73)
			hard[8][0] = 0;
		else if (sortHard[i] == 74)
			hard[8][1] = 0;
		else if (sortHard[i] == 75)
			hard[8][2] = 0;
		else if (sortHard[i] == 76)
			hard[8][3] = 0;
		else if (sortHard[i] == 77)
			hard[8][4] = 0;
		else if (sortHard[i] == 78)
			hard[8][5] = 0;
		else if (sortHard[i] == 79)
			hard[8][6] = 0;
		else if (sortHard[i] == 80)
			hard[8][7] = 0;
		else if (sortHard[i] == 81)
			hard[8][8] = 0;
	}

	//Converting to char
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			string tmp = std::to_string(hard[i][j]);

			sortHardChar[i][j] = tmp[0];
		}
	}

	//Removing all 0 to ' '
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			if (hard[i][j] == 0)
				sortHardChar[i][j] = ' ';
		}
	}

	//---------------------------------------------------------------------------------------------------------------------

	//Printing the Board into a txt.-file
	ofstream sudoku_Hard("Sudoku_Hard.txt", ios::in | ios::app | ios::out);
	sudoku_Hard << "Resets: " << rstCounter << endl;
	sudoku_Hard << "----------" << endl;
	for (size_t i = 0; i < row; i++)
	{
		if (i == 3 || i == 6)
		{
			for (size_t i = 0; i < 21; i++)
				sudoku_Hard << "-";
			sudoku_Hard << endl;
		}

		for (size_t j = 0; j < row; j++)
		{
			if (j == 3 || j == 6)
			{
				sudoku_Hard << "| ";
				sudoku_Hard << sortHardChar[i][j] << " ";
			}
			else
				sudoku_Hard << sortHardChar[i][j] << " ";
		}

		sudoku_Hard << endl;
	}
	sudoku_Hard << endl << endl;
	sudoku_Hard.close();

	sortHard.clear();
}
void sudoku_Expert(int row, vector<vector<int>> board, int rangeExpert, int rstCounter)
{
	vector<vector<int>> expert(row, vector<int>(row));
	vector<int> sortExpert{};
	vector<vector<char>> sortExpertChar(9, vector<char>(9));

	int rnd{};
	int countExpert{};

	//Bulding the easy-vector
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
			expert[i][j] = board[i][j];
	}

	//Building the sort-vector
	for (size_t i = 0; i < rangeExpert; i++)
	{
		sortExpert.push_back(0);
	}

	//---------------------------------------------------------------

	//Delegate available numbers to the vector
	for (size_t i = 0; i < sortExpert.size();)
	{
		random_device rd;
		mt19937_64 gen(rd());
		uniform_int_distribution<int> RNG(1, 81);
		rnd = RNG(gen);

		for (size_t j = 0; j < sortExpert.size(); j++)
		{
			if (sortExpert[j] == rnd)
				j = sortExpert.size();
			else
				countExpert++;
		}

		if (countExpert >= sortExpert.size() - 1)
		{
			sortExpert[i] = rnd;

			countExpert = 0;
			i++;
		}
	}

	//Applying empty space to the "vector<vector<int>> easy"
	for (size_t i = 0; i < sortExpert.size(); i++)
	{
		if (sortExpert[i] == 1)
			expert[0][0] = 0;
		else if (sortExpert[i] == 2)
			expert[0][1] = 0;
		else if (sortExpert[i] == 3)
			expert[0][2] = 0;
		else if (sortExpert[i] == 4)
			expert[0][3] = 0;
		else if (sortExpert[i] == 5)
			expert[0][4] = 0;
		else if (sortExpert[i] == 6)
			expert[0][5] = 0;
		else if (sortExpert[i] == 7)
			expert[0][6] = 0;
		else if (sortExpert[i] == 8)
			expert[0][7] = 0;
		else if (sortExpert[i] == 9)
			expert[0][8] = 0;

		else if (sortExpert[i] == 10)
			expert[1][0] = 0;
		else if (sortExpert[i] == 11)
			expert[1][1] = 0;
		else if (sortExpert[i] == 12)
			expert[1][2] = 0;
		else if (sortExpert[i] == 13)
			expert[1][3] = 0;
		else if (sortExpert[i] == 14)
			expert[1][4] = 0;
		else if (sortExpert[i] == 15)
			expert[1][5] = 0;
		else if (sortExpert[i] == 16)
			expert[1][6] = 0;
		else if (sortExpert[i] == 17)
			expert[1][7] = 0;
		else if (sortExpert[i] == 18)
			expert[1][8] = 0;

		else if (sortExpert[i] == 19)
			expert[2][0] = 0;
		else if (sortExpert[i] == 20)
			expert[2][1] = 0;
		else if (sortExpert[i] == 21)
			expert[2][2] = 0;
		else if (sortExpert[i] == 22)
			expert[2][3] = 0;
		else if (sortExpert[i] == 23)
			expert[2][4] = 0;
		else if (sortExpert[i] == 24)
			expert[2][5] = 0;
		else if (sortExpert[i] == 25)
			expert[2][6] = 0;
		else if (sortExpert[i] == 26)
			expert[2][7] = 0;
		else if (sortExpert[i] == 27)
			expert[2][8] = 0;

		else if (sortExpert[i] == 28)
			expert[3][0] = 0;
		else if (sortExpert[i] == 29)
			expert[3][1] = 0;
		else if (sortExpert[i] == 30)
			expert[3][2] = 0;
		else if (sortExpert[i] == 31)
			expert[3][3] = 0;
		else if (sortExpert[i] == 32)
			expert[3][4] = 0;
		else if (sortExpert[i] == 33)
			expert[3][5] = 0;
		else if (sortExpert[i] == 34)
			expert[3][6] = 0;
		else if (sortExpert[i] == 35)
			expert[3][7] = 0;
		else if (sortExpert[i] == 36)
			expert[3][8] = 0;

		else if (sortExpert[i] == 37)
			expert[4][0] = 0;
		else if (sortExpert[i] == 38)
			expert[4][1] = 0;
		else if (sortExpert[i] == 39)
			expert[4][2] = 0;
		else if (sortExpert[i] == 40)
			expert[4][3] = 0;
		else if (sortExpert[i] == 41)
			expert[4][4] = 0;
		else if (sortExpert[i] == 42)
			expert[4][5] = 0;
		else if (sortExpert[i] == 43)
			expert[4][6] = 0;
		else if (sortExpert[i] == 44)
			expert[4][7] = 0;
		else if (sortExpert[i] == 45)
			expert[4][8] = 0;

		else if (sortExpert[i] == 46)
			expert[5][0] = 0;
		else if (sortExpert[i] == 47)
			expert[5][1] = 0;
		else if (sortExpert[i] == 48)
			expert[5][2] = 0;
		else if (sortExpert[i] == 49)
			expert[5][3] = 0;
		else if (sortExpert[i] == 50)
			expert[5][4] = 0;
		else if (sortExpert[i] == 51)
			expert[5][5] = 0;
		else if (sortExpert[i] == 52)
			expert[5][6] = 0;
		else if (sortExpert[i] == 53)
			expert[5][7] = 0;
		else if (sortExpert[i] == 54)
			expert[5][8] = 0;

		else if (sortExpert[i] == 55)
			expert[6][0] = 0;
		else if (sortExpert[i] == 56)
			expert[6][1] = 0;
		else if (sortExpert[i] == 57)
			expert[6][2] = 0;
		else if (sortExpert[i] == 58)
			expert[6][3] = 0;
		else if (sortExpert[i] == 59)
			expert[6][4] = 0;
		else if (sortExpert[i] == 60)
			expert[6][5] = 0;
		else if (sortExpert[i] == 61)
			expert[6][6] = 0;
		else if (sortExpert[i] == 62)
			expert[6][7] = 0;
		else if (sortExpert[i] == 63)
			expert[6][8] = 0;

		else if (sortExpert[i] == 64)
			expert[7][0] = 0;
		else if (sortExpert[i] == 65)
			expert[7][1] = 0;
		else if (sortExpert[i] == 66)
			expert[7][2] = 0;
		else if (sortExpert[i] == 67)
			expert[7][3] = 0;
		else if (sortExpert[i] == 68)
			expert[7][4] = 0;
		else if (sortExpert[i] == 69)
			expert[7][5] = 0;
		else if (sortExpert[i] == 70)
			expert[7][6] = 0;
		else if (sortExpert[i] == 71)
			expert[7][7] = 0;
		else if (sortExpert[i] == 72)
			expert[7][8] = 0;

		else if (sortExpert[i] == 73)
			expert[8][0] = 0;
		else if (sortExpert[i] == 74)
			expert[8][1] = 0;
		else if (sortExpert[i] == 75)
			expert[8][2] = 0;
		else if (sortExpert[i] == 76)
			expert[8][3] = 0;
		else if (sortExpert[i] == 77)
			expert[8][4] = 0;
		else if (sortExpert[i] == 78)
			expert[8][5] = 0;
		else if (sortExpert[i] == 79)
			expert[8][6] = 0;
		else if (sortExpert[i] == 80)
			expert[8][7] = 0;
		else if (sortExpert[i] == 81)
			expert[8][8] = 0;
	}

	//Converting to char
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			string tmp = std::to_string(expert[i][j]);

			sortExpertChar[i][j] = tmp[0];
		}
	}

	//Removing all 0 to ' '
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			if (expert[i][j] == 0)
				sortExpertChar[i][j] = ' ';
		}
	}

	//---------------------------------------------------------------------------------------------------------------------

	//Printing the Board into a txt.-file
	ofstream sudoku_Expert("Sudoku_Expert.txt", ios::in | ios::app | ios::out);
	sudoku_Expert << "Resets: " << rstCounter << endl;
	sudoku_Expert << "----------" << endl;
	for (size_t i = 0; i < row; i++)
	{
		if (i == 3 || i == 6)
		{
			for (size_t i = 0; i < 21; i++)
				sudoku_Expert << "-";
			sudoku_Expert << endl;
		}

		for (size_t j = 0; j < row; j++)
		{
			if (j == 3 || j == 6)
			{
				sudoku_Expert << "| ";
				sudoku_Expert << sortExpertChar[i][j] << " ";
			}
			else
				sudoku_Expert << sortExpertChar[i][j] << " ";
		}

		sudoku_Expert << endl;
	}
	sudoku_Expert << endl << endl;
	sudoku_Expert.close();

	sortExpert.clear();
}
void sudoku_Impossible(int row, vector<vector<int>> board, int rangeImpossible, int rstCounter)
{
	vector<vector<int>> impossible(row, vector<int>(row));
	vector<int> sortImpossible{};
	vector<vector<char>> sortImpossibleChar(9, vector<char>(9));

	int rnd{};
	int countImpossible{};

	//Bulding the easy-vector
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
			impossible[i][j] = board[i][j];
	}

	//Building the sort-vector
	for (size_t i = 0; i < rangeImpossible; i++)
	{
		sortImpossible.push_back(0);
	}

	//---------------------------------------------------------------

	//Delegate available numbers to the vector
	for (size_t i = 0; i < sortImpossible.size();)
	{
		random_device rd;
		mt19937_64 gen(rd());
		uniform_int_distribution<int> RNG(1, 81);
		rnd = RNG(gen);

		for (size_t j = 0; j < sortImpossible.size(); j++)
		{
			if (sortImpossible[j] == rnd)
				j = sortImpossible.size();
			else
				countImpossible++;
		}

		if (countImpossible >= sortImpossible.size() - 1)
		{
			sortImpossible[i] = rnd;

			countImpossible = 0;
			i++;
		}
	}

	//Applying empty space to the "vector<vector<int>> easy"
	for (size_t i = 0; i < sortImpossible.size(); i++)
	{
		if (sortImpossible[i] == 1)
			impossible[0][0] = 0;
		else if (sortImpossible[i] == 2)
			impossible[0][1] = 0;
		else if (sortImpossible[i] == 3)
			impossible[0][2] = 0;
		else if (sortImpossible[i] == 4)
			impossible[0][3] = 0;
		else if (sortImpossible[i] == 5)
			impossible[0][4] = 0;
		else if (sortImpossible[i] == 6)
			impossible[0][5] = 0;
		else if (sortImpossible[i] == 7)
			impossible[0][6] = 0;
		else if (sortImpossible[i] == 8)
			impossible[0][7] = 0;
		else if (sortImpossible[i] == 9)
			impossible[0][8] = 0;

		else if (sortImpossible[i] == 10)
			impossible[1][0] = 0;
		else if (sortImpossible[i] == 11)
			impossible[1][1] = 0;
		else if (sortImpossible[i] == 12)
			impossible[1][2] = 0;
		else if (sortImpossible[i] == 13)
			impossible[1][3] = 0;
		else if (sortImpossible[i] == 14)
			impossible[1][4] = 0;
		else if (sortImpossible[i] == 15)
			impossible[1][5] = 0;
		else if (sortImpossible[i] == 16)
			impossible[1][6] = 0;
		else if (sortImpossible[i] == 17)
			impossible[1][7] = 0;
		else if (sortImpossible[i] == 18)
			impossible[1][8] = 0;

		else if (sortImpossible[i] == 19)
			impossible[2][0] = 0;
		else if (sortImpossible[i] == 20)
			impossible[2][1] = 0;
		else if (sortImpossible[i] == 21)
			impossible[2][2] = 0;
		else if (sortImpossible[i] == 22)
			impossible[2][3] = 0;
		else if (sortImpossible[i] == 23)
			impossible[2][4] = 0;
		else if (sortImpossible[i] == 24)
			impossible[2][5] = 0;
		else if (sortImpossible[i] == 25)
			impossible[2][6] = 0;
		else if (sortImpossible[i] == 26)
			impossible[2][7] = 0;
		else if (sortImpossible[i] == 27)
			impossible[2][8] = 0;

		else if (sortImpossible[i] == 28)
			impossible[3][0] = 0;
		else if (sortImpossible[i] == 29)
			impossible[3][1] = 0;
		else if (sortImpossible[i] == 30)
			impossible[3][2] = 0;
		else if (sortImpossible[i] == 31)
			impossible[3][3] = 0;
		else if (sortImpossible[i] == 32)
			impossible[3][4] = 0;
		else if (sortImpossible[i] == 33)
			impossible[3][5] = 0;
		else if (sortImpossible[i] == 34)
			impossible[3][6] = 0;
		else if (sortImpossible[i] == 35)
			impossible[3][7] = 0;
		else if (sortImpossible[i] == 36)
			impossible[3][8] = 0;

		else if (sortImpossible[i] == 37)
			impossible[4][0] = 0;
		else if (sortImpossible[i] == 38)
			impossible[4][1] = 0;
		else if (sortImpossible[i] == 39)
			impossible[4][2] = 0;
		else if (sortImpossible[i] == 40)
			impossible[4][3] = 0;
		else if (sortImpossible[i] == 41)
			impossible[4][4] = 0;
		else if (sortImpossible[i] == 42)
			impossible[4][5] = 0;
		else if (sortImpossible[i] == 43)
			impossible[4][6] = 0;
		else if (sortImpossible[i] == 44)
			impossible[4][7] = 0;
		else if (sortImpossible[i] == 45)
			impossible[4][8] = 0;

		else if (sortImpossible[i] == 46)
			impossible[5][0] = 0;
		else if (sortImpossible[i] == 47)
			impossible[5][1] = 0;
		else if (sortImpossible[i] == 48)
			impossible[5][2] = 0;
		else if (sortImpossible[i] == 49)
			impossible[5][3] = 0;
		else if (sortImpossible[i] == 50)
			impossible[5][4] = 0;
		else if (sortImpossible[i] == 51)
			impossible[5][5] = 0;
		else if (sortImpossible[i] == 52)
			impossible[5][6] = 0;
		else if (sortImpossible[i] == 53)
			impossible[5][7] = 0;
		else if (sortImpossible[i] == 54)
			impossible[5][8] = 0;

		else if (sortImpossible[i] == 55)
			impossible[6][0] = 0;
		else if (sortImpossible[i] == 56)
			impossible[6][1] = 0;
		else if (sortImpossible[i] == 57)
			impossible[6][2] = 0;
		else if (sortImpossible[i] == 58)
			impossible[6][3] = 0;
		else if (sortImpossible[i] == 59)
			impossible[6][4] = 0;
		else if (sortImpossible[i] == 60)
			impossible[6][5] = 0;
		else if (sortImpossible[i] == 61)
			impossible[6][6] = 0;
		else if (sortImpossible[i] == 62)
			impossible[6][7] = 0;
		else if (sortImpossible[i] == 63)
			impossible[6][8] = 0;

		else if (sortImpossible[i] == 64)
			impossible[7][0] = 0;
		else if (sortImpossible[i] == 65)
			impossible[7][1] = 0;
		else if (sortImpossible[i] == 66)
			impossible[7][2] = 0;
		else if (sortImpossible[i] == 67)
			impossible[7][3] = 0;
		else if (sortImpossible[i] == 68)
			impossible[7][4] = 0;
		else if (sortImpossible[i] == 69)
			impossible[7][5] = 0;
		else if (sortImpossible[i] == 70)
			impossible[7][6] = 0;
		else if (sortImpossible[i] == 71)
			impossible[7][7] = 0;
		else if (sortImpossible[i] == 72)
			impossible[7][8] = 0;

		else if (sortImpossible[i] == 73)
			impossible[8][0] = 0;
		else if (sortImpossible[i] == 74)
			impossible[8][1] = 0;
		else if (sortImpossible[i] == 75)
			impossible[8][2] = 0;
		else if (sortImpossible[i] == 76)
			impossible[8][3] = 0;
		else if (sortImpossible[i] == 77)
			impossible[8][4] = 0;
		else if (sortImpossible[i] == 78)
			impossible[8][5] = 0;
		else if (sortImpossible[i] == 79)
			impossible[8][6] = 0;
		else if (sortImpossible[i] == 80)
			impossible[8][7] = 0;
		else if (sortImpossible[i] == 81)
			impossible[8][8] = 0;
	}

	//Converting to char
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			string tmp = std::to_string(impossible[i][j]);

			sortImpossibleChar[i][j] = tmp[0];
		}
	}

	//Removing all 0 to ' '
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			if (impossible[i][j] == 0)
				sortImpossibleChar[i][j] = ' ';
		}
	}

	//---------------------------------------------------------------------------------------------------------------------

	//Printing the Board into a txt.-file
	ofstream sudoku_Impossible("Sudoku_Impossible.txt", ios::in | ios::app | ios::out);
	sudoku_Impossible << "Resets: " << rstCounter << endl;
	sudoku_Impossible << "----------" << endl;
	for (size_t i = 0; i < row; i++)
	{
		if (i == 3 || i == 6)
		{
			for (size_t i = 0; i < 21; i++)
				sudoku_Impossible << "-";
			sudoku_Impossible << endl;
		}

		for (size_t j = 0; j < row; j++)
		{
			if (j == 3 || j == 6)
			{
				sudoku_Impossible << "| ";
				sudoku_Impossible << sortImpossibleChar[i][j] << " ";
			}
			else
				sudoku_Impossible << sortImpossibleChar[i][j] << " ";
		}

		sudoku_Impossible << endl;
	}
	sudoku_Impossible << endl << endl;
	sudoku_Impossible.close();

	sortImpossible.clear();
}