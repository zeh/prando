#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node *next;
}
bool isCycle(Node *head){
	if(!head)return false;

	Node *single=head;
	Node *doub=head->next;
	while(single&&doub&&doub->next)
	{
		if(single->data==doub->data)
			return true;
		single=single->next;
		doub=doub->next->next;

	}
	return false;

}

/* algorithm

we use two pointers approach first we initialize one of the pointers to
our current head and the second just after that . the first pointer is 
made to traverse by moving one step and the second by moving two step and because 
of this they would meet at a point

1------2-------3------4                       
(1)   (2)             |
                12----5
                 |    |
                11    7
                 |    |
                 10-9-8


                     (2)
1------2-------3------4                       
      (1)             |
                12----5
                 |    |
                11    7
                 |    |
                 10-9-8


                     
1------2-------3------4                       
              (1)     |
                12----5
                 |    |
                11    7(2)
                 |    |
                 10-9-8

1------2-------3------4(1)                       
                      |
                12----5
                 |    |
                11    7
                 |    |
                 10-9-8
                   (2)    

1------2-------3------4                       
                      |
                12----5(1)
                 |    |
              (2)11    7
                 |    |
                 10-9-8

1------2-------3------4                       
                      |
                12----5(2)
                 |    |
                11    7(1)
                 |    |
                 10-9-8



1------2-------3------4                       
                      |
                12----5
                 |    |
                11    7
                 |    |
                 10-9-8(1)(2)

                                   
as we can see the frist iterator takes a jump of one unit and the second 
of two units and they meet at 8 hence cycle is detected


1------2------3-------4-----NULL
(1)   (2)


1------2------3--------4-----NULL
       (1)            (2)

as the doub-<next==NULL therefore program terminates


EDGE CASES

1---NULL
handled by the first if condition

1--2--NULL
doub->next==NULL therefore doesn't enter the while loop
