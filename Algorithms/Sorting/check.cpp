#include <bits/stdc++.h>
using namespace std;


/* Radix sort */

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[],int n)
{
	int m = getMax(arr,n);

	for(int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr,n,exp);
}


/* Min Heap */

void minHeapify(int arr[],int index,int n)
{
	int smallest = index;
	int left = 2*index + 1;
	int right = 2*index + 2;

	if(left<n && arr[left] < arr[index])
		smallest = left;
	else
		smallest = index;

	if(right<n && arr[right] < arr[smallest])
		smallest = right;

	if(smallest != index)
	{
		swap(arr[smallest],arr[index]);
		minHeapify(arr,smallest,n);
	}

}

void buildMinHeap(int arr[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
		minHeapify(arr,i,n);
}


void min_sort(int arr[],int n)
{
	int i;
	for(i=n-1;i>=1;i--)
	{
		swap(arr[0],arr[i]);
		n = n-1;
		minHeapify(arr,0,n);
	}
}

/* (MaxHeap) Heap sort */

void maxHeapify(int arr[],int index, int n)
{
	int largest = index;
	int left = 2*index + 1;
	int right = 2*index + 2;

	if(left < n && arr[left] > arr[index])
		largest = left;
	else
		largest = index;

	if(right < n && arr[right] > arr[largest])
		largest = right;

	if(largest != index)
	{
		swap(arr[index],arr[largest]);
		maxHeapify(arr,largest,n);
	}
}

void buildHeap(int arr[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
		maxHeapify(arr,i,n);
}

void max_HeapSort(int arr[],int n)
{
	int i;

	for(i=n-1;i>=1;i--)
	{
		swap(arr[0],arr[i]);
		n = n-1;
		maxHeapify(arr,0,n);
	}
}

/* Merge Sort */

void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1] , R[n2];

	for(i=0;i<n1;i++) L[i]=arr[l+i];
	for(j=0;j<n2;j++) R[j]=arr[m+1+j];	

	i=j=0;
	k=l;

	while(i<n1 && j<n2)
	{
		if(L[i] >= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while(i<n1)
		arr[k++]=L[i++];

	while(j<n2)
		arr[k++]=R[j++];

}	

void mergeSort(int arr[],int l,int r)
{
	if(r > l)
	{
		int m = l + (r-l)/2;

		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}

int main()
{
	int n;
	cin >> n;

	int arr[n];
	int i;
	for(i=0;i<n;i++) cin >> arr[i];

	// mergeSort(arr,0,n-1);
	// buildHeap(arr,n);
	// max_HeapSort(arr,n);

	// buildMinHeap(arr,n);
	// min_sort(arr,n);

	radixSort(arr,n);	
	
	for(i=0;i<n;i++) cout << arr[i] << " ";
	cout << "\n";	
}