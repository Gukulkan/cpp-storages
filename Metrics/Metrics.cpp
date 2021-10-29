    

#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include <set>

int arr1k[1000];
int arr10k[10000];
int arr100k[100000];

std::vector<int> GetVector(int size) {
	std::vector<int> vec;
	for (int i = 0; i < size; i++) {
		vec.push_back(i);
	}
	return vec;
}

std::vector<int> vec1k = GetVector(1000);
std::vector<int> vec10k = GetVector(10000);
std::vector<int> vec100k = GetVector(100000);
std::vector<int> vec1m = GetVector(1000000);

std::list<int> GetList(int size) {
	std::list<int> l;
	for (int i = 0; i < size; i++) {
		l.push_back(i);
	}
	return l;
}

std::list<int> list1k = GetList(1000);
std::list<int> list10k = GetList(10000);
std::list<int> list100k = GetList(100000);
std::list<int> list1m = GetList(1000000);


std::deque<int> GetDeque(int size) {
	std::deque<int> d;
	for (int i = 0; i < size; i++) {
		d.push_back(i);
	}
	return d;
}

std::deque<int> deque1k = GetDeque(1000);
std::deque<int> deque10k = GetDeque(10000);
std::deque<int> deque100k = GetDeque(100000);
std::deque<int> deque1m = GetDeque(1000000);

std::set<int> GetSet(int size) {
	std::set<int> s;
	for (int i = 0; i < size; i++) {
		s.insert(i);
	}
	return s;
}

std::set<int> set1k = GetSet(1000);
std::set<int> set10k = GetSet(10000);
std::set<int> set100k = GetSet(100000);
std::set<int> set1m = GetSet(1000000);


void calculateTime(const std::string& text, void (*func)())
{
	auto start = std::chrono::high_resolution_clock::now();

	func();

	auto stop = std::chrono::high_resolution_clock::now();

	//std::cout << "Time taken by function: " << text << " is "  << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << std::endl;

	std::ofstream outfile;

	outfile.open("output.txt", std::ios_base::app); 
	outfile << text << " is " << (stop - start).count() << std::endl;
}

void ArrayInsert(int arr[], int index, int value) 
{
	arr[index] = value;
}

