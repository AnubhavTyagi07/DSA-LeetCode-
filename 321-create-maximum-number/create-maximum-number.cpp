class Solution {
public:

    // Get the maximum subsequence of length k
    vector<int> getMax(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;

        for (int x : nums) {

            while (!st.empty() && remove > 0 && st.back() < x) {
                st.pop_back();
                remove--;
            }

            st.push_back(x);
        }

        // Keep only k elements
        st.resize(k);

        return st;
    }

    // Check which sequence is lexicographically larger
    bool greater(vector<int>& a, int i,
                 vector<int>& b, int j) {

        while (i < a.size() && j < b.size() &&
               a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size())
            return true;

        if (i == a.size())
            return false;

        return a[i] > b[j];
    }

    // Merge two sequences into the largest possible sequence
    vector<int> merge(vector<int>& a, vector<int>& b) {

        vector<int> result;

        int i = 0;
        int j = 0;

        while (i < a.size() || j < b.size()) {

            if (greater(a, i, b, j)) {
                result.push_back(a[i]);
                i++;
            }
            else {
                result.push_back(b[j]);
                j++;
            }
        }

        return result;
    }

    // Compare two complete answers
    bool isGreater(vector<int>& a, vector<int>& b) {

        for (int i = 0; i < a.size(); i++) {

            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }

        return false;
    }

    vector<int> maxNumber(vector<int>& nums1,
                           vector<int>& nums2,
                           int k) {

        vector<int> answer(k, 0);

        int n1 = nums1.size();
        int n2 = nums2.size();

        // Try every possible split
        for (int k1 = 0; k1 <= k; k1++) {

            int k2 = k - k1;

            // Invalid split
            if (k1 > n1 || k2 > n2)
                continue;

            vector<int> a = getMax(nums1, k1);
            vector<int> b = getMax(nums2, k2);

            vector<int> candidate = merge(a, b);

            if (isGreater(candidate, answer)) {
                answer = candidate;
            }
        }

        return answer;
    }
};