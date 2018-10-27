from collections import Counter 
  
def common(str1,str2): 
      
    # convert both strings into counter dictionary 
    dict1 = Counter(str1) 
    dict2 = Counter(str2) 
  
    # take intersection of these dictionaries 
    commonDict = dict1 & dict2 
  
    if len(commonDict) == 0: 
        print -1
        return
  
    # get a list of common elements 
    commonChars = list(commonDict.elements()) 
  
    # sort list in ascending order to print resultant  
    # string on alphabetical order 
    commonChars = sorted(commonChars) 
   
    # join characters without space to produce  
    # resultant string 
    print ''.join(commonChars) 
  
# Driver program 
if __name__ == "__main__": 
    str1 = 'geeks'
    str2 = 'forgeeks'
    common(str1, str2) 