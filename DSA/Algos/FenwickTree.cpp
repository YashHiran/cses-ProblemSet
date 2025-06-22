
// Learning video => https://www.youtube.com/watch?v=uSFzHCZ4E-8
// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    vector<int> BIT, nums;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        BIT.resize(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            add(nums[i], i + 1);
        }
    }

    void add(int val, int idx) {
        while(idx <= n) {
            BIT[idx] += val;
            idx += idx & (-idx);
        }
    }
    
    void update(int index, int val) {
        add(val - nums[index], index + 1);
        nums[index] = val;
    }

    int getSum(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += BIT[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        return getSum(right + 1) - getSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
