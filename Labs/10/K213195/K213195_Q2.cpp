#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
	public:

	char data;
	int freq;
	Node *left, *right;

	Node(char data, int freq){
		this->data = data;
		this->freq = freq;
		left = right = NULL;
	}
};

class MinHeap
{
	public:
	int size;
	int capacity;
	Node** array;
	
	MinHeap* createMinHeap(int capacity)
	{
		this->capacity = capacity;
		this->size = size;
		MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
		minHeap->size = 0;
	
		minHeap->capacity = capacity;
	
		minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
		return minHeap;
	}
	
	void swap(Node** a, Node** b)
	{
		Node* t = *a;
		*a = *b;
		*b = t;
	}
	
	void minHeapify(MinHeap* minHeap, int i)
	{
		int smallest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
	
		if (left < minHeap->size && minHeap->array[left]-> freq < minHeap->array[smallest]->freq)
			smallest = left;
	
		if (right < minHeap->size && minHeap->array[right]-> freq < minHeap->array[smallest]->freq)
			smallest = right;
		
		// if root is not the smallest

		if (smallest != i) 
		{
			swap(&minHeap->array[smallest],&minHeap->array[i]);
			minHeapify(minHeap, smallest);
		}
	}
	
	int isSizeOne(MinHeap* minHeap)
	{
		return (minHeap->size == 1);
	}
	
	Node* extractMin(MinHeap* minHeap)
	{
		Node* temp = minHeap->array[0];
		minHeap->array[0] = minHeap->array[minHeap->size - 1];
	
		--minHeap->size;
		minHeapify(minHeap, 0);
	
		return temp;
	}
	
	void insertMinHeap(MinHeap* minHeap, Node* minHeapNode)
	{
		++minHeap->size;
		int i = minHeap->size - 1;
	
		while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) 
		{
	
			minHeap->array[i] = minHeap->array[(i - 1) / 2];
			i = (i - 1) / 2;
		}
	
		minHeap->array[i] = minHeapNode;
	}
	
	void buildMinHeap(MinHeap* minHeap)
	{
		int n = minHeap->size - 1;
		int i;
	
		for (i = (n - 1) / 2; i >= 0; --i)
			minHeapify(minHeap, i);
	}
	
	int isLeaf(Node* root)
	{
		return !(root->left) && !(root->right);
	}
	
	MinHeap* BuildMinHeap(char data[], int freq[], int size)
	{
		MinHeap* minHeap = createMinHeap(size);
	
		for (int i = 0; i < size; ++i)
			minHeap->array[i] = new Node(data[i], freq[i]);
	
		minHeap->size = size;
		buildMinHeap(minHeap);
	
		return minHeap;
	}
	
	Node* buildTree(char data[], int freq[], int size)
	{
		Node*left, *right, *top;
	
		MinHeap* minHeap = BuildMinHeap(data, freq, size);
		
		while (!isSizeOne(minHeap))
		{
			left = extractMin(minHeap);
			right = extractMin(minHeap);
	
	// '!' is a special value for internal nodes
			top = new Node('!', left->freq + right->freq);
	
			top->left = left;
			top->right = right;
	
			insertMinHeap(minHeap, top);
		}
	
		return extractMin(minHeap);
	}
	
	void print(Node* root, int arr[], int top)
	{
		if (root->left) 
		{
	
			arr[top] = 0;
			print(root->left, arr, top + 1);
		}
	
		if (root->right) 
		{	
			arr[top] = 1;
			print(root->right, arr, top + 1);
		}

		if (isLeaf(root)) 
		{
			cout <<"\n "<< root->data <<" =  ";
			for (int i = 0; i < top; ++i)
				cout<< arr[i];		
		}
	}
	
	Node * Huffman(char data[], int freq[], int size)
	{
		Node* root = buildTree(data, freq, size);
	
		int arr[100], top = 0;
		return root;
	}

	void decode_huff(Node* root,string st)
	{
	    string str = "";
	    Node *current =root;
	    for(int i=0;i<st.size();i++)
		{
	        if(st[i]=='0') 
				current = current->left;
	        else 
				current = current->right;
	        if(!current->left && !current->right) //reached leaf node
			{ 
	            str = str + current->data;
	            current=root;
	        }
	    }
	    cout<<str<<endl;
	}
	
};

int main()
{
	char arr[] = { 'a', 'b', 'c', 'd' };
	int freq[] = { 6, 3, 1, 4};

	int size = sizeof(arr) / sizeof(arr[0]);
	
	MinHeap hm;
	Node *root;
	root = hm.Huffman(arr, freq, size);
	hm.decode_huff(root, "010110111");
	return 0;
}

