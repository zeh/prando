class lowerToUper{
    public static void main(String argv[]){
        String input = "AbcDefF";
        String temp = "";
        for(int i=0;i<=input.length();i++)
        {
            if(isUpperCase(input[i]))
                temp+=toLowerCase(input[i]);
                else
                temp+=toUpperCase(input[i]);
        }
        System.out.print(temp);
    }
}