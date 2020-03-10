			#include <iostream>
			#include <vector>
			using namespace std;

			class  Heap
			{
			public:

				int LeftChild(int index)
				{
					return index * 2 + 1;
				}
				int RightChild(int index)
				{
					return index * 2 + 2;
				}
				int Parent(int index)
				{
					return (index - 1) / 2;
				}
				void heapify(int index)
				{
					int largest = index;
					if (LeftChild(index) < capacity && heapArr[LeftChild(index)] > heapArr[largest])
					{
						largest = LeftChild(index);
					}
					if (RightChild(index) < capacity && heapArr[RightChild(index)] > heapArr[largest])
					{
						largest = RightChild(index);
					}
					if (largest != index)
					{
						swap(heapArr[index], heapArr[largest]);
						heapify(largest);
					}
				}
				void insert(int element)
				{
					if (heapArr.size() == capacity)
					{
						cout << "heap is full!";
						return;
					}
					heapArr.push_back(element);
					int i = heapArr.size() - 1;
					while (i != 0 && heapArr[i] > heapArr[Parent(i)])
					{
						swap(heapArr[i], heapArr[Parent(i)]);
						i = Parent(i);
					}
				}
				int pop()
				{
					int root = heapArr[0];
					heapArr[0] = heapArr[heapArr.size() - 1];
					heapArr.erase(heapArr.begin()+heapArr.size()-1);
					heapify(0);
					return root;
				}

				void View()
				{
					for (auto el : heapArr)
					{
						cout << el << " ";
					}
				}
				Heap(int size)
				{
					this->capacity = size;
				}
				~Heap()
				{

				}

			private:
				vector<int> heapArr;
				int capacity;

			};


			int main()
			{
				Heap HepiMeal(7);
				HepiMeal.insert(4);
				HepiMeal.insert(5);
				HepiMeal.insert(17);
				HepiMeal.insert(34);
				HepiMeal.insert(9);
				HepiMeal.insert(32);
				HepiMeal.View();

				cin.get();
				return 0;
			}
