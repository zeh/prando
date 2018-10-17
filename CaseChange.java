import java.util.Scanner;
class CaseChange{
    
    static String caseChangeMethod(String inputString){
        char c;
        String resultString = "";

        for(int i=0;i<inputString.length();i++){
            c = inputString.charAt(i);
            if(c >= 65 && c <= 90)
                resultString+= (char)(c+32);
            else
                if(c >= 97 && c <= 122)
                    resultString+= (char)(c-32);
            else
                resultString+= c;
        }
        return resultString;
    }

    public static void main(String... X) {
       
        Scanner sc = new Scanner(System.in);

        String inputString = sc.nextLine();

        inputString=caseChangeMethod(inputString);
        
        System.out.println("Changed : " +inputString);
    }
}