int main()
{
	//Arrays
	//1k
	calculateTime("Array with 1000 elements add begin", []() {
		ArrayInsert(arr1k, 0, 50);
		});
	calculateTime("Array with 1000 elements add end", []() {
		ArrayInsert(arr1k, 1000 - 1, 50);
		});
	calculateTime("Array with 1000 elements search existing element", []() {
		std::find(std::begin(arr1k), std::end(arr1k), 50);
		});
	calculateTime("Array with 1000 elements search non-existing element", []() {
		std::find(std::begin(arr1k), std::end(arr1k), 51);
		});
	calculateTime("Array with 1000 elements sort", []() {
		std::sort(std::begin(arr1k), std::end(arr1k));
		});

	//10k
	calculateTime("Array with 10000 elements add begin", []() {
		ArrayInsert(arr10k, 0, 50);
		});
	calculateTime("Array with 10000 elements add end", []() {
		ArrayInsert(arr10k, 1000 - 1, 50);
		});
	calculateTime("Array with 10000 elements search existing element", []() {
		std::find(std::begin(arr10k), std::end(arr10k), 50);
		});
	calculateTime("Array with 10000 elements search non-existing element", []() {
		std::find(std::begin(arr10k), std::end(arr10k), 51);
		});
	calculateTime("Array with 10000 elements sort", []() {
		std::sort(std::begin(arr10k), std::end(arr10k));
		});

	//100k
	calculateTime("Array with 100000 elements add begin", []() {
		ArrayInsert(arr100k, 0, 50);
		});
	calculateTime("Array with 100000 elements add end", []() {
		ArrayInsert(arr100k, 1000 - 1, 50);
		});
	calculateTime("Array with 100000 elements search existing element", []() {
		std::find(std::begin(arr100k), std::end(arr100k), 50);
		});
	calculateTime("Array with 100000 elements search non-existing element", []() {
		std::find(std::begin(arr100k), std::end(arr100k), 51);
		});
	calculateTime("Array with 100000 elements sort", []() {
		std::sort(std::begin(arr100k), std::end(arr100k));
		});
	//1m - stack overflow? Need more explanation 


	//Vectors
	//1k
	calculateTime("Vector with 1000 elements add begin", []() {
		vec1k.insert(vec1k.begin(), 100500 - 1);
		});
	calculateTime("Vector with 1000 elements add end", []() {
		vec1k.push_back(100500);
		});
	calculateTime("Vector with 1000 elements search existing element", []() {
		std::find(std::begin(vec1k), std::end(vec1k), 100500);
		});
	calculateTime("Vector with 1000 elements search non-existing element", []() {
		std::find(std::begin(vec1k), std::end(vec1k), 100501);
		});
	calculateTime("Vector with 1000 elements sort", []() {
		std::sort(std::begin(vec1k), std::end(vec1k));
		});

	//10k
	calculateTime("Vector with 10000 elements add begin", []() {
		vec10k.insert(vec10k.begin(), 100500 - 1);
		});
	calculateTime("Vector with 10000 elements add end", []() {
		vec10k.push_back(100500);
		});
	calculateTime("Vector with 10000 elements search existing element", []() {
		std::find(std::begin(vec10k), std::end(vec10k), 100500);
		});
	calculateTime("Vector with 10000 elements search non-existing element", []() {
		std::find(std::begin(vec10k), std::end(vec10k), 100501);
		});
	calculateTime("Vector with 10000 elements sort", []() {
		std::sort(std::begin(vec10k), std::end(vec10k));
		});

	//100k
	calculateTime("Vector with 100000 elements add begin", []() {
		vec100k.insert(vec100k.begin(), 100500 - 1);
		});
	calculateTime("Vector with 100000 elements add end", []() {
		vec100k.push_back(100500);
		});
	calculateTime("Vector with 100000 elements search existing element", []() {
		std::find(std::begin(vec100k), std::end(vec100k), 100500);
		});
	calculateTime("Vector with 100000 elements search non-existing element", []() {
		std::find(std::begin(vec100k), std::end(vec100k), 100501);
		});
	calculateTime("Vector with 100000 elements sort", []() {
		std::sort(std::begin(vec100k), std::end(vec100k));
		});

	//1m
	calculateTime("Vector with 1000000 elements add begin", []() {
		vec1m.insert(vec1m.begin(), 100500 - 1);
		});
	calculateTime("Vector with 1000000 elements add end", []() {
		vec1m.push_back(100500);
		});
	calculateTime("Vector with 1000000 elements search existing element", []() {
		std::find(std::begin(vec1m), std::end(vec1m), 100500);
		});
	calculateTime("Vector with 1000000 elements search non-existing element", []() {
		std::find(std::begin(vec1m), std::end(vec1m), 100501);
		});
	calculateTime("Vector with 1000000 elements sort", []() {
		std::sort(std::begin(vec1m), std::end(vec1m));
		});

	//List
	//1k
	calculateTime("List with 1000 elements add begin", []() {
		list1k.push_front(100500 - 1);
		});
	calculateTime("List with 1000 elements add end", []() {
		list1k.push_back(100500);
		});
	calculateTime("List with 1000 elements search existing element", []() {
		std::find(std::begin(list1k), std::end(list1k), 100500);
		});
	calculateTime("List with 1000 elements search non-existing element", []() {
		std::find(std::begin(list1k), std::end(list1k), 100501);
		});
	calculateTime("List with 1000 elements sort", []() {
		list1k.sort();
		});

	//10k
	calculateTime("List with 10000 elements add begin", []() {
		list10k.push_front(100500 - 1);
		});
	calculateTime("List with 10000 elements add end", []() {
		list10k.push_back(100500);
		});
	calculateTime("List with 10000 elements search existing element", []() {
		std::find(std::begin(list10k), std::end(list10k), 100500);
		});
	calculateTime("List with 10000 elements search non-existing element", []() {
		std::find(std::begin(list10k), std::end(list10k), 100501);
		});
	calculateTime("List with 10000 elements sort", []() {
		list1k.sort();
		});

	//100k
	calculateTime("List with 100000 elements add begin", []() {
		list100k.push_front(100500 - 1);
		});
	calculateTime("List with 100000 elements add end", []() {
		list100k.push_back(100500);
		});
	calculateTime("List with 100000 elements search existing element", []() {
		std::find(std::begin(list100k), std::end(list100k), 100500);
		});
	calculateTime("List with 100000 elements search non-existing element", []() {
		std::find(std::begin(list100k), std::end(list100k), 100501);
		});
	calculateTime("List with 100000 elements sort", []() {
		list1k.sort();
		});

	//1m
	calculateTime("List with 1000000 elements add begin", []() {
		list1m.push_front(100500 - 1);
		});
	calculateTime("List with 1000000 elements add end", []() {
		list1m.push_back(100500);
		});
	calculateTime("List with 1000000 elements search existing element", []() {
		std::find(std::begin(list1m), std::end(list1m), 100500);
		});
	calculateTime("List with 1000000 elements search non-existing element", []() {
		std::find(std::begin(list1m), std::end(list1m), 100501);
		});
	calculateTime("List with 1000000 elements sort", []() {
		list1k.sort();
		});


	//Deque
	//1k
	calculateTime("Deque with 1000 elements add begin", []() {
		deque1k.push_front(0);
		});
	calculateTime("Deque with 1000 elements add end", []() {
		deque1k.push_back(100500);
		});
	calculateTime("Deque with 1000 elements search existing element", []() {
		std::find(std::begin(deque1k), std::end(deque1k), 100500);
		});
	calculateTime("Deque with 1000 elements search non-existing element", []() {
		std::find(std::begin(deque1k), std::end(deque1k), 100501);
		});
	calculateTime("Deque with 1000 elements sort", []() {
		std::sort(std::begin(deque1k), std::end(deque1k));
		});

	//10k
	calculateTime("Deque with 10000 elements add begin", []() {
		deque10k.push_front(100500 - 1);
		});
	calculateTime("Deque with 10000 elements add end", []() {
		deque10k.push_back(100500);
		});
	calculateTime("Deque with 10000 elements search existing element", []() {
		std::find(std::begin(deque10k), std::end(deque10k), 100500);
		});
	calculateTime("Deque with 10000 elements search non-existing element", []() {
		std::find(std::begin(deque10k), std::end(deque10k), 100501);
		});
	calculateTime("Deque with 10000 elements sort", []() {
		std::sort(std::begin(deque10k), std::end(deque10k));
		});

	//100k
	calculateTime("Deque with 100000 elements add begin", []() {
		deque100k.push_front(100500 - 1);
		});
	calculateTime("Deque with 100000 elements add end", []() {
		deque100k.push_back(100500);
		});
	calculateTime("Deque with 100000 elements search existing element", []() {
		std::find(std::begin(deque100k), std::end(deque100k), 100500);
		});
	calculateTime("Deque with 100000 elements search non-existing element", []() {
		std::find(std::begin(deque100k), std::end(deque100k), 100501);
		});
	calculateTime("Deque with 100000 elements sort", []() {
		std::sort(std::begin(deque100k), std::end(deque100k));
		});

	//1m
	calculateTime("Deque with 1000000 elements add begin", []() {
		deque1m.push_front(100500 - 1);
		});
	calculateTime("Deque with 1000000 elements add end", []() {
		deque1m.push_back(100500);
		});
	calculateTime("Deque with 1000000 elements search existing element", []() {
		std::find(std::begin(deque1m), std::end(deque1m), 100500);
		});
	calculateTime("Deque with 1000000 elements search non-existing element", []() {
		std::find(std::begin(deque1m), std::end(deque1m), 100501);
		});
	calculateTime("Deque with 1000000 elements sort", []() {
		std::sort(std::begin(deque1m), std::end(deque1m));
		});


	//Set (resort imposible, because it has tree)
	//1k
	calculateTime("Set with 1000 elements add begin", []() {
		set1k.insert(set1k.begin(), 100500 - 1);
		});
	calculateTime("Set with 1000 elements add end", []() {
		set1k.insert(100500);
		});
	calculateTime("Set with 1000 elements search existing element", []() {
		std::find(std::begin(set1k), std::end(set1k), 100500);
		});
	calculateTime("Set with 1000 elements search non-existing element", []() {
		std::find(std::begin(set1k), std::end(set1k), 100501);
		});


	//10k
	calculateTime("Set with 10000 elements add begin", []() {
		set10k.insert(set10k.begin(), 100500 - 1);
		});
	calculateTime("Set with 10000 elements add end", []() {
		set10k.insert(100500);
		});
	calculateTime("Set with 10000 elements search existing element", []() {
		std::find(std::begin(set10k), std::end(set10k), 100500);
		});
	calculateTime("Set with 10000 elements search non-existing element", []() {
		std::find(std::begin(set10k), std::end(set10k), 100501);
		});

	//100k
	calculateTime("Set with 100000 elements add begin", []() {
		set100k.insert(set100k.begin(), 100500 - 1);
		});
	calculateTime("Set with 100000 elements add end", []() {
		set100k.insert(100500);
		});
	calculateTime("Set with 100000 elements search existing element", []() {
		std::find(std::begin(set100k), std::end(set100k), 100500);
		});
	calculateTime("Set with 100000 elements search non-existing element", []() {
		std::find(std::begin(set100k), std::end(set100k), 100501);
		});


	//1m
	calculateTime("Set with 1000000 elements add begin", []() {
		set1m.insert(set1m.begin(), 100500 - 1);
		});
	calculateTime("Set with 1000000 elements add end", []() {
		set1m.insert(100500);
		});
	calculateTime("Set with 1000000 elements search existing element", []() {
		std::find(std::begin(set1m), std::end(set1m), 100500);
		});
	calculateTime("Set with 1000000 elements search non-existing element", []() {
		std::find(std::begin(set1m), std::end(set1m), 100501);
		});

}

