#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MaxLength 40
typedef float Element;
typedef int num;
typedef struct {
   char ID[10];
   char Name[50];
   float R1, R2, R3;
}Student;

struct Node{
	Student Element;
	struct Node *Next;
	
};
typedef struct Node* List;
List getList(){
	List L;
	L = (List)malloc(sizeof(struct Node));
	return L;
}

int append(Student s, List *pL){
	List p ;
	p = *pL;
	while(p->Next != NULL){
		if(strcmp(s.ID,p->Next->Element.ID)){
			return 0;
		}
		p = p->Next;
	}
	p->Next = (List)malloc(sizeof(struct Node));
	strcpy(p->Next->Element.ID,s.ID);
	strcpy(p->Next->Element.Name,s.Name);
	p->Next->Element.R1 = s.R1;
	p->Next->Element.R2 = s.R2;
	p->Next->Element.R3 = s.R3;
	return 1;
}


List readList()
{
	int n,i;
	Student s;
	char st[50];
	List L = getList(); // Kh?i t?o danh sách r?ng
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" "); //skip some characters
		fgets(st,10,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.ID, st);
		fgets(st,50,stdin);
		if (st[strlen(st)-1] == '\n')
			st[strlen(st)-1] = '\0';
		strcpy(s.Name, st);
		scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
		// N?u mã sinh viên chua có thì chèn vào danh sách
                append(s,&L); 
	}
	return L;
} 


struct Node* locate(char x[10], List L){
	List P = L;
	while(P->Next != NULL){
		if(strcmp(P->Next->Element.ID,x) == 0){
			return P;
		}
		P = P->Next;
	}
	return P;
	
}

int main(){
	List L = (struct Node*)malloc(sizeof(struct Node));
L->Next=NULL;
struct Node *p, *q;
	
Student s;		

strcpy(s.ID,"123" );
strcpy(s.Name,"Hai Long" );
s.R1 = 1.2f;
s.R2 = 5.6f;
s.R3 = 5.6f;
	
p=L;
q = (struct Node*)malloc(sizeof(struct Node));
q->Element = s;
q->Next=NULL;
p->Next = q;
	
	
p=p->Next;	
strcpy(s.ID,"567" );
strcpy(s.Name,"Minh Bien" );
s.R1 = 1.2f;
s.R2 = 1.3f;
s.R3 = 5.6f;
	
q = (struct Node*)malloc(sizeof(struct Node));
q->Element = s;
q->Next=NULL;
p->Next = q;
	
p = locate("566", L);
if(p->Next==NULL)
   printf("NOT FOUND 566");
else
{
   float R = (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3)/3;
      printf("FOUND %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",p->Next->Element.ID, 
      p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
      p->Next->Element.R3,R);	
}
}

