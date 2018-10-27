#include<iostream>
#include<cstring>
using namespace std;

void print_sparse(int mat[][3]){
    int c[mat[0][0]][mat[0][1]] ,k = 1;
    for(int i = 0; i< mat[0][0]; i++){
        for(int j = 0; j<mat[0][1]; j++){
            if(i == mat[k][0] && j == mat[k][1]){
                c[i][j] = mat[k][2];
                k++;
            }
            else
                c[i][j] = 0;
        }
    }
    cout<<endl;
    /*for(int i =0; i<= mat[0][2]; i++){
        cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
    }
    cout<<endl;*/
    for(int i=0; i<mat[0][0]; i++){
        for(int j=0; j<mat[0][1]; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}

void print(int mat[][3]){
    cout<<endl;
    for(int i =0; i<= mat[0][2]; i++){
        cout<<mat[i][0]<<" "<<mat[i][1]<<" "<<mat[i][2]<<endl;
    }
    cout<<endl;
}

void del(int mul[][3], int x, int n){
    for(int i = x; i< n; i++){
        mul[i][0]= mul[i+1][0];
        mul[i][1]= mul[i+1][1];
        mul[i][2]= mul[i+1][2];
    }
}

int partition(int a[][3],int s,int e)
{
    int pivot=a[e][1];
    int indexpivot=s;
    for(int i=s;i<e;i++)
    {
        if(a[i][1] < pivot)
        {
            swap(a[i],a[indexpivot]);
            indexpivot++;
        }
    }
    swap(a[indexpivot],a[e]);
    return indexpivot;
}

void quicksort(int a[][3], int s,int e)
{
    if(s>=e)    return;
    int indexpivot=partition(a,s,e);
    quicksort(a, s, indexpivot-1);
    quicksort(a, indexpivot+1, e);
}

void sorted(int a[][3]){
    int *count = new int[10];
    for(int i = 0; i<10 ; i++){
        count[i] = 0;
    }
    for(int i = 1; i <= a[0][2]; i++){
        count[a[i][0]]++;
    }
    int start = 1, end = count[0] + 1;
    for(int i =0; i<a[0][0] ; i++){
        quicksort(a, start, end - 1);
        start = end ;
        end += count[i+1];
    }
  //  print(a);
}

void multiply_sparse(int A[][3], int B[][3], int mul[][3], int cnta, int cntb){
    int i = 1, k = 1;
    while(i <= cnta){
        int j = 1;
        while(j <= cntb){
            if(A[i][1] == B[j][1]){
                mul[k][0]= A[i][0];
                mul[k][1]= B[j][0];
                mul[k++][2]= A[i][2] * B[j][2];
            }
            j++;
        }
        i++;
    }
    mul[0][2] = k - 1;
    print(mul);
    //sort by column
    sorted(mul);

    for(int m = 1; m < k - 1; m++){
        if((mul[m][0] == mul[m + 1][0]) && (mul[m][1] == mul[m + 1][1])){
            mul[m][2] = mul[m][2] + mul[m + 1][2];
            del(mul, m+1, k-1);
            mul[0][2] = --k - 1;
        }
    }
    print(mul);
    print_sparse(mul);
}

int main(){
    int row1, row2, col1, col2;
    cin>>row1>>col1>>row2>>col2;
    cout<<endl;
    int **A = new int*[row1];
    for(int i= 0; i< row1; i++){
        A[i] = new int[col1];
    }
    int **B = new int*[row2];
    for(int i = 0; i< row2; i++){
        B[i] = new int[col2];
    }
    int cnt_a = 0, cnt_b = 0;
    for(int i = 0; i < row1; i++){
        for(int j = 0;j < col1; j++){
            cin>>A[i][j];
            if(A[i][j] != 0)    cnt_a++;
        }
    }
    cout<<endl;
    for(int i = 0; i < row2; i++){
        for(int j = 0;j < col2; j++){
            cin>>B[i][j];
            if(B[i][j] != 0)    cnt_b++;
        }
    }
    int t[row2][col2];
    for(int i = 0; i < row2; i++){
        for(int j = 0;j < col2; j++){
             t[j][i] = B[i][j];
        }
    }

    int A_sparse [cnt_a + 1][3];
    int B_sparse [cnt_b + 1][3];
    //cout<<endl;
    A_sparse[0][0] = row1; A_sparse[0][1] = col1; A_sparse[0][2] = cnt_a;
    int k =1;
    for(int i =0; i < row1; i++){
        for(int j =0; j< col1; j++){
            if(A[i][j] != 0){
                A_sparse[k][0] = i;
                A_sparse[k][1] = j;
                A_sparse[k][2] = A[i][j];
                k++;
            }
        }
    }
    //print_sparse(A_sparse);
    B_sparse[0][0] = row2; B_sparse[0][1] = col2; B_sparse[0][2] = cnt_b;
    int c =1;
    for(int i =0; i < row2; i++){
        for(int j =0; j< col2; j++){
            if(t[i][j] != 0){
                B_sparse[c][0] = i;
                B_sparse[c][1] = j;
                B_sparse[c][2] = t[i][j];
                c++;
            }
        }
    }
    //print_sparse(B_sparse);
    int mul[row1 * col2 + 1][3];
    mul[0][0] = row1; mul[0][1] = col2;
    multiply_sparse(A_sparse, B_sparse, mul, cnt_a, cnt_b);

}
