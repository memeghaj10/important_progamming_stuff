class Solution:
    def CreateConnections(self, A, N):
        Connections = [[""] * N for _ in range(N)]
        Len = [[0] * N for _ in range(N)]
        for i, j in permutations(range(N), 2):
            Connections[i][j] = A[j]
            Len[i][j] = len(A[j])
            for k in range(min(len(A[i]), len(A[j]))):
                if A[i][-k:] == A[j][:k]:
                    Connections[i][j] = A[j][k:]
                    Len[i][j] = len(A[j][k:])
        return Connections, Len

    def shortestSuperstring(self, A):
        N = len(A)
        Connections, Len = self.CreateConnections(A, N)
        dp = [[(float("inf"), -1)] * N for _ in range(1<<N)]
        for i in range(N): dp[1<<i][i] = (len(A[i]), -1)
            
        for mask in range(1<<N):
            n_z_bits = [j for j in range(N) if mask&(1<<j)]
            for j, k in permutations(n_z_bits, 2):
                dp[mask][j] = min(dp[mask][j], (dp[mask^(1<<j)][k][0] + Len[k][j], k))
                
        mask = (1<<N) - 1
        prev = min(dp[mask])
        last = dp[mask].index(prev)
        prev = prev[1]
        ans = ""
        
        while prev != -1:
            ans = Connections[prev][last] + ans
            mask -= (1<<last)
            prev, last = dp[mask][prev][1], prev
            
        return A[last] + ans