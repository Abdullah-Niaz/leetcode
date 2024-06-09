def isAcronym(words, s) -> bool:
    # Step 1: Extract the first character of each word
    # acronym = "".join(word[0] for word in words)
    acronym = ""
    for word in words:
        acronym +=word[0]
    
    # Step 2: Compare the concatenated string with s
    print(acronym)
    return acronym == s


words = ["alice","bob","charlie"]
s = "abc"
ans = isAcronym(words,s)
print(ans)