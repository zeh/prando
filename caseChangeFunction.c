

//vice versa 
//first arg is string second is the len of string
void caseChange(char* str,int len)
{
  int i=0,magicNumber=32;
  
  for(i=0;i<len;i++)
  {
    
    if(str[i] >= 'a' && str[i]<='z')
    {
      str[i] = str[i] & ~ magicNumber;
    }
    
    else if(str[i] >= 'A' && str[i]<='Z')
    {
      str[i] = str[i] |  magicNumber;
    }
  
  
  }

  return ; 
}
