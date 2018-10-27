//algorithm for stack push operation

push(stack,top,maxsize,item)
if(top=maxsize-1) then
  print: stack overflow and return
else
  set top=top+1
  set stack[top]=item
end if

//algorithm for stack pop operation

pop(stack,top,item)
if(top=-1) then
  print: stack underflow and return
else:
  set item=stack[top]
  set top=top-1
  return
end if
