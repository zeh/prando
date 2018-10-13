var array = [1, 3, 5, 6, 7, 2, 8, 2, 5, 2, 7, 3, 6]
var fbig = array[0];
var sbig = array[1];
if( sbig > fbig )
 {
    temp = sbig;
    sbig = fbig;
    fbig = temp;
 }
 
 for(var i=2; i < array.length ; i++)
	 if(array[i] > fbig)
	 {
		sbig = fbig;
		fbig = array[i];
	 }
	 else if(array[i] > sbig)
		sbig = array[i];
 }
