// WAP to convert the Sparse Matrix into non-zero form and vice-versa.
#include<iostream>
using namespace std;
template<class T>
class sparse
{
		int s;  //no of non-zero elements
		int dim; //dimension of square matrix
		static int k;
		T *t, *posi, *posj;
	public:
		sparse(int n=2, int m=2)
		{
			s=n;
			dim=m;
			t=new T[s];
			posi=new T[s];
			posj=new T[s];
		}/*
		sparse(const sparse<T> &temp)
		{
			s=temp.s;
			t=new T[s];
			for(int i=0;i<s;i++)
			{
				t[i]=temp.t[i];
				posi[i]=temp.posi[i];
				posj[i]=temp.posj[i];
			}
		}
		void show()
		{
			for(int l=0;l<k;l++)
			{
				cout<<t[l]<<" "<<posi[l]<<" "<<posj[l];
				cout<<endl;
			}
		}			*/
		void store(int i, int j, const T &x)
		{
			if(i<0 || j<0 || i>=dim || j>=dim)
			{
				cout<<"\n Index out of bounds! ";
				exit(1);
			}
			t[k]=x;
			posi[k]=i;
			posj[k]=j;
			k++;
		}
		T getValue(int i, int j)
		{
			if(i<0 || j<0 || i>=dim || j>=dim)
			{
				cout<<"\n Index out of bounds! ";
				exit(1);
			}
			for(int l=0;l<k;l++)
			{
				if(posi[l]==i && posj[l]==j)
					return t[l];
			}
			return 0;
		}
};
template<class T>
int sparse<T>::k=0;
int main()
{
	int n, temp, s;
	cout<<"\n\t SPARSE MATRIX "<<endl;
	cout<<"\n Enter size of square matrix: ";
	cin>>n;
	cout<<"\n Enter number of non-zero elements: ";
	cin>>s;
	sparse<int> array(s,n);
	cout<<"\n Enter Matrix Elements: ";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			if(temp!=0)
				array.store(i,j,temp);
		}
	}
	//array.show();
	cout<<"\n Displaying Matrix Entered: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<array.getValue(i,j);
		}
		cout<<endl;
	} 
	return 0;
}
