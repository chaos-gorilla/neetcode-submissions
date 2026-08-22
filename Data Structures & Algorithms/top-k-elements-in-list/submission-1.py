class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        for num in nums:
            if num not in counts:
                counts[num] = 0
            counts[num] += 1
        
        sorted_numbers_by_count = sorted(counts.items(), key=lambda entry: entry[1], reverse=True)
        return [k for k,v in sorted_numbers_by_count[0:k]]
        