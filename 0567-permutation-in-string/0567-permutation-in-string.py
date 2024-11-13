class Solution(object):
    def checkInclusion(self, s1, s2):

        my_dict = dict()
        window_dict = dict()

        window_length = len(s1)
        string1 = sorted(s1)
        string2 = sorted(s2)

        for char in range(len(s1)):
            if s1[char] in my_dict:
                my_dict[s1[char]] += 1
            else:
                my_dict[s1[char]] = 1

        left = 0

        for right in range(len(s2)):

            current_char = s2[right]
            window_dict[current_char] = window_dict.get(current_char, 0) + 1

            if right >= window_length:
                left_char = s2[right - window_length]
                if window_dict[left_char] == 1:
                    del window_dict[left_char]
                else:
                    window_dict[left_char] -= 1
            
            if my_dict == window_dict:
                return True
    
        return False








        