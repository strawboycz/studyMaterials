#include <chrono>
#include<iostream>
#include <queue>
#include <random>
#include <stack>
#include <vector>
using namespace std;
using namespace chrono;
int getSumOfN(int n)
{
	if (n < 1) return 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += i;
	return sum;
}
bool contains(vector<int> & arr, int item)
{
	for(auto element : arr)
	{
		if (element == item) return true;
	}
	return false;
}
void removeDividables(vector<int>& arr, int item)
{
	auto it = arr.begin();
	while (it != arr.end())
	{
		if (*it % item == 0 && *it != item)
		{
			it = arr.erase(it);
		}
		else
		{
			++it;
		}
	}
}
vector<int> erathostenes(int n)
{
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i] == false) continue;
		for (int j = i * i; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}
	vector<int> outp;
	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i]) outp.push_back(i);
	}
	return outp;
}
bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = floor(sqrt(n)); i > 1; i--)
	{
		if (n % i == 0) return false;
	}
	return true;
}
void bubbleSort(int *arr, int n, bool asc)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (asc)
			{
				if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
			}
			else
			{
				if (arr[j] < arr[j + 1]) swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void selectionSort(int *arr, int n)
{
	int start = 0;

	while (start < n)
	{
		int min = arr[start];
		int minIndex = start;

		for (int i = start; i < n; i++)
		{
			if (arr[i] < min) {
				min = arr[i];
				minIndex = i;
			}
		}
		swap(arr[minIndex], arr[start]);
		start++;
	}

}
void optimizedBubbleSort(int *arr, int n, bool asc)
{
	for (int i = 0; i < n; i++)
	{
		bool swapped = false;
		for (int j = 0; j < n - 1; j++)
		{
			if (asc)
			{
				if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
				swapped = true;
			}
			else
			{
				if (arr[j] < arr[j + 1]) swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}
bool isSorted(int *arr, int n, bool asc)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (asc)
		{
			if (arr[i] > arr[i + 1]) return false;
		}
		else
		{
			if (arr[i] < arr[i + 1]) return false;
		}
	}
	return true;
}
class Graph {
public:
	int size;  
	vector<vector<int>> adj;

	Graph(int vertices) {
		size = vertices;
		adj.resize(size);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>& getNeighbors(int u) {
		return adj[u];
	}
};
class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Node(int value) : value(value), left(nullptr), right(nullptr){}
	~Node()
	{
		delete left;
		delete right;
	}
	void insert(int value)
	{
		if (this->value < value)
		{
			if (this->right) this->right->insert(value);
			else this->right = new Node(value);
		}
		else
		{
			if (this->left) this->left->insert(value);
			else this->left = new Node(value);
		}
	}
	int size()
	{
		int leftTree = 0;
		int rightTree = 0;
		if (this->left)
		{
			leftTree = this->left->size();
		}

		if (this->right)
		{
			rightTree = this->right->size();
		}

		return leftTree + rightTree + 1;
	}
};
void BFS(Node *graph)
{
	queue<Node*> discovered;
	discovered.push(graph);
	while (!discovered.empty())
	{
		Node* current = discovered.front();
		discovered.pop();
		if (current->left)
		{
			discovered.push(current->left);
		}
		if (current->right)
		{
			discovered.push(current->right);
		}
		cout << current->value << "\t";
	}
}
void DFS(Node* graph)
{
	stack<Node*> discovered;
	discovered.push(graph);
	while (!discovered.empty())
	{
		Node* current = discovered.top();
		discovered.pop();
		if (current->left)
		{
			discovered.push(current->left);
		}
		if (current->right)
		{
			discovered.push(current->right);
		}
		cout << current->value << "\t";
	}
}
int main(int argc, char* argv[])
{
	int N = 10000;
	/*cout << getSumOfN(10) << endl;*/
	/*cout << "Erathostenes primes up to N:";
	for (auto value : erathostenes(N))
	{
		cout << " " << value;
	}
	cout << endl;
	cout << "N" << (isPrime(N) ?  " is " : " is NOT ") << "a prime number" << endl;*/

	uniform_int_distribution<int> dist(-N,N);
	mt19937 rd;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = dist(rd);
	}
	auto start = high_resolution_clock::now();
	bubbleSort(arr,N,true);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	if (isSorted(arr,N,true))  cout << "Bubble sort: " << duration.count() << " ms" << endl;
	
	for (int i = 0; i < N; i++)
	{
		arr[i] = dist(rd);
	}
	start = high_resolution_clock::now();
	optimizedBubbleSort(arr, N, true);
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	if (isSorted(arr, N, true))  cout << "Optimized Bubble sort: " << duration.count() << " ms" << endl;

	for (int i = 0; i < N; i++)
	{
		arr[i] = dist(rd);
	}
	start = high_resolution_clock::now();
	selectionSort(arr, N);
	end = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(end - start);
	if (isSorted(arr, N, true))  cout << "Selection sort: " << duration.count() << " ms" << endl;

	Node* tree = new Node(0);
	tree->insert(-5);
	tree->insert(20);
	tree->insert(-3);
	tree->insert(1);
	tree->insert(21);
	tree->insert(-4);
	tree->insert(-1);
	tree->insert(16);
	tree->insert(30000);
	cout << "size: ";
	cout << tree->size() << endl;
	cout << "BFS" << endl;
	BFS(tree);
	cout << endl;
	cout << "DFS" << endl;
	DFS(tree);

	Graph* g = new Graph(5);
	g->addEdge(1, 2);
	g->addEdge(2, 3);
	g->addEdge(3, 4);
	g->addEdge(4, 5);

	delete[] arr;
	delete tree;
}
