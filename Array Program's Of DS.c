#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void disp(int *,int);
void disp_rev(int *,int);
void insbeg(int *,int *);
void insend(int *,int *);
void inspos(int *,int *);
void insaft(int *,int *);
void insbef(int *,int *);
void inssorted(int *,int *);
void delbeg(int *,int *);
void delend(int *,int *);
void delpos(int *,int *);
void delaft(int *,int *);
void delbef(int *,int *);
void delele(int *,int *);
void deleleall(int *,int *);
void deldup(int *,int *);
int seqsearch(int *, int, int);
int advseqsearch(int *,int,int);
int bsi(int *,int,int);
int bsr(int *,int,int,int);
void inter_sort(int *,int);
void bubble_sort(int *,int);
void bubble1_sort(int *,int);
void selection_sort(int *,int);
void insertion_sort(int *,int);
void mergesort(int *,int,int);
void mergearr(int *,int,int,int,int);
void quicksort(int *,int,int);
int splitt(int *,int,int);
void merge(int *,int *,int *,int,int);
void concat(int *,int *,int *,int,int);
int issorted(int *,int);
void main()
	{
	    int a[MAX],b[MAX],c[2*MAX],n=0,n1=0,ch,opt,ele,loc;
	    while(1)
	        {
	            system("cls");
	            printf("\n\n\tMenu of Array:");
	            printf("\n\n1.Creation");
	            printf("\n2.Display");
	            printf("\n3.Insertion");
	            printf("\n4.Deletion");
	            printf("\n5.Searching");
	            printf("\n6.Merging");
	            printf("\n7.Concatenaion");
	            printf("\n8.Sorting");
	            printf("\n0.Exit");
	            printf("\n\nEnter your choice:");
	            scanf("%d",&ch);
	            if(ch==0)
	                break;
	            else
	                {
	                    system("cls");
	                    switch(ch)
	                        {
	                            case 1:printf("\n\nCreate an array:");
		                            create(a,&n);
		                            break;
	                             case 2:system("cls");
		                            printf("Traversal of elements of the array:");
		                            printf("\n\n\tSub-Menu for display");
		                            printf("\n\n1.In-order");
		                            printf("\n2.Reverse order");
		                            printf("\n0.Exit");
		                            printf("\n\nEnter your choice:");
		                            scanf("%d",&opt);
		                            switch(opt)
			                            {
			                                case 1:printf("Elements of array in in-order");
				                                disp(a,n);
				                                break;
			                                case 2:printf("Elements of array inreverse-order");
				                                disp_rev(a,n);
				                                break;
			                                case 0:break;
			                                default:printf("Invalid option");
			                            }
		                            break;
	                            case 3:system("cls");
		                            printf("\n\n\tSub-Menu for Insertion:");
		                            printf("\n\n1.At beginning");
		                            printf("\n2.At end");
		                            printf("\n3.At given position");
		                            printf("\n4.After given element");
		                            printf("\n5.Before given element");
		                            printf("\n6.In sorted array");
		                            printf("\n0.Exit");
		                            printf("\n\nEnter your choice:");
		                            scanf("%d",&opt);
		                            switch(opt)
			                            {
			                                case 1:printf("Insertion of element at beg of array");
				                                insbeg(a,&n);
				                                break;
			                                case 2:printf("Insertion of element at end of array");
				                                insend(a,&n);
				                                break;
			                                case 3:printf("Insertion of element at given position of array");
				                                inspos(a,&n);
				                                break;
			                                case 4:printf("Insertion of element after given element");
				                                insaft(a,&n);
				                                break;
			                                case 5:printf("Insertion of element before given element");
				                                insbef(a,&n);
				                                break;
			                                case 6:printf("Insertion of element before given element");
				                                if(issorted(a,n))
				                                    inssorted(a,&n);
				                                else
				                                    printf("\nArray is unsorted. Insertion not possible.");
				                                break;
			                                case 0:break;
			                                default:printf("Invalid option");
			                            }
		                            break;
	                            case 4:system("cls");
		                            printf("\n\n\tSub-Menu for Deletion:");
		                            printf("\n\n1.From beginning");
		                            printf("\n2.From end");
		                            printf("\n3.From given position");
		                            printf("\n4.Given element(Once)");
		                            printf("\n5.Given element from all occurences.");
		                            printf("\n6.After given element");
		                            printf("\n7.Before given element");
		                            printf("\n8.Duplicate elements");
		                            printf("\n0.Exit");
		                            printf("\n\nEnter your choice:");
		                            scanf("%d",&opt);
		                            switch(opt)
			                            {
			                                case 1:printf("Deletion of element from beg of array");
				                                delbeg(a,&n);
				                                break;
			                                case 2:printf("Deletion of element from end of array");
				                                delend(a,&n);
				                                break;
			                                case 3:printf("Deletion of element from given position of array");
				                                delpos(a,&n);
				                                break;
			                                case 4:printf("Deletion of given element(Once)");
				                                delele(a,&n);
				                                break;
			                                case 5:printf("Deletion of given element(All)");
				                                deleleall(a,&n);
				                                break;
			                                case 6:printf("Deletion of element after given element of array.");
				                                delaft(a,&n);
				                                break;
			                                case 7:printf("Deletion of element before given element of array.");
				                                delbef(a,&n);
				                                break;
			                                case 8:printf("Deletion of duplicate element");
				                                deldup(a,&n);
				                                break;
			                                case 0:break;
			                                default:printf("Invalid option");
			                            }
		                            break;
		                        case 5:system("cls");
		                            printf("\n\n\tSub-Menu for Searching:");
		                            printf("\n\n1.Sequential Search");
		                            printf("\n2.Advanced Sequential Search");
		                            printf("\n3.Binary Search(Iterative).");
		                            printf("\n4.Binary Search(Recursive).");
		                            printf("\n0.Exit");
		                            printf("\n\nEnter your choice:");
		                            scanf("%d",&opt);
		                            switch(opt)
			                            {
			                                case 1:printf("Searching of an element using seuential search");
				                                if(n==0)
				                                    printf("\nArray is empty. Searching not possible");
				                                else
				                                    {
				                                        printf("Enter element to be searched:");
				                                        scanf("%d",&ele);
				                                        loc=seqsearch(a,n,ele);
				                                        if(loc==-1)
				                                            printf("Element not found in array:");
				                                        else
				                                            printf("Element found at %d position",loc);
				                                    }
				                                break;
			                                case 2:printf("Searching of an element using advanced seuential search");
				                                if(n==0)
				                                    printf("\nArray is empty. Searching not possible");
				                                else
				                                    {
				                                        printf("Enter element to be searched:");
				                                        scanf("%d",&ele);
				                                        loc=advseqsearch(a,n,ele);
				                                        if(loc==-1)
				                                            printf("Element not found in array:");
				                                        else
				                                            printf("Element found at %d position",loc);
				                                    }
				                                break;
			                                case 3:printf("Searching of an element using binary iterative");
				                                if(n==0)
				                                    printf("\nArray is empty. Searching not possible");
				                                else
				                                    {
				                                        printf("Enter element to be searched:");
				                                        scanf("%d",&ele);
				                                        loc=bsi(a,n,ele);
				                                        if(loc==-1)
				                                            printf("Element not found in array:");
				                                        else
				                                            printf("Element found at %d position",loc);
				                                    }
				                                break;
			                                case 4:printf("Searching of an element using binary recursive");
				                                if(n==0)
				                                    printf("\nArray is empty. Searching not possible");
				                                else
				                                    {
				                                        printf("Enter element to be searched:");
				                                        scanf("%d",&ele);
				                                        loc=bsr(a,0,n-1,ele);
				                                        if(loc==-1)
				                                            printf("Element not found in array:");
				                                        else
				                                            printf("Element found at %d position",loc);
				                                    }
				                                break;
			                                case 0:break;
			                                default:printf("Invalid option");
			                            }
			                        break;
		                        case 6:system("cls");
		                            printf("\n\nMerging of two arrays");
		                            printf("\n\nTo merge create another array:");
		                            create(b,&n1);
		                            if(issorted(a,n)&&issorted(b,n1))
			                            {
			                                merge(a,b,c,n,n1);
			                                printf("\n\nAftre merging elements of resultant array:");
			                                disp(c,n+n1);
			                            }
		                            else
			                            printf("\n\nArrays are unsorted. Merging not possible");
		                            break;
		                        case 7:system("cls");
		                            printf("\n\nConcatenation of two arrays:");
		                            printf("\n\nTo concatenate create another array:");
		                            create(b,&n1);
		                            concat(a,b,c,n,n1);
		                            printf("\n\nAfter concatenation elements of resultant array:");
		                            disp(c,n+n1);
		                            break;
		                        case 8:system("cls");
		                            printf("\n\n\tSub-Menu for Sorting:");
		                            printf("\n\n1.Bubble");
		                            printf("\n2.Modified Bubble");
		                            printf("\n3.Selection");
		                            printf("\n4.Insertion");
		                            printf("\n5.Quick");
		                            printf("\n6.Merge");
		                            printf("\n0.Exit");
		                            printf("\n\nEnter your choice:");
		                            scanf("%d",&opt);
		                            switch(opt)
			                            {
			                                case 1:bubble_sort(a,n);
				                                printf("\n\nAfter sorting elements of array are:");
			    	                            disp(a,n);
				                                break;
			                                case 2:bubble1_sort(a,n);
				                                printf("\n\nAfter sorting elements of array are:");
				                                disp(a,n);
				                                break;
			                                case 3:selection_sort(a,n);
				                                printf("\n\nAfter sorting elements of array are:");
				                                disp(a,n);
				                                break;
			                                case 4:insertion_sort(a,n);
				                                printf("\n\nAfter sorting elements of array are:");
				                                disp(a,n);
				                                break;
			                                case 5:quicksort(a,0,n-1);
				                                printf("\n\nAfter sorting elements of array are:");
				                                disp(a,n);
				                                break;
			                                case 6:mergesort(a,0,n-1);
				                                printf("\n\nAfter sorting elements of array are:");
				                                disp(a,n);
				                                break;
			                                case 0:break;
			                                    default:printf("Invalid option");
			                            }
		                            break;
	                            default:printf("Invalid option");
	                        }
	                }
                    getch();
            }
        // getch();
    }
