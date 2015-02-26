#include<stdio.h>
#include<stdlib.h>
#include<time.h>

# define MAX 10000

int n,e;
int array[10];
int queue[5000];
int front=-1;
int rear=-1;
void enqueue(int ele);
void traverse();
void fordfulkerson(int *p,int s,int t);
void dfs(int *p,int s,int *v,int n);
int visit[MAX];
int *v;


void main()
{
	int i,j,c;
	
	clock_t start,end;
	double time;
	
	FILE *fp;
	fp=fopen("rsd.txt","r");
	fscanf(fp,"%d%d",&n,&e);
	int graph[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			graph[i][j]=0;
		}
	}

	
	
	while(fscanf(fp,"%d%d%d",&i,&j,&c)!=EOF)
	{
		graph[i-1][j-1]=c;
		
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	
	int s=0;
	int t=n-1;
	int *p=&graph[0][0];
	int maxflow=0;	
	int *x;
	start=clock();
	fordfulkerson(p,s,t);
	end=clock();
	time=(end-start)/CLOCKS_PER_SEC;
	//printf("\nmaxflow is %d",maxflow);
	
}

void fordfulkerson(int *p,int s,int t)
{
	int maxflow=0;
	int i,j;
	
	int rgraph[n][n];
	
	int parent[n];
	

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			rgraph[i][j]=*(p+(n*i+j));
		}
	}
	
	

	int *q=&rgraph[0][0];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//printf("%d ",*(q+(n*i+j)));
		}
		//printf("\n");
	}	
	
	int *par=&parent[0];
	int bneck;
	
	while(bfs(q,s,t,par))
	{
		bneck=400;
		for(j=t;j!=s;j=*(par+j))
		{
			i=*(par+j);
			bneck=min(bneck,*(q+(n*i+j)));
			//printf("000");		
		}

		for(j=t;j!=s;j=*(par+j))
		{
			i=*(par+j);
			bneck=min(bneck,*(q+(n*i+j)));
			*(q+(n*i+j))-=bneck;
			*(q+(n*j+i))+=bneck;
				
		}
		
		maxflow+=bneck;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				//printf("%d ",*(q+(i*n+j)));
			}
			//printf("\n");
		}
		
	}
	// S-T Min Cut
	
	//printf("****n=%d",n);
	for(i=0;i<n;i++)
		visit[i]=0;

	//printf("n=%d",n);
	printf("maxflow=%d\n",maxflow);
	v=&visit[0];
	//printf("n=%d",n);
	dfs(q,s,v,n);

	
	//for(i=0;i<n;i++)
	//	printf("%d ",*(v+i));
	printf("\n");
	printf("S-T Cut Edges\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((*(v+i)==1) && (*(v+j)==0) && (*(p+(i*n+j))>0))
			{
				printf("%d->%d\n",i,j);
				
			}
		}
	}
			
	
}

int bfs(int *q,int s,int t,int *par)
{
	int i,j,top;
	int visited[n];
	
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}

	enqueue(s);
	visited[s]=1;
	*(par+s)=-1;

	while(!empty())
	{
		top=dequeue();
		
		for(i=0;i<n;i++)
		{
			//printf("****%d\n ",*(q+(n*top+i)));
			if(visited[i]==0 && (*(q+(n*top+i)))>0)
			{
				//printf("hello");
				enqueue(i);
				*(par+i)=top;
				visited[i]=1;
			}
			
		}
		traverse();		
				
	}
		if(visited[t]==1)
		{
			return 1;
		}
		else
		{
			//printf("****hiii");
			return 0;
		}	
	
}

void dfs(int *q,int s,int *v,int n)
{
	int i,j;
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",*(q+(n*i+j)));
		}
		printf("\n");
	}*/
	
	
	*(v+s)=1;
	//printf("Hello");
	//printf("n=%d",n);
	
	for(i=0;i<n;i++)
	{
		if((*(q+(s*n+i))>0)&&*(v+i)==0)
		{
			//printf("hi");
			dfs(q,i,v,n);
		}
	}
}

void enqueue(int ele)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=ele;
	}	
	else if(front==0&&rear==4999)
	{
		printf("Overflowed");
	}
	else if(front!=0 && rear==4999)
	{
		rear=0;
		queue[rear]=ele;
	}
	else
	{
		rear++;
		queue[rear]=ele;
	}

	//printf("%d element has been added to the queue\n",ele);
}

int dequeue()
{
	if(front==-1)
	{
		//printf("no element to delete");
		return -1;
	}
	int element;
	element=queue[front];
	
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		if(front==4999)
		{
			front=0;
		}
		else
		{
			front++;
		}
		//printf("Element dequeued is %d\n",element);
		return element;
	}
	return element;
}

int empty()
{
	if(front==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void traverse()
{
	int i=0;
	
	for(i=front;i<=rear;i++)
	{
		//printf("%d ",queue[i]);
	}
}

int min(int x,int y)
{
	if(x<=y)
	{
		return x;
	}
	else
		return y;
}


	
