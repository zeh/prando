node *intersection(node *Ahead,node *Bhead)
{
	node *ptr1=Ahead;
	node *ptr2=Bhead;
	int ptr1count=0,ptr2count=0;
	while((ptr1->next!=NULL)&&(ptr2->next!=NULL))
	{
		ptr1=ptr->next;
		ptr1count++
		ptr2=ptr2->next;
		ptr2count++;
	}
	int differenceinlength=abs(ptr1count-ptr2count);
	if(ptr1count>pr2count)
	{
		for(int i=0;i<differenceinlength;i++)
			ptr2=ptr2->next;
	}
	else
	{
		for(int i=0;i<differenceinlength;i++)
			ptr2=ptr2->next;
	}

	while(ptr1!=ptr2)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	return ptr1;


}