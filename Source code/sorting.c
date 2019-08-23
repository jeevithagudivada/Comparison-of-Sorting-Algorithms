#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<time.h>
#define ma 1000000
void shellsort(int *,int);              //SHELL
void selsort(int* ,int);                //SELECTION
void quicksort(int [],int,int);         //QUICK
int parti(int [],int,int);
void mergesort(int [],int ,int ,int );  //MERGE
void part(int [],int ,int );
void heapsort(int [], int );            //HEAP
void heapify(int [], int , int );
void swap(int *, int *);
void bubsort(int* ,int );               //BUBBLE
void insertion_sort(int*,int);          //INSERTION
void bucketsort(int*,int);              //BUCKET
void radixsort(int*,int);               //RADIX
int no_dig(int*,int);
void combsort(int*,int);                //COMB
void display(int* ,int );
void copyarray(int* ,int* ,int );


int main()
{
    int i;
    printf("size\tshellsort\tselsort\tquicksort\tmergesort\theapsort\tbubsort\tinsort\tbucketsort\tradixsort\tcombsort\n");
    for(i=10;i<=100000;i*=10)
    {
        int num[i];
        int b[i];
        int j;
        int nums;
        for(j=0;j<i;++j)
	{
		scanf("%d",&num[j]);
	}
        
        printf("%d \t ",i);
        copyarray(b,num,i);
        clock_t s=clock();
        shellsort(b,i);
        clock_t endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        selsort(b,i);
        endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        quicksort(b,0,i-1);
        endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        part(b,0,i-1);
        endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        heapsort(b,i);
        endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        bubsort(b,i);
        endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        insertion_sort(b,i);
        endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        bucketsort(b,i);
        endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        radixsort(b,i);
        endd=clock();
        printf("%f\t",1000*(endd-s)/(double)CLOCKS_PER_SEC);
        copyarray(b,num,i);
        s=clock();
        combsort(b,i);
        endd=clock();
        printf("%f\n",1000*(endd-s)/(double)CLOCKS_PER_SEC);
    }
    //fclose(ptr);
    return 0;
}

void display(int* a,int n)
{
    int i;
    for(i=0;i<n;++i)
        printf("%d\n",a[i]);
}

void copyarray(int* b,int* a,int n)
{
    int i;
    for(i=0;i<n;++i)
        b[i]=a[i];

}

///SHELL SORT

void shellsort(int *a,int n)
{
    int i,j,t,k;
    int incrementer=n/2;
    for(i=incrementer;i>0;i/=2)
    {
        for(j=i;j<n;j++)
        {
            t=a[j];
            for(k=j;k>=i;k-=i)
            {
                if(t<a[k-i])
                    a[k]=a[k-i];
                else
                    break;
            }
            a[k]=t;
        }
    }
}

///SELECTION SORT

void selsort(int* a,int n)
{
	int i,j,t,m;
	for(i=0;i<n;++i)
	{
		m=i;
		for(j=i;j<n;++j)
		{
			if(a[j]<a[m])
				m=j;
		}
		if(i!=m)
		{
			t=a[i];
			a[i]=a[m];
			a[m]=t;
		}
	}
}

///QUICK SORT

int parti(int a[],int l,int h)
{
    int p, i, j, t;
    p=a[l];
    i=l;
    j=h+1;
    do
    {
         do
            ++i;
         while(a[i]<p);
         do
            --j;
         while(a[j]>p);
         t=a[i];
         a[i]=a[j];
         a[j]=t;
      }
      while(i<j);
      t=a[i];
      a[i]=a[j];
      a[j]=t;
      t=a[l];
      a[l]=a[j];
      a[j]=t;
      return j;
}

void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int ind=parti(a,l,h);
        quicksort(a,l,ind-1);
        quicksort(a,ind+1,h);
    }
}

///MERGE SORT

