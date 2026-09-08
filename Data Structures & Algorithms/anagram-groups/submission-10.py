class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        key_to_anagrams = defaultdict(list)

        for string in strs:
            key = "".join(sorted(string))
            key_to_anagrams[key].append(string)
        
        return list(key_to_anagrams.values())