void create(int *a,int *n)
	{
	    int ele;
	    while(1)
	        {
	            if(*n==MAX)
	                {
	                    printf("\nArray is full.Insertion not possible");
	                        break;
	                }
	            else
	                {
	                    printf("Enter elements(-1to exit):");
	                    scanf("%d",&ele);
	                    if(ele==-1)
		                    break;
	                    else
		                    a[(*n)++]=ele;
	                }
	        }
	}
void disp(int *a,int n)
	{
	    int i;
	    if(n==0)
	        printf("\nList is empty");
	    else
	        {
	            printf("\nElements of array are:\n");
	            printf("Position    Element");
	            for(i=0;i<n;i++)
	                printf("\na[%d]\t=\t%d",i,a[i]);
	        }
	}
void disp_rev(int *a,int n)
	{
	    int i;
	    if(n==0)
	        printf("\nList is empty");
	    else
	        {
	            printf("\nElements of array in reverse order are:");
	            printf("\nPosition Element");
	            for(i=n-1;i>=0;i--)
		            printf("\n a[%d]=\t\t%d",i,a[i]);
	        }
	}
void insbeg(int *a,int*n)
	{
	    int i,ele;
	    if(*n==MAX)
	        printf("\nArray is full. Insertion not possible");
	    else
	        {
	            printf("\nEnter element to be inserted at beg:");
	            scanf("%d",&ele);
	            for(i=*n;i>0;i--)
		            a[i]=a[i-1];
	                a[0]=ele;
	                (*n)++;
	        }
	}
