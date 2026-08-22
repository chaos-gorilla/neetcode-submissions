class Solution:
    def generateKey(self, s: str):
        key = [0] * 26
        for ch in s:
            key[ord(ch) - ord('a')] += 1
        return str(key)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = dict()
        for s in strs:
            key = self.generateKey(s)
            if key not in anagrams:
                anagrams[key] = []
            anagrams[key].append(s)
        
        return list(anagrams.values())

