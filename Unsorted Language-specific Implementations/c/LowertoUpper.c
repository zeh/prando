int main(){
    char s1[100], s2[100];

    printf("String:\n");
    gets(s1);

    strcpy(s2, s1);

    for(int i = 0; i < 100; i++){

        if(s2[i] > 63 && s2[i] < 91){
            s2[i] = s2[i] + 32;
        }else if(s2[i] > 96 && s2[i] < 123){
            s2[i] = s2[i] - 32;
        }
    }

    printf("%s", s2);
}
