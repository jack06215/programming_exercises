from collections import defaultdict
from collections import deque
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: list) -> int:
        # if end word is not in the word list
        # there is no solution
        wordDict = set(wordList)
        if endWord not in wordDict: 
            return 0
        
        # a dictionary containing all combinations
        # each key stores all possible words, e.g.
        # {'*ot': ['hot', 'dot', 'lot'], 
        # 'h*t': ['hot'], 'ho*': ['hot'],...}
        wordLen = len(beginWord)
        adj = defaultdict(list)
        for word in wordList:
            for i in range(wordLen):
                adj[word[:i] + '*' + word[i+1:]].append(word)

        # queue to that stores new word and n-round
        # begin words starts with 1, increase as it goes
        # until it becomes end word
        dq = deque([(beginWord, 1)])
        # if nothing in the queue, we return 0 as there is no result
        while dq:
            word, n_round = dq.popleft()
            for i in range(wordLen):
                dummyWord = word[:i] + '*' + word[i+1:]
                for newWord in adj[dummyWord]:
                    if newWord == endWord:
                        return n_round + 1
                    
                    # new word found, so remove it from wordDict
                    # since we do not want to add the same word
                    # to the queue again (infinity loop!)
                    if newWord in wordDict:
                        wordDict.remove(newWord)
                        dq.append((newWord, n_round + 1))
        return 0

solution = Solution()


'''
"hit" -> "hot" -> "dot" -> "dog" -> "cog" with 5 words.
'''
beginWord = "hit"
endWord = "cog"
ladder = ["hot","dot","dog","lot","log","cog"]
assert solution.ladderLength(beginWord, endWord, ladder) == 5