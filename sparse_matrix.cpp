#include<iostream>
using namespace std;

class BaseMat
{
    protected :
        int row,col;
        int array[100][100];
    public :
        void Matrix()
        {
            cout<<"Enter the number of rows and columns : ";
            cin>>row>>col;
            this ->row=row; this->col=col;
            cout<<"\nEnter the array elements "<<endl;
            for(int i =0; i<row;i++)
            {
                for(int j = 0;j<col;j++)
                {
                    cin>>array[i][j];
                }
            }
        }

        void display()
        {
            cout<<"The base matrix is : "<<endl;
            for(int i =0; i<row;i++)
            {
                for(int j = 0;j<col;j++)
                {
                    cout<<array[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
};

class sparseMat : public BaseMat
{
    int k =0;
    int NonZero[100];
    public :
        int temp;
        int countZ=0, countN=0;
        void Sparse()
        {
            for(int i =0;i<row;i++)
            {
                for(int j = 0 ;j<col;j++)
                {
                    if(array[i][j]==0)
                        countZ++;
                    else    
                        countN++;
                }
            }
            if(countN<countZ){ 
                cout<<"The matrix is a sparse matrix "<<endl<<endl;

                for(int i =0 ;i<row;i++)
                {
                    for(int j =0;j<col;j++)
                    {
                        if(array[i][j]!=0)
                            NonZero[k++]=array[i][j];
                    }
                }
                cout<<"The non zero elements of the Sparse matrix are :"<<endl;
                
                for(int i =0;i<k;i++)
                {
                    cout<<NonZero[i]<<" ";
                }
                cout<<"\n";

                for(int i =0 ;i<k-1;++i)
                {
                    for(int j =0;j<k-i-1;++j)
                    {
                        if(NonZero[j]>NonZero[j+1])
                        {
                            temp = NonZero[j];
                            NonZero[j]=NonZero[j+1];
                            NonZero[j+1]=temp;
                        }   
                    }
                }

                cout<<"The elements in the sorted order are :"<<endl;
                for(int i =0;i<k;i++)
                {
                    cout<<NonZero[i]<<" ";
                }
                cout<<"\n";
            }

            else{
                cout<<"it is not a sparse matrix"<<endl<<endl;
            }
        }
};

int main()
{
    sparseMat Mat;
    Mat.Matrix();
    Mat.display();
    cout<<"Checking if the matrix is a sparse matrix \n"<<endl;
    Mat.Sparse();
    return 0;
}