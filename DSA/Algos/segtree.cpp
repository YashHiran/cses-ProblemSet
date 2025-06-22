

// https://leetcode.com/problems/range-sum-query-mutable/?envType=problem-list-v2&envId=segment-tree

class NumArray {
public:
    vector<int> seg;
    vector<int> nums;
    int n;
    void build(int idx, int ss, int se) {
        if(ss == se) {
            seg[idx] = nums[ss - 1];
            return;
        }
        int mid = ss + (se - ss) / 2;
        build(2 * idx, ss, mid);
        build(2 * idx + 1, mid + 1, se);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        seg.resize(4 * n);
        build(1, 1, n);
    }

    void updateUtil(int idx, int ss, int se, int index, int val) {
        if(index < ss || index > se) {
            return;
        }
        if(ss == se && ss == index) {
            seg[idx] = val;
            return;
        }
        int mid = ss + (se - ss) / 2;
        updateUtil(2 * idx, ss, mid, index, val);
        updateUtil(2 * idx + 1, mid + 1, se, index , val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
        
    void update(int index, int val) {
        nums[index] = val;
        updateUtil(1, 1, n, index + 1, val);
    }
    
    int query(int idx, int ss, int se, int left, int right) {
        if(right < ss || left > se) {
            return 0;
        }

        if(ss >= left && se <= right) {
            return seg[idx];
        }
        int mid = ss + (se - ss)/2;
        int ll = query(2*idx, ss, mid, left, right);
        int rr = query(2*idx+1, mid + 1, se, left, right);
        return ll + rr;
    }

    int sumRange(int left, int right) {
        return query(1, 1, n, left + 1, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */