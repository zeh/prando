$abc=array("a"=>1,"b"=>2,"c"=>4,"e"=>7,"d"=>5);
/*A program to find max value of an array*/
$lagest = array();
$i=0;
foreach($abc as $key=>$a) {
    if($i==0) $b=$a;
    if($b<$a) {
        $b=$a;
        $k=$key;
    }
    $i++;
 }
 $lagest[$k]=$b;
 print_r($lagest);
