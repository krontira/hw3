#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> heap_;
  PComparator cmp_;
  int m_;

  int parent(int i) const;
  
	int kthChild(int i, int k) const;
  
	void heapifyUp(int i);
  
	void heapifyDown(int i);
  
	int minChild(int i) const;


};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : cmp_(c), m_(m) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  heap_.push_back(item);
  
	heapifyUp(heap_.size() - 1);
}

template <typename T, typename PComparator>
T const& Heap<T, PComparator>::top() const {
  if (empty()) {
    throw std::underflow_error("Heap is empty");
  }
	
	T const& topItem = heap_[0];
  for (size_t i = 1; i < heap_.size(); ++i) {
    
		if(!cmp_(topItem, heap_[i]) && !cmp_(heap_[i], topItem)){
      
			return topItem;
    }
  
	}
  return topItem;
  //return heap_.front();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
  if(empty()) {
    throw std::underflow_error("Heap is empty");
  }
  
	
	heap_[0] = heap_.back();
  heap_.pop_back();
  heapifyDown(0);
}


template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  
	return heap_.empty(); //bool return for empty
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  
	return heap_.size(); //returns size
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::parent(int i) const {
  
	return (i - 1) / m_; //takes in size and index to find parent
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::kthChild(int i, int k) const {
  
	
	return m_ * i + k;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int i) {
  T tmp = heap_[i];
  while (i > 0 && cmp_(tmp, heap_[parent(i)])) {
    heap_[i] = heap_[parent(i)];
    i = parent(i);
  }
  heap_[i] = tmp;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int i) {
  
	int child;
  T tmp = heap_[i];

  while(kthChild(i, 1) < heap_.size()) {
    child = minChild(i);
    if (cmp_(heap_[child], tmp)) {
      heap_[i] = heap_[child];
    } else {
      break;
    }
    
		i = child;
  }
  heap_[i] = tmp;
}

template <typename T, typename PComparator>
int Heap<T, PComparator>::minChild(int i) const {
  /*int bestChild = kthChild(i, 1);
  int k = 2;
  int pos = kthChild(i, k);
  while (k <= m_ && pos < heap_.size()) {
    if (cmp_(heap_[pos], heap_[bestChild])) {
      bestChild = pos;
    }
  }*/
	int bestChild = kthChild(i, 1);
  int k = 2;
  int pos = kthChild(i, k);
  while (k <= m_ && pos < heap_.size()) {
    if (cmp_(heap_[pos], heap_[bestChild])) {
      bestChild = pos;
    }
    k++;  //must increment k
    pos = kthChild(i, k);
  }
  return bestChild;
};

// We will start top() for you to handle the case of 
// calling top on an empty heap




#endif

