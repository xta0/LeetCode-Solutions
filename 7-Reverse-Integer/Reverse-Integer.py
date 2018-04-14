class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s =(x > 0) - (x < 0)
        n = s * int(str(abs(x))[::-1])
        return n if n.bit_length() < 32 else 0