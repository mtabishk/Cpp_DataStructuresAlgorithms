#include <vector>
#include <climits>
class PriorityQueue {
	std::vector<int> pq;

public:
	bool isEmpty() {
		return pq.size() == 0;
	}

	int getSize() {
		return pq.size();
	}

	int getMin() {
		if (isEmpty()) {
			return INT_MIN;
		}

		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);

		int childIndex = pq.size() - 1;

		while (childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if (pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			} else {
				break;
			}

			childIndex = parentIndex;
		}
	}

	int removeMin() {
		if (isEmpty()) {
			return INT_MIN;
		}
		int ans = pq[0];

		// update the root (min element) with last element of pq and then remove it.
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// Down-Heapify
		int parentIndex = 0;
		int leftChildIndex = (2 * parentIndex) + 1;
		int rightChildIndex = (2 * parentIndex) + 2;

		while (leftChildIndex < pq.size() ) {
			int minIndex = parentIndex;

			// swap
			if (pq[minIndex] > pq[leftChildIndex] ) {
				minIndex = leftChildIndex;
			}

			if (rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {
				minIndex = rightChildIndex;
			}

			if (minIndex == parentIndex) {
				break;
			}

			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;
		}
		return ans;
	}
};