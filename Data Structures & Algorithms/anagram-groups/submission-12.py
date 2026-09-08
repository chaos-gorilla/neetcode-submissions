class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}

        for string in strs:
            key = str(sorted(string))
            if key not in groups:
                groups[key] = []
            groups[key].append(string)
        
        return list(groups.values())