void insend(int *a,int *n)
	{
	    int ele;
	    if(*n==MAX)
	        printf("\nArray is full. Insertion not possible");
	    else
	        {
	            printf("\nEnter element to be inserted at end:");
	            scanf("%d",&ele);
	            a[*n]=ele;
	            (*n)++;
	        }
	}
void insaft(int *a,int *n)
	{
	    int ele,i,pos;
	    if(*n==MAX)
	        printf("\nList is full. Insertion not possible");
	    else
	        {
	            printf("\nEnter element after which you want to insert:");
	            scanf("%d",&ele);
	            for(pos=0;pos<*n;pos++)
	                if(a[pos]==ele)
		                break;
	                if(pos==*n)
	                    printf("\nElement not found. Insertion not possible.");
	                else
	                    {
	                        printf("\nEnter element to be inserted:");
	                        scanf("%d",&ele);
	                        for(i=*n;i>pos+1;i--)
		                        a[i]=a[i-1];
	                            a[i]=ele;
	                            (*n)++;
	                    }
	        }
	}
void insbef(int *a,int *n)
	{
	    int ele,i,pos;
	    if(*n==MAX)
	        printf("\nList is full. Insertion not possible.");
	    else
	        {
	            printf("\nEnter element before which you want to insert:");
	            scanf("%d",&ele);
	            for(pos=0;pos<*n;pos++)
	                if(a[pos]==ele)
		                break;
	                if(pos==*n)
	                    printf("\nElement not found. Insertion not possible.");
	                else
	                    {
	                        printf("\nEnter element to be inserted:");
	                        scanf("%d",&ele);
	                        for(i=*n;i>pos;i--)
		                        a[i]=a[i-1];
	                            a[i]=ele;
	                            (*n)++;
	                    }
	        }
	}
