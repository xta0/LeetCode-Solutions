class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        result = []
        for i, n in enumerate(nums):
            dict[n] = i
        for i, x in enumerate(nums):
            n = target - x
            if n in dict.keys():
                index = dict[n]
                if(index != i):
                    result.append(i)
                    result.append(index)
                    break

        return result
