class Solution:
    def stableMarriage(self, men, women):
        n = len(men)

        woman_partner = [-1] * n
        man_next = [0] * n
        free_man = [True] * n

        rank = [[0] * n for _ in range(n)]

        for w in range(n):
            for i in range(n):
                rank[w][women[w][i]] = i

        free_count = n

        while free_count > 0:
            m = next(i for i in range(n) if free_man[i])

            w = men[m][man_next[m]]
            man_next[m] += 1

            if woman_partner[w] == -1:
                woman_partner[w] = m
                free_man[m] = False
                free_count -= 1
            else:
                m1 = woman_partner[w]

                if rank[w][m] < rank[w][m1]:
                    woman_partner[w] = m
                    free_man[m] = False
                    free_man[m1] = True

        result = [0] * n
        for w in range(n):
            result[woman_partner[w]] = w

        return result
