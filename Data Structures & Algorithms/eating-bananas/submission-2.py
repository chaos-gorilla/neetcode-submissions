class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        answer = -1
        min_rate = 1
        max_rate = max(piles)
        
        def canEatAtRateK(rate: int) -> bool:
            total = sum(math.ceil(pile / rate) for pile in piles)
            return total <= h

        answer_rate = max_rate
        while min_rate <= max_rate:
            k_rate = math.ceil((min_rate + max_rate) / 2)
            if canEatAtRateK(k_rate):
                answer_rate = k_rate
                max_rate = k_rate - 1
            else:
                min_rate = k_rate + 1

        return answer_rate