class Solution:
    def _canCompletePileWithRateK(self, piles: List[int], rate: int, total_hours: int) -> bool:
        total_moves = 0
        for pile in piles:
            total_moves += math.ceil(pile / rate)
        return total_moves <= total_hours

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if h < len(piles):
            return -1
        min_rate = 1
        max_rate = max(piles)
        answer_rate = -1
        while min_rate <= max_rate:
            mid_rate = math.ceil((min_rate + max_rate) // 2)
            if self._canCompletePileWithRateK(piles, mid_rate, h):
                answer_rate = mid_rate
                max_rate = mid_rate - 1
                continue
            else:
                min_rate = mid_rate + 1

        return answer_rate