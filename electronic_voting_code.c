#include<stdio.h>
#include<stdlib.h>
void main()
{
    int candidates_count;
    printf("Enter the no.of candidates:\n");
    scanf("%d",&candidates_count);
    char str[candidates_count][15];
    int i,temp=0,vote,password,flag=0,reg_num,reg_list[]={123,156,157,158,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
                                                          176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,
                                                          196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,
                                                          216,217};
    int arr[candidates_count],arr1[candidates_count];
    printf("Enter candidates name:\n");
    for(i=0;i<candidates_count;i++)
    {
        scanf("%s[^\n]",str[i]);
    }
    if(candidates_count==1)
    {
        printf("%s you are winner without competition\n!CONGRATULATIONS!",str[0]);
        exit(1);
    }
    else
    {
        printf("**********************************************\n");
        printf("            Voting is started\n");
        printf("          Vote your representative.\n");
        printf("**********************************************\n");    
        for(i=0;i<candidates_count;i++)
        {
            arr[i]=0;
            arr1[i]=i+1;
        }
        while(1)
        {
            for(i=0;i<candidates_count;i++)
            {
                printf("To vote for %s enter (%d)\n",str[i],i+1);
            }
            printf("Enter your register number:\n");
            scanf("%d",&reg_num);
            for(i=0;i<62;i++)
            {
                if(reg_num!=123)
                {
                    if (reg_list[i]==reg_num)
                    {
                        reg_list[i]=0;
                        flag=1;
                    }
                }
                else if(reg_num==123)
                flag=1;
            }
            if(flag==1)
            {
                flag=0;
                while(1)
                {
                    printf("Enter your vote:\n");
                    scanf("%d",&vote);
                    if(vote<=candidates_count&&vote>0)
                    {
                        for(i=0;i<candidates_count;i++)
                        {
                            if(arr1[i]==vote)
                            {
                                arr[i]+=1;
                            }
                        }
                        break;
                    }
                    else if (vote==123&&reg_num==123)
                    break;
                    else 
                    printf("ENTER CORRECT NUMBER!\n");
                }
            }
            else
            printf("!!!Enter CORRECT register number!!!");
            if(vote==123)
            break;
        }   
        printf("\n");   
        while(1)
        { 
            printf("Enter password to know the leader:\n");
            scanf("%d",&password);
            if(password==12345)
            {
                int temp1=0;
                for(i=0;i<candidates_count;i++)
                {
                    if(arr[i]>temp1)
                    {
                        temp1=arr[i];
                        temp=i;
                    }
                    else if(arr[i]==temp1)
                    {
                        temp=-1;
                    }
                    printf("%s has got %d votes\n",str[i],arr[i]);
                }
                if(temp>=0)
                {
                    printf("Congratulations\n%s won election\n",str[temp]);
                    break;
                }
                else
                {
                    printf("**********************************************\n");
                    printf("                 !!!Oops!!!\n");
                    printf("     !!!Looks like we got equal votes!!!\n");
                    printf("**********************************************\n");
                    break;
                }
            }
            else
            printf("Enter correct password!\n");
        }
    }
    for(i=0;i<62;i++)
    {
        printf("%d ",reg_list[i]);
    }
}