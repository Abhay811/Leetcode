class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
       int size = arr.size();
          int i = 0;
          while (i < size - 1 && arr[i] < arr[i + 1])
               i++;
          if (i == size - 1 || i == 0)
               return false;
          while (i < size - 1 && arr[i] > arr[i + 1])
               i++;
          if (i == size - 1)
               return true;
          else
               return false;
    }
};