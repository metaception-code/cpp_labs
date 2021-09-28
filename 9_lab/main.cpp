#include "A2D08.h"

int main()
{
	int N, M;
	fstream f;
	f.open("input.txt", ios_base::in);
	f >> N >> M;

	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			f >> arr[i][j];
		}
	}

	f.close();
	calc(arr, N, M);
	return 0;
}