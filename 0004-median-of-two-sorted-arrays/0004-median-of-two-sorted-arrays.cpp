class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //Check
        vector<int> sortedVec = mergeTwoVec(nums1, nums2, 0, 0);
        printVector(sortedVec);

        //Median
        res = findMedian(sortedVec);

        return res;
    }

    double findMedian(vector<int>& sortedVec)
    {
        int n = sortedVec.size();
        //Check if odd or even
        //Find median array.size() / 2
        double median;
        
        //Even
        if (n % 2 == 0)
        {
            median = ((sortedVec[n / 2] + sortedVec[n / 2 - 1]) / 2.0);
            std::cout << "Even" << std::endl;
            std::cout << median << std::endl;
        }
        //Odd
        else 
        {
            median = (double)sortedVec[n / 2];
            std::cout << "Odd" << std::endl;
            std::cout << median << std::endl;
        }

        return median;
    }

    void printVector(const std::vector<int>& vec) 
    {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    vector<int> mergeTwoVec(vector<int>& nums1, vector<int>& nums2, int i, int j)
    {
        vector<int> sortedVec;

        //Check if empty
        if (nums1.empty())
        {
            std::sort(nums2.begin(), nums2.end());
            return nums2;
        }

        if (nums2.empty())
        {
            std::sort(nums1.begin(), nums1.end());
            return nums1;
        }

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                sortedVec.push_back(nums1[i]);
                i++;
            }
            else 
            {
                sortedVec.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size())
        {
            //Add remainder
            sortedVec.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            //Add remainder
            sortedVec.push_back(nums2[j]);
            j++;
        }

        return sortedVec;
    }

private:

    double res;
};