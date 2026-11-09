
class Solution {
public:

    // =====================================================
    // LC 2281: Sum of Total Strength of Wizards
    //
    // Total Strength of a subarray =
    // Minimum element * Sum of all elements
    //
    // Approach:
    // Monotonic Stack + Prefix Sum + Double Prefix Sum
    //
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =====================================================

    const long long MOD = 1e9 + 7;


    // =====================================================
    // 1. NEXT SMALLER OR EQUAL ELEMENT (NSE)
    //
    // For every index i, find the first index on the
    // right having value <= strength[i].
    //
    // If not found, return n.
    //
    // We pop only strictly greater elements.
    // This handles duplicate minimum elements.
    // =====================================================

    vector<int> nse(vector<int>& strength) {

        int n = strength.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() &&
                  strength[st.top()] > strength[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }


    // =====================================================
    // 2. PREVIOUS SMALLER ELEMENT (PSE)
    //
    // For every index i, find the nearest index on the
    // left having value < strength[i].
    //
    // If not found, return -1.
    //
    // We pop greater than OR equal elements.
    //
    // Together with NSE, this assigns every subarray
    // to exactly one minimum element.
    // =====================================================

    vector<int> pse(vector<int>& strength) {

        int n = strength.size();

        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  strength[st.top()] >= strength[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }


    // =====================================================
    // 3. MAIN FUNCTION
    // =====================================================

    int totalStrength(vector<int>& strength) {

        int n = strength.size();

        vector<int> right = nse(strength);
        vector<int> left = pse(strength);


        // =================================================
        // 4. PREFIX SUM
        //
        // pre[i] = sum of elements from index 0 to i-1
        //
        // Sum of subarray [l, r]:
        //
        // pre[r+1] - pre[l]
        // =================================================

        vector<long long> pre(n+1, 0);

        for(int i = 0; i < n; i++) {

            pre[i+1] =
                (pre[i] + strength[i]) % MOD;
        }


        // =================================================
        // 5. DOUBLE PREFIX SUM
        //
        // dbl_pre[i] = pre[0] + pre[1] + ... + pre[i-1]
        //
        // It helps calculate the SUM OF MULTIPLE PREFIX
        // SUMS in O(1).
        //
        // Sum of pre[l] to pre[r]:
        //
        // dbl_pre[r+1] - dbl_pre[l]
        // =================================================

        vector<long long> dbl_pre(n+2, 0);

        for(int i = 1; i <= n; i++) {

            dbl_pre[i+1] =
                (dbl_pre[i] + pre[i]) % MOD;
        }


        // =================================================
        // 6. CONTRIBUTION CALCULATION
        //
        // For every index i:
        //
        // L = previous smaller element index
        // R = next smaller or equal element index
        //
        // Valid subarrays must satisfy:
        //
        // L < start <= i <= end < R
        //
        // Therefore:
        //
        // left_count  = i - L
        // right_count = R - i
        //
        // These are the number of possible starting
        // and ending positions respectively.
        // =================================================

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            int L = left[i];
            int R = right[i];

            long long left_count = i - L;
            long long right_count = R - i;


            // =============================================
            // 7. CALCULATE LEFT SUM
            //
            // left_sum =
            // pre[L+1] + pre[L+2] + ... + pre[i]
            //
            // Using double prefix sum:
            //
            // Q[i+1] - Q[L+1]
            //
            // This is the sum of prefix sums corresponding
            // to all possible starting positions.
            // =============================================

            long long left_sum =
                (dbl_pre[i+1] - dbl_pre[L+1] + MOD) % MOD;


            // =============================================
            // 8. CALCULATE RIGHT SUM
            //
            // right_sum =
            // pre[i+1] + pre[i+2] + ... + pre[R]
            //
            // Using double prefix sum:
            //
            // Q[R+1] - Q[i+1]
            //
            // This is the sum of prefix sums corresponding
            // to all possible ending positions.
            // =============================================

            long long right_sum =
                (dbl_pre[R+1] - dbl_pre[i+1] + MOD) % MOD;


            // =============================================
            // 9. MOST IMPORTANT: CONTRIBUTION FORMULA
            //
            // Every subarray sum:
            //
            // pre[end+1] - pre[start]
            //
            // When we expand the sum of all valid
            // subarrays:
            //
            // Every RIGHT prefix sum occurs left_count
            // times (one for every starting position).
            //
            // Every LEFT prefix sum occurs right_count
            // times (one for every ending position).
            //
            // Therefore:
            //
            // S = left_count * right_sum
            //     - right_count * left_sum
            //
            // S = SUM OF ALL SUBARRAY SUMS in which
            //     strength[i] is the assigned minimum.
            // =============================================

            long long S =
                (right_sum * left_count % MOD
                - left_sum * right_count % MOD
                + MOD) % MOD;


            // =============================================
            // 10. CURRENT ELEMENT'S CONTRIBUTION
            //
            // Total Strength =
            // Minimum element * Subarray Sum
            //
            // Therefore:
            //
            // Contribution = strength[i] * S
            // =============================================

            long long contribution =
                S * strength[i] % MOD;


            // Add current element's contribution
            // to the final answer.

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};
