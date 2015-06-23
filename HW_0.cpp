/*
* Returns the sum closest to 330 that can be made from adding up to three integers in the array [nums].
*
* @param nums  An integer array allocated with space for [len] integers
* @param len      The allocated length of the array.
* @requires integers in [nums] are all positive
* @requires [len]>0
* @return  The sum closest to 330 that was found.
*
* @example: If [nums] contains [10 100 200 2] and [len]==4, returns 310 = 200+100+10.
* @example: If [nums] contains [10 100 230 2] and [len]==4, returns 330 = 100+230.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;


int Sum (int *nums, int len)
{

        for(int x = 0; x < len; x++)
        {
                int index_of_min = x;
                for(int y = x; y < len; y++)
                {
                        if(nums[index_of_min]>nums[y])
                        {
                                index_of_min = y;
                        }
                }

                int temp = nums[x];
                nums[x] = nums[index_of_min];
                nums[index_of_min] = temp;
        }

        const int target_value = 330;
        int delta = 100000;
        int closest_number;



        for (int a = len - 1; a > 0; --a){
                if (nums[a] == target_value){
                        return nums[a];
                        break;
                }
                else{
                        if (abs(nums[a] - target_value) < delta){
                                delta = abs(nums[a] - target_value);
                                closest_number = nums[a];
                        }

                }

        }

        int sum;
        int min_sum = nums[0] + nums[1];

        for(int l = 0; l < len - 1; l++)
        {
                for(int r = l+1; r < len; r++)
                {
                        sum = nums[l] + nums[r];
                        if (sum == target_value)
                        {
                                return sum;
                                break;
                        }
                        if (abs(sum - target_value) < delta)
                        {
                                delta = abs(sum - target_value);
                                closest_number = sum;
                        }
                }
        }

        for (int i = 0; i < len-2; ++i)
        {
                int j = i + 1;
                int k = len - 1;
                while (k >= j)
                {

                        int sum_of_three = nums[i]+nums[j]+nums[k];

                        if (abs(sum_of_three - target_value) < delta)
                        {
                                delta = abs(sum_of_three - target_value);
                                closest_number = sum_of_three;
                        }

                        if ((sum_of_three == target_value && (i != j) && (j != k) && (k != i)))
                        {
                                return sum_of_three;
                                break;
                        }

                        if (sum_of_three > target_value){
                                --k;
                        }
                        else{
                                ++j;
                        }

                }

        }

        return closest_number;
}



int main()
{

    int foo [5] = { 16, 2, 77, 40, 12071 };
    cout << Sum(foo, 5) << endl;
    return 0;

}
