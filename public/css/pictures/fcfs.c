#include<stdio.h>
int main()
{
int n,a[10],b[10],t[10],w[10],g[10],i,m;
float att=0,awt=0;
            for(i=0;i<10;i++)
            {
                        a[i]=0; b[i]=0; w[i]=0; g[i]=0;
            }
printf("enter number of process:");
            scanf("%d",&n);
printf("enter burst times:");
            for(i=0;i<n;i++)
                scanf("%d",&b[i]);
    printf("\nenter the arrival times:");
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
    g[0]=0;
             for(i=0;i<10;i++)
                   g[i+1]=g[i]+b[i];
             for(i=0;i<n;i++)
            {     
w[i]=g[i]-a[i];
                        t[i]=g[i+1]-a[i];
                        awt=awt+w[i];
                        att=att+t[i]; 
            }
     awt =awt/n;
            att=att/n;
            printf("\n\tprocess\twaiting time\tturn arround time\n");
            for(i=0;i<n;i++)
            {
                        printf("\tp%d\t\t%d\t\t%d\n",i,w[i],t[i]);
            }
printf("Average waiting time = %f\n",awt);
printf("Average turn around time = %f\n",att);
} 

