class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // at every step, we have to return the number which is kth largest. 
        // so we maintain a priority queue of size k only. 
        this->k=k;

        for (int num : nums) {
            pq.push(num);
            if (pq.size()>k) {
                pq.pop();
            }
        }

    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size()>k) {
            pq.pop();
        }
        return pq.top();
    }
};
