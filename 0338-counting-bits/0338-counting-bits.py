class Solution:
    def countBits(self, n: int) -> List[int]:

        count = 0

        array = []

        while count <= n:
            binary = bin(count)[2:]
            ones = binary.count("1")
            array.append(ones)
            count += 1
        
        return array
