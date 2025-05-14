import numpy as np
import math
class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        A = np.zeros((26, 26), dtype="object")
        mod = 1000000007
        for idx, num in enumerate(nums):
            for n in range(num):
                A[(n + idx + 1) % 26, idx] = 1

        total_squares = int(math.log(t, 2))
        prev_matrices = [A.copy()] * (total_squares + 1)
        
        for square in range(1, total_squares + 1):
            A = (prev_matrices[square - 1] @ prev_matrices[square - 1]) % mod
            prev_matrices[square] = A.copy()
            
        newT = 1 << total_squares
        while newT < t:
            new_power = int(math.log(t - newT, 2))
            A = (A @ prev_matrices[new_power]) % mod
            newT += 1 << new_power

        x = [0] * 26
        for c in s:
            x[ord(c) - ord('a')] += 1
        x = np.vstack(x)

        return int(np.sum(A @ x) % mod)