void inspos(int *a,int *n)
	{
	    int i,ele,pos;
	    if(*n==MAX)
	        printf("\nArray is full. Insertion not possible");
	    else
	        {
	            printf("\nEnter position where you want to insert:");
	            scanf("%d",&pos);
	            if(pos<0||pos>*n)
		            printf("\nInvalid position value. Insertion not possible");
	            else
		            {
		                printf("\nEnter element to be inserted:");
		                scanf("%d",&ele);
		                for(i=*n;i>pos;i--)
		                    a[i]=a[i-1];
		                    a[pos]=ele;
		                    (*n)++;
		            }
	        }
	}
void inssorted(int *a,int *n)
	{
	    int ele,i;
	    if(*n==MAX)
	        printf("\nList is full. Insertion not possible");
	    else
	        {
	            printf("\nEnter element to be inserted:");
	            scanf("%d",&ele);
	            for(i=*n;i>0;i--)
	                if(a[i-1]>ele)
		                a[i]=a[i-1];
	                else
		                break;
	            a[i]=ele;
	            (*n)++;
	        }
	}
void delbeg(int *a,int *n)
	{
	    int ele,i;
	    if(*n==0)
	        printf("\nList is empty. Deletion not possible");
	    else
	        {
	            ele=a[0];
	            for(i=0;i<(*n)-1;i++)
	                a[i]=a[i+1];
	                (*n)--;
	            printf("\nElement deleted from beg=%d",ele);
	        }
	}
void delend(int *a,int *n)
	{
	    int ele;
	    if(*n==0)
	        printf("\nList is empty. Deletion not possible");
	    else
	        {
	            ele=a[(*n)-1];
	            (*n)--;
	            printf("\nElement deleted from end=%d\n",ele);
	        }
	}
void delpos(int *a,int *n)
	{
	    int ele,i,pos;
	    if(*n==0)
	        printf("\nList is empty. Deletion not possible");
	    else
	        {
	            printf("\nEnter position from where you want to delete:");
	            scanf("%d",&pos);
	            if(pos<0||pos>(*n)-1)
	                printf("\nInvalid position value. Deletion not possible.");
	            else
	                {
	                    ele=a[pos];
	                    for(i=pos;i<(*n)-1;i++)
		                    a[i]=a[i+1];
	                        (*n)--;
	                    printf("\nDeleted element from given position=%d\n",ele);
	                }
	        }
	}
void delaft(int *a,int *n)
	{
	    int ele,i,j;
	    if(*n==0)
	        printf("\nList is empty. Deletion not possible");
	    else
	        {
	            printf("\nEnter element after which you want to delete:");
	            scanf("%d",&ele);
	            for(i=0;i<*n;i++)
	                if(a[i]==ele)
		                break;
	                if(*n==i)
	                    printf("\nElement not found. Deletion not possible");
	                else if(i==(*n)-1)
	                    printf("\nElement found at last position. Deletion not possible");
	                else
	                    {
	                        ele=a[i+1];
	                        for(j=i+1;j<(*n)-1;j++)
		                    a[j]=a[j+1];
	                        (*n)--;
	                        printf("\nDeleted element=%d",ele);
	                    }
	        }
	}
