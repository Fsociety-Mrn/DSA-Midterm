#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
	int largest = root; // root is the largest element
	int l = 2 * root + 1; // left = 2*root + 1
	int r = 2 * root + 2; // right = 2*root + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != root)
	{
		//swap root and largest
		swap(arr[root], arr[largest]);

		// Recursively heapify the sub-tree
		heapify(arr, n, largest);
	}
}

void heapi(int arr[], int n, int root)
{
	int largest = root; // root is the largest element
	int l = 2 * root + 1; // left = 2*root + 1
	int r = 2 * root + 2; // right = 2*root + 2

	// If left child is larger than root
	if (l < n && arr[l] < arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] < arr[largest])
		largest = r;

	// If largest is not root
	if (largest != root)
	{
		//swap root and largest
		swap(arr[root], arr[largest]);

		// Recursively heapify the sub-tree
		heapify(arr, n, largest);
	}
}
// implementing heap sort
void ascending_sort(int arr[], int n)
{
	// build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// extracting elements from heap one by one
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// again call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// implementing heap sort
void descending_sort(int arr[], int n)
{
	// build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapi(arr, n, i);

	// extracting elements from heap one by one
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// again call max heapify on the reduced heap
		heapi(arr, i, 0);
	}
}

/* print contents of array - utility function */void displayArray(int arr[], int n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// main program
int main()
{
	system("cls");
	int heap_arr[] = {0}, size;
	cout << "HEAP SORTING" << endl << endl;
	cout << "enter size of the list: ";
	cin >> size;
	cout << endl;

	for (int i = 0; i < size; i++){
		cout << "Element " << 1 + i << ": ";
		cin >> heap_arr[i];
	}

	system("cls");
	cout << "size of the list: "<<size<<endl<<endl;
	cout << "Enter value of the List: " << endl;
	displayArray(heap_arr, size);
	ascending_sort(heap_arr, size);
	cout << "\nSorted in ascending: "<<endl;
	displayArray(heap_arr, size);
	descending_sort(heap_arr, size);
	cout << "\nSorted in descending: " << endl;
	displayArray(heap_arr, size);
	
	system("pause");
	return main();
}