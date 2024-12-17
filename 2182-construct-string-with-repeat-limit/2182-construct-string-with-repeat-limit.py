class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:

        #use counter instad of dict
        from collections import Counter

        my_dict = Counter(s)

        sorted_chars = sorted(my_dict.keys(), reverse=True)

        result = []

        i = 0

        while i < len(sorted_chars):
            char = sorted_chars[i]
            # Use the character until it can't be used directly anymore
            while my_dict[char] > 0:
                # Determine the allowable amount of this character to use
                repeat_count = min(repeatLimit, my_dict[char])
                result.append(char * repeat_count)
                my_dict[char] -= repeat_count

                # If more of this character remains, try to intersperse with another
                if my_dict[char] > 0:
                    # Find next available character to intersperse
                    if i + 1 < len(sorted_chars) and my_dict[sorted_chars[i + 1]] > 0:
                        result.append(sorted_chars[i + 1])
                        my_dict[sorted_chars[i + 1]] -= 1
                    else:
                        # No suitable interspersing character found, stop adding this character
                        break
                # Continue to the next character if current is exhausted or can't add more due to limit
            i += 1

        return ''.join(result)
        


        