void mergesort(int a[],int low,int mid,int high)
{
    int i,m,k,l,t[ma];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high))
    {
        if(a[l]<=a[m])
        {
            t[i]=a[l];
            l++;
        }
        else{
            t[i]=a[m];
            m++;
        }
        i++;
    }
    if(l>mid)
    {
        for(k=m;k<=high;k++)
        {
            t[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=l;k<=mid;k++)
        {
            t[i]=a[k];
            i++;
        }
    }
    for(k=low;k<=high;k++)
    {
        a[k]=t[k];
    }
}

void part(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        part(a,low,mid);
        part(a,mid+1,high);
        mergesort(a,low,mid,high);
    }
}

///HEAP SORT

void heapsort(int a[], int n)
{
	int i;
	for(i=n/2; i>0;i--)
	{
		heapify(a,n,i);
	}
	//disp(a, n);
	for(i=1;i<=n;i++)
	{
		swap(&a[1], &a[n-i+1]);
		heapify(a, n-i, 1);
	}
}

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void heapify(int a[], int n, int pos)
{
	int val = a[pos];
	int i = pos;
	int is_heap = 0;
	while(!(is_heap) && 2*i <= n)
	{
		int j = 2*i;
		if(j<n && a[j+1] > a[j])
			j++;
		if(val < a[j])
		{
			a[i] = a[j];
			i = j;
		}
		else
			is_heap = 1;
	}
	a[i] = val;
}

///BUBBLE SORT

void bubsort(int* a,int n)
{
    int i,j,temp,flag=1;
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<n-1-i;++j)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=0;
            }
        }
        if(flag==1)
            break;
    }
}

///INSERTION SORT

void insertion_sort(int* a,int n)
{
    int i,j,temp,e;
    for(i=1;i<n;++i)
    {
        j=i-1;
        e=a[i];
        while(j>=0&&e<a[j])
        {
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=e;
    }
}

///BUCKET SORT

void bucketsort(int* a,int n)
{
    int i,k,max=-65535;
    for(i=0;i<n;++i)
    {
        if(a[i]>max)
            max=a[i];
    }
    int m=max+1;
    int b[m];
    for(i=0;i<m;++i)
        b[i]=0;

    for(i=0;i<n;++i)
    {
        k=a[i];
        b[k]++;
    }
    int j=0;
    for(i=0;i<m;++i)
    {
        if(b[i]!=0)
        {
             int k=0;
             while(k<b[i])
             {
                 a[j]=i;
                 ++j;
                 ++k;
             }
         }
     }
}

///RADIX SORT

void radixsort(int* a,int n)
{
    int digit=no_dig(a,n);
    int i,j,k,l,m,p;
    int ar[n][10];
    for(i=0;i<digit;++i)
    {
        m=0;
        for(p=0;p<n;++p)
            for(j=0;j<10;++j)
                ar[p][j]=0;
        for(j=0;j<n;++j)
        {
           k=((a[j]/(int)pow(10,i))%10);
           ar[j][k]=a[j];
        }
        for(k=0;k<10;++k)
            for(l=0;l<n;++l)
                if(ar[l][k]!=0)
                {
                    a[m]=ar[l][k];
                    ++m;
                }
    }
}

int no_dig(int* a,int n)
{
    int max=a[0];
    int i;
    for(i=1;i<n;++i)
    {
        if(a[i]>max)
            max=a[i];
    }
    int d=0;
    while(max)
    {
        d++;
        max/=10;
    }
    return d;
}

///COMB SORT

void combsort(int* a,int n)
{
    int gap = n;
    while(1)
    {
        if(gap>1)
        {
            gap=(int)((double)gap/1.3);
        }
        int i,swapped = 0;
        for(i=0;i+ gap<n;++i)
        {
            if(a[i]>a[i+gap])
            {
                int t;
                t=a[i];
                a[i]=a[i+gap];
                a[i+gap]=t;
                swapped=1;
            }
        }
        if(gap==1&&!swapped)
        {
            break;
        }
    }
}
