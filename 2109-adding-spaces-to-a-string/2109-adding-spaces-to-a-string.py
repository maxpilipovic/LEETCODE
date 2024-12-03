class Solution(object):
    def addSpaces(self, s, spaces):

        Sstr = []

        Sspaces = 0
        for i in range(len(s)):
            if Sspaces < len(spaces):
                if spaces[Sspaces] == i:
                    Sstr.append(' ')
                    Sspaces += 1

            Sstr.append(s[i])

        return ''.join(Sstr)



        