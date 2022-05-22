#include "vector.h"
#include "matrix.h"

int main()
{
	TVector<int> vector1;
	TVector<int> vector2(3, 5);
	TVector<int> vector3(vector2);
	vector1.Resize(3);
	std::cin >> vector2;
	for (int i = 0; i < vector1.GetLen(); i++)
		vector1[i] = rand() % 50 + 10;

	vector3 = vector1 + vector2;
	std::cout << "vector3 = vector1 + vector2 =\n" << vector1 << "+  " << vector2 << "=  " << vector3 << "\n";
	vector3 = vector1 - vector2;
	std::cout << "vector3 = vector1 - vector2 =\n" << vector1 << "-  " << vector2 << "=  " << vector3 << "\n";
	vector1 = vector2 * vector3;
	std::cout << "vector1 = vector2 * vector3 =\n" << vector2 << "*  " << vector3 << "=  " << vector1 << "\n";
	vector3 = vector1 / vector2;
	std::cout << "vector3 = vector1 / vector2 =\n" << vector1 << "/  " << vector2 << "=  " << vector3 << "\n";

	TMatrix<int> matrix1;
	TMatrix<int> matrix2(4, 4);
	TMatrix<int> matrix3(Matrix2);
	TMatrix<int> matrix4(3, 2);
	int** indexes;
	std::cin >> matrix2;
	std::cout << matrix2;

	for (int i = 0; i < matrix3.GetWidth(); i++)
		for (int j = 0; j < matrix3.GetLen(); j++)
			matrix3[i][j] = rand();
	std::cout << "matrix3 = \n" << matrix3;

	matrix1 = matrix2 + matrix3;
	std::cout << "matrix1 = matrix2 + matrix3 =\n"
		<< matrix2 << "\n + \n\n" << matrix3 << "\n = \n\n" << matrix1 << "\n";

	matrix2 = matrix3 - matrix1;
	std::cout << "matrix2 = matrix3 - matrix1 =\n"
		<< matrix3 << "\n - \n\n" << matrix1 << "\n = \n\n" << matrix2 << "\n";

	matrix1.Resize(2, 2);
	matrix2.Resize(2, 2);
	matrix3.Resize(2, 2);
	matrix3 = matrix2 * matrix1;
	std::cout << "matrix3 = matrix2 * matrix1 =\n"
		<< matrix2 << "\n * \n\n" << matrix1 << "\n = \n\n" << matrix3 << "\n";

	for (int i = 0; i < matrix4.GetWidth(); i++)
		for (int j = 0; j < matrix4.GetLen(); j++)
			matrix4[i][j] = rand() % 50;
	vector1 = matrix4 * vector2;
	std::cout << "vector1 = matrix4 * vector2 = \n" << matrix4 << "\n *\n\n" << vector2 << "\n\n =\n\n" << vector1;


	vector1.QuickSort();
	std::cout << "vector1 = " << vector1;

	TMatrix<int> matrix5(vector2.GetLen(), matrix4.GetLen());
	matrix4.Resize(1, matrix4.GetLen());
	matrix5 = vector2 * matrix4;
	std::cout << "matrix5 = vector2 * matrix4 = \n" << vector2 << "\n *\n\n" << matrix4
		<< "\n\n = \n\n" << matrix5;

	return 0;
}