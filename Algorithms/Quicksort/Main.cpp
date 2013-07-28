#include<iostream>

#define SORT_SIZE 8

using namespace std;

void Swap(int a[], int left, int right)
{
	if(left == right) return;

	int temp = a[right];
	a[right] = a[left];
	a[left]  = temp;
}

int Partition(int a[], int left, int right)
{
	// store pivot at the end of this subsequence
	int pivot = left; // this can be calculated in any way
	int lessIndex = left;
	int value = a[pivot];

	Swap(a, pivot, right);

	for(int i = left; i < right; ++i){
		if(a[i] < value){
			Swap(a, lessIndex, i);
			++lessIndex;
		}
	}

	// check if there were any values less than 0 (lessIndex will be 0 if pivot was smallest value)
	if(lessIndex == 0){
		Swap(a, 0, right);
		return 0;
	}
	else{
		Swap(a, lessIndex, right);
		return lessIndex;
	}
}

void Quicksort(int a[], int left, int right)
{
	if(left >= right) return;

	int pivot = Partition(a, left, right);

	Quicksort(a, left, pivot - 1);
	Quicksort(a, pivot + 1, right);
}


int main(int argc, char** argv)
{
	int a[] = {2, 4, 5, 1, 3, 4, 0, 5};
	Quicksort(a, 0, SORT_SIZE - 1);

	for(int i = 0; i < SORT_SIZE; ++i){
		cout << a[i] << " ";
	}

	cin.get();
	return 0;
}