void delbef(int *a,int *n)
	{
	    int ele,i,j;
	    if(*n==0)
	        printf("\nList is empty. Deletion not possible");
	    else
	        {
	            printf("\nEnter element before which you want to delete:");
	            scanf("%d",&ele);
	            for(i=0;i<*n;i++)
	            if(a[i]==ele)
		            break;
	            if(*n==i)
	                printf("\nElement not found. Deletion not possible");
	            else if(i==0)
	                printf("\nElement found at first position. Deletion not possible");
	            else
	                {
	                    ele=a[i-1];
	                    for(j=i-1;j<(*n)-1;j++)
		                    a[j]=a[j+1];
	                        (*n)--;
	                    printf("\nDeleted element=%d",ele);
	                }
	        }
	}
void delele(int *a,int *n)
	{
	    int ele,i,j;
	    if(*n==0)
	        printf("\nList is empty. Deletion not possible");
	    else
	        {
	            printf("\nEnter element which you want to delete:");
	            scanf("%d",&ele);
	            for(i=0;i<*n;i++)
	                if(a[i]==ele)
		                break;
	                if(*n==i)
	                    printf("\nElement not found. Deletion not possible");
	                else
	                    {
	                        for(j=i;j<(*n)-1;j++)
		                        a[j]=a[j+1];
	                            (*n)--;
	                        printf("\nElement deleted from %d position.",i);
	                    }
	        }
	}
void deleleall(int *a,int *n)
	{
	    int ele,i,j,count=0;
	    if(*n==0)
	        printf("\nList is empty. Deletion not possible");
	    else
	        {
	            printf("\nEnter element to be deleted:");
	            scanf("%d",&ele);
	            i=0;
	            while(i<*n)
	                {
	                    if(a[i]==ele)
		                    {
		                        count++;
		                        for(j=i;j<(*n)-1;j++)
		                        a[j]=a[j+1];
		                        (*n)--;
		                    }
	                    else
		                    i++;
	                }
	            if(count==0)
	                printf("\nElement not found");
	            else
	                printf("\nElement deleted from %d positions",count);
	        }
	}
void deldup(int *a,int *n)
	{
	    int i,j,k,count=0;
	    if(*n==0)
	        printf("\nList is empty. Deletion not possible");
	    else
	        {
	            for(i=0;i<(*n)-1;i++)
	                {
	                    j=i+1;
	                    while(j<*n)
		                if(a[i]==a[j])
		                    {
		                        count++;
		                        for(k=j;k<(*n)-1;k++)
		                            a[k]=a[k+1];
		                            (*n)--;
		                    }
		                else
		                    j++;
	                }
	            if(count==0)
	                printf("\nNo duplicate element found.");
	            else
	                printf("\n%d duplicate element deleted.",count);
	        }
	}
int seqsearch(int *a,int n,int ele)
	{
	    int i;
	    for(i=0;i<n;i++)
	        if(a[i]==ele)
	            return i;
	    return -1;
	}
int advseqsearch(int *a,int n,int ele)
	{
	    int i;
	    for(i=0;i<n&&a[i]<=ele;i++)
	        if(a[i]==ele)
	            return i;
	    return -1;
	}
int bsi(int *a,int n,int ele)
	{
	    int beg,mid,end;
	    beg=0;
	    end=n-1;
	    while(beg<=end)
	        {
	            mid=(beg+end)/2;
	            if(a[mid]==ele)
	                return mid;
	            else if(a[mid]>ele)
	                end=mid-1;
	            else
	                beg=mid+1;
	        }
	    return -1;
	}
int bsr(int *a,int beg,int end,int ele)
	{
	    int mid;
	    if(beg<=end)
	        {
	            mid=(beg+end)/2;
	            if(a[mid]==ele)
	                return mid;
	            else if(a[mid]>ele)
	                return(bsr(a,beg,mid-1,ele));
	            else
	                return(bsr(a,mid+1,end,ele));
	        }
	    return -1;
	}
void inter_sort(int *a,int n)
	{
	    int i,j,temp;
	    for(i=0;i<n-1;i++)
	        for(j=i+1;j<n;j++)
	            if(a[i]>a[j])
		            {
		                temp=a[i];
		                a[i]=a[j];
		                a[j]=temp;
		            }
	}
void bubble_sort(int *a,int n)
	{
	    int i,j,temp;
	    for(i=1;i<n;i++)
	        for(j=0;j<n-i-1;j++)
	            if(a[j]>a[j+1])
		            {
		                temp=a[j];
		                a[j]=a[j+1];
		                a[j+1]=temp;
		            }
	    printf("No. of pass executed:%d",i-1);
	}
void bubble1_sort(int *a,int n)
	{
	    int i,j,temp,done=0;
	    for(i=1;i<n&&!done;i++)
	        {
	            done=1;
	            for(j=0;j<n-i;j++)
	                if(a[j]>a[j+1])
		                {
		                    done=0;
		                    temp=a[j];
		                    a[j]=a[j+1];
		                    a[j+1]=temp;
		                }
	        }
	    printf("No. of pass executed:%d",i-1);
	}
void selection_sort(int *a,int n)
	{
	    int i,j,s,temp;
	    for(i=0;i<n-1;i++)
	        {
	            s=i;
	            for(j=i+1;j<n;j++)
	                if(a[j]<a[s])
		                s=j;
	                if(i!=s)
	                    {
	                        temp=a[i];
	                        a[i]=a[s];
	                        a[s]=temp;
	                    }
	    }
	}
void insertion_sort(int *a,int n)
	{
	    int i,j,s,temp;
	    for(i=1;i<n;i++)
	        {
	            temp=a[i];
	            for(j=i;j>0;j--)
	                if(a[j-1]>temp)
		                a[j]=a[j-1];
	                else
		                break;
	            a[j]=temp;
	        }
	}
void quicksort(int *a,int beg,int end)
	{
	    int loc;
	    if(beg<end)
	        {
	            loc=splitt(a,beg,end);
	            quicksort(a,beg,loc-1);
	            quicksort(a,loc+1,end);
	        }
	}
int splitt(int *a,int lt,int rt)
	{
	    int loc,temp,done=0;
	    loc=lt;
	    while(!done)
	        {
	            while(loc!=rt&&a[loc]<=a[rt])
	                rt--;
	            if(loc==rt)
	                done=1;
	            else
	                {
	                    temp=a[loc];
	                    a[loc]=a[rt];
	                    a[rt]=temp;
	                    loc=rt;
	                    lt++;
	                }
	            if(!done)
	                {
	                    while(loc!=lt&&a[loc]>=a[lt])
		                    lt++;
	                    if(loc==lt)
		                    done=1;
	                    else
		                    {
		                        temp=a[loc];
		                        a[loc]=a[lt];
		                        a[lt]=temp;
		                        loc=lt;
		                        rt--;
		                    }
	                }
	        }
	    return loc;
	}
void mergesort(int *a,int beg,int end)
	{
	    int mid;
	    if(beg<end)
	        {
	            mid=(beg+end)/2;
	            mergesort(a,beg,mid);
	            mergesort(a,mid+1,end);
	            mergearr(a,beg,mid,mid+1,end);
	        }
	}
void mergearr(int *a,int lb,int le,int rb,int re)
	{
	    int c[MAX],i,na,nb,nc;
	    na=nc=lb;
	    nb=rb;
	    while(na<=le&&nb<=re)
	        {
	            if(a[na]<a[nb])
	                c[nc++]=a[na++];
	            else
	                c[nc++]=a[nb++];
	        }
	    if(na>le)
	        while(nb<=re)
	            c[nc++]=a[nb++];
	    else
	        while(na<=le)
	            c[nc++]=a[na++];
	    for(i=lb;i<=re;i++)
	        a[i]=c[i];
	}
void merge(int *a,int *b,int *c, int n1,int n2)
	{
	    int na,nb,nc;
	    na=nb=nc=0;
	    while(na<n1&&nb<n2)
	        if(a[na]<b[nb])
	            c[nc++]=a[na++];
	        else
	            c[nc++]=b[nb++];
	    if(na==n1)
	        while(nb<n2)
	            c[nc++]=b[nb++];
	    else
	        while(na<n1)
	            c[nc++]=a[na++];
	}
void concat(int *a,int *b,int *c,int n1,int n2)
	{
	    int i;
	    for(i=0;i<n1;i++)
	        c[i]=a[i];
	    for(i=0;i<n2;i++)
	        c[n1+i]=b[i];
	}
int issorted(int *a,int n)
	{
	    int i;
	    for(i=0;i<n-1;i++)
	        if(a[i]>a[i+1])
	            return 0;
	    return 